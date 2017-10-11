import sys
#sys.path.append('/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python')
sys.path.append('.')


#from GangaTools import *
import SubmissionTools


DISPLACED = False
MAGDOWN  = True
TEST      = False

jname       = 'Data.2016.6500.X2ApGm'
tag         = 'first_prmpt'

if DISPLACED:
    jname  += '_displ'
    script      = '/mnt/shared/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/MakeNTuple_X2ApGm_displaced.py'
    tag += '_displ'
else:
    jname  += '_prmpt'
    script      = '/mnt/shared/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/MakeNTuple_X2ApGm_prompt.py'
    tag += '_prmpt'
if MAGDOWN:
    tag += '_mag_down'
    jname += '.MagDown'
else:
    tag += '_mag_up'
    jname += '.MagUp'
outfiles    = ['NTuple_X2ApGm_all_files_with_materials_test.root']
MIT_shared_dir = '/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python/'
infiles     = [LocalFile('./IsoBdt.py'), LocalFile('./IsoBdtLong.xml'), LocalFile('./IsoBdtVelo.xml')]
infiles     += [LocalFile(MIT_shared_dir+'MITParticleMakers/AllMuMuGms.py'), LocalFile(MIT_shared_dir+'MITParticleMakers/AllMuMuGms_displaced.py'), LocalFile(MIT_shared_dir+'MITParticleMakers/DiElectrons.py'), LocalFile(MIT_shared_dir+'TTreeTools/NtupleBase.py'), LocalFile(MIT_shared_dir+'TTreeTools/NtupleComponents.py')]
infiles     += [LocalFile('./Add_material_deploy.cxx'), LocalFile('./Add_material.cxx'), LocalFile('./velo.C'), LocalFile('./velo.h'), LocalFile('./HE16.1_pars.root')]
#infiles     += SubmissionTools.getInputList()


print "infiles : ", infiles


#maybe switch back to DaVinci v42r2 to avoid DDDBTag issues.
SubmissionTools.submitDV(jname, tag, script, outfiles,
             appName='DaVinci', appPath='/home/weisser/', appVer='v42r5p1',
             backend=None, infiles=infiles, gaudirun=False, test=TEST, maxFiles=-1)
# appVer='v42r3'
