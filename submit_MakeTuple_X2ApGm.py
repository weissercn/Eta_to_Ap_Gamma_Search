import sys
#sys.path.append('/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python')
sys.path.append('.')


def name_DISPLACED(DISPLACED):
    if DISPLACED: return "Displ"
    else:         return "Prmpt"

def name_MAGDOWN(MAGDOWN):
    if MAGDOWN:   return "MagDown"
    else:         return "MagUp"

def name_GRID(GRID):
    if GRID:      return "Grid"
    else:         return "Local"

def script_factory(DECAY, DISPLACED, YEAR, GRID, EvtMax):

    with open("MakeNTuple_"+DECAY+"_factory.py", "r") as f_in:
        DATA = f_in.read()
        DATA = DATA.format(DISPLACED, YEAR, GRID, EvtMax)
        #print DATA
        name_f_out = "MakeNTuple_{0}_{1}_{2}_{3}.py".format(DECAY, name_DISPLACED(DISPLACED), YEAR, name_GRID(GRID))

        print "writing to file ", name_f_out
        with open(name_f_out, "w") as f_out:
            f_out.write(DATA)



#from GangaTools import *
import SubmissionTools

########################################################################################################
########################################################################################################

DECAY     = "X2ApGm"
DISPLACED = True
YEAR      = 2017
MAGDOWN   = True

GRID      = False
TEST      = False
TAG       = "pheonix"

########################################################################################################
########################################################################################################





if GRID:

    jname       = 'Data.{0}.{1}.{2}.{3}'.format(DECAY, name_DISPLACED(DISPLACED), YEAR, name_MAGDOWN(MAGDOWN))

    script_factory (DECAY, DISPLACED, YEAR, GRID, -1)
    script      = '/mnt/shared/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/MakeNTuple_{0}_{1}_{2}_{3}.py'.format(DECAY, name_DISPLACED(DISPLACED), YEAR, name_GRID(GRID))


    outfiles    = ['NTuple_X2ApGm_all_files_with_materials_test.root']
    MIT_shared_dir = '/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python/'
    infiles     = [LocalFile('./IsoBdt.py'), LocalFile('./IsoBdtLong.xml'), LocalFile('./IsoBdtVelo.xml')]
    infiles     += [LocalFile(MIT_shared_dir+'MITParticleMakers/AllMuMuGms.py'), LocalFile(MIT_shared_dir+'MITParticleMakers/AllMuMuGms_displaced.py'), LocalFile(MIT_shared_dir+'MITParticleMakers/AllMuMuGms_2017.py'), LocalFile(MIT_shared_dir+'MITParticleMakers/AllMuMuGms_displaced_2017.py'), LocalFile(MIT_shared_dir+'MITParticleMakers/DiElectrons.py'), LocalFile(MIT_shared_dir+'TTreeTools/NtupleBase.py'), LocalFile(MIT_shared_dir+'TTreeTools/NtupleComponents.py')]
    infiles     += [LocalFile('./Add_material_deploy.cxx'), LocalFile('./Add_material.cxx'), LocalFile('./velo.C'), LocalFile('./velo.h'), LocalFile('./HE16.1_pars.root')]
    #infiles     += SubmissionTools.getInputList()


    print "infiles : ", infiles


    #maybe switch back to DaVinci v42r2 to avoid DDDBTAG issues.
    SubmissionTools.submitDV(jname, TAG, script, outfiles,
                 appName='DaVinci', appPath='/home/weisser/', appVer='v42r6p1',
                 backend=None, infiles=infiles, gaudirun=False, test=TEST, maxFiles=-1, do_auto_resubmit=False)
                 #backend=None, infiles=infiles, gaudirun=False, test=TEST, maxFiles=1329, do_auto_resubmit=False)
    # appVer='v42r3'

else: #when GRID = False
    EvtMax = 400
    EvtMax = -1
    script_factory(DECAY, DISPLACED, YEAR, GRID, EvtMax)
    from subprocess import call
    call("lb-run DaVinci/v42r6p1 python MakeNTuple_{0}_{1}_{2}_{3}.py".format(DECAY, name_DISPLACED(DISPLACED), YEAR, name_GRID(GRID)).split(" "))

    print "\n\nWrote to file NTuple__Test__X2ApGm_{0}_{1}_{3}.root".format(DISPLACED, YEAR, GRID, EvtMax)
