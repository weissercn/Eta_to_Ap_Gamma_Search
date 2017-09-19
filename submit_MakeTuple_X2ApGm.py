import sys
#sys.path.append('/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python')
sys.path.append('.')


#from GangaTools import *
import SubmissionTools


jname       = 'Data.2016.6500.X2ApGm.MagDown'
#jname       = 'Data.2016.6500.X2ApGm.MagUp'
tag         = 'mag_down_hlt_updated'
#tag         = 'mag_up_hlt_updated'
script      = '/mnt/shared/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/MakeNTuple_X2ApGm.py'
outfiles    = ['*.root']
MIT_shared_dir = '/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python/'
infiles     = [LocalFile('./IsoBdt.py'), LocalFile('./IsoBdtLong.xml'), LocalFile('./IsoBdtVelo.xml')]
infiles     += [LocalFile(MIT_shared_dir+'MITParticleMakers/AllMuMuGms_displaced.py'), LocalFile(MIT_shared_dir+'MITParticleMakers/DiElectrons.py'), LocalFile(MIT_shared_dir+'TTreeTools/NtupleBase.py'), LocalFile(MIT_shared_dir+'TTreeTools/NtupleComponents.py')]
#infiles     += SubmissionTools.getInputList()
test        = False
#test        = True

print "infiles : ", infiles


#maybe switch back to DaVinci v42r2 to avoid DDDBTag issues.
SubmissionTools.submitDV(jname, tag, script, outfiles,
             appName='DaVinci', appPath='/home/weisser/', appVer='v42r3',
             backend=None, infiles=infiles, gaudirun=False, test=test, maxFiles=-1)
