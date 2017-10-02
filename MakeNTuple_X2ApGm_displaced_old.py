import sys
sys.path.append(".")


from Configurables import DaVinci
from PhysSelPython.Wrappers import Selection, SelectionSequence

run_ganga = True
#run_ganga = False

if not run_ganga:
    from GaudiConf import IOHelper
    IOHelper('ROOT').inputFiles(['00059560_00000002_1.ew.dst'],clear=True)
    sys.path.append('/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python/MITParticleMakers')
    sys.path.append('/mnt/shared/LbVMWeisser_shared/MIT_shared/AnalysisTools/python/TTreeTools')

#===============================
# Setup the particle algorithms
#from MITParticleMakers import AllMuMuGms
import AllMuMuGms_displaced as AllMuMuGms
nameLL   = 'convLL'
nameDD   = 'convDD'
nameCalo = 'calo'
nameMergedPi0 = 'mergedpi0'
#nameMuMu = 'dimu'

# Create the selection algorithms
convLLAlg = AllMuMuGms.x2MuMuGmConvAlg(nameLL, 'Long')
convDDAlg = AllMuMuGms.x2MuMuGmConvAlg(nameDD, 'Downstream')
caloAlg   = AllMuMuGms.x2MuMuGmCaloAlg(nameCalo)
mergedpi0Alg   = AllMuMuGms.x2MuMuMergedPi0Alg(nameMergedPi0)
#dimuAlg   = AllMuMuGms.x2MuMuAlg(nameMuMu)
dimuAlg   = AllMuMuGms.x2MuMuAlg()

# Create the selection sequences
convLLSeq = SelectionSequence('RecoLL',   TopSelection=convLLAlg)
convDDSeq = SelectionSequence('RecoDD',   TopSelection=convDDAlg)
caloSeq   = SelectionSequence('RecoCalo', TopSelection=caloAlg)
mergedpi0Seq   = SelectionSequence('RecoMergedPi0', TopSelection=mergedpi0Alg)
dimuSeq   = SelectionSequence('RecoMuMu', TopSelection=dimuAlg)

#===============
# Setup DaVinci
DaVinci().EvtMax = -1
DaVinci().PrintFreq = 1000
DaVinci().Simulation = False
#if jobType.startswith('MC'): DaVinci().Simulation = True
#elif jobType.startswith('Data'): DaVinci().Simulation = False
DaVinci().Lumi = False
DaVinci().DataType = '2016'
DaVinci().CondDBtag = 'cond-20161004'
DaVinci().DDDBtag = 'dddb-20150724'

DaVinci().UserAlgorithms = [
    convLLSeq,
    convDDSeq,
    caloSeq,
    mergedpi0Seq,
    dimuSeq
    ]

#================
# Setup Turbo
#from Configurables import DstConf
#from Configurables import TurboConf
from PhysConf.Filters import LoKi_Filters
hltFilter = LoKi_Filters(HLT2_Code = "HLT_PASS_RE('.*ExoticaDisplDiMuonDecision.*')")
#DstConf().Turbo = True
#DstConf().Turbo = False
#TurboConf().PersistReco = True

#from GaudiConf import IOHelper
#IOHelper().inputFiles([
#        '~/DSTs/pPbPhotons/MinBiasMC.dst'
#],clear=True)

#===================
# Setup GaudiPython



if False:
    from Configurables import HltParticleFlow, HltJetBuilder
    pf = HltParticleFlow('pf')
    pf.Inputs += [
        ['ProtoParticle',  'best',  'Rec/ProtoP/Charged'],
        ['ProtoParticle',  'gamma', 'Rec/ProtoP/Neutrals']]

    pf.Inputs += [
            ['Particle', 'daughters', convLLSeq.outputLocation()],
            ['Particle', 'daughters', convDDSeq.outputLocation()],
            ['Particle', 'daughters', caloSeq.outputLocation()],
            ['Particle', 'daughters', mergedpi0Seq.outputLocation()],
            ['Particle', 'daughters', dimuSeq.outputLocation()]]



    pf.Output = 'Phys/PF/Particles'
    pf.ProBestNames = ['mu+', 'e+', 'p+', 'K+', 'pi+']
    pf.ProBestKeys  = [701,   700,  704,  703,  702]
    pf.ProBestMins  = [0.5,   0.5,  0.5,  0.5,  0.5]
    pf.EcalBest = True
    pf.SprRecover = False
    pf.TrkLnErrMax = 10
    pf.TrkUpErrMax = 10
    pf.TrkDnErrMax = 10
    jb = HltJetBuilder('jb')
    jb.JetEcPath = ''
    jb.Inputs = [pf.Output]
    jb.Output = 'Phys/JB/Particles'
    jb.JetPtMin = 0
    DaVinci().appendToMainSequence([pf, jb])

