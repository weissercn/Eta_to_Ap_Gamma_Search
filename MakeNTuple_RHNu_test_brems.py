# lb-run DaVinci/Latest python MakeNTuple_RHNu.py
import sys
sys.path.append('.')
from GaudiConf import IOHelper
from IsoBdt import IsoBdt
#IOHelper('ROOT').inputFiles(['/data/dst/CL16.MD.Reco16MINIBIAS.0.00.dst'],
#                            clear = True) # CL16
#IOHelper('ROOT').inputFiles(['/data/dst/CL16.MD.Reco16DIMUON.0.00.dst'],
#                            clear=True)   # CL16
#IOHelper('ROOT').inputFiles(['/data/dst/CL16.MD.Turbo03LEPTONS.0.00.dst'],
#                            clear=True)   # Turbo03
#IOHelper('ROOT').inputFiles(['/data/dst/MC16.MD.40114002.0.00.dst'],
#                            clear=True)    # MC16
#IOHelper('ROOT').inputFiles(['/data/dst/MC16.MD.40114017.0.00.dst'],
#                            clear=True)   # MC16
#IOHelper('ROOT').inputFiles(['/data/dst/MC16.MD.40114007.0.00.dst'],
#                            clear=True)   # MC16
#IOHelper('ROOT').inputFiles(['/data/dst/MC16.MD.42122060.0.00.ldst'],
#                            clear=True)   # MC16

#IOHelper('ROOT').inputFiles(['LFN:/data/dst/MC16.MD.40114002.0.00.dst'],
#                            clear=True)    # MC16

# Single Files

#run_ganga = True
run_ganga = False
#Mode = 'mu'
#Mode = 'el'
Mode = 'RHNu'
QuadE = False
#Type = 'Single.DiMu.MC16'
#Type = 'Single.MinBias.MC15'
Type = 'Single.RHNu.CL'


ThisDataType   = '2016'
ThisDDDBtag    = 'dddb-20150724'
ThisCLCondDBtag  = 'cond-20160522'
ThisMCCondDBtag = 'sim-20160820-vc-md100'
ThisDQFLAGStag = 'dq-20150717'

if not run_ganga: from GaudiConf import IOHelper

if Type == 'Single.DiMu.MC16':
    if not run_ganga: IOHelper('ROOT').inputFiles(['DiMu.MC16.ldst'],clear=True)


elif Type == 'Single.MinBias.MC15':
    ThisMCCondDBtag = 'sim-20161124-2015early-vc-md100'
    ThisDDDBtag = 'dddb-20150703'
    ThisDataType = '2015'
    if not run_ganga: IOHelper('ROOT').inputFiles(['MinBias.MC15.dst'], clear=True)

elif 'RHNu.CL' in Type:
    ThisCLCondDBtag = 'cond-20161004'
    ThisDDDBtag = 'dddb-20150724'
    ThisDataType = '2016'
    #if not run_ganga: IOHelper('ROOT').inputFiles(['RHNu.CL.dst'],clear=True)
    #if not run_ganga: IOHelper('ROOT').inputFiles(['00061346_00007293_1.ew.dst'],clear=True)
    #if not run_ganga: IOHelper('ROOT').inputFiles(['00061346_00006242_1.ew.dst'],clear=True)
    if not run_ganga: IOHelper('ROOT').inputFiles(['00059560_00000002_1.ew.dst'],clear=True) # for operation in X2ApGm directory.

# DaVinci configuration.
from Configurables import DaVinci
DaVinci().DataType   = ThisDataType
DaVinci().DDDBtag    = ThisDDDBtag
DaVinci().CondDBtag  = ThisCLCondDBtag
DaVinci().DQFLAGStag = ThisDQFLAGStag
DaVinci().Lumi = True
#DaVinci().Lumi = False
DaVinci().TupleFile = 'lumi.root'
if 'MC' in Type:
    DaVinci().Simulation = True
    DaVinci().Lumi = False
    DaVinci().CondDBtag = ThisMCCondDBtag
if 'Turbo' in Type:
    from Configurables import DstConf, TurboConf
    from PhysConf.Filters import LoKi_Filters
    hlt = LoKi_Filters(HLT2_Code =
                       "HLT_PASS_RE('.*Hlt2Exotica.*TurboDecision.*')")
    DstConf().Turbo = True
    TurboConf().PersistReco = True
    DaVinci().EventPreFilters = hlt.filters('TriggerFilters')






# Tag configuration.
TrkCats = [('ve', 1), ('tt', 2), ('it', 3), ('ot', 4), ('mu', 7)]
#TrgLocs = ['Hlt2ExoticaPrmptDiMuonSSTurbo',
#           'Hlt2ExoticaPrmptDiMuonTurbo',
#           'Hlt2ExoticaDiMuonNoIPTurbo',
#           'Hlt2ExoticaQuadMuonNoIP',
#           'Hlt2ExoticaDisplDiMuon']

TrgLocs = []
#TrgLocs = ['Hlt2ExoticaDisplDiE']

#TrgLocs = ['Hlt2ExoticaPrmptDiMuonSSTurbo',
#           'Hlt2ExoticaPrmptDiMuonTurbo',
#           'Hlt2ExoticaDiMuonNoIPTurbo'
#           ]

# Create the di-electrons
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLooseANNElectrons #"RequiresDet='RICHORCALO' ProbNNe>'0.03'
cmbDiels = CombineParticles(
    'CmbDiels',
    DecayDescriptor = "KS0 -> e+ e-",
    CombinationCut = ("(AMAXDOCA('') < 0.2*mm) & "
                      "(AMAXCHILD('e-' == ABSID, TRCHI2DOF) < 3) &"
                      "(AMINCHILD('e-' == ABSID, P) > 10*GeV) &"
                      "(AMINCHILD('e-' == ABSID, PROBNNe) > 0.5) &"
                      "(AMINCHILD('e-' == ABSID, PT) > 0.5*GeV)"),
    MotherCut = "(HASVERTEX) & (VFASPF(VCHI2PDOF) < 10)")
selDiels = Selection(
    'SelDiels',
    Algorithm = cmbDiels,
    RequiredSelections = [StdAllLooseANNElectrons])
seqDiels = SelectionSequence('SeqDiels', TopSelection = selDiels)
if Mode == 'el': DaVinci().appendToMainSequence([seqDiels])

