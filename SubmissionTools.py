#====================================================
# Some functions for submitting jobs to the grid

from GangaJobInfo import JobInfo


# Get a list of input files from TTreeTools and MITParticleMakers
def getInputList():
    import pkgutil
    import TTreeTools
    import MITParticleMakers
    import Generators
    import GangaTools

    inputs = []

    path = TTreeTools.__path__
    for importer, modname, ispkg in pkgutil.iter_modules(path):
        inputs.append(path[0]+'/'+modname+'.py')
    path = MITParticleMakers.__path__
    for importer, modname, ispkg in pkgutil.iter_modules(path):
        inputs.append(path[0]+'/'+modname+'.py')
    path = Generators.__path__
    for importer, modname, ispkg in pkgutil.iter_modules(path):
        inputs.append(path[0]+'/'+modname+'.py')
    path = GangaTools.__path__
    for importer, modname, ispkg in pkgutil.iter_modules(path):
        inputs.append(path[0]+'/'+modname+'.py')

    return inputs

def submitDV(jname, tag, script, outfiles,
             appName='DaVinci', appPath='.', appVer='v42r3', appArgs=[],
             backend=None, infiles=None, gaudirun=False, test=False, maxFiles=-1, do_auto_resubmit = True):

    '''
    Function for submitting a generic GaudiExec job to the grid with Ganga.
    If a local version of the application doesn't exist, prepareGaudiExec is
    used to create it. Otherwise GaudiExec is used.
    '''

    #from GangaDirac.Lib.Backends import Dirac
    import os
    from Ganga.GPI import (Dirac,
                           DiracFile,
                           SplitByFiles,
                           BKQuery,
                           Job,
                           prepareGaudiExec,
                           GaudiExec
                           )

    if test: maxFiles = 1

    if infiles == None:
        infiles = getInputList()
    if backend == None:
        backend = Dirac()

    appDir = appPath + '/' + appName + 'Dev_' + appVer
    appDir = os.path.expanduser(appDir)
    if os.path.isdir(appDir):
        app = GaudiExec()
        app.directory = appDir
    else:
        app = prepareGaudiExec(appName,
                               appVer,
                               myPath=appPath)


    app.options = [script]
    app.useGaudiRun = gaudirun

    nfiles = JobInfo[jname]['NFiles']
    dpath = JobInfo[jname]['Input']

    mySplit = SplitByFiles()
    mySplit.filesPerJob = nfiles
    mySplit.maxFiles = maxFiles
    mySplit.ignoremissing = True

    j = Job(
        name             = jname + '.' + tag,
        application      = app,
        splitter         = mySplit,
        inputdata        = BKQuery(path=dpath).getDataset(),
        inputfiles       = infiles,
        outputfiles      = [DiracFile(outfile) for outfile in outfiles],
        do_auto_resubmit = do_auto_resubmit,
        backend          = backend
        )

    j.application.extraArgs += appArgs
    j.submit()
