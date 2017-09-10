//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jun 29 12:18:57 2017 by ROOT version 6.04/02
// from TTree data/data
// found on file: NTuple_RHNu_all_files_small.root
//////////////////////////////////////////////////////////

#ifndef Plot_hists_X2ApGm_h
#define Plot_hists_X2ApGm_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TSelector.h>
#include <stdlib.h>
#include <cmath>
//#include <velo.h>
//#include "MyClass.h"

#include <iostream>
#include <fstream>

//gROOT->LoadMacro("velo.C+"); //crashes, because cannot execute code in the header file

// Header file for the classes stored in the TTree if any.
#include "vector"





class Plot_hists_X2ApGm : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<double>  *pvr_x;
   vector<double>  *pvr_y;
   vector<double>  *pvr_z;
   vector<double>  *tag_idx_pvr;
   vector<double>  *tag_idx_prt0;
   vector<double>  *tag_idx_prt1;
   vector<double>  *tag_px;
   vector<double>  *tag_py;
   vector<double>  *tag_pz;
   vector<double>  *tag_e;
   vector<double>  *tag_x;
   vector<double>  *tag_y;
   vector<double>  *tag_z;
   vector<double>  *tag_m;
   vector<double>  *tag_veto_h_modmiss;
   vector<double>  *tag_veto_mu_modmiss;
   vector<double>  *tag_veto_cutFM;
   vector<double>  *tag_dmat;
   vector<double>  *tag_xxx;
   vector<double>  *tag_dmat_isRescaled;
   vector<double>  *tag_dtf_m;
   vector<double>  *tag_dtf_dm;
   vector<double>  *tag_ip_chi2;
   vector<double>  *tag_il;
   vector<double>  *tag_iv;
   vector<double>  *tag_dtf_chi2;
   vector<double>  *tag_chi2;
   vector<double>  *tag_ve_ns;
   vector<double>  *tag_tt_ns;
   vector<double>  *tag_it_ns;
   vector<double>  *tag_ot_ns;
   vector<double>  *tag_mu_ns;
   vector<double>  *tag_l0_tos1;
   vector<double>  *tag_l0_tos2;
   vector<double>  *tag_l0_tis;
   vector<double>  *tag_hlt1_tos4;
   vector<double>  *tag_hlt1_tos5;
   vector<double>  *tag_hlt1_tis;
   vector<double>  *tag_hlt2_tos0;
   vector<double>  *tag_hlt2_tis;
   vector<double>  *prt_idx_pvr;
   vector<double>  *prt_pid;
   vector<double>  *prt_px;
   vector<double>  *prt_py;
   vector<double>  *prt_pz;
   vector<double>  *prt_e;
   vector<double>  *prt_isMuon;
   vector<double>  *prt_pnn_mu;
   vector<double>  *prt_pnn_pi;
   vector<double>  *prt_pnn_k;
   vector<double>  *prt_pnn_p;
   vector<double>  *prt_pnn_ghost;
   vector<double>  *prt_prb_ghost;
   vector<double>  *prt_ip;
   vector<double>  *prt_ip_chi2;
   vector<double>  *prt_x0;
   vector<double>  *prt_y0;
   vector<double>  *prt_z0;
   vector<double>  *prt_id0;
   vector<double>  *prt_x1;
   vector<double>  *prt_y1;
   vector<double>  *prt_z1;
   vector<double>  *prt_id1;
   vector<double>  *prt_iso;
   vector<double>  *prt_smooth_iso;
   vector<double>  *prt_isDiRHNu;
   //vector<double>  *h_velo_tip;
   //vector<double>  *h_velo_miss;
   //vector<double>  *mu_velo_tip;
   //vector<double>  *mu_velo_miss;
   Double_t        pvr_n;
   Double_t        run_n;
   Double_t        evt_n;
   Double_t        evt_tck;
   Double_t        evt_spd;

   // List of branches
   TBranch        *b_pvr_x;   //!
   TBranch        *b_pvr_y;   //!
   TBranch        *b_pvr_z;   //!
   TBranch        *b_tag_idx_pvr;   //!
   TBranch        *b_tag_idx_prt0;   //!
   TBranch        *b_tag_idx_prt1;   //!
   TBranch        *b_tag_px;   //!
   TBranch        *b_tag_py;   //!
   TBranch        *b_tag_pz;   //!
   TBranch        *b_tag_e;   //!
   TBranch        *b_tag_x;   //!
   TBranch        *b_tag_y;   //!
   TBranch        *b_tag_z;   //!
   TBranch        *b_tag_m;   //!
   TBranch        *b_tag_veto_h_modmiss;   //!
   TBranch        *b_tag_veto_mu_modmiss;   //!
   TBranch        *b_tag_veto_cutFM;   //!
   TBranch        *b_tag_dmat;   //!
   TBranch        *b_tag_xxx;   //!
   TBranch        *b_tag_dmat_isRescaled;
   TBranch        *b_tag_dtf_m;   //!
   TBranch        *b_tag_dtf_dm;   //!
   TBranch        *b_tag_ip_chi2;   //!
   TBranch        *b_tag_il;   //!
   TBranch        *b_tag_iv;   //!
   TBranch        *b_tag_dtf_chi2;   //!
   TBranch        *b_tag_chi2;   //!
   TBranch        *b_tag_ve_ns;   //!
   TBranch        *b_tag_tt_ns;   //!
   TBranch        *b_tag_it_ns;   //!
   TBranch        *b_tag_ot_ns;   //!
   TBranch        *b_tag_mu_ns;   //!
   TBranch        *b_tag_l0_tos1;   //!
   TBranch        *b_tag_l0_tos2;   //!
   TBranch        *b_tag_l0_tis;   //!
   TBranch        *b_tag_hlt1_tos4;   //!
   TBranch        *b_tag_hlt1_tos5;   //!
   TBranch        *b_tag_hlt1_tis;   //!
   TBranch        *b_tag_hlt2_tos0;   //!
   TBranch        *b_tag_hlt2_tis;   //!
   TBranch        *b_prt_idx_pvr;   //!
   TBranch        *b_prt_pid;   //!
   TBranch        *b_prt_px;   //!
   TBranch        *b_prt_py;   //!
   TBranch        *b_prt_pz;   //!
   TBranch        *b_prt_e;   //!
   TBranch        *b_prt_isMuon;   //!
   TBranch        *b_prt_pnn_mu;   //!
   TBranch        *b_prt_pnn_pi;   //!
   TBranch        *b_prt_pnn_k;   //!
   TBranch        *b_prt_pnn_p;   //!
   TBranch        *b_prt_pnn_ghost;   //!
   TBranch        *b_prt_prb_ghost;   //!
   TBranch        *b_prt_ip;   //!
   TBranch        *b_prt_ip_chi2;   //!
   TBranch        *b_prt_x0;   //!
   TBranch        *b_prt_y0;   //!
   TBranch        *b_prt_z0;   //!
   TBranch        *b_prt_id0;   //!
   TBranch        *b_prt_x1;   //!
   TBranch        *b_prt_y1;   //!
   TBranch        *b_prt_z1;   //!
   TBranch        *b_prt_id1;   //!
   TBranch        *b_prt_iso;   //!
   TBranch        *b_prt_smooth_iso;   //!
   TBranch        *b_prt_isDiRHNu;
   TBranch        *b_pvr_n;   //!
   TBranch        *b_run_n;   //!
   TBranch        *b_evt_n;   //!
   TBranch        *b_evt_tck;   //!
   TBranch        *b_evt_spd;   //!
   //TBranch        *b_h_velo_tip;
   //TBranch        *b_h_velo_miss;
   //TBranch        *b_mu_velo_tip;
   //TBranch        *b_mu_velo_miss;

   TFile *f;
   TH1F *fmu_pnnmu, *fh_pnnmu, *fh_pnnk, *fh_pnnpi, *fmu_isMuon, *fh_isMuon, *fd2, *fd2_no_matveto_cut, *fdmat, *fdmat_rescaled, *fdmat_rescaled_I, *fdmat_rescaled_II, *fdmat_rescaled_III, *fxxx, *fiv_hf, *fiv_sig, *fil_hf, *fil_sig, *fQ, *fM, *fM_l0_p, *fM_l0_f, *fM_hlt1_p, *fM_hlt1_f, *fM_hlt2_p, *fM_hlt2_f, *fM_kin_p, *fM_kin_f, *fM_patho_p, *fM_patho_f, *fM_hf_p, *fM_hf_f, *fM_fd_r_p, *fM_fd_r_f, *fM_material_p, *fM_material_f, *fM_material_h_modmiss_p, *fM_material_h_modmiss_f, *fM_material_mu_modmiss_p, *fM_material_mu_modmiss_f, *fM_material_cutFM_p, *fM_material_cutFM_f, *fM_pid_p, *fM_pid_f, *fM_data_consistency_p, *fM_data_consistency_f, *fM_pid1_p, *fM_pid1_f, *fM_pid2_p, *fM_pid2_f, *fM_strip_p, *fM_strip_f, *fM_pid_I_p, *fM_pid_II_p, *fM_pid_III_p, *fM_pid_IV_p;
   TH1F *ffd_r, *ffd_r_I, *ffd_r_II, *ffd_r_III, *ffd_r_IV;
   TH1F *fM_trigger_cuts, *fM_necessary_cuts, *fM_necessary_and_material_cuts, *fM_necessary_and_hf_cuts, *fM_necessary_and_hf_and_material_cuts;
   TH2F *fMT, *fMT_l0_p, *fMT_l0_f, *fMT_hlt1_p, *fMT_hlt1_f, *fMT_hlt2_p, *fMT_hlt2_f, *fMT_kin_p, *fMT_kin_f, *fMT_data_consistency_p, *fMT_data_consistency_f, *fMT_patho_p, *fMT_patho_f, *fMT_hf_p, *fMT_hf_f, *fMT_fd_r_p, *fMT_fd_r_f, *fMT_material_p, *fMT_material_f, *fMT_pid_p, *fMT_pid_f, *fMT_pid1_p, *fMT_pid1_f, *fMT_pid2_p, *fMT_pid2_f, *fMT_strip_p, *fMT_strip_f, *fMT_pid_I_p, *fMT_pid_II_p, *fMT_pid_III_p, *fMT_pid_IV_p;
   TH2F *fzx, *fyx;
   TH2F *fM1M2, *fM1M2_tau_1to2, *fM1M2_tau_2to5, *fM1M2_tau_5to10;
   TH2F *fM1M2_dtf_chi2_0to2, *fM1M2_dtf_chi2_2to5, *fM1M2_dtf_chi2_5to8;
   TH2F *fM1M2_l0, *fM1M2_hlt1, *fM1M2_hlt2, *fM1M2_strip, *fM1M2_kin, *fM1M2_data_consistency, *fM1M2_patho, *fM1M2_material, *fM1M2_hf, *fM1M2_fd_r, *fM1M2_pid;
   TH2F *fM1M2_trigger_cuts,*fM1M2_necessary_cuts, *fM1M2_necessary_and_material_cuts, *fM1M2_necessary_and_hf_cuts, *fM1M2_necessary_and_hf_and_material_cuts;
   TH2F *fM2nMavg;
   TH2F *fMdmat_necessary_cuts, *fMdmat_rescaled_necessary_cuts, *fMdmat_necessary_cuts_diRHNu, *fMdmat_rescaled_necessary_cuts_diRHNu;
   TH2F *fM_il_necessary_cuts, *fM_iv_necessary_cuts, *fM_il_necessary_cuts_diRHNu, *fM_iv_necessary_cuts_diRHNu;
   bool prt_bool, prt_bool_patho_srd, hf_veto, material_veto, prt_bool_no_matveto_cut;
   bool prt_bool_l0, prt_bool_hlt1, prt_bool_hlt2, prt_bool_strip, prt_bool_kin, prt_bool_data_consistency, prt_bool_patho, prt_bool_dec_topo, prt_bool_patho_mu, prt_bool_patho_h, prt_bool_material, prt_bool_hf, prt_bool_fd_r, prt_bool_pid;
   bool prt_bool_region_I, prt_bool_region_II, prt_bool_region_III, prt_bool_region_IV;
   bool prt_bool_material_h_modmiss, prt_bool_material_mu_modmiss, prt_bool_material_cutFM;
   bool prt_bool_l0_1, prt_bool_hlt1_1, prt_bool_hlt2_1, prt_bool_strip_1, prt_bool_kin_1, prt_bool_data_consistency_1, prt_bool_patho_1, prt_bool_dec_topo_1, prt_bool_patho_mu_1, prt_bool_patho_h_1, prt_bool_material_1, prt_bool_hf_1, prt_bool_fd_r_1, prt_bool_pid_1;
   bool prt_bool_l0_2, prt_bool_hlt1_2, prt_bool_hlt2_2, prt_bool_strip_2, prt_bool_kin_2, prt_bool_data_consistency_2, prt_bool_patho_2, prt_bool_dec_topo_2, prt_bool_patho_mu_2, prt_bool_patho_h_2, prt_bool_material_2, prt_bool_hf_2, prt_bool_fd_r_2, prt_bool_pid_2;
   bool prt_bool_full, prt_bool_full_1, prt_bool_full_2;
   bool prt_bool_necessary_cuts, prt_bool_necessary_cuts_1, prt_bool_necessary_cuts_2;
   bool prt_bool_trigger_cuts, prt_bool_trigger_cuts_1, prt_bool_trigger_cuts_2;

   int n_candidates_orig, n_accepted, n_more_than_1_cand;
   int reject_l0, reject_hlt1, reject_hlt2, reject_kin, reject_dec_topo, reject_patho, reject_hf, reject_material, reject_pid;
   double prt_trk_dist_mu_h, tag_d2, tag_fd_r, tag_fd, tag_p, tag_pt, tag_eta, tag_beta, tag_gamma, tag_flighttime, tag_tau_ps;
   double mu_p, mu_eta, h_p, h_eta;
   double tag_tau_ps_1, tag_tau_ps_2, tag_d2_1, tag_d2_2, tag_m_1, tag_m_2, tag_dtf_chi2_1, tag_dtf_chi2_2;
   double m_diff, delta_m_diff, sig_m_diff, m_avg, m_2N, Q;
   std::map<std::string, double> first_variables, second_variables;
   std::tuple<double, double> DiRHNu_variables;
   //bool h_velo_tip, h_velo_miss, mu_velo_tip, mu_velo_miss;
   vector<Double_t> x_scatter, y_scatter, z_scatter, x_scatter_no_matveto_cut, y_scatter_no_matveto_cut, z_scatter_no_matveto_cut, x_scatter_matveto_reject, y_scatter_matveto_reject, z_scatter_matveto_reject, x_scatter_I, y_scatter_I, z_scatter_I, x_scatter_II, y_scatter_II, z_scatter_II, x_scatter_III, y_scatter_III, z_scatter_III, x_scatter_IV, y_scatter_IV, z_scatter_IV;
   bool pass_separately;
   int idx_mu_1, idx_h_1, idx_mu_2, idx_h_2, idx_mu, idx_h, idx_pvr;
   int n_nn, n_yn, n_ny, n_yy;
   TCanvas *c1;
   TGraph *gyx, *gzx, *gyx_no_matveto_cut, *gzx_no_matveto_cut;
   TString option;


   Plot_hists_X2ApGm(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~Plot_hists_X2ApGm() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SingleRHNu_Plots(unsigned mum);
   virtual void    DiRHNu_Plots(unsigned first_id_test, unsigned second_id_test);
   std::map<std::string, double> Simple_Variables_Calculation(int mum);
   virtual std::tuple<double, double> DiRHNu_Variables_Calculation(unsigned first_id_test, unsigned second_id_test);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Plot_Scatter_Graphs();
   virtual void    Terminate();

   ClassDef(Plot_hists_X2ApGm,0);
};