# Create the same-sign di-electrons.
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLooseANNElectrons #"RequiresDet='RICHORCALO' ProbNNe>'0.03'
cmbSsels = CombineParticles(
    'CmbSsels',
    DecayDescriptor = "[KS0 -> e- e-]cc",
    CombinationCut = ("(AMAXDOCA('') < 0.2*mm) & "
                      "(AMAXCHILD('e-' == ABSID, TRCHI2DOF) < 3) &"
                      "(AMINCHILD('e-' == ABSID, P) > 10*GeV) &"
                      "(AMINCHILD('e-' == ABSID, PROBNNe) > 0.5) &"
                      "(AMINCHILD('e-' == ABSID, PT) > 0.5*GeV)"),
    MotherCut = "(HASVERTEX) & (VFASPF(VCHI2PDOF) < 10)")
selSsels = Selection(
    'SelSsels',
    Algorithm = cmbSsels,
    RequiredSelections = [StdAllLooseANNElectrons])
seqSsels = SelectionSequence('SeqSsels', TopSelection = selSsels)
if Mode == 'el' and 'MC' in Type: DaVinci().appendToMainSequence([seqSsels])

# Create the quad-electrons.
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLooseANNElectrons #"RequiresDet='RICHORCALO' ProbNNe>'0.03'
cmbQdels = CombineParticles(
    'CmbQdels',
    DecayDescriptor = "B0 -> KS0 KS0",
    MotherCut = "(HASVERTEX) & (VFASPF(VCHI2PDOF) < 10)")
selQdels = Selection(
    'SelQdels',
    Algorithm = cmbQdels,
    RequiredSelections = [selDiels])
seqQdels = SelectionSequence('SeqQdels', TopSelection = selQdels)
if Mode == 'el' and QuadE: DaVinci().appendToMainSequence([seqQdels])

##################################################################################

# Create the right handed neutrinos
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLooseMuons, StdAllNoPIDsPions
#from Inputs import Hlt2Muons, Hlt2NoPIDsPions
dc = {}
dc['mu+'] = ("(PT > 500*MeV) "
                 "& (P > 10000*MeV) "
                 "& (BPVIPCHI2() > 16) "
                 "& (TRGHOSTPROB < 0.3) "
                 "& (PROBNNmu > 0.5) ")
dc['pi+'] = ("(PT > 500*MeV) "
                 "& (P > 10000*MeV) "
                 "& (BPVIPCHI2() > 16) "
                 "& (TRGHOSTPROB < 0.3)")
cmbRHNu = CombineParticles(
    'CmbRHNu',
    DecayDescriptor = "[KS0 -> mu+ pi-]cc",
    DaughtersCuts = dc,
    CombinationCut = "(APT > 2*500*MeV) &  (AM > 0) & (ACUTDOCACHI2(10,''))",
    MotherCut = ("(PT > 2*500*MeV)"
              "& (HASVERTEX)"
              "& (VFASPF(VCHI2PDOF) < 10) "
              "& (BPVIPCHI2() < 16)"
              "& (BPVVDCHI2 > 45)"
              "& (BPVLTIME() > 1*picosecond)"))
selRHNu = Selection(
    'SelRHNu',
    Algorithm = cmbRHNu,
    RequiredSelections = [StdAllLooseMuons,StdAllNoPIDsPions])
seqRHNu = SelectionSequence('SeqRHNu', TopSelection = selRHNu)
if Mode == 'RHNu': DaVinci().appendToMainSequence([seqRHNu])

# Create the same sign right handed neutrinos
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLooseMuons, StdAllNoPIDsPions
#from Inputs import Hlt2Muons, Hlt2NoPIDsPions
dc = {}
dc['mu+'] = ("(PT > 500*MeV) "
                 "& (P > 10000*MeV) "
                 "& (BPVIPCHI2() > 16) "
                 "& (TRGHOSTPROB < 0.3) "
                 "& (PROBNNmu > 0.7) ")
dc['pi+'] = ("(PT > 500*MeV) "
                 "& (P > 10000*MeV) "
                 "& (BPVIPCHI2() > 16) "
                 "& (TRGHOSTPROB < 0.3)")
cmbSSRHNu = CombineParticles(
    'CmbSSRHNu',
    DecayDescriptor = "[KS0 -> mu+ pi+]cc",
    DaughtersCuts = dc,
    CombinationCut = "(APT > 2*500*MeV) &  (AM > 0) & (ACUTDOCACHI2(10,''))",
    MotherCut = ("(PT > 2*500*MeV)"
              "& (HASVERTEX)"
              "& (VFASPF(VCHI2PDOF) < 10) "
              "& (BPVIPCHI2() < 16)"
              "& (BPVVDCHI2 > 45)"
              "& (BPVLTIME() > 1*picosecond)"))
selSSRHNu = Selection(
    'SelSSRHNu',
    Algorithm = cmbSSRHNu,
    RequiredSelections = [StdAllLooseMuons,StdAllNoPIDsPions])
seqSSRHNu = SelectionSequence('SeqSSRHNu', TopSelection = selSSRHNu)
if Mode == 'RHNu' and 'MC' in Type: DaVinci().appendToMainSequence([seqSSRHNu])

# Create the DiRHNu.
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLooseANNElectrons #"RequiresDet='RICHORCALO' ProbNNe>'0.03'
cmbDiRHNu = CombineParticles(
    'CmbDiRHNu',
    DecayDescriptor = "B0 -> KS0 KS0",
    MotherCut = "(HASVERTEX)")
selDiRHNu = Selection(
    'SelDiRHNu',
    Algorithm = cmbDiRHNu,
    RequiredSelections = [selRHNu])
seqDiRHNu = SelectionSequence('SeqDiRHNu', TopSelection = selDiRHNu)
if Mode == 'RHNu': DaVinci().appendToMainSequence([seqDiRHNu])

##################################################################################

# Create the di-muons.
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLooseMuons
cmbDimus = CombineParticles(
    'CmbDimus',
    DecayDescriptor = "KS0 -> mu+ mu-",
    CombinationCut = ("(AMAXDOCA('') < 0.2*mm) & "
                      "(AMAXCHILD('mu-' == ABSID, TRCHI2DOF) < 3) &"
                      "(AMINCHILD('mu-' == ABSID, P) > 10*GeV) &"
                      "(AMINCHILD('mu-' == ABSID, PROBNNmu) > 0.5) &"
                      "(AMINCHILD('mu-' == ABSID, PT) > 0.5*GeV)"),
    MotherCut = "(HASVERTEX) & (VFASPF(VCHI2PDOF) < 10)")
selDimus = Selection(
    'SelDimus',
    Algorithm = cmbDimus,
    RequiredSelections = [StdAllLooseMuons])
