import sys
#sys.path.append('/home/thboettc/MIT_shared/AnalysisTools/python')

from Configurables import DaVinci
from PhysSelPython.Wrappers import Selection, SelectionSequence

#===============================
# Setup the particle algorithms
#from MITParticleMakers import AllMuMuGms
import AllMuMuGms
nameLL   = 'convLL'
nameDD   = 'convDD'
nameCalo = 'calo'
nameMuMu = 'dimu'

# Create the selection algorithms
convLLAlg = AllMuMuGms.x2MuMuGmConvAlg(nameLL, 'Long')
convDDAlg = AllMuMuGms.x2MuMuGmConvAlg(nameDD, 'Downstream')
caloAlg   = AllMuMuGms.x2MuMuGmCaloAlg(nameCalo)
dimuAlg   = AllMuMuGms.x2MuMuAlg(nameMuMu)

# Create the selection sequences
convLLSeq = SelectionSequence('RecoLL',   TopSelection=convLLAlg)
convDDSeq = SelectionSequence('RecoDD',   TopSelection=convDDAlg)
caloSeq   = SelectionSequence('RecoCalo', TopSelection=caloAlg)
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
DaVinci().UserAlgorithms = [
    convLLSeq,
    convDDSeq,
    caloSeq,
    dimuSeq
    ]

#================
# Setup Turbo
from Configurables import DstConf, TurboConf
from PhysConf.Filters import LoKi_Filters
hltFilter = LoKi_Filters(HLT2_Code = "HLT_PASS_RE('.*ExoticaPrmptDiMuonTurboDecision.*')")
DstConf().Turbo = True
TurboConf().PersistReco = True

#from GaudiConf import IOHelper
#IOHelper().inputFiles([
#        '~/DSTs/pPbPhotons/MinBiasMC.dst'
#],clear=True)

#===================
# Setup GaudiPython

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
mus   = Tracks('mu',  pvrs, gens, pvrTool, dstTool, mcpTool)
es    = Tracks('e',   pvrs, gens, pvrTool, dstTool, mcpTool)
calos = Calos('calo', pvrs, gens, pvrTool, mcpTool)

# Converted photon component
cnvDaus = [(es, ['e1','e2'])]
cnvs = Combos('cnv', pvrs, cnvDaus, gens,
              pvrTool, dstTool, None, mcpTool)

# eta -> mu mu component
dimuDaus = [(mus, ['mu1', 'mu2'])]
dimus = Combos('dimus', pvrs, dimuDaus, gens,
               pvrTool, dstTool, None, mcpTool)

components = OrderedDict([(evt.prefix,   evt),
                          (gens.prefix,  gens),
                          (pvrs.prefix,  pvrs),
                          (dimus.prefix, dimus),
                          (mus.prefix,   mus),
                          (calos.prefix, calos),
                          (cnvs.prefix,  cnvs),
                          (es.prefix,    es)])

ntuple = NtupleBase('data', components)

#================
# Event Loop
evtnum = 0
gaudi.run(1)
while bool(tes['/Event']):

    #if evtnum > 1000: break

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
