//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Feb  5 10:39:55 2018 by ROOT version 6.08/06
// from TTree data/data
// found on file: NTuple_X2ApGm_all_files_noip_44_part.root
//////////////////////////////////////////////////////////

#ifndef DalitzToyMaker_h
#define DalitzToyMaker_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <TH2F.h>
#include "Pythia8/Basics.h"
#include "Pythia8/Pythia.h"

// Headers needed by this particular selector
#include <vector>


class DalitzToyMaker : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Generator
   Pythia8::Pythia pyg;

   // Efficiency hists
   TFile* pnn_eff_file;
   TFile* trig_eff_file;
   TH2F* pnn_eff_hist;
   TH2F* trig_eff_hist;

   // Output file and ttree
   TFile* outfile;
   TTree* outtree;

   // Output tree branches
   double pv_x;
   double pv_y;
   double pv_z;

   double mom_pt;
   double mom_px;
   double mom_py;
   double mom_pz;
   double mom_e;
   double mom_eta;
   double mom_phi;
   double mom_m;
   double mom_pnn_wgt;
   double mom_tistos_wgt;

   double dimu_pt;
   double dimu_px;
   double dimu_py;
   double dimu_pz;
   double dimu_e;
   double dimu_eta;
   double dimu_phi;
   double dimu_m;

   double mu1_pt;
   double mu1_px;
   double mu1_py;
   double mu1_pz;
   double mu1_e;
   double mu1_eta;
   double mu1_phi;

   double mu2_pt;
   double mu2_px;
   double mu2_py;
   double mu2_pz;
   double mu2_e;
   double mu2_eta;
   double mu2_phi;

   double gm_pt;
   double gm_px;
   double gm_py;
   double gm_pz;
   double gm_e;
   double gm_eta;
   double gm_phi;
   double gm_end_x;
   double gm_end_y;
   double gm_end_z;
   double gm_in_ecal;

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderArray<double> evt_event = {fReader, "evt_event"};
   TTreeReaderArray<double> evt_run = {fReader, "evt_run"};
   TTreeReaderArray<double> evt_ntracks = {fReader, "evt_ntracks"};
   TTreeReaderArray<double> evt_nspd = {fReader, "evt_nspd"};
   TTreeReaderArray<double> pvr_idx = {fReader, "pvr_idx"};
   TTreeReaderArray<double> pvr_x = {fReader, "pvr_x"};
   TTreeReaderArray<double> pvr_y = {fReader, "pvr_y"};
   TTreeReaderArray<double> pvr_z = {fReader, "pvr_z"};
   TTreeReaderArray<double> tag_idx = {fReader, "tag_idx"};
   TTreeReaderArray<double> tag_idx_pvr = {fReader, "tag_idx_pvr"};
   TTreeReaderArray<double> tag_idx_prt0 = {fReader, "tag_idx_prt0"};
   TTreeReaderArray<double> tag_idx_prt1 = {fReader, "tag_idx_prt1"};
   TTreeReaderArray<double> tag_il = {fReader, "tag_il"};
   TTreeReaderArray<double> tag_iv = {fReader, "tag_iv"};
   TTreeReaderArray<double> tag_l0_tos1 = {fReader, "tag_l0_tos1"};
   TTreeReaderArray<double> tag_l0_tos2 = {fReader, "tag_l0_tos2"};
   TTreeReaderArray<double> tag_l0_tos3 = {fReader, "tag_l0_tos3"};
   TTreeReaderArray<double> tag_l0_tis = {fReader, "tag_l0_tis"};
   TTreeReaderArray<double> tag_hlt1_tos3 = {fReader, "tag_hlt1_tos3"};
   TTreeReaderArray<double> tag_hlt1_tos4 = {fReader, "tag_hlt1_tos4"};
   TTreeReaderArray<double> tag_hlt1_tis4 = {fReader, "tag_hlt1_tis4"};
   TTreeReaderArray<double> tag_hlt1_tos5 = {fReader, "tag_hlt1_tos5"};
   TTreeReaderArray<double> tag_hlt1_tis = {fReader, "tag_hlt1_tis"};
   TTreeReaderArray<double> tag_hlt2_tos0 = {fReader, "tag_hlt2_tos0"};
   TTreeReaderArray<double> tag_hlt2_tos1 = {fReader, "tag_hlt2_tos1"};
   TTreeReaderArray<double> tag_hlt2_tos2 = {fReader, "tag_hlt2_tos2"};
   TTreeReaderArray<double> tag_nu_brem_0 = {fReader, "tag_nu_brem_0"};
   TTreeReaderArray<double> tag_nu_brem_1 = {fReader, "tag_nu_brem_1"};
   TTreeReaderArray<double> tag_pid = {fReader, "tag_pid"};
   TTreeReaderArray<double> tag_px = {fReader, "tag_px"};
   TTreeReaderArray<double> tag_py = {fReader, "tag_py"};
   TTreeReaderArray<double> tag_pz = {fReader, "tag_pz"};
   TTreeReaderArray<double> tag_pt = {fReader, "tag_pt"};
   TTreeReaderArray<double> tag_e = {fReader, "tag_e"};
   TTreeReaderArray<double> tag_eta = {fReader, "tag_eta"};
   TTreeReaderArray<double> tag_phi = {fReader, "tag_phi"};
   TTreeReaderArray<double> tag_m = {fReader, "tag_m"};
   TTreeReaderArray<double> tag_dls = {fReader, "tag_dls"};
   TTreeReaderArray<double> tag_ctau = {fReader, "tag_ctau"};
   TTreeReaderArray<double> tag_chi2 = {fReader, "tag_chi2"};
   TTreeReaderArray<double> tag_ndof = {fReader, "tag_ndof"};
   TTreeReaderArray<double> tag_dira = {fReader, "tag_dira"};
   TTreeReaderArray<double> tag_vrt_x = {fReader, "tag_vrt_x"};
   TTreeReaderArray<double> tag_vrt_y = {fReader, "tag_vrt_y"};
   TTreeReaderArray<double> tag_vrt_z = {fReader, "tag_vrt_z"};
   TTreeReaderArray<double> tag_ve_ns = {fReader, "tag_ve_ns"};
   TTreeReaderArray<double> tag_x = {fReader, "tag_x"};
   TTreeReaderArray<double> tag_y = {fReader, "tag_y"};
   TTreeReaderArray<double> tag_z = {fReader, "tag_z"};
   TTreeReaderArray<double> tag_dx = {fReader, "tag_dx"};
   TTreeReaderArray<double> tag_dy = {fReader, "tag_dy"};
   TTreeReaderArray<double> tag_dz = {fReader, "tag_dz"};
   TTreeReaderArray<double> tag_dtf_px = {fReader, "tag_dtf_px"};
   TTreeReaderArray<double> tag_dtf_py = {fReader, "tag_dtf_py"};
   TTreeReaderArray<double> tag_dtf_pz = {fReader, "tag_dtf_pz"};
   TTreeReaderArray<double> tag_dtf_pt = {fReader, "tag_dtf_pt"};
   TTreeReaderArray<double> tag_dtf_e = {fReader, "tag_dtf_e"};
   TTreeReaderArray<double> tag_dtf_m = {fReader, "tag_dtf_m"};
   TTreeReaderArray<double> tag_dtf_ctau = {fReader, "tag_dtf_ctau"};
   TTreeReaderArray<double> tag_dtf_chi2 = {fReader, "tag_dtf_chi2"};
   TTreeReaderArray<double> tag_dtf_ndof = {fReader, "tag_dtf_ndof"};
   TTreeReaderArray<double> tag_l0_tos = {fReader, "tag_l0_tos"};
   TTreeReaderArray<double> prt_idx = {fReader, "prt_idx"};
   TTreeReaderArray<double> prt_idx_pvr = {fReader, "prt_idx_pvr"};
   TTreeReaderArray<double> prt_pid = {fReader, "prt_pid"};
   TTreeReaderArray<double> prt_pt = {fReader, "prt_pt"};
   TTreeReaderArray<double> prt_px = {fReader, "prt_px"};
   TTreeReaderArray<double> prt_py = {fReader, "prt_py"};
   TTreeReaderArray<double> prt_pz = {fReader, "prt_pz"};
   TTreeReaderArray<double> prt_e = {fReader, "prt_e"};
   TTreeReaderArray<double> prt_eta = {fReader, "prt_eta"};
   TTreeReaderArray<double> prt_phi = {fReader, "prt_phi"};
   TTreeReaderArray<double> prt_m = {fReader, "prt_m"};
   TTreeReaderArray<double> prt_pid_e = {fReader, "prt_pid_e"};
   TTreeReaderArray<double> prt_pid_mu = {fReader, "prt_pid_mu"};
   TTreeReaderArray<double> prt_pid_k = {fReader, "prt_pid_k"};
   TTreeReaderArray<double> prt_pid_p = {fReader, "prt_pid_p"};
   TTreeReaderArray<double> prt_pnn_e = {fReader, "prt_pnn_e"};
   TTreeReaderArray<double> prt_pnn_mu = {fReader, "prt_pnn_mu"};
   TTreeReaderArray<double> prt_pnn_pi = {fReader, "prt_pnn_pi"};
   TTreeReaderArray<double> prt_pnn_k = {fReader, "prt_pnn_k"};
   TTreeReaderArray<double> prt_pnn_p = {fReader, "prt_pnn_p"};
   TTreeReaderArray<double> prt_pnn_ghost = {fReader, "prt_pnn_ghost"};
   TTreeReaderArray<double> prt_charge = {fReader, "prt_charge"};
   TTreeReaderArray<double> prt_type = {fReader, "prt_type"};
   TTreeReaderArray<double> prt_x = {fReader, "prt_x"};
   TTreeReaderArray<double> prt_y = {fReader, "prt_y"};
   TTreeReaderArray<double> prt_z = {fReader, "prt_z"};
   TTreeReaderArray<double> prt_chi2 = {fReader, "prt_chi2"};
   TTreeReaderArray<double> prt_ndof = {fReader, "prt_ndof"};
   TTreeReaderArray<double> prt_prob_chi2 = {fReader, "prt_prob_chi2"};
   TTreeReaderArray<double> prt_clone_dist = {fReader, "prt_clone_dist"};
   TTreeReaderArray<double> prt_ip = {fReader, "prt_ip"};
   TTreeReaderArray<double> prt_ip_chi2 = {fReader, "prt_ip_chi2"};
   TTreeReaderArray<double> prt_x0 = {fReader, "prt_x0"};
   TTreeReaderArray<double> prt_x1 = {fReader, "prt_x1"};
   TTreeReaderArray<double> prt_y0 = {fReader, "prt_y0"};
   TTreeReaderArray<double> prt_y1 = {fReader, "prt_y1"};
   TTreeReaderArray<double> prt_z0 = {fReader, "prt_z0"};
   TTreeReaderArray<double> prt_z1 = {fReader, "prt_z1"};
   TTreeReaderArray<double> prt_id0 = {fReader, "prt_id0"};
   TTreeReaderArray<double> prt_id1 = {fReader, "prt_id1"};
   TTreeReaderArray<double> prt_ecal_face_x = {fReader, "prt_ecal_face_x"};
   TTreeReaderArray<double> prt_ecal_face_y = {fReader, "prt_ecal_face_y"};
   TTreeReaderArray<double> prt_ecal_12620_dx = {fReader, "prt_ecal_12620_dx"};
   TTreeReaderArray<double> prt_ecal_12620_dy = {fReader, "prt_ecal_12620_dy"};
   TTreeReaderArray<double> prt_ecal_12720_dx = {fReader, "prt_ecal_12720_dx"};
   TTreeReaderArray<double> prt_ecal_12720_dy = {fReader, "prt_ecal_12720_dy"};
   TTreeReaderArray<double> prt_iso = {fReader, "prt_iso"};
   TTreeReaderArray<double> prt_l0_tos1 = {fReader, "prt_l0_tos1"};
   TTreeReaderArray<double> prt_l0_tos2 = {fReader, "prt_l0_tos2"};
   TTreeReaderArray<double> prt_l0_tos3 = {fReader, "prt_l0_tos3"};
   TTreeReaderArray<double> prt_l0_tis = {fReader, "prt_l0_tis"};
   TTreeReaderArray<double> prt_hlt1_tos3 = {fReader, "prt_hlt1_tos3"};
   TTreeReaderArray<double> prt_hlt1_tos4 = {fReader, "prt_hlt1_tos4"};
   TTreeReaderArray<double> prt_hly_tis4 = {fReader, "prt_hly_tis4"};
   TTreeReaderArray<double> prt_hlt1_tos5 = {fReader, "prt_hlt1_tos5"};
   TTreeReaderArray<double> prt_hlt1_tis = {fReader, "prt_hlt1_tis"};
   TTreeReaderArray<double> prt_hlt2_tos0 = {fReader, "prt_hlt2_tos0"};
   TTreeReaderArray<double> prt_hlt2_tos1 = {fReader, "prt_hlt2_tos1"};
   TTreeReaderArray<double> calo_idx = {fReader, "calo_idx"};
   TTreeReaderArray<double> calo_idx_pvr = {fReader, "calo_idx_pvr"};
   TTreeReaderArray<double> calo_pid = {fReader, "calo_pid"};
   TTreeReaderArray<double> calo_px = {fReader, "calo_px"};
   TTreeReaderArray<double> calo_py = {fReader, "calo_py"};
   TTreeReaderArray<double> calo_pz = {fReader, "calo_pz"};
   TTreeReaderArray<double> calo_pt = {fReader, "calo_pt"};
   TTreeReaderArray<double> calo_e = {fReader, "calo_e"};
   TTreeReaderArray<double> calo_eta = {fReader, "calo_eta"};
   TTreeReaderArray<double> calo_phi = {fReader, "calo_phi"};
   TTreeReaderArray<double> calo_m = {fReader, "calo_m"};
   TTreeReaderArray<double> calo_cl = {fReader, "calo_cl"};
   TTreeReaderArray<double> calo_deposit_id = {fReader, "calo_deposit_id"};
   TTreeReaderArray<double> calo_e19 = {fReader, "calo_e19"};
   TTreeReaderArray<double> calo_e49 = {fReader, "calo_e49"};
   TTreeReaderArray<double> calo_ecal = {fReader, "calo_ecal"};
   TTreeReaderArray<double> calo_prs_m = {fReader, "calo_prs_m"};
   TTreeReaderArray<double> calo_prs = {fReader, "calo_prs"};
   TTreeReaderArray<double> calo_spd = {fReader, "calo_spd"};
   TTreeReaderArray<double> calo_prs_e19 = {fReader, "calo_prs_e19"};
   TTreeReaderArray<double> calo_prs_e49 = {fReader, "calo_prs_e49"};
   TTreeReaderArray<double> calo_prs_e4_max = {fReader, "calo_prs_e4_max"};
   TTreeReaderArray<double> calo_tr_match = {fReader, "calo_tr_match"};
   TTreeReaderArray<double> calo_is_not_e = {fReader, "calo_is_not_e"};
   TTreeReaderArray<double> calo_is_not_h = {fReader, "calo_is_not_h"};
   TTreeReaderArray<double> calo_photon_id = {fReader, "calo_photon_id"};
   TTreeReaderArray<double> calo_shower_shape = {fReader, "calo_shower_shape"};
   TTreeReaderArray<double> calo_hcal_ecal = {fReader, "calo_hcal_ecal"};
   TTreeReaderArray<double> calo_n_photon_hypos = {fReader, "calo_n_photon_hypos"};
   TTreeReaderArray<double> calo_x = {fReader, "calo_x"};
   TTreeReaderArray<double> calo_y = {fReader, "calo_y"};
   TTreeReaderArray<double> calo_calohypo_z = {fReader, "calo_calohypo_z"};
   TTreeReaderArray<double> calo_spread_0 = {fReader, "calo_spread_0"};
   TTreeReaderArray<double> calo_spread_1 = {fReader, "calo_spread_1"};
   TTreeReaderArray<double> calo_spread_2 = {fReader, "calo_spread_2"};
   TTreeReaderArray<double> calo_spread_3 = {fReader, "calo_spread_3"};
   TTreeReaderArray<double> cnv_idx = {fReader, "cnv_idx"};
   TTreeReaderArray<double> cnv_idx_pvr = {fReader, "cnv_idx_pvr"};
   TTreeReaderArray<double> cnv_idx_e1 = {fReader, "cnv_idx_e1"};
   TTreeReaderArray<double> cnv_idx_e2 = {fReader, "cnv_idx_e2"};
   TTreeReaderArray<double> cnv_pid = {fReader, "cnv_pid"};
   TTreeReaderArray<double> cnv_px = {fReader, "cnv_px"};
   TTreeReaderArray<double> cnv_py = {fReader, "cnv_py"};
   TTreeReaderArray<double> cnv_pz = {fReader, "cnv_pz"};
   TTreeReaderArray<double> cnv_pt = {fReader, "cnv_pt"};
   TTreeReaderArray<double> cnv_e = {fReader, "cnv_e"};
   TTreeReaderArray<double> cnv_eta = {fReader, "cnv_eta"};
   TTreeReaderArray<double> cnv_phi = {fReader, "cnv_phi"};
   TTreeReaderArray<double> cnv_m = {fReader, "cnv_m"};
   TTreeReaderArray<double> cnv_dls = {fReader, "cnv_dls"};
   TTreeReaderArray<double> cnv_ctau = {fReader, "cnv_ctau"};
   TTreeReaderArray<double> cnv_chi2 = {fReader, "cnv_chi2"};
   TTreeReaderArray<double> cnv_ndof = {fReader, "cnv_ndof"};
   TTreeReaderArray<double> cnv_dira = {fReader, "cnv_dira"};
   TTreeReaderArray<double> cnv_vrt_x = {fReader, "cnv_vrt_x"};
   TTreeReaderArray<double> cnv_vrt_y = {fReader, "cnv_vrt_y"};
   TTreeReaderArray<double> cnv_vrt_z = {fReader, "cnv_vrt_z"};
   TTreeReaderArray<double> cnv_ve_ns = {fReader, "cnv_ve_ns"};
   TTreeReaderArray<double> cnv_x = {fReader, "cnv_x"};
   TTreeReaderArray<double> cnv_y = {fReader, "cnv_y"};
   TTreeReaderArray<double> cnv_z = {fReader, "cnv_z"};
   TTreeReaderArray<double> cnv_dx = {fReader, "cnv_dx"};
   TTreeReaderArray<double> cnv_dy = {fReader, "cnv_dy"};
   TTreeReaderArray<double> cnv_dz = {fReader, "cnv_dz"};
   TTreeReaderArray<double> e_idx = {fReader, "e_idx"};
   TTreeReaderArray<double> e_idx_pvr = {fReader, "e_idx_pvr"};
   TTreeReaderArray<double> e_pid = {fReader, "e_pid"};
   TTreeReaderArray<double> e_pt = {fReader, "e_pt"};
   TTreeReaderArray<double> e_px = {fReader, "e_px"};
   TTreeReaderArray<double> e_py = {fReader, "e_py"};
   TTreeReaderArray<double> e_pz = {fReader, "e_pz"};
   TTreeReaderArray<double> e_e = {fReader, "e_e"};
   TTreeReaderArray<double> e_eta = {fReader, "e_eta"};
   TTreeReaderArray<double> e_phi = {fReader, "e_phi"};
   TTreeReaderArray<double> e_m = {fReader, "e_m"};
   TTreeReaderArray<double> e_pid_e = {fReader, "e_pid_e"};
   TTreeReaderArray<double> e_pid_mu = {fReader, "e_pid_mu"};
   TTreeReaderArray<double> e_pid_k = {fReader, "e_pid_k"};
   TTreeReaderArray<double> e_pid_p = {fReader, "e_pid_p"};
   TTreeReaderArray<double> e_pnn_e = {fReader, "e_pnn_e"};
   TTreeReaderArray<double> e_pnn_mu = {fReader, "e_pnn_mu"};
   TTreeReaderArray<double> e_pnn_pi = {fReader, "e_pnn_pi"};
   TTreeReaderArray<double> e_pnn_k = {fReader, "e_pnn_k"};
   TTreeReaderArray<double> e_pnn_p = {fReader, "e_pnn_p"};
   TTreeReaderArray<double> e_pnn_ghost = {fReader, "e_pnn_ghost"};
   TTreeReaderArray<double> e_charge = {fReader, "e_charge"};
   TTreeReaderArray<double> e_type = {fReader, "e_type"};
   TTreeReaderArray<double> e_x = {fReader, "e_x"};
   TTreeReaderArray<double> e_y = {fReader, "e_y"};
   TTreeReaderArray<double> e_z = {fReader, "e_z"};
   TTreeReaderArray<double> e_chi2 = {fReader, "e_chi2"};
   TTreeReaderArray<double> e_ndof = {fReader, "e_ndof"};
   TTreeReaderArray<double> e_prob_chi2 = {fReader, "e_prob_chi2"};
   TTreeReaderArray<double> e_clone_dist = {fReader, "e_clone_dist"};
   TTreeReaderArray<double> e_ip = {fReader, "e_ip"};
   TTreeReaderArray<double> e_ip_chi2 = {fReader, "e_ip_chi2"};
   TTreeReaderArray<double> tag_dmat = {fReader, "tag_dmat"};
   TTreeReaderArray<double> tag_xxx = {fReader, "tag_xxx"};
   TTreeReaderArray<double> tag_dmat_isRescaled = {fReader, "tag_dmat_isRescaled"};
   TTreeReaderArray<double> tag_veto_h_modmiss = {fReader, "tag_veto_h_modmiss"};
   TTreeReaderArray<double> tag_veto_mu_modmiss = {fReader, "tag_veto_mu_modmiss"};
   TTreeReaderArray<double> tag_veto_cutFM = {fReader, "tag_veto_cutFM"};


   DalitzToyMaker(TTree * /*tree*/ =0) { }
   virtual ~DalitzToyMaker() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual double  TrigEff(Pythia8::Vec4 p1, Pythia8::Vec4 p2);
   virtual double  PnnEff(Pythia8::Vec4 p1, Pythia8::Vec4 p2);
   virtual Bool_t  InEcal(double x, double y);
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(DalitzToyMaker,0);

};

#endif

#ifdef DalitzToyMaker_cxx
void DalitzToyMaker::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t DalitzToyMaker::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef DalitzToyMaker_cxx