seqDimus = SelectionSequence('SeqDimus', TopSelection = selDimus)
if Mode == 'mu': DaVinci().appendToMainSequence([seqDimus])

# Create the same-sign di-muons.
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLooseMuons
cmbSsmus = CombineParticles(
    'CmbSsmus',
    DecayDescriptor = "[KS0 -> mu- mu-]cc",
    CombinationCut = ("(AMAXDOCA('') < 0.2*mm) & "
                      "(AMAXCHILD('mu-' == ABSID, TRCHI2DOF) < 3) &"
                      "(AMINCHILD('mu-' == ABSID, P) > 10*GeV) &"
                      "(AMINCHILD('mu-' == ABSID, PROBNNmu) > 0.5) &"
                      "(AMINCHILD('mu-' == ABSID, PT) > 0.5*GeV)"),
    MotherCut = "(HASVERTEX) & (VFASPF(VCHI2PDOF) < 10)")
selSsmus = Selection(
    'SelSsmus',
    Algorithm = cmbSsmus,
    RequiredSelections = [StdAllLooseMuons])
seqSsmus = SelectionSequence('SeqSsmus', TopSelection = selSsmus)
if Mode == 'mu' and 'MC' in Type: DaVinci().appendToMainSequence([seqSsmus])

# Create the quad-muons.
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLooseMuons
cmbQdmus = CombineParticles(
    'CmbQdmus',
    DecayDescriptor = "B0 -> KS0 KS0",
    MotherCut = "(HASVERTEX) & (VFASPF(VCHI2PDOF) < 10)")
selQdmus = Selection(
    'SelQdmus',
    Algorithm = cmbQdmus,
    RequiredSelections = [selDimus])
seqQdmus = SelectionSequence('SeqQdmus', TopSelection = selQdmus)
if Mode == 'mu': DaVinci().appendToMainSequence([seqQdmus])

# Create the Kss.
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLoosePions
cmbKss = CombineParticles(
    'CmbKss',
    DecayDescriptor = "KS0 -> pi+ pi-",
    CombinationCut = ("(ADAMASS('KS0') < 50*MeV)"
                      " & (AMINCHILD(BPVIPCHI2(), ABSID == 'pi+') > 16)"
                      " & (AMINCHILD(PT,          ABSID == 'pi+') > 0.5*GeV)"),
    MotherCut = "(VFASPF(VCHI2PDOF) < 25)")
selKss = Selection(
    'SelKss',
    Algorithm = cmbKss,
    RequiredSelections = [StdAllLoosePions])
seqKss = SelectionSequence('SeqKss', TopSelection = selKss)
if Mode == 'Ks': DaVinci().appendToMainSequence([seqKss])

# Create the di-pions.
from Configurables import CombineParticles
from PhysSelPython.Wrappers import Selection, SelectionSequence
from StandardParticles import StdAllLoosePions
cmbDipss = CombineParticles(
    'CmbDipss',
    DecayDescriptor = "[KS0 -> pi+ pi+]cc",
    CombinationCut = ("(AMINCHILD(PT, ABSID == 'pi+') > 0.5*GeV)"),
    MotherCut = "(VFASPF(VCHI2PDOF) < 25)")
selDipss = Selection(
    'SelDipss',
    Algorithm = cmbDipss,
    RequiredSelections = [StdAllLoosePions])
seqDipss = SelectionSequence('SeqDipss', TopSelection = selDipss)
cmbDipos = CombineParticles(
    'CmbDipos',
    DecayDescriptor = "KS0 -> pi+ pi-",
    CombinationCut = ("(AMINCHILD(PT, ABSID == 'pi+') > 0.5*GeV)"),
    MotherCut = "(VFASPF(VCHI2PDOF) < 25)")
selDipos = Selection(
    'SelDipos',
    Algorithm = cmbDipos,
    RequiredSelections = [StdAllLoosePions])
seqDipos = SelectionSequence('SeqDipos', TopSelection = selDipos)
if Mode == 'pi': DaVinci().appendToMainSequence([seqDipss, seqDipos])

# Create the jets.
from Configurables import HltParticleFlow, HltJetBuilder
pf = HltParticleFlow('pf')
pf.Inputs += [
    ['ProtoParticle',  'best',  'Rec/ProtoP/Charged'],
    ['ProtoParticle',  'gamma', 'Rec/ProtoP/Neutrals']]
if 'Turbo' in Type:
    pf.Inputs += [
        ['Particle', 'daughters', '/Event/Turbo/' +
         loc + '/Particles'] for loc in TrgLocs]
elif Mode == 'mu':
    pf.Inputs += [
        ['Particle', 'daughters', seqDimus.outputLocation()],
        ['Particle', 'daughters', seqQdmus.outputLocation()]]
    if 'MC' in Type:
        pf.Inputs += [['Particle', 'daughters', seqSsmus.outputLocation()]]
elif Mode == 'Ks':
    pf.Inputs += [['Particle', 'daughters', seqKss.outputLocation()]]
elif Mode == 'pi':
    pf.Inputs += [
        ['Particle', 'daughters', seqDipss.outputLocation()],
        ['Particle', 'daughters', seqDipos.outputLocation()]]
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

# GaudiPython configuration.
import GaudiPython, ROOT
from Configurables import ApplicationMgr
gaudi = GaudiPython.AppMgr()
tes   = gaudi.evtsvc()

# Tools.
rndTool = ROOT.TRandom3(0)
genTool = gaudi.toolsvc().create(
    'DaVinciSmartAssociator',
    interface = 'IParticle2MCWeightedAssociator')
rftTool = gaudi.toolsvc().create(
    'PVOfflineTool',
    interface = 'IPVOfflineTool')
pvrTool = gaudi.toolsvc().create(
    'GenericParticle2PVRelator<_p2PVWithIPChi2, '
    'OfflineDistanceCalculatorName>/P2PVWithIPChi2',
    interface = 'IRelatedPVFinder')
#velTool = gaudi.toolsvc().create(
#    'VeloExpectation',
#    interface = 'IVeloExpectation')
velTool = -100

dstTool = gaudi.toolsvc().create(
    'LoKi::TrgDistanceCalculator',
    interface = 'IDistanceCalculator')
#detTool = gaudi.detSvc()['/dd/Structure/LHCb/BeforeMagnetRegion/Velo']
trkTool = gaudi.toolsvc().create(
    'TrackMasterExtrapolator',
    interface = 'ITrackExtrapolator')
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
bremTool = gaudi.toolsvc().create(
    'BremAdder',
    interface = 'IBremAdder')

