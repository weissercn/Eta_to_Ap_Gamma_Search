import sys
#sys.path.append('/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python')
sys.path.append('.')


#from GangaTools import *
import SubmissionTools


jname       = 'Data.2016.6500.X2ApGm'
tag         = 'mag_down_first_try'
script      = '/mnt/shared/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/MakeNTuple_X2ApGm.py'
outfiles    = ['*.root']
infiles     = [LocalFile('./IsoBdt.py'), LocalFile('./IsoBdtLong.xml'), LocalFile('./IsoBdtVelo.xml')]
MIT_shared_dir = '/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python/'
infiles     += [LocalFile(MIT_shared_dir+'MITParticleMakers/AllMuMuGms_displaced.py'), LocalFile(MIT_shared_dir+'TTreeTools/NTupleBase.py'), LocalFile(MIT_shared_dir+'TTreeTools/NTupleComponents.py')]
#infiles     += SubmissionTools.getInputList()
#test        = False
test        = True

print "infiles : ", infiles


#maybe switch back to DaVinci v42r2 to avoid DDDBTag issues.
SubmissionTools.submitDV(jname, tag, script, outfiles,
             appName='DaVinci', appPath='/home/weisser/', appVer='v42r3',
             backend=None, infiles=infiles, gaudirun=False, test=test, maxFiles=2)