# TisTos configuration.
from Configurables import ToolSvc, TriggerTisTos
for stage in ('Hlt1', 'Hlt2', 'Strip/Phys'):
    ToolSvc().addTool(TriggerTisTos, stage + "TriggerTisTos")
    tool = getattr(ToolSvc(), stage + "TriggerTisTos")
    tool.HltDecReportsLocation = '/Event/' + stage + '/DecReports'
    tool.HltSelReportsLocation = '/Event/' + stage + '/SelReports'

# Create gaudi and tes
import GaudiPython
gaudi = GaudiPython.AppMgr()
tes   = gaudi.evtsvc()

# Create some tools
mcpTool = gaudi.toolsvc().create(
    'DaVinciSmartAssociator',
    interface = 'IParticle2MCWeightedAssociator'
    ) if DaVinci().Simulation else None
recTool = gaudi.toolsvc().create(
    'MCReconstructible',
    interface = 'IMCReconstructible'
    ) if DaVinci().Simulation else None
dstTool = gaudi.toolsvc().create(
    'LoKi::TrgDistanceCalculator',
    interface = 'IDistanceCalculator')
pvrTool = gaudi.toolsvc().create(
    'GenericParticle2PVRelator<_p2PVWithIPChi2, '
    'OfflineDistanceCalculatorName>/P2PVWithIPChi2',
    interface = 'IRelatedPVFinder')

l0Tool = gaudi.toolsvc().create(
    'L0TriggerTisTos',
    interface = 'ITriggerTisTos')
hlt1Tool = gaudi.toolsvc().create(
    'TriggerTisTos/Hlt1TriggerTisTos',
    interface = 'ITriggerTisTos')
hlt2Tool = gaudi.toolsvc().create(
    'TriggerTisTos/Hlt2TriggerTisTos',
    interface = 'ITriggerTisTos')
physTool = gaudi.toolsvc().create(
    'TriggerTisTos/Strip/PhysTriggerTisTos',
    interface = 'ITriggerTisTos')
trkTool = gaudi.toolsvc().create(
    'TrackMasterExtrapolator',
    interface = 'ITrackExtrapolator') # For x0, x1, ...
#detTool = gaudi.detSvc()['/dd/Structure/LHCb/BeforeMagnetRegion/Velo'] # This might crash
bremTool = gaudi.toolsvc().create(
    'BremAdder',
    interface = 'IBremAdder')


from IsoBdt import IsoBdt
isoTool = IsoBdt(dstTool)

#=================
# Setup the ttree
#from TTreeTools.NtupleComponents import *
#from TTreeTools.NtupleBase import *

from NtupleComponents import *
from NtupleBase import *
from collections import OrderedDict

# Create basic ntuple components
evt   = Event('evt')
pvrs  = PrimaryVertices('pvr')
gens  = Gens('gens',recTool)
#mus   = Tracks('prt',  pvrs, gens, pvrTool, dstTool, mcpTool, tes, trkTool, jb) #enable this to get info about iso
mus   = Tracks('prt',  pvrs, gens, pvrTool, dstTool, mcpTool, tes, l0Tool, hlt1Tool, hlt2Tool, trkTool) #mu
es    = Tracks('e',   pvrs, gens, pvrTool, dstTool, mcpTool)
calos = Calos('calo', pvrs, gens, pvrTool, mcpTool)
mergedpi0s = Calos('mergedpi0', pvrs, gens, pvrTool, mcpTool)

# Converted photon component
cnvDaus = [(es, ['e1','e2'])]
cnvs = Combos('cnv', pvrs, cnvDaus, gens,
              pvrTool, dstTool, None, mcpTool)

# eta -> mu mu component
dimuDaus = [(mus, ['prt0', 'prt1'])]
dtf_pid_list = [13,-13]
dimus = Combos('tag', pvrs, dimuDaus, gens,
               pvrTool, dstTool, dtf_pid_list, mcpTool, False, tes, l0Tool, hlt1Tool, hlt2Tool, physTool, isoTool, bremTool) #dimus

components = OrderedDict([(evt.prefix,   evt),
                          (gens.prefix,  gens),
                          (pvrs.prefix,  pvrs),
                          (dimus.prefix, dimus),
                          (mus.prefix,   mus),
                          (calos.prefix, calos),
                          (mergedpi0s.prefix, mergedpi0s),
                          (cnvs.prefix,  cnvs),
                          (es.prefix,    es)])