docaTool = GaudiPython.gbl.LoKi.Particles.DOCA(0, 0, dstTool)

isoTool = IsoBdt(dstTool)

# Simple ntuple class.
class Ntuple:
    def __init__(self, name, tes, genTool, rftTool, pvrTool, velTool, dstTool,
                 detTool, trkTool, l0Tool, hlt1Tool, hlt2Tool, isoTool, bremTool, Type, Mode):
        from collections import OrderedDict
        import ROOT, array
        self.tes      = tes
        self.genTool  = genTool
        self.rftTool  = rftTool
        self.pvrTool  = pvrTool
        self.velTool  = velTool
        self.dstTool  = dstTool
        self.detTool  = detTool
        self.trkTool  = trkTool
        self.l0Tool   = l0Tool
        self.hlt1Tool = hlt1Tool
        self.hlt2Tool = hlt2Tool
        self.isoTool  = isoTool
        self.bremTool= bremTool
        self.saved    = {}
        self.ntuple   = OrderedDict()
        self.tfile_name = 'output.{}.{}.root'.format(Mode,Type)
        self.tfile    = ROOT.TFile(self.tfile_name, 'RECREATE')
        self.ttree    = ROOT.TTree('data', 'data')
        vrsVrt = ['x', 'y', 'z']
        vrsMom = ['px', 'py', 'pz', 'e']
        vrsJet = ['jet_id', 'jet_px', 'jet_py', 'jet_pz']
        if 'MC' in Type: vrsMom = ['idx_gen'] + vrsMom
        vrsPrt = ['iso', 'smooth_iso', 'isDiRHNu'] + vrsJet + ['isMuon', 'pnn_mu', 'pnn_pi',
                  'pnn_k', 'pnn_p', 'pnn_ghost', 'prb_ghost', 'ip', 'ip_chi2',
                  'x0', 'y0', 'z0', 'id0', 'x1', 'y1', 'z1', 'id1']
        vrsTrg = ['l0_tos1', 'l0_tos2', 'l0_tis', 'hlt1_tos4', 'hlt1_tos5', 'hlt1_tis'] + [
            'hlt2_tos%i' % i for i in range(0, len(TrgLocs))] + ['hlt2_tos0'] + ['hlt2_tis']
        self.vrsInit('pvr', vrsVrt)
        self.vrsInit('tag', ['idx_pvr', 'idx_prt0', 'idx_prt1'] +
                     vrsMom + vrsVrt + ['dx', 'dy', 'dz'] + [
                'm', 'dtf_m', 'dtf_dm', 'ip_chi2', 'il', 'iv',
                'dtf_chi2', 'chi2', 've_ns', 'tt_ns', 'it_ns', 'ot_ns',
                'mu_ns'] + vrsTrg)
        self.vrsInit('prt', ['idx_pvr', 'pid'] + vrsMom + vrsPrt)
        if 'MC' in Type:
            vrsMcp = ['pid', 'q', 'px', 'py', 'pz', 'e', 'x', 'y', 'z']
            self.vrsInit('mcpvr', ['x', 'y', 'z'])
            self.vrsInit('mctag', ['idx_pvr', 'idx_prt0', 'idx_prt1',
                                   'pid_mom'] + vrsMcp)
            self.vrsInit('mcprt', ['idx_pvr'] + vrsMcp)
        self.ntuple['pvr_n'] = array.array('d', [-1])
        self.ntuple['run_n'] = array.array('d', [-1])
        self.ntuple['evt_n'] = array.array('d', [-1])
        self.ntuple['evt_tck'] = array.array('d', [-1])
        self.ntuple['evt_spd'] = array.array('d', [-1])
        for key, val in self.ntuple.iteritems():
            if type(val) is array.array: self.ttree.Branch(key, val, key + '/D')
            else: self.ttree.Branch(key, val)
        from LoKiPhys.decorators import CTAU
        self.ctau = CTAU
    def vrsInit(self, pre, vrs):
        import ROOT
        for v in vrs: self.ntuple['%s_%s' % (pre, v)] = ROOT.vector('double')()
    def keyPrt(self, obj):
        key = (obj.momentum().Px(), obj.momentum().Py(), obj.momentum().Pz())
        try:
            trk = obj.proto().track()
            key = (trk.momentum().X(), trk.momentum().Y(), trk.momentum().Z())
        except:
            try:
                pos = obj.proto().calo()[0].position()
                key = (pos.x(), pos.y(), pos.z(), pos.e())
            except: pass
        return key
    def keyTrk(self, obj):
        key = float(1)
        try:
            trk = obj.proto().track()
            for lid in trk.lhcbIDs():
                if lid.isVelo():
                    key *= float(lid.veloID().channelID()/1000000.0)
        except: pass
        return key
    def keyVrt(self, obj):
        return (obj.position().X(), obj.position().Y(), obj.position().Z())
    def close(self):
        self.tfile.Write('data', ROOT.TObject.kOverwrite)
        print 'Closing file ', self.tfile_name, '\n\n\n'
        self.tfile.Close()
    def clear(self):
        import array
        self.saved.clear()
        for key, val in self.ntuple.iteritems():
            if type(val) is array.array: val[0] = -1
            else: val.clear()
    def fill(self, key = None, val = None, idx = None):
        if key == None or val == None: self.tfile.Cd(''); self.ttree.Fill()
        elif key in self.ntuple:
            if idx == None: self.ntuple[key].push_back(val)
            elif idx < len(self.ntuple[key]): self.ntuple[key][idx] = val
    def fillVrt(self, pre, vrt, cov = None, pos = None):
        from math import sqrt
        if cov == None: cov = vrt.covMatrix()
        if pos == None: pos = vrt.position()
        self.fill('%s_x' % pre, pos.X())
        self.fill('%s_y' % pre, pos.Y())
        self.fill('%s_z' % pre, pos.Z())
        self.fill('%s_dx' % pre, sqrt(abs(cov[0][0])))
        self.fill('%s_dy' % pre, sqrt(abs(cov[1][1])))
        self.fill('%s_dz' % pre, sqrt(abs(cov[2][2])))
    def fillMom(self, pre, mom):
        self.fill('%s_px'  % pre, mom.Px())
        self.fill('%s_py'  % pre, mom.Py())
        self.fill('%s_pz'  % pre, mom.Pz())
        self.fill('%s_e'   % pre, mom.E())
        try:
            self.fill('%s_dtf_m'  % pre, mom.m().value())
            self.fill('%s_dtf_dm' % pre, mom.m().error())
        except:
            self.fill('%s_dtf_m'  % pre, -1)
            self.fill('%s_dtf_dm' % pre, -1)
    def fillPrt(self, prt, l_gdtr_prt_for_smooth_iso = []):
        import ROOT
        pid = prt.particleID().pid()
        pro = prt.proto()
        try: prt = prt.data()
        except: pass
        try: pvr = self.pvrTool.relatedPV(prt, 'Rec/Vertex/Primary')
        except: pvr = None
        vrt = prt.endVertex()
        mom = prt.momentum()
        key = self.keyPrt(prt)
        pre = 'tag' if vrt else 'prt'
        if key in self.saved: return (pre, self.saved[key])
        # Daughters.
        if pre == 'tag':
            trks = []
            dtrs = prt.daughters()
            idxs = []
            for dtr in prt.daughters():
                (dtrPre, dtrIdx) = self.fillPrt(dtr, l_gdtr_prt_for_smooth_iso)
                idxs += [dtrIdx]
                if dtr.proto() and dtr.proto().track():
                    trk, mu = dtr.proto().track(), None
                    hits = self.hits(trk)
	            if hits[7] == 0 and dtr.proto().muonPID():
 	                mu = dtr.proto().muonPID().muonTrack()
                    trks += [(trk, mu)]
            for prtIdx, dtr in enumerate(idxs):
                self.fill('%s_idx_prt%i' % (pre, prtIdx), dtr)
        idx = self.ntuple['%s_px' % pre].size()
        self.saved[key] = idx
        if pre == 'tag':
            # Shared hits.
            n = self.share(trks)
            # Vertex.
            from LoKiArrayFunctors.decorators import AMAXDOCA
            if pvr:
                dtf = GaudiPython.gbl.DecayTreeFitter.Fitter(prt, pvr)
                dtf.fit()
                par = dtf.fitParams(prt)
                mom = par.momentum()
                self.fill('%s_dtf_chi2' % pre, dtf.chiSquare())
                self.fillVrt(pre, prt, par.posCovMatrix(), par.position())
                self.fill('%s_ctau' % pre, self.ctau(pvr)(prt))
            else:
                self.fill('%s_dtf_chi2' % pre, -1)
                self.fillVrt(pre, vrt)
            self.fill('%s_chi2' % pre, vrt.chi2())
            self.fill('%s_doca' % pre, AMAXDOCA('')(prt.daughters()))

        # Momentum and mass.
        self.fill('%s_m'  % pre, prt.measuredMass())
        self.fillMom(pre, mom)
        # Trigger.
        self.l0Tool.setOfflineInput(prt)
        self.hlt1Tool.setOfflineInput(prt)
        self.hlt2Tool.setOfflineInput(prt)
        self.l0Tool.setTriggerInput('L0DiMuonDecision')
        trg = l0Tool.tisTosTobTrigger()
        self.fill('%s_l0_tos0' % pre, trg.tos())
        self.l0Tool.setTriggerInput('L0MuonDecision')
        trg = l0Tool.tisTosTobTrigger()
        self.fill('%s_l0_tos1' % pre, trg.tos())
        self.l0Tool.setTriggerInput('L0HadronDecision')
        trg = self.l0Tool.tisTosTobTrigger()
        self.fill('%s_l0_tos2' % pre, trg.tos())
        self.fill('%s_l0_tis' % pre, trg.tis())
        self.hlt1Tool.setTriggerInput('Hlt1DiMuonNoIPDecision')
        trg = self.hlt1Tool.tisTosTobTrigger()
        self.fill('%s_hlt1_tos0' % pre, trg.tos())
        self.hlt1Tool.setTriggerInput('Hlt1MultiDiMuonNoIPDecision')
        trg = self.hlt1Tool.tisTosTobTrigger()
        self.fill('%s_hlt1_tos1' % pre, trg.tos())
        self.hlt1Tool.setTriggerInput('Hlt1DiMuonLowMassDecision')
        trg = self.hlt1Tool.tisTosTobTrigger()
        self.fill('%s_hlt1_tos2' % pre, trg.tos())
        self.hlt1Tool.setTriggerInput('Hlt1DiMuonHighMassDecision')
        trg = self.hlt1Tool.tisTosTobTrigger()
        self.fill('%s_hlt1_tos3' % pre, trg.tos())
        self.hlt1Tool.setTriggerInput('Hlt1TrackMVADecision')
        trg = self.hlt1Tool.tisTosTobTrigger()
        self.fill('%s_hlt1_tos4' % pre, trg.tos())
        self.hlt1Tool.setTriggerInput('Hlt1TwoTrackMVADecision')
        trg = self.hlt1Tool.tisTosTobTrigger()
        self.fill('%s_hlt1_tos5' % pre, trg.tos())
        self.hlt1Tool.setTriggerInput('Hlt1.*TrackMVA.*')
        trg = self.hlt1Tool.tisTosTobTrigger()
        self.fill('%s_hlt1_tis' % pre, trg.tis())
        self.hlt2Tool.setTriggerInput('Hlt2ExoticaRHNuDecision')
        trg = self.hlt2Tool.tisTosTobTrigger()
        self.fill('%s_hlt2_tos0' % pre, trg.tos())
        self.hlt2Tool.setTriggerInput('Hlt2ExoticaRHNuHighMassDecision')
        trg = self.hlt2Tool.tisTosTobTrigger()
        self.fill('%s_hlt2_tos1' % pre, trg.tos())
        self.hlt2Tool.setTriggerInput('Hlt2ExoticaDiRHNuDecision')
        trg = self.hlt2Tool.tisTosTobTrigger()
        self.fill('%s_hlt2_tos2' % pre, trg.tos())
        self.hlt2Tool.setTriggerInput('Hlt2Topo.*')
        trg = self.hlt2Tool.tisTosTobTrigger()
        self.fill('%s_hlt2_tis' % pre, trg.tis())
        for locIdx, loc in enumerate(TrgLocs):
            self.hlt2Tool.setTriggerInput(loc + 'Decision')
            trg = self.hlt2Tool.tisTosTobTrigger()
            self.fill('%s_hlt2_tos%i' % (pre, locIdx), trg.tos())
        # Particle ID.
        self.fill('%s_pid' % pre, pid)

        from LoKiPhys.decorators import ISMUON
        try:
            self.fill('%s_isMuon' % pre, ISMUON(prt))
        except: pass

        if pro:
            #if (prt.info(16, -7) > -1):
            print "prt.info(16, -7) name/hasInfo/info : ", prt.additionalInfoToString(16), prt.hasInfo(16), prt.info(16, -7)
            #if (prt.hasInfo(16)):
            if (True):
                #print "proto info: InAccBrem : ", pro.info(304,-7), "\tCaloBremMatch : ", pro.info(312,-7) , "\tCaloBremChi2 : ", pro.info(335,-7) , "\tBremPIDe : ", pro.info(362,-7)
                #print "bremTool.hasBrem(prt) : ", self.bremTool.hasBrem(prt)
                #print "bremTool.bremMomentum(prt) : ", self.bremTool.bremMomentum(prt, "some_name")
                print "bremTool.hasBrem(prt) : ", self.bremTool.hasBrem(prt)
                print "bremTool.addBrem(prt) : ", self.bremTool.addBrem(prt)
                print "bremTool.hasBrem(prt) : ", self.bremTool.hasBrem(prt)
                print "prt.info(16, -7) name/hasInfo/info : ", prt.additionalInfoToString(16), prt.hasInfo(16), prt.info(16, -7)
                print "bremTool.removeBrem(prt) : ", self.bremTool.removeBrem(prt)
                print "bremTool.hasBrem(prt) : ", self.bremTool.hasBrem(prt)
                print "\n\n\n"




            try:
                self.fill('%s_mu' % pre, pro.muonPID().IsMuon())
                self.fill('%s_loose_mu' % pre, pro.muonPID().IsMuonLoose())
                self.fill('%s_tight_mu' % pre, pro.muonPID().IsMuonTight())
            except:
                self.fill('%s_mu' % pre, -100)
                self.fill('%s_loose_mu' % pre, -100)
                self.fill('%s_tight_mu' % pre, -100)
            self.fill('%s_pnn_mu'    % pre, pro.info(701, -100))
            self.fill('%s_pnn_pi'    % pre, pro.info(702, -100))
            self.fill('%s_pnn_k'     % pre, pro.info(703, -100))
            self.fill('%s_pnn_p'     % pre, pro.info(704, -100))
            self.fill('%s_pnn_ghost' % pre, pro.info(705, -100))
            self.fill('%s_prb_ghost' % pre, pro.track().ghostProbability()
                      if pro.track() else -100)
            # Track.
            trk = pro.track()
            ids = []
            for i in trk.lhcbIDs():
                if i.isVelo():
                    d = self.detTool.sensor(i.veloID())
                    ids += [(d.z(), d, i)]
                ids.sort()
            for hit in range(0, 4):
                if hit >= len(ids):
                    self.fill('%s_x%i'  % (pre, hit), -1)
                    self.fill('%s_y%i'  % (pre, hit), -1)
                    self.fill('%s_z%i'  % (pre, hit), -1)
                    self.fill('%s_id%i' % (pre, hit), -1)
                    self.fill('%s_t%i' % (pre, hit),  -1)
                    self.fill('%s_p%i' % (pre, hit),  -1)
                    continue
                z, d, i = ids[hit]
                s = i.veloID()
                v = GaudiPython.gbl.LHCb.StateVector()
                self.trkTool.propagate(trk, z, v, prt.particleID())
                self.fill('%s_x%i'  % (pre, hit), v.x())
                self.fill('%s_y%i'  % (pre, hit), v.y())
                self.fill('%s_z%i'  % (pre, hit), v.z())
                self.fill('%s_id%i' % (pre, hit), i.lhcbID()*
                          (-1 if s.isPhiType() else 1))
                if (s.isPhiType()):
                    self.fill('%s_t%i' % (pre, hit), d.globalPhi(s.strip(), 0))
                    self.fill('%s_p%i' % (pre, hit), d.phiPitch(s.strip()))
                if (s.isRType()):
                    self.fill('%s_t%i' % (pre, hit), d.globalR(s.strip(), 0))
                    self.fill('%s_p%i' % (pre, hit), d.rPitch(s.strip()))
            # Muon extrapolation.
            z = 15270.0
            v = GaudiPython.gbl.LHCb.StateVector()
            self.trkTool.propagate(trk, z, v, prt.particleID())
            self.fill('%s_xm2' % pre, v.x())
            self.fill('%s_ym2' % pre, v.y())
            self.fill('%s_zm2' % pre, v.z())
        # Linked MC particle.
        if 'MC' in Type:
            gen = None; wgt = 0; rels = self.genTool.relatedMCPs(prt)
            for rel in rels: gen = rel.to() if rel.weight() > wgt else gen
            if gen: (genPre, genIdx) = self.fillMcp(gen)
            else: genIdx = -1
            self.fill('%s_idx_gen' % pre, genIdx)
        # IP.
        ip, ipChi2 = ROOT.Double(-1), ROOT.Double(-1)
        if pvr: self.dstTool.distance(prt, pvr, ip, ipChi2)
        self.fill('%s_ip' % pre, ip)
        self.fill('%s_ip_chi2' % pre, ipChi2)
        fd, fdChi2 = ROOT.Double(-1), ROOT.Double(-1)
        if pvr and vrt: self.dstTool.distance(vrt, pvr, fd, fdChi2)
        self.fill('%s_fd' % pre, fd)
        self.fill('%s_fd_chi2' % pre, fdChi2)
        if False:
            #this seems to crash for some files
            from LoKiPhys.decorators import BPVVDR
            #print '\n'*3, type(pvr), type(prt)
            fd_r = ROOT.Double(-1)
            if pvr and vrt: fd_r = BPVVDR(prt)
            self.fill('%s_fd_r' % pre,fd_r)



        if pre == 'prt':
            #Old Isolation without subtracting momenta of other daughters
            jets = self.tes[jb.Output]
            iso  = None
            vid  = self.keyTrk(prt)
            for jetid, jet in enumerate(jets):
                for dtr in jet.daughters():
                    if self.keyTrk(dtr) == vid: iso = jet; break
                if iso: break
            self.fill('%s_iso' % pre, float(prt.pt()/iso.pt()) if iso else -1)
            self.fill('%s_jet_id' % pre, jetid)
            self.fill('%s_jet_px' % pre, jet.momentum().px())
            self.fill('%s_jet_py' % pre, jet.momentum().py())
            self.fill('%s_jet_pz' % pre, jet.momentum().pz())

        if pre == 'prt':
            #print("Before trying to make smooth_iso")
            if l_gdtr_prt_for_smooth_iso:
                self.fill('%s_isDiRHNu' % pre, 1.)
            else:
                self.fill('%s_isDiRHNu' % pre, 0.)


            if l_gdtr_prt_for_smooth_iso:
                print("\nl_gdtr_prt_for_smooth_iso exists\n")

                #New Smooth Isolation; Get the momenta from the 4 daughters, so they can be subtracted in the smooth iso calculation
                jets = self.tes[jb.Output]
                smooth_iso  = None
                jet_p = None
                vid  = self.keyTrk(prt)
                for jet in jets:
                    for dtr in jet.daughters():
                        if self.keyTrk(dtr) == vid:
                            smooth_iso = jet;
                            jet_p = smooth_iso.momentum()
                            # Now loop over the other granddaughters and subtract momentum if necessary
                            for prt2 in l_gdtr_prt_for_smooth_iso:
                                if prt2 != prt:
                                    vid2  = self.keyTrk(prt2)
                                    for dtr2 in jet.daughters():
                                        if self.keyTrk(dtr2) == vid2:
                                            jet_p -= prt2.momentum()
                            break
                    if smooth_iso: break
                #if smooth_iso: print float(prt.pt()/jet_p.pt())
                #print float(prt.pt()/jet_p.pt())
                self.fill('%s_smooth_iso' % pre, float(prt.pt()/jet_p.pt()) if smooth_iso else -1)
            else: self.fill('%s_smooth_iso' % pre, -1)

        # Isolation IsoBdt
        if pre == 'tag':
            pvrs = self.tes['Rec/Vertex/Primary']
            prts = self.tes['Rec/Track/Best']

            # WARNING !!!! If l_gdtr_prt_for_smooth_iso exists this will return a smooth heavy flavour isolation, otherwise not
            velo_isos = self.isoTool.isolation(prt, pvr, l_gdtr_prt_for_smooth_iso, pvrs, prts, 0)
            long_isos = self.isoTool.isolation(prt, pvr, l_gdtr_prt_for_smooth_iso, pvrs, prts, 1)
            self.fill('%s_iv' % pre, velo_isos[0] + velo_isos[1]) # muon
            self.fill('%s_il' % pre, ROOT.Double(long_isos[0])+ ROOT.Double(long_isos[1])) # muon


        # Primary vertex.
            # weisser added the "if pre == 'tag':" condition to have the same number of pvr_x as tag_x
        if pvr:
            key = self.keyVrt(pvr)
            if not key in self.saved:
                self.saved[key] = self.ntuple['pvr_x'].size()
                self.fillVrt('pvr', pvr)
            self.fill('%s_idx_pvr' % pre, self.saved[key])
        else: self.fill('%s_idx_pvr' % pre, -1)
        return (pre, idx)
    def deltaR(self, p1, p2):
        import ROOT
        v1 = ROOT.TVector3(p1.momentum().X(), p1.momentum().Y(),
                           p1.momentum().Z())
        v2 = ROOT.TVector3(p2.momentum().X(), p2.momentum().Y(),
                           p2.momentum().Z())
        return v1.DeltaR(v2)
    def fillMcp(self, prt):
        import ROOT
        pid = prt.particleID().pid()
        mom = prt.momentum()
        pos = None
        key = self.keyPrt(prt)
        pre = 'mctag' if pid == 36 else 'mcprt'
        if key in self.saved: return (pre, self.saved[key])
        # Daughters.
        if pre == 'mctag':
            idxs = []
            for vrt in prt.endVertices():
                for dtr in vrt.products():
                    if abs(dtr.particleID().pid()) != 13: continue
                    pos = vrt.position()
                    (dtrPre, dtrIdx) = self.fillMcp(dtr)
                    idxs += [dtrIdx]
            for prtIdx, dtr in enumerate(idxs):
                self.fill('%s_idx_prt%i' % (pre, prtIdx), dtr)
        idx = self.ntuple['%s_px' % pre].size()
        self.saved[key] = idx
        # Momentum.
        self.fill('%s_px' % pre, mom.Px())
        self.fill('%s_py' % pre, mom.Py())
        self.fill('%s_pz' % pre, mom.Pz())
        self.fill('%s_e'  % pre, mom.E())
        # PID.
        self.fill('%s_q' % pre, float(prt.particleID().threeCharge()) / 3.0)
        self.fill('%s_pid' % pre, pid)
        try: self.fill('%s_pid_mom' % pre, prt.originVertex().mother().
                       particleID().pid())
        except: self.fill('%s_pid_mom' % pre, 0)
        # Vertex.
        if not pos: pos = prt.originVertex().position()
        self.fill('%s_x' % pre, pos.X())
        self.fill('%s_y' % pre, pos.Y())
        self.fill('%s_z' % pre, pos.Z())
        # Primary vertex.
        pvr = prt.primaryVertex()
        if pvr:
            key = self.keyVrt(pvr)
            if not key in self.saved:
                self.saved[key] = self.ntuple['mcpvr_x'].size()
                self.fill('mcpvr_x', pvr.position().X())
                self.fill('mcpvr_y', pvr.position().Y())
                self.fill('mcpvr_z', pvr.position().Z())
            self.fill('%s_idx_pvr' % pre, self.saved[key])
        else: self.fill('%s_idx_pvr' % pre, -1)
        return (pre, idx)
    def hits(self, trk1, trk2 = None, mu1 = None, mu2 = None, dct = None):
        if dct == None: dct = {n:0 for n in range(0, 13)}
        if not trk1: return dct
        id1s = [id1 for id1 in trk1.lhcbIDs()]
        id2s = [id2 for id2 in trk2.lhcbIDs()] if trk2 else []
        if mu1: id1s += [id1 for id1 in mu1.lhcbIDs()]
        if mu2: id2s += [id2 for id2 in mu2.lhcbIDs()]
        for id1 in id1s:
            cat1 = id1.detectorType()
            chn1 = id1.channelID()
            if not trk2: dct[cat1] += 1; dct[0] += 1
            for id2 in id2s:
                cat2 = id2.detectorType()
                chn2 = id2.channelID()
                if chn1 == chn2:
                    dct[0] += 1
                    if cat1 == cat2: dct[cat1] += 1
        return dct
    def share(self, trks):
        ns = {n:0 for n in range(0, 13)}
        for trk1 in trks:
            for trk2 in trks:
                if trk1[0] == trk2[0]: continue
                hits = self.hits(trk1[0], trk2[0], trk1[1], trk2[1])
                for key, val in hits.iteritems():
                    if val > ns[key]: ns[key] = val
        for cat in TrkCats:
            n = ns[cat[1]]
            self.fill('tag_%s_ns' % (cat[0]), n)
        return ns[TrkCats[0][1]]