#endif

#ifdef Plot_hists_X2ApGm_cxx
void Plot_hists_X2ApGm::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pvr_x = 0;
   pvr_y = 0;
   pvr_z = 0;
   tag_idx_pvr = 0;
   tag_idx_prt0 = 0;
   tag_idx_prt1 = 0;
   tag_px = 0;
   tag_py = 0;
   tag_pz = 0;
   tag_e = 0;
   tag_x = 0;
   tag_y = 0;
   tag_z = 0;
   tag_m = 0;
   tag_veto_mu_modmiss = 0;
   tag_veto_h_modmiss = 0;
   tag_veto_cutFM = 0;
   tag_dmat = 0;
   tag_xxx = 0;
   tag_dmat_isRescaled = 0;
   tag_dtf_m = 0;
   tag_dtf_dm = 0;
   tag_ip_chi2 = 0;
   tag_il = 0;
   tag_iv = 0;
   tag_dtf_chi2 = 0;
   tag_chi2 = 0;
   tag_ve_ns = 0;
   tag_tt_ns = 0;
   tag_it_ns = 0;
   tag_ot_ns = 0;
   tag_mu_ns = 0;
   tag_l0_tos1 = 0;
   tag_l0_tos2 = 0;
   tag_l0_tis = 0;
   tag_hlt1_tos4 = 0;
   tag_hlt1_tos5 = 0;
   tag_hlt1_tis = 0;
   tag_hlt2_tos0 = 0;
   tag_hlt2_tis = 0;
   prt_idx_pvr = 0;
   prt_pid = 0;
   prt_px = 0;
   prt_py = 0;
   prt_pz = 0;
   prt_e = 0;
   prt_isMuon = 0;
   prt_pnn_mu = 0;
   prt_pnn_pi = 0;
   prt_pnn_k = 0;
   prt_pnn_p = 0;
   prt_pnn_ghost = 0;
   prt_prb_ghost = 0;
   prt_ip = 0;
   prt_ip_chi2 = 0;
   prt_x0 = 0;
   prt_y0 = 0;
   prt_z0 = 0;
   prt_id0 = 0;
   prt_x1 = 0;
   prt_y1 = 0;
   prt_z1 = 0;
   prt_id1 = 0;
   prt_iso = 0;
   prt_smooth_iso = 0;
   prt_isDiRHNu =0;
   //h_velo_tip = 0;
   //h_velo_miss = 0;
   //mu_velo_tip = 0;
   //mu_velo_miss = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pvr_x", &pvr_x, &b_pvr_x);
   fChain->SetBranchAddress("pvr_y", &pvr_y, &b_pvr_y);
   fChain->SetBranchAddress("pvr_z", &pvr_z, &b_pvr_z);
   fChain->SetBranchAddress("tag_idx_pvr", &tag_idx_pvr, &b_tag_idx_pvr);
   fChain->SetBranchAddress("tag_idx_prt0", &tag_idx_prt0, &b_tag_idx_prt0);
   fChain->SetBranchAddress("tag_idx_prt1", &tag_idx_prt1, &b_tag_idx_prt1);
   fChain->SetBranchAddress("tag_px", &tag_px, &b_tag_px);
   fChain->SetBranchAddress("tag_py", &tag_py, &b_tag_py);
   fChain->SetBranchAddress("tag_pz", &tag_pz, &b_tag_pz);
   fChain->SetBranchAddress("tag_e", &tag_e, &b_tag_e);
   fChain->SetBranchAddress("tag_x", &tag_x, &b_tag_x);
   fChain->SetBranchAddress("tag_y", &tag_y, &b_tag_y);
   fChain->SetBranchAddress("tag_z", &tag_z, &b_tag_z);
   fChain->SetBranchAddress("tag_m", &tag_m, &b_tag_m);
   fChain->SetBranchAddress("tag_veto_mu_modmiss", &tag_veto_mu_modmiss, &b_tag_veto_mu_modmiss);
   fChain->SetBranchAddress("tag_veto_h_modmiss", &tag_veto_h_modmiss, &b_tag_veto_h_modmiss);
   fChain->SetBranchAddress("tag_veto_cutFM", &tag_veto_cutFM, &b_tag_veto_cutFM);
   fChain->SetBranchAddress("tag_dmat", &tag_dmat, &b_tag_dmat);
   fChain->SetBranchAddress("tag_xxx", &tag_xxx, &b_tag_xxx);
   fChain->SetBranchAddress("tag_dmat_isRescaled", &tag_dmat_isRescaled, &b_tag_dmat_isRescaled);
   fChain->SetBranchAddress("tag_dtf_m", &tag_dtf_m, &b_tag_dtf_m);
   fChain->SetBranchAddress("tag_dtf_dm", &tag_dtf_dm, &b_tag_dtf_dm);
   fChain->SetBranchAddress("tag_ip_chi2", &tag_ip_chi2, &b_tag_ip_chi2);
   fChain->SetBranchAddress("tag_il", &tag_il, &b_tag_il);
   fChain->SetBranchAddress("tag_iv", &tag_iv, &b_tag_iv);
   fChain->SetBranchAddress("tag_dtf_chi2", &tag_dtf_chi2, &b_tag_dtf_chi2);
   fChain->SetBranchAddress("tag_chi2", &tag_chi2, &b_tag_chi2);
   fChain->SetBranchAddress("tag_ve_ns", &tag_ve_ns, &b_tag_ve_ns);
   fChain->SetBranchAddress("tag_tt_ns", &tag_tt_ns, &b_tag_tt_ns);
   fChain->SetBranchAddress("tag_it_ns", &tag_it_ns, &b_tag_it_ns);
   fChain->SetBranchAddress("tag_ot_ns", &tag_ot_ns, &b_tag_ot_ns);
   fChain->SetBranchAddress("tag_mu_ns", &tag_mu_ns, &b_tag_mu_ns);
   fChain->SetBranchAddress("tag_l0_tos1", &tag_l0_tos1, &b_tag_l0_tos1);
   fChain->SetBranchAddress("tag_l0_tos2", &tag_l0_tos2, &b_tag_l0_tos2);
   fChain->SetBranchAddress("tag_l0_tis", &tag_l0_tis, &b_tag_l0_tis);
   fChain->SetBranchAddress("tag_hlt1_tos4", &tag_hlt1_tos4, &b_tag_hlt1_tos4);
   fChain->SetBranchAddress("tag_hlt1_tos5", &tag_hlt1_tos5, &b_tag_hlt1_tos5);
   fChain->SetBranchAddress("tag_hlt1_tis", &tag_hlt1_tis, &b_tag_hlt1_tis);
   fChain->SetBranchAddress("tag_hlt2_tos0", &tag_hlt2_tos0, &b_tag_hlt2_tos0);
   fChain->SetBranchAddress("tag_hlt2_tis", &tag_hlt2_tis, &b_tag_hlt2_tis);
   fChain->SetBranchAddress("prt_idx_pvr", &prt_idx_pvr, &b_prt_idx_pvr);
   fChain->SetBranchAddress("prt_pid", &prt_pid, &b_prt_pid);
   fChain->SetBranchAddress("prt_px", &prt_px, &b_prt_px);
   fChain->SetBranchAddress("prt_py", &prt_py, &b_prt_py);
   fChain->SetBranchAddress("prt_pz", &prt_pz, &b_prt_pz);
   fChain->SetBranchAddress("prt_e", &prt_e, &b_prt_e);
   fChain->SetBranchAddress("prt_isMuon", &prt_isMuon, &b_prt_isMuon);
   fChain->SetBranchAddress("prt_pnn_mu", &prt_pnn_mu, &b_prt_pnn_mu);
   fChain->SetBranchAddress("prt_pnn_pi", &prt_pnn_pi, &b_prt_pnn_pi);
   fChain->SetBranchAddress("prt_pnn_k", &prt_pnn_k, &b_prt_pnn_k);
   fChain->SetBranchAddress("prt_pnn_p", &prt_pnn_p, &b_prt_pnn_p);
   fChain->SetBranchAddress("prt_pnn_ghost", &prt_pnn_ghost, &b_prt_pnn_ghost);
   fChain->SetBranchAddress("prt_prb_ghost", &prt_prb_ghost, &b_prt_prb_ghost);
   fChain->SetBranchAddress("prt_ip", &prt_ip, &b_prt_ip);
   fChain->SetBranchAddress("prt_ip_chi2", &prt_ip_chi2, &b_prt_ip_chi2);
   fChain->SetBranchAddress("prt_x0", &prt_x0, &b_prt_x0);
   fChain->SetBranchAddress("prt_y0", &prt_y0, &b_prt_y0);
   fChain->SetBranchAddress("prt_z0", &prt_z0, &b_prt_z0);
   fChain->SetBranchAddress("prt_id0", &prt_id0, &b_prt_id0);
   fChain->SetBranchAddress("prt_x1", &prt_x1, &b_prt_x1);
   fChain->SetBranchAddress("prt_y1", &prt_y1, &b_prt_y1);
   fChain->SetBranchAddress("prt_z1", &prt_z1, &b_prt_z1);
   fChain->SetBranchAddress("prt_id1", &prt_id1, &b_prt_id1);
   fChain->SetBranchAddress("prt_iso", &prt_iso, &b_prt_iso);
   fChain->SetBranchAddress("prt_smooth_iso", &prt_smooth_iso, &b_prt_smooth_iso);
   fChain->SetBranchAddress("prt_isDiRHNu", &prt_isDiRHNu, &b_prt_isDiRHNu);
   fChain->SetBranchAddress("pvr_n", &pvr_n, &b_pvr_n);
   fChain->SetBranchAddress("run_n", &run_n, &b_run_n);
   fChain->SetBranchAddress("evt_n", &evt_n, &b_evt_n);
   fChain->SetBranchAddress("evt_tck", &evt_tck, &b_evt_tck);
   fChain->SetBranchAddress("evt_spd", &evt_spd, &b_evt_spd);
   //fChain->SetBranchAddress("h_velo_tip", &h_velo_tip, &b_h_velo_tip);
   //fChain->SetBranchAddress("h_velo_miss", &h_velo_miss, &b_h_velo_miss);
   //fChain->SetBranchAddress("mu_velo_tip", &mu_velo_tip, &b_mu_velo_tip);
   //fChain->SetBranchAddress("mu_velo_miss", &mu_velo_miss, &b_mu_velo_miss);

}

Bool_t Plot_hists_X2ApGm::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef Plot_hists_X2ApGm_cxx