ntuple = NtupleBase('data', components)

#================
# Event Loop
evtnum = 0
gaudi.run(1)
while bool(tes['/Event']):

    #if evtnum > 2000: break

    detTool = gaudi.detSvc()['/dd/Structure/LHCb/BeforeMagnetRegion/Velo'] # This has to be added in the event loop (ask phil why)
    ntuple.Tracks_set_detTool('prt', detTool)

    # Fill event information
    evtFill = False

    # Fill X -> mu mu
    prts = tes[dimuAlg.outputLocation()]
    if prts:
        #print 'Filling dimus...'
        for prt in prts:
            if not evtFill: ntuple(evt.prefix, tes)
            evtFill = True
            if abs(prt.particleID().pid()) == 310:
                ntuple(dimus.prefix, prt)

    # Fill X -> mu mu gamma (calo)
    prts = tes[caloAlg.outputLocation()]
    if prts:
        #print 'Filling mu mu gm calo...'
        for prt in prts:
            if not evtFill: ntuple(evt.prefix, tes)
            evtFill = True
            for dau in prt.daughters():
                if dau.particleID().pid() == 22:
                    ntuple(calos.prefix, dau)
                elif abs(dau.particleID().pid()) == 310:
                    ntuple(dimus.prefix, dau)

    # Fill X -> mu mu gamma(-> ee)
    prts = tes[convLLAlg.outputLocation()]
    if prts:
        #print 'Filling mu mu gm LL...'
        for prt in prts:
            if not evtFill: ntuple(evt.prefix, tes)
            evtFill = True
            for dau in prt.daughters():
                if dau.particleID().pid() == 22:
                    ntuple(cnvs.prefix, dau)
                elif abs(dau.particleID().pid()) == 310:
                    ntuple(dimus.prefix, dau)

    prts = tes[convDDAlg.outputLocation()]
    if prts:
        #print 'Filling mu mu gm DD...'
        for prt in prts:
            if not evtFill: ntuple(evt.prefix, tes)
            evtFill = True
            for dau in prt.daughters():
                if dau.particleID().pid() == 22:
                    ntuple(cnvs.prefix, dau)
                elif abs(dau.particleID().pid()) == 310:
                    ntuple(dimus.prefix, dau)

    # Fill X -> mu mu mergedpi0
    prts = tes[mergedpi0Alg.outputLocation()]
    if prts:
        #print 'Filling mu mu gm calo...'
        for prt in prts:
            if not evtFill: ntuple(evt.prefix, tes)
            evtFill = True
            for dau in prt.daughters():
                if dau.particleID().pid() == 111:
                    ntuple(mergedpi0s.prefix, dau)
                elif abs(dau.particleID().pid()) == 310:
                    ntuple(dimus.prefix, dau)


    if False:
        # Fill mcp info
        if mcpTool:
            mcps = tes['/Event/MC/Particles']
            if mcps:
                for mcp in mcps:
                    if((abs(mcp.particleID().pid()) == 13) or
                       (abs(mcp.particleID().pid()) == 221)):
                        if not evtFill:
                            ntuple(evt.prefix, tes)
                            evtFill = True
                        ntuple(gens.prefix, mcp)

    # Fill, clear, and increment the loop
    #if evtFill:
    ntuple.fillTree()
    ntuple.clear()
    evtnum += 1
    gaudi.run(1)

# Close the ttree and file
ntuple.close()

print 2*"\n", 200*"-", "\nNow adding material\n", 200*"-", 2*"\n"

import os, subprocess
#os.system("export DISPLAY=localhost:0.0")


#addmat_out = os.system('root -l -b -q "Add_material_deploy.cxx(\\"Test\\")" |& tee add_material_docu.txt')
#addmat_out = os.popen('root -l -b -q "Add_material_deploy.cxx(\\"Test\\")"').read()
addmat_out = subprocess.Popen('root -l -b -q "Add_material_deploy.cxx(\\"Test\\")"', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
print "stdout : \n", addmat_out.stdout.read()
print "stderr : \n", addmat_out.stderr.read()
#addmat_out = subprocess.call('root -l -b -q "Add_material_deploy.cxx(\\"Test\\")"', shell=True)
#print addmat_out

print "File NTuple_X2ApGm_all_files_with_materials_test.root has been written : ", os.path.isfile('NTuple_X2ApGm_all_files_with_materials_test.root')


print 2*"\n", 200*"-", "\nNow finishing\n", 200*"-", 2*"\n"