# Run.
import sys, ROOT
#try: evtmax = int(sys.argv[1])
#except: evtmax = float('inf')
evtmax = float('inf')
#evtmax = 2000
evtnum = 0
detTool = -100
ntuple = Ntuple('output.root', tes, genTool, rftTool, pvrTool, velTool, dstTool,
                detTool, trkTool, l0Tool, hlt1Tool, hlt2Tool, isoTool, bremTool, Type, Mode)


while evtnum < evtmax:
    gaudi.run(1)
    if not bool(tes['/Event']): break
    #print tes.dump()
    evtnum += 1
    ntuple.clear()

    ntuple.detTool = gaudi.detSvc()['/dd/Structure/LHCb/BeforeMagnetRegion/Velo']

    # Fill event info.
    daq = tes['DAQ/ODIN']
    try:
        ntuple.ntuple['run_n'][0] = daq.runNumber()
        ntuple.ntuple['evt_n'][0] = daq.eventNumber()
        ntuple.ntuple['evt_tck'][0] = daq.triggerConfigurationKey()
    except: continue
    try: ntuple.ntuple['pvr_n'][0] = len(tes['Rec/Vertex/Primary'])
    except: continue
    try: ntuple.ntuple['evt_spd'][0] = GaudiPython.gbl.LoKi.L0.DataValue(
        'Spd(Mult)')(tes['Trig/L0/L0DUReport'])
    except: pass

    # Fill candidates.
    fill = False
    if 'Turbo' in Type:
        for locIdx, loc in enumerate(TrgLocs):
            prts = tes['/Event/Turbo/' + loc + '/Particles']
            try: len(prts); run = True
            except: run = False
            if run:
                for prt in prts:
                    (prtPre, prtIdx) = ntuple.fillPrt(prt); fill = True
                    if prtPre == 'tag': ntuple.fill('%s_hlt2_tos%i' % (
                            prtPre, locIdx), 1, prtIdx)
    elif Mode == 'mu':
        if 'MC' in Type:
            prts = tes[seqSsmus.outputLocation()]
            try: len(prts); run = True
            except: run = False
            if run:
                for prt in prts: ntuple.fillPrt(prt); fill = True
        prts = tes[seqDimus.outputLocation()]
        sigs = []
        try: len(prts); run = True
        except: run = False
        if run:
            for prt in prts:
                sigs += [prt]; ntuple.fillPrt(prt); fill = True
        prts = tes[seqQdmus.outputLocation()]
        try: len(prts); run = True
        except: run = False
        if run:
            for prt in prts:
                for dtr in prt.daughters(): ntuple.fillPrt(dtr); fill = True
        prts = tes[pf.Output]
        try: len(prts); run = len(sigs) > 0
        except: run = False
        if run:
            for prt in prts:
                if abs(prt.charge()) != 1: continue
                try: pvr = pvrTool.relatedPV(prt, 'Rec/Vertex/Primary')
                except: pvr = None
                if not pvr: continue
                ip, ipChi2 = ROOT.Double(-1), ROOT.Double(-1)
                dstTool.distance(prt, pvr, ip, ipChi2)
                if ipChi2 > 9 and prt.momentum().Pt() > 200:
                    minDoca = 100
                    for sig in sigs:
                        for dtr in sig.daughters():
                            doca = docaTool.doca(prt, dtr)
                            if doca < minDoca: minDoca = doca
                    if minDoca < 0.2: ntuple.fillPrt(prt); fill = True
    elif Mode == 'el':
        if 'MC' in Type:
            prts = tes[seqSsels.outputLocation()]
            try: len(prts); run = True
            except: run = False
            if run:
                for prt in prts: ntuple.fillPrt(prt); fill = True
        prts = tes[seqDiels.outputLocation()]
        sigs = []
        try: len(prts); run = True
        except: run = False
        if run:
            for prt in prts:
                sigs += [prt]; ntuple.fillPrt(prt); fill = True
        if QuadE:
            prts = tes[seqQdels.outputLocation()]
            try: len(prts); run = True
            except: run = False
            if run:
                for prt in prts:
                    for dtr in prt.daughters(): ntuple.fillPrt(dtr); fill = True
    elif Mode == 'RHNu':
        if 'MC' in Type:
            prts = tes[seqSSRHNu.outputLocation()]
            try: len(prts); run = True
            except: run = False
            if run:
                for prt in prts: ntuple.fillPrt(prt); fill = True
        if False:
            prts = tes[seqDiRHNu.outputLocation()]
            try: len(prts); run = True
            except: run = False
            if run:
                for prt in prts:
                    print "\nDiRHNu candidate\n"
                    # Get the momenta from the 4 daughters, so they can be subtracted in the smooth iso calculation
                    l_gdtr_prt_for_smooth_iso = []
                    for dtr in prt.daughters():
                        for gdtr in dtr.daughters():
                            #Graddaughters
                            l_gdtr_prt_for_smooth_iso.append(gdtr)

                    for dtr in prt.daughters():
                        print "l_gdtr_prt_for_smooth_iso[0] : ", l_gdtr_prt_for_smooth_iso[0]
                        #print "\nlen(l_gdtr_prt_for_smooth_iso) : ", len(l_gdtr_prt_for_smooth_iso), "\n"
                        ntuple.fillPrt(dtr, l_gdtr_prt_for_smooth_iso);

                        fill = True
        if True:
            prts = tes[seqRHNu.outputLocation()]
            sigs = []
            try: len(prts); run = True
            except: run = False
            if run:
                for prt in prts:
                    sigs += [prt]; ntuple.fillPrt(prt); fill = True

    elif Mode == 'Ks':
        prts = tes[seqKss.outputLocation()]
        try: len(prts); run = True
        except: run = False
        if run:
            for prt in prts: ntuple.fillPrt(prt); fill = True
    elif Mode == 'pi':
        for loc in [seqDipss.outputLocation(), seqDipos.outputLocation()]:
            prts = tes[loc]
            try: len(prts); run = True
            except: run = False
            if run:
                for prt in prts: ntuple.fillPrt(prt); fill = True
    if False and 'MC' in Type:
        prts = tes['Phys/StdAllLooseMuons/Particles']
        try: len(prts); run = True
        except: run = False
        if run:
            for prt in prts: ntuple.fillPrt(prt); fill = True

    if False:
        # Fill MC.
        mcps = tes['MC/Particles']
        try: len(mcps); run = True
        except: run = False
        if run:
            for mcp in mcps:
                pid = mcp.particleID()
                if abs(pid.pid()) in [36, 13] or pid.hasCharm() or pid.hasBottom():
                    ntuple.fillMcp(mcp); fill = True

    if fill: ntuple.fill()

# Close and write the output.
ntuple.close()
