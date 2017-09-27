import sys
#sys.path.append('/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python')
sys.path.append('.')


#from GangaTools import *
import SubmissionTools


jname       = 'Data.2016.6500.X2ApGm.MagDown'
#jname       = 'Data.2016.6500.X2ApGm.MagUp'
tag         = 'mag_down_with_hasBremAdded_materialadded'
#tag         = 'mag_up_restart'
script      = '/mnt/shared/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/MakeNTuple_X2ApGm.py'
outfiles    = ['outfile.root', 'NTuple_X2ApGm_all_files_with_materials_test.root']
MIT_shared_dir = '/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python/'
infiles     = [LocalFile('./IsoBdt.py'), LocalFile('./IsoBdtLong.xml'), LocalFile('./IsoBdtVelo.xml')]
infiles     += [LocalFile(MIT_shared_dir+'MITParticleMakers/AllMuMuGms_displaced.py'), LocalFile(MIT_shared_dir+'MITParticleMakers/DiElectrons.py'), LocalFile(MIT_shared_dir+'TTreeTools/NtupleBase.py'), LocalFile(MIT_shared_dir+'TTreeTools/NtupleComponents.py')]
infiles     += [LocalFile('./Add_material_deploy.cxx'), LocalFile('./Add_material.cxx'), LocalFile('./velo.C'), LocalFile('./velo.h'), LocalFile('./HE16.1_pars.root')]
#infiles     += SubmissionTools.getInputList()
test        = False
#test        = True

print "infiles : ", infiles


#maybe switch back to DaVinci v42r2 to avoid DDDBTag issues.
SubmissionTools.submitDV(jname, tag, script, outfiles,
             appName='DaVinci', appPath='/home/weisser/', appVer='v42r5p1',
             backend=None, infiles=infiles, gaudirun=False, test=test, maxFiles=-1)
# appVer='v42r3'
