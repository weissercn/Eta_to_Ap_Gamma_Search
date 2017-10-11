//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Sep 10 15:38:20 2017 by ROOT version 6.08/06
// from TTree data/data
// found on file: outfile.root
//////////////////////////////////////////////////////////

#ifndef Plot_hists_X2ApGm_TomsCuts_h
#define Plot_hists_X2ApGm_TomsCuts_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TSelector.h>
#include <TLorentzVector.h>
#include <stdlib.h>
#include <cmath>
//#include <velo.h>
//#include "MyClass.h"

#include <iostream>
#include <fstream>

//gROOT->LoadMacro("velo.C+"); //crashes, because cannot execute code in the header file

// Header file for the classes stored in the TTree if any.
#include "vector"

class Plot_hists_X2ApGm_TomsCuts : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<double>  *evt_event;
   vector<double>  *evt_run;
   vector<double>  *evt_ntracks;
   vector<double>  *evt_nspd;
   vector<double>  *gens_idx;
   vector<double>  *gens_idx_mom;
   vector<double>  *gens_pid;
   vector<double>  *gens_px;
   vector<double>  *gens_py;
   vector<double>  *gens_pz;
   vector<double>  *gens_pt;
   vector<double>  *gens_e;
   vector<double>  *gens_eta;
   vector<double>  *gens_phi;
   vector<double>  *gens_m;
   vector<double>  *gens_acc;
   vector<double>  *gens_rec;
   vector<double>  *pvr_idx;
   vector<double>  *pvr_x;
   vector<double>  *pvr_y;
   vector<double>  *pvr_z;
   vector<double>  *pvr_chi2;
   vector<double>  *pvr_ndof;
   vector<double>  *tag_idx;
   vector<double>  *tag_idx_pvr;
   vector<double>  *tag_idx_prt0;
   vector<double>  *tag_idx_prt1;
   vector<double>  *tag_il;
   vector<double>  *tag_iv;
   vector<double>  *tag_pid;
   vector<double>  *tag_px;
   vector<double>  *tag_py;
   vector<double>  *tag_pz;
   vector<double>  *tag_pt;
   vector<double>  *tag_e;
   vector<double>  *tag_eta;
   vector<double>  *tag_phi;
   vector<double>  *tag_m;
   vector<double>  *tag_veto_h_modmiss;
   vector<double>  *tag_veto_mu_modmiss;
   vector<double>  *tag_veto_cutFM;
   vector<double>  *tag_nu_brem_0;
   vector<double>  *tag_nu_brem_1;
   vector<double>  *tag_dls;
   vector<double>  *tag_ctau;
   vector<double>  *tag_dtf_chi2;
   vector<double>  *tag_dtf_px, *tag_dtf_py, *tag_dtf_pz, *tag_dtf_e;
   vector<double>  *tag_dtf_m;
   vector<double>  *tag_chi2;
   vector<double>  *tag_ndof;
   vector<double>  *tag_dira;
   vector<double>  *tag_vrt_x;
   vector<double>  *tag_vrt_y;
   vector<double>  *tag_vrt_z;
   vector<double>  *tag_ve_ns;
   vector<double>  *tag_x;
   vector<double>  *tag_y;
   vector<double>  *tag_z;
   vector<double>  *tag_dx;
   vector<double>  *tag_dy;
   vector<double>  *tag_dz;
   vector<double>  *prt_idx;
   vector<double>  *prt_idx_pvr;
   vector<double>  *prt_pid;
   vector<double>  *prt_pt;
   vector<double>  *prt_px;
   vector<double>  *prt_py;
   vector<double>  *prt_pz;
   vector<double>  *prt_e;
   vector<double>  *prt_eta;
   vector<double>  *prt_phi;
   vector<double>  *prt_m;
   vector<double>  *prt_pid_e;
   vector<double>  *prt_pid_mu;
   vector<double>  *prt_pid_k;
   vector<double>  *prt_pid_p;
   vector<double>  *prt_pnn_e;
   vector<double>  *prt_pnn_mu;
   vector<double>  *prt_pnn_pi;
   vector<double>  *prt_pnn_k;
   vector<double>  *prt_pnn_p;
   vector<double>  *prt_pnn_ghost;
   vector<double>  *prt_charge;
   vector<double>  *prt_type;
   vector<double>  *prt_x;
   vector<double>  *prt_y;
   vector<double>  *prt_z;
   vector<double>  *prt_chi2;
   vector<double>  *prt_ndof;
   vector<double>  *prt_prob_chi2;
   vector<double>  *prt_clone_dist;
   vector<double>  *prt_ip;
   vector<double>  *prt_ip_chi2;
   vector<double>  *prt_x0;
   vector<double>  *prt_x1;
   vector<double>  *prt_y0;
   vector<double>  *prt_y1;
   vector<double>  *prt_z0;
   vector<double>  *prt_z1;
   vector<double>  *tag_l0_tos1;
   vector<double>  *tag_l0_tos2;
   vector<double>  *tag_l0_tos3;
   vector<double>  *tag_l0_tis;
   vector<double>  *tag_hlt1_tos4;
   vector<double>  *tag_hlt1_tos5;
   vector<double>  *tag_hlt1_tis;
   vector<double>  *tag_hlt2_tos0;
   vector<double>  *tag_strip_dec0;
   vector<double>  *prt_iso;
   vector<double>  *calo_idx;
   vector<double>  *calo_idx_pvr;
   vector<double>  *calo_pid;
   vector<double>  *calo_px;
   vector<double>  *calo_py;
   vector<double>  *calo_pz;
   vector<double>  *calo_pt;
   vector<double>  *calo_e;
   vector<double>  *calo_eta;
   vector<double>  *calo_phi;
   vector<double>  *calo_m;
   vector<double>  *calo_cl;
   vector<double>  *calo_deposit_id;
   vector<double>  *calo_e19;
   vector<double>  *calo_e49;
   vector<double>  *calo_ecal;
   vector<double>  *calo_prs_m;
   vector<double>  *calo_prs;
   vector<double>  *calo_spd;
   vector<double>  *calo_prs_e19;
   vector<double>  *calo_prs_e49;
   vector<double>  *calo_prs_e4_max;
   vector<double>  *calo_tr_match;
   vector<double>  *calo_is_not_e;
   vector<double>  *calo_is_not_h;
   vector<double>  *calo_photon_id;
   vector<double>  *calo_shower_shape;
   vector<double>  *calo_hcal_ecal;
   vector<double>  *mergedpi0_idx;
   vector<double>  *mergedpi0_idx_pvr;
   vector<double>  *mergedpi0_pid;
   vector<double>  *mergedpi0_px;
   vector<double>  *mergedpi0_py;
   vector<double>  *mergedpi0_pz;
   vector<double>  *mergedpi0_pt;
   vector<double>  *mergedpi0_e;
   vector<double>  *mergedpi0_eta;
   vector<double>  *mergedpi0_phi;
   vector<double>  *mergedpi0_m;
   vector<double>  *mergedpi0_cl;
   vector<double>  *mergedpi0_deposit_id;
   vector<double>  *mergedpi0_e19;
   vector<double>  *mergedpi0_e49;
   vector<double>  *mergedpi0_ecal;
   vector<double>  *mergedpi0_prs_m;
   vector<double>  *mergedpi0_prs;
   vector<double>  *mergedpi0_spd;
   vector<double>  *mergedpi0_prs_e19;
   vector<double>  *mergedpi0_prs_e49;
   vector<double>  *mergedpi0_prs_e4_max;
   vector<double>  *mergedpi0_tr_match;
   vector<double>  *mergedpi0_is_not_e;
   vector<double>  *mergedpi0_is_not_h;
   vector<double>  *mergedpi0_photon_id;
   vector<double>  *mergedpi0_shower_shape;
   vector<double>  *mergedpi0_hcal_ecal;
   vector<double>  *cnv_idx;
   vector<double>  *cnv_idx_pvr;
   vector<double>  *cnv_idx_e1;
   vector<double>  *cnv_idx_e2;
   vector<double>  *cnv_pid;
   vector<double>  *cnv_px;
   vector<double>  *cnv_py;
   vector<double>  *cnv_pz;
   vector<double>  *cnv_pt;
   vector<double>  *cnv_e;
   vector<double>  *cnv_eta;
   vector<double>  *cnv_phi;
   vector<double>  *cnv_m;
   vector<double>  *cnv_dls;
   vector<double>  *cnv_ctau;
   vector<double>  *cnv_chi2;
   vector<double>  *cnv_ndof;
   vector<double>  *cnv_dira;
   vector<double>  *cnv_vrt_x;
   vector<double>  *cnv_vrt_y;
   vector<double>  *cnv_vrt_z;
   vector<double>  *cnv_ve_ns;
   vector<double>  *cnv_x;
   vector<double>  *cnv_y;
   vector<double>  *cnv_z;
   vector<double>  *cnv_dx;
   vector<double>  *cnv_dy;
   vector<double>  *cnv_dz;
   vector<double>  *e_idx;
   vector<double>  *e_idx_pvr;
   vector<double>  *e_pid;
   vector<double>  *e_pt;
   vector<double>  *e_px;
   vector<double>  *e_py;
   vector<double>  *e_pz;
   vector<double>  *e_e;
   vector<double>  *e_eta;
   vector<double>  *e_phi;
   vector<double>  *e_m;
   vector<double>  *e_pid_e;
   vector<double>  *e_pid_mu;
   vector<double>  *e_pid_k;
   vector<double>  *e_pid_p;
   vector<double>  *e_pnn_e;
   vector<double>  *e_pnn_mu;
   vector<double>  *e_pnn_pi;
   vector<double>  *e_pnn_k;
   vector<double>  *e_pnn_p;
   vector<double>  *e_pnn_ghost;
   vector<double>  *e_charge;
   vector<double>  *e_type;
   vector<double>  *e_x;
   vector<double>  *e_y;
   vector<double>  *e_z;
   vector<double>  *e_chi2;
   vector<double>  *e_ndof;
   vector<double>  *e_prob_chi2;
   vector<double>  *e_clone_dist;
   vector<double>  *e_ip;
   vector<double>  *e_ip_chi2;

   // List of branches
   TBranch        *b_evt_event;   //!
   TBranch        *b_evt_run;   //!
   TBranch        *b_evt_ntracks;   //!
   TBranch        *b_evt_nspd;   //!
   TBranch        *b_gens_idx;   //!
   TBranch        *b_gens_idx_mom;   //!
   TBranch        *b_gens_pid;   //!
   TBranch        *b_gens_px;   //!
   TBranch        *b_gens_py;   //!
   TBranch        *b_gens_pz;   //!
   TBranch        *b_gens_pt;   //!
   TBranch        *b_gens_e;   //!
   TBranch        *b_gens_eta;   //!
   TBranch        *b_gens_phi;   //!
   TBranch        *b_gens_m;   //!
   TBranch        *b_gens_acc;   //!
   TBranch        *b_gens_rec;   //!
   TBranch        *b_pvr_idx;   //!
   TBranch        *b_pvr_x;   //!
   TBranch        *b_pvr_y;   //!
   TBranch        *b_pvr_z;   //!
   TBranch        *b_pvr_chi2;   //!
   TBranch        *b_pvr_ndof;   //!
   TBranch        *b_tag_idx;   //!
   TBranch        *b_tag_idx_pvr;   //!
   TBranch        *b_tag_idx_prt0;   //!
   TBranch        *b_tag_idx_prt1;   //!
   TBranch        *b_tag_il;   //!
   TBranch        *b_tag_iv;   //!
   TBranch        *b_tag_pid;   //!
   TBranch        *b_tag_px;   //!
   TBranch        *b_tag_py;   //!
   TBranch        *b_tag_pz;   //!
   TBranch        *b_tag_pt;   //!
   TBranch        *b_tag_e;   //!
   TBranch        *b_tag_eta;   //!
   TBranch        *b_tag_phi;   //!
   TBranch        *b_tag_m;   //!
   TBranch        *b_tag_veto_h_modmiss;   //!
   TBranch        *b_tag_veto_mu_modmiss;   //!
   TBranch        *b_tag_veto_cutFM;   //!
   TBranch        *b_tag_nu_brem_0;   //!
   TBranch        *b_tag_nu_brem_1;   //!
   TBranch        *b_tag_dls;   //!
   TBranch        *b_tag_ctau;   //!
   TBranch        *b_tag_dtf_chi2;   //!
   TBranch        *b_tag_dtf_px, *b_tag_dtf_py, *b_tag_dtf_pz, *b_tag_dtf_e;   //!
   TBranch        *b_tag_dtf_m;   //!
   TBranch        *b_tag_chi2;   //!
   TBranch        *b_tag_ndof;   //!
   TBranch        *b_tag_dira;   //!
   TBranch        *b_tag_vrt_x;   //!
   TBranch        *b_tag_vrt_y;   //!
   TBranch        *b_tag_vrt_z;   //!
   TBranch        *b_tag_ve_ns;   //!
   TBranch        *b_tag_x;   //!
   TBranch        *b_tag_y;   //!
   TBranch        *b_tag_z;   //!
   TBranch        *b_tag_dx;   //!
   TBranch        *b_tag_dy;   //!
   TBranch        *b_tag_dz;   //!
   TBranch        *b_prt_idx;   //!
   TBranch        *b_prt_idx_pvr;   //!
   TBranch        *b_prt_pid;   //!
   TBranch        *b_prt_pt;   //!
   TBranch        *b_prt_px;   //!
   TBranch        *b_prt_py;   //!
   TBranch        *b_prt_pz;   //!
   TBranch        *b_prt_e;   //!
   TBranch        *b_prt_eta;   //!
   TBranch        *b_prt_phi;   //!
   TBranch        *b_prt_m;   //!
   TBranch        *b_prt_pid_e;   //!
   TBranch        *b_prt_pid_mu;   //!
   TBranch        *b_prt_pid_k;   //!
   TBranch        *b_prt_pid_p;   //!
   TBranch        *b_prt_pnn_e;   //!
   TBranch        *b_prt_pnn_mu;   //!
   TBranch        *b_prt_pnn_pi;   //!
   TBranch        *b_prt_pnn_k;   //!
   TBranch        *b_prt_pnn_p;   //!
   TBranch        *b_prt_pnn_ghost;   //!
   TBranch        *b_prt_charge;   //!
   TBranch        *b_prt_type;   //!
   TBranch        *b_prt_x;   //!
   TBranch        *b_prt_y;   //!
   TBranch        *b_prt_z;   //!
   TBranch        *b_prt_chi2;   //!
   TBranch        *b_prt_ndof;   //!
   TBranch        *b_prt_prob_chi2;   //!
   TBranch        *b_prt_clone_dist;   //!
   TBranch        *b_prt_ip;   //!
   TBranch        *b_prt_ip_chi2;   //!
   TBranch        *b_prt_x0;   //!
   TBranch        *b_prt_x1;   //!
   TBranch        *b_prt_y0;   //!
   TBranch        *b_prt_y1;   //!
   TBranch        *b_prt_z0;   //!
   TBranch        *b_prt_z1;   //!
   TBranch        *b_tag_l0_tos1;   //!
   TBranch        *b_tag_l0_tos2;   //!
   TBranch        *b_tag_l0_tos3;   //!
   TBranch        *b_tag_l0_tis;   //!
   TBranch        *b_tag_hlt1_tos4;   //!
   TBranch        *b_tag_hlt1_tos5;   //!
   TBranch        *b_tag_hlt1_tis;   //!
   TBranch        *b_tag_hlt2_tos0;
   TBranch        *b_tag_strip_dec0;   //!
   TBranch        *b_prt_iso;   //!
   TBranch        *b_calo_idx;   //!
   TBranch        *b_calo_idx_pvr;   //!
   TBranch        *b_calo_pid;   //!
   TBranch        *b_calo_px;   //!
   TBranch        *b_calo_py;   //!
   TBranch        *b_calo_pz;   //!
   TBranch        *b_calo_pt;   //!
   TBranch        *b_calo_e;   //!
   TBranch        *b_calo_eta;   //!
   TBranch        *b_calo_phi;   //!
   TBranch        *b_calo_m;   //!
   TBranch        *b_calo_cl;   //!
   TBranch        *b_calo_deposit_id;   //!
   TBranch        *b_calo_e19;   //!
   TBranch        *b_calo_e49;   //!
   TBranch        *b_calo_ecal;   //!
   TBranch        *b_calo_prs_m;   //!
   TBranch        *b_calo_prs;   //!
   TBranch        *b_calo_spd;   //!
   TBranch        *b_calo_prs_e19;   //!
   TBranch        *b_calo_prs_e49;   //!
   TBranch        *b_calo_prs_e4_max;   //!
   TBranch        *b_calo_tr_match;   //!
   TBranch        *b_calo_is_not_e;   //!
   TBranch        *b_calo_is_not_h;   //!
   TBranch        *b_calo_photon_id;   //!
   TBranch        *b_calo_shower_shape;   //!
   TBranch        *b_calo_hcal_ecal;   //!
   TBranch        *b_mergedpi0_idx;   //!
   TBranch        *b_mergedpi0_idx_pvr;   //!
   TBranch        *b_mergedpi0_pid;   //!
   TBranch        *b_mergedpi0_px;   //!
   TBranch        *b_mergedpi0_py;   //!
   TBranch        *b_mergedpi0_pz;   //!
   TBranch        *b_mergedpi0_pt;   //!
   TBranch        *b_mergedpi0_e;   //!
   TBranch        *b_mergedpi0_eta;   //!
   TBranch        *b_mergedpi0_phi;   //!
   TBranch        *b_mergedpi0_m;   //!
   TBranch        *b_mergedpi0_cl;   //!
   TBranch        *b_mergedpi0_deposit_id;   //!
   TBranch        *b_mergedpi0_e19;   //!
   TBranch        *b_mergedpi0_e49;   //!
   TBranch        *b_mergedpi0_ecal;   //!
   TBranch        *b_mergedpi0_prs_m;   //!
   TBranch        *b_mergedpi0_prs;   //!
   TBranch        *b_mergedpi0_spd;   //!
   TBranch        *b_mergedpi0_prs_e19;   //!
   TBranch        *b_mergedpi0_prs_e49;   //!
   TBranch        *b_mergedpi0_prs_e4_max;   //!
   TBranch        *b_mergedpi0_tr_match;   //!
   TBranch        *b_mergedpi0_is_not_e;   //!
   TBranch        *b_mergedpi0_is_not_h;   //!
   TBranch        *b_mergedpi0_photon_id;   //!
   TBranch        *b_mergedpi0_shower_shape;   //!
   TBranch        *b_mergedpi0_hcal_ecal;   //!
   TBranch        *b_cnv_idx;   //!
   TBranch        *b_cnv_idx_pvr;   //!
   TBranch        *b_cnv_idx_e1;   //!
   TBranch        *b_cnv_idx_e2;   //!
   TBranch        *b_cnv_pid;   //!
   TBranch        *b_cnv_px;   //!
   TBranch        *b_cnv_py;   //!
   TBranch        *b_cnv_pz;   //!
   TBranch        *b_cnv_pt;   //!
   TBranch        *b_cnv_e;   //!
   TBranch        *b_cnv_eta;   //!
   TBranch        *b_cnv_phi;   //!
   TBranch        *b_cnv_m;   //!
   TBranch        *b_cnv_dls;   //!
   TBranch        *b_cnv_ctau;   //!
   TBranch        *b_cnv_chi2;   //!
   TBranch        *b_cnv_ndof;   //!
   TBranch        *b_cnv_dira;   //!
   TBranch        *b_cnv_vrt_x;   //!
   TBranch        *b_cnv_vrt_y;   //!
   TBranch        *b_cnv_vrt_z;   //!
   TBranch        *b_cnv_ve_ns;   //!
   TBranch        *b_cnv_x;   //!
   TBranch        *b_cnv_y;   //!
   TBranch        *b_cnv_z;   //!
   TBranch        *b_cnv_dx;   //!
   TBranch        *b_cnv_dy;   //!
   TBranch        *b_cnv_dz;   //!
   TBranch        *b_e_idx;   //!
   TBranch        *b_e_idx_pvr;   //!
   TBranch        *b_e_pid;   //!
   TBranch        *b_e_pt;   //!
   TBranch        *b_e_px;   //!
   TBranch        *b_e_py;   //!
   TBranch        *b_e_pz;   //!
   TBranch        *b_e_e;   //!
   TBranch        *b_e_eta;   //!
   TBranch        *b_e_phi;   //!
   TBranch        *b_e_m;   //!
   TBranch        *b_e_pid_e;   //!
   TBranch        *b_e_pid_mu;   //!
   TBranch        *b_e_pid_k;   //!
   TBranch        *b_e_pid_p;   //!
   TBranch        *b_e_pnn_e;   //!
   TBranch        *b_e_pnn_mu;   //!
   TBranch        *b_e_pnn_pi;   //!
   TBranch        *b_e_pnn_k;   //!
   TBranch        *b_e_pnn_p;   //!
   TBranch        *b_e_pnn_ghost;   //!
   TBranch        *b_e_charge;   //!
   TBranch        *b_e_type;   //!
   TBranch        *b_e_x;   //!
   TBranch        *b_e_y;   //!
   TBranch        *b_e_z;   //!
   TBranch        *b_e_chi2;   //!
   TBranch        *b_e_ndof;   //!
   TBranch        *b_e_prob_chi2;   //!
   TBranch        *b_e_clone_dist;   //!
   TBranch        *b_e_ip;   //!
   TBranch        *b_e_ip_chi2;   //!

   TFile *f;
   TString option;

   TH1F *fM, *fM_l0_p, *fM_l0_f, *fM_hlt1_p, *fM_hlt1_f, *fM_hlt2_p, *fM_hlt2_f, *fM_kin_p, *fM_kin_f, *fM_data_consistency_p, *fM_data_consistency_f, *fM_patho_p, *fM_patho_f, *fM_hf_p, *fM_hf_f, *fM_fd_r_p, *fM_fd_r_f, *fM_material_p, *fM_material_f, *fM_pid_p, *fM_pid_f, *fM_strip_p, *fM_strip_f;
   TH1F *fM_require_calo, *fM_require_calo_at_m_eta, *fM_require_calo_at_m_eta_no_brem, *fM_tag_calo;
   TH1F *fM_calo_mu0, *fM_calo_mu1, *fangle_calo_mu0, *fangle_calo_mu1, *fDphi_calo_mu0, *fDphi_calo_mu1, *fDeta_calo_mu0, *fDeta_calo_mu1, *fDR_calo_mu0, *fDR_calo_mu1, *fcalo_cl;
   TH1F *fM_calo_mu0_m_eta, *fM_calo_mu1_m_eta, *fangle_calo_mu0_m_eta, *fangle_calo_mu1_m_eta, *fDphi_calo_mu0_m_eta, *fDphi_calo_mu1_m_eta, *fDeta_calo_mu0_m_eta, *fDeta_calo_mu1_m_eta, *fDR_calo_mu0_m_eta, *fDR_calo_mu1_m_eta, *fcalo_cl_m_eta;
   TH1F *fM_calo_mu0_not_m_eta, *fM_calo_mu1_not_m_eta, *fangle_calo_mu0_not_m_eta, *fangle_calo_mu1_not_m_eta, *fDphi_calo_mu0_not_m_eta, *fDphi_calo_mu1_not_m_eta, *fDeta_calo_mu0_not_m_eta, *fDeta_calo_mu1_not_m_eta, *fDR_calo_mu0_not_m_eta, *fDR_calo_mu1_not_m_eta, *fcalo_cl_not_m_eta;

   std::map<std::string, double> first_variables, second_variables;

   vector<Double_t> dalitz_mu0_mu1, dalitz_calo_mu0, dalitz_calo_mu1, dalitz_mu0_mu1_m_eta, dalitz_calo_mu0_m_eta, dalitz_calo_mu1_m_eta, dalitz_mu0_mu1_not_m_eta, dalitz_calo_mu0_not_m_eta, dalitz_calo_mu1_not_m_eta;

   double prt_trk_dist_mu_h, tag_d2, tag_fd_r, tag_fd, tag_p, tag_beta, tag_gamma, tag_flighttime, tag_tau_ps;
   double mu_p, mu_eta, h_p, h_eta;
   double tag_tau_ps_1, tag_tau_ps_2, tag_d2_1, tag_d2_2, tag_m_1, tag_m_2, tag_dtf_chi2_1, tag_dtf_chi2_2;


   int idx_mu, idx_h, idx_pvr;

   bool prt_bool, prt_bool_patho_srd, hf_veto, material_veto, prt_bool_no_matveto_cut;
   bool prt_bool_l0, prt_bool_hlt1, prt_bool_hlt2, prt_bool_strip, prt_bool_kin, prt_bool_data_consistency, prt_bool_patho, prt_bool_dec_topo, prt_bool_patho_mu, prt_bool_patho_h, prt_bool_material, prt_bool_hf, prt_bool_fd_r, prt_bool_pid;
   bool prt_bool_material_h_modmiss, prt_bool_material_mu_modmiss, prt_bool_material_cutFM;
   bool prt_bool_l0_1, prt_bool_hlt1_1, prt_bool_hlt2_1, prt_bool_strip_1, prt_bool_kin_1, prt_bool_data_consistency_1, prt_bool_patho_1, prt_bool_dec_topo_1, prt_bool_patho_mu_1, prt_bool_patho_h_1, prt_bool_material_1, prt_bool_hf_1, prt_bool_fd_r_1, prt_bool_pid_1;
   bool prt_bool_l0_2, prt_bool_hlt1_2, prt_bool_hlt2_2, prt_bool_strip_2, prt_bool_kin_2, prt_bool_data_consistency_2, prt_bool_patho_2, prt_bool_dec_topo_2, prt_bool_patho_mu_2, prt_bool_patho_h_2, prt_bool_material_2, prt_bool_hf_2, prt_bool_fd_r_2, prt_bool_pid_2;
   bool prt_bool_full, prt_bool_full_1, prt_bool_full_2;
   bool prt_bool_necessary_cuts, prt_bool_necessary_cuts_1, prt_bool_necessary_cuts_2;
   bool prt_bool_trigger_cuts, prt_bool_trigger_cuts_1, prt_bool_trigger_cuts_2;
   bool pass_separately;

   std::map<std::string, double>  Simple_Variables_Calculation(int mum);
   void Ap_Anal(unsigned mum);
   void Ap_Plots(unsigned mum);
   void Calo_Plots(unsigned calo, unsigned mum);
   void Plot_Dalitz_Graphs();

   Plot_hists_X2ApGm_TomsCuts(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~Plot_hists_X2ApGm_TomsCuts() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(Plot_hists_X2ApGm_TomsCuts,0);
};

#endif

#ifdef Plot_hists_X2ApGm_TomsCuts_cxx
void Plot_hists_X2ApGm_TomsCuts::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   evt_event = 0;
   evt_run = 0;
   evt_ntracks = 0;
   evt_nspd = 0;
   gens_idx = 0;
   gens_idx_mom = 0;
   gens_pid = 0;
   gens_px = 0;
   gens_py = 0;
   gens_pz = 0;
   gens_pt = 0;
   gens_e = 0;
   gens_eta = 0;
   gens_phi = 0;
   gens_m = 0;
   gens_acc = 0;
   gens_rec = 0;
   pvr_idx = 0;
   pvr_x = 0;
   pvr_y = 0;
   pvr_z = 0;
   pvr_chi2 = 0;
   pvr_ndof = 0;
   tag_idx = 0;
   tag_idx_pvr = 0;
   tag_idx_prt0 = 0;
   tag_idx_prt1 = 0;
   tag_il = 0;
   tag_iv = 0;
   tag_pid = 0;
   tag_px = 0;
   tag_py = 0;
   tag_pz = 0;
   tag_pt = 0;
   tag_e = 0;
   tag_eta = 0;
   tag_phi = 0;
   tag_m = 0;
   tag_veto_mu_modmiss = 0;
   tag_veto_h_modmiss = 0;
   tag_veto_cutFM = 0;
   tag_nu_brem_0 = 0;
   tag_nu_brem_1 = 0;
   tag_dls = 0;
   tag_ctau = 0;
   tag_dtf_chi2 = 0;
   tag_dtf_px = 0; tag_dtf_py = 0; tag_dtf_pz = 0; tag_dtf_e = 0;
   tag_dtf_m = 0;
   tag_chi2 = 0;
   tag_ndof = 0;
   tag_dira = 0;
   tag_vrt_x = 0;
   tag_vrt_y = 0;
   tag_vrt_z = 0;
   tag_ve_ns = 0;
   tag_x = 0;
   tag_y = 0;
   tag_z = 0;
   tag_dx = 0;
   tag_dy = 0;
   tag_dz = 0;
   prt_idx = 0;
   prt_idx_pvr = 0;
   prt_pid = 0;
   prt_pt = 0;
   prt_px = 0;
   prt_py = 0;
   prt_pz = 0;
   prt_e = 0;
   prt_eta = 0;
   prt_phi = 0;
   prt_m = 0;
   prt_pid_e = 0;
   prt_pid_mu = 0;
   prt_pid_k = 0;
   prt_pid_p = 0;
   prt_pnn_e = 0;
   prt_pnn_mu = 0;
   prt_pnn_pi = 0;
   prt_pnn_k = 0;
   prt_pnn_p = 0;
   prt_pnn_ghost = 0;
   prt_charge = 0;
   prt_type = 0;
   prt_x = 0;
   prt_y = 0;
   prt_z = 0;
   prt_chi2 = 0;
   prt_ndof = 0;
   prt_prob_chi2 = 0;
   prt_clone_dist = 0;
   prt_ip = 0;
   prt_ip_chi2 = 0;
   prt_x0 = 0;
   prt_x1 = 0;
   prt_y0 = 0;
   prt_y1 = 0;
   prt_z0 = 0;
   prt_z1 = 0;
   tag_l0_tos1 = 0;
   tag_l0_tos2 = 0;
   tag_l0_tos3 = 0;
   tag_l0_tis = 0;
   tag_hlt1_tos4 = 0;
   tag_hlt1_tos5 = 0;
   tag_hlt1_tis = 0;
   tag_hlt2_tos0 = 0;
   tag_strip_dec0 = 0;
   prt_iso = 0;
   calo_idx = 0;
   calo_idx_pvr = 0;
   calo_pid = 0;
   calo_px = 0;
   calo_py = 0;
   calo_pz = 0;
   calo_pt = 0;
   calo_e = 0;
   calo_eta = 0;
   calo_phi = 0;
   calo_m = 0;
   calo_cl = 0;
   calo_deposit_id = 0;
   calo_e19 = 0;
   calo_e49 = 0;
   calo_ecal = 0;
   calo_prs_m = 0;
   calo_prs = 0;
   calo_spd = 0;
   calo_prs_e19 = 0;
   calo_prs_e49 = 0;
   calo_prs_e4_max = 0;
   calo_tr_match = 0;
   calo_is_not_e = 0;
   calo_is_not_h = 0;
   calo_photon_id = 0;
   calo_shower_shape = 0;
   calo_hcal_ecal = 0;
   mergedpi0_idx = 0;
   mergedpi0_idx_pvr = 0;
   mergedpi0_pid = 0;
   mergedpi0_px = 0;
   mergedpi0_py = 0;
   mergedpi0_pz = 0;
   mergedpi0_pt = 0;
   mergedpi0_e = 0;
   mergedpi0_eta = 0;
   mergedpi0_phi = 0;
   mergedpi0_m = 0;
   mergedpi0_cl = 0;
   mergedpi0_deposit_id = 0;
   mergedpi0_e19 = 0;
   mergedpi0_e49 = 0;
   mergedpi0_ecal = 0;
   mergedpi0_prs_m = 0;
   mergedpi0_prs = 0;
   mergedpi0_spd = 0;
   mergedpi0_prs_e19 = 0;
   mergedpi0_prs_e49 = 0;
   mergedpi0_prs_e4_max = 0;
   mergedpi0_tr_match = 0;
   mergedpi0_is_not_e = 0;
   mergedpi0_is_not_h = 0;
   mergedpi0_photon_id = 0;
   mergedpi0_shower_shape = 0;
   mergedpi0_hcal_ecal = 0;
   cnv_idx = 0;
   cnv_idx_pvr = 0;
   cnv_idx_e1 = 0;
   cnv_idx_e2 = 0;
   cnv_pid = 0;
   cnv_px = 0;
   cnv_py = 0;
   cnv_pz = 0;
   cnv_pt = 0;
   cnv_e = 0;
   cnv_eta = 0;
   cnv_phi = 0;
   cnv_m = 0;
   cnv_dls = 0;
   cnv_ctau = 0;
   cnv_chi2 = 0;
   cnv_ndof = 0;
   cnv_dira = 0;
   cnv_vrt_x = 0;
   cnv_vrt_y = 0;
   cnv_vrt_z = 0;
   cnv_ve_ns = 0;
   cnv_x = 0;
   cnv_y = 0;
   cnv_z = 0;
   cnv_dx = 0;
   cnv_dy = 0;
   cnv_dz = 0;
   e_idx = 0;
   e_idx_pvr = 0;
   e_pid = 0;
   e_pt = 0;
   e_px = 0;
   e_py = 0;
   e_pz = 0;
   e_e = 0;
   e_eta = 0;
   e_phi = 0;
   e_m = 0;
   e_pid_e = 0;
   e_pid_mu = 0;
   e_pid_k = 0;
   e_pid_p = 0;
   e_pnn_e = 0;
   e_pnn_mu = 0;
   e_pnn_pi = 0;
   e_pnn_k = 0;
   e_pnn_p = 0;
   e_pnn_ghost = 0;
   e_charge = 0;
   e_type = 0;
   e_x = 0;
   e_y = 0;
   e_z = 0;
   e_chi2 = 0;
   e_ndof = 0;
   e_prob_chi2 = 0;
   e_clone_dist = 0;
   e_ip = 0;
   e_ip_chi2 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evt_event", &evt_event, &b_evt_event);
   fChain->SetBranchAddress("evt_run", &evt_run, &b_evt_run);
   fChain->SetBranchAddress("evt_ntracks", &evt_ntracks, &b_evt_ntracks);
   fChain->SetBranchAddress("evt_nspd", &evt_nspd, &b_evt_nspd);
   fChain->SetBranchAddress("gens_idx", &gens_idx, &b_gens_idx);
   fChain->SetBranchAddress("gens_idx_mom", &gens_idx_mom, &b_gens_idx_mom);
   fChain->SetBranchAddress("gens_pid", &gens_pid, &b_gens_pid);
   fChain->SetBranchAddress("gens_px", &gens_px, &b_gens_px);
   fChain->SetBranchAddress("gens_py", &gens_py, &b_gens_py);
   fChain->SetBranchAddress("gens_pz", &gens_pz, &b_gens_pz);
   fChain->SetBranchAddress("gens_pt", &gens_pt, &b_gens_pt);
   fChain->SetBranchAddress("gens_e", &gens_e, &b_gens_e);
   fChain->SetBranchAddress("gens_eta", &gens_eta, &b_gens_eta);
   fChain->SetBranchAddress("gens_phi", &gens_phi, &b_gens_phi);
   fChain->SetBranchAddress("gens_m", &gens_m, &b_gens_m);
   fChain->SetBranchAddress("gens_acc", &gens_acc, &b_gens_acc);
   fChain->SetBranchAddress("gens_rec", &gens_rec, &b_gens_rec);
   fChain->SetBranchAddress("pvr_idx", &pvr_idx, &b_pvr_idx);
   fChain->SetBranchAddress("pvr_x", &pvr_x, &b_pvr_x);
   fChain->SetBranchAddress("pvr_y", &pvr_y, &b_pvr_y);
   fChain->SetBranchAddress("pvr_z", &pvr_z, &b_pvr_z);
   fChain->SetBranchAddress("pvr_chi2", &pvr_chi2, &b_pvr_chi2);
   fChain->SetBranchAddress("pvr_ndof", &pvr_ndof, &b_pvr_ndof);
   fChain->SetBranchAddress("tag_idx", &tag_idx, &b_tag_idx);
   fChain->SetBranchAddress("tag_idx_pvr", &tag_idx_pvr, &b_tag_idx_pvr);
   fChain->SetBranchAddress("tag_idx_prt0", &tag_idx_prt0, &b_tag_idx_prt0);
   fChain->SetBranchAddress("tag_idx_prt1", &tag_idx_prt1, &b_tag_idx_prt1);
   fChain->SetBranchAddress("tag_il", &tag_il, &b_tag_il);
   fChain->SetBranchAddress("tag_iv", &tag_iv, &b_tag_iv);
   fChain->SetBranchAddress("tag_pid", &tag_pid, &b_tag_pid);
   fChain->SetBranchAddress("tag_px", &tag_px, &b_tag_px);
   fChain->SetBranchAddress("tag_py", &tag_py, &b_tag_py);
   fChain->SetBranchAddress("tag_pz", &tag_pz, &b_tag_pz);
   fChain->SetBranchAddress("tag_pt", &tag_pt, &b_tag_pt);
   fChain->SetBranchAddress("tag_e", &tag_e, &b_tag_e);
   fChain->SetBranchAddress("tag_eta", &tag_eta, &b_tag_eta);
   fChain->SetBranchAddress("tag_phi", &tag_phi, &b_tag_phi);
   fChain->SetBranchAddress("tag_m", &tag_m, &b_tag_m);
   fChain->SetBranchAddress("tag_veto_mu_modmiss", &tag_veto_mu_modmiss, &b_tag_veto_mu_modmiss);
   fChain->SetBranchAddress("tag_veto_h_modmiss", &tag_veto_h_modmiss, &b_tag_veto_h_modmiss);
   fChain->SetBranchAddress("tag_veto_cutFM", &tag_veto_cutFM, &b_tag_veto_cutFM);
   fChain->SetBranchAddress("tag_nu_brem_0", &tag_nu_brem_0, &b_tag_nu_brem_0);
   fChain->SetBranchAddress("tag_nu_brem_1", &tag_nu_brem_1, &b_tag_nu_brem_1);
   fChain->SetBranchAddress("tag_dls", &tag_dls, &b_tag_dls);
   fChain->SetBranchAddress("tag_ctau", &tag_ctau, &b_tag_ctau);
   fChain->SetBranchAddress("tag_dtf_chi2", &tag_dtf_chi2, &b_tag_dtf_chi2);
   fChain->SetBranchAddress("tag_dtf_px", &tag_dtf_px, &b_tag_dtf_px);
   fChain->SetBranchAddress("tag_dtf_py", &tag_dtf_py, &b_tag_dtf_py);
   fChain->SetBranchAddress("tag_dtf_pz", &tag_dtf_pz, &b_tag_dtf_pz);
   fChain->SetBranchAddress("tag_dtf_e", &tag_dtf_e, &b_tag_dtf_e);
   fChain->SetBranchAddress("tag_dtf_m", &tag_dtf_m, &b_tag_dtf_m);
   fChain->SetBranchAddress("tag_chi2", &tag_chi2, &b_tag_chi2);
   fChain->SetBranchAddress("tag_ndof", &tag_ndof, &b_tag_ndof);
   fChain->SetBranchAddress("tag_dira", &tag_dira, &b_tag_dira);
   fChain->SetBranchAddress("tag_vrt_x", &tag_vrt_x, &b_tag_vrt_x);
   fChain->SetBranchAddress("tag_vrt_y", &tag_vrt_y, &b_tag_vrt_y);
   fChain->SetBranchAddress("tag_vrt_z", &tag_vrt_z, &b_tag_vrt_z);
   fChain->SetBranchAddress("tag_ve_ns", &tag_ve_ns, &b_tag_ve_ns);
   fChain->SetBranchAddress("tag_x", &tag_x, &b_tag_x);
   fChain->SetBranchAddress("tag_y", &tag_y, &b_tag_y);
   fChain->SetBranchAddress("tag_z", &tag_z, &b_tag_z);
   fChain->SetBranchAddress("tag_dx", &tag_dx, &b_tag_dx);
   fChain->SetBranchAddress("tag_dy", &tag_dy, &b_tag_dy);
   fChain->SetBranchAddress("tag_dz", &tag_dz, &b_tag_dz);
   fChain->SetBranchAddress("prt_idx", &prt_idx, &b_prt_idx);
   fChain->SetBranchAddress("prt_idx_pvr", &prt_idx_pvr, &b_prt_idx_pvr);
   fChain->SetBranchAddress("prt_pid", &prt_pid, &b_prt_pid);
   fChain->SetBranchAddress("prt_pt", &prt_pt, &b_prt_pt);
   fChain->SetBranchAddress("prt_px", &prt_px, &b_prt_px);
   fChain->SetBranchAddress("prt_py", &prt_py, &b_prt_py);
   fChain->SetBranchAddress("prt_pz", &prt_pz, &b_prt_pz);
   fChain->SetBranchAddress("prt_e", &prt_e, &b_prt_e);
   fChain->SetBranchAddress("prt_eta", &prt_eta, &b_prt_eta);
   fChain->SetBranchAddress("prt_phi", &prt_phi, &b_prt_phi);
   fChain->SetBranchAddress("prt_m", &prt_m, &b_prt_m);
   fChain->SetBranchAddress("prt_pid_e", &prt_pid_e, &b_prt_pid_e);
   fChain->SetBranchAddress("prt_pid_mu", &prt_pid_mu, &b_prt_pid_mu);
   fChain->SetBranchAddress("prt_pid_k", &prt_pid_k, &b_prt_pid_k);
   fChain->SetBranchAddress("prt_pid_p", &prt_pid_p, &b_prt_pid_p);
   fChain->SetBranchAddress("prt_pnn_e", &prt_pnn_e, &b_prt_pnn_e);
   fChain->SetBranchAddress("prt_pnn_mu", &prt_pnn_mu, &b_prt_pnn_mu);
   fChain->SetBranchAddress("prt_pnn_pi", &prt_pnn_pi, &b_prt_pnn_pi);
   fChain->SetBranchAddress("prt_pnn_k", &prt_pnn_k, &b_prt_pnn_k);
   fChain->SetBranchAddress("prt_pnn_p", &prt_pnn_p, &b_prt_pnn_p);
   fChain->SetBranchAddress("prt_pnn_ghost", &prt_pnn_ghost, &b_prt_pnn_ghost);
   fChain->SetBranchAddress("prt_charge", &prt_charge, &b_prt_charge);
   fChain->SetBranchAddress("prt_type", &prt_type, &b_prt_type);
   fChain->SetBranchAddress("prt_x", &prt_x, &b_prt_x);
   fChain->SetBranchAddress("prt_y", &prt_y, &b_prt_y);
   fChain->SetBranchAddress("prt_z", &prt_z, &b_prt_z);
   fChain->SetBranchAddress("prt_chi2", &prt_chi2, &b_prt_chi2);
   fChain->SetBranchAddress("prt_ndof", &prt_ndof, &b_prt_ndof);
   fChain->SetBranchAddress("prt_prob_chi2", &prt_prob_chi2, &b_prt_prob_chi2);
   fChain->SetBranchAddress("prt_clone_dist", &prt_clone_dist, &b_prt_clone_dist);
   fChain->SetBranchAddress("prt_ip", &prt_ip, &b_prt_ip);
   fChain->SetBranchAddress("prt_ip_chi2", &prt_ip_chi2, &b_prt_ip_chi2);
   fChain->SetBranchAddress("prt_x0", &prt_x0, &b_prt_x0);
   fChain->SetBranchAddress("prt_x1", &prt_x1, &b_prt_x1);
   fChain->SetBranchAddress("prt_y0", &prt_y0, &b_prt_y0);
   fChain->SetBranchAddress("prt_y1", &prt_y1, &b_prt_y1);
   fChain->SetBranchAddress("prt_z0", &prt_z0, &b_prt_z0);
   fChain->SetBranchAddress("prt_z1", &prt_z1, &b_prt_z1);
   fChain->SetBranchAddress("tag_l0_tos1", &tag_l0_tos1, &b_tag_l0_tos1);
   fChain->SetBranchAddress("tag_l0_tos2", &tag_l0_tos2, &b_tag_l0_tos2);
   fChain->SetBranchAddress("tag_l0_tos3", &tag_l0_tos3, &b_tag_l0_tos3);
   fChain->SetBranchAddress("tag_l0_tis", &tag_l0_tis, &b_tag_l0_tis);
   fChain->SetBranchAddress("tag_hlt1_tos4", &tag_hlt1_tos4, &b_tag_hlt1_tos4);
   fChain->SetBranchAddress("tag_hlt1_tos5", &tag_hlt1_tos5, &b_tag_hlt1_tos5);
   fChain->SetBranchAddress("tag_hlt1_tis", &tag_hlt1_tis, &b_tag_hlt1_tis);
   fChain->SetBranchAddress("tag_hlt2_tos0", &tag_hlt2_tos0, &b_tag_hlt2_tos0);
   fChain->SetBranchAddress("tag_strip_dec0", &tag_strip_dec0, &b_tag_strip_dec0);
   fChain->SetBranchAddress("prt_iso", &prt_iso, &b_prt_iso);
   fChain->SetBranchAddress("calo_idx", &calo_idx, &b_calo_idx);
   fChain->SetBranchAddress("calo_idx_pvr", &calo_idx_pvr, &b_calo_idx_pvr);
   fChain->SetBranchAddress("calo_pid", &calo_pid, &b_calo_pid);
   fChain->SetBranchAddress("calo_px", &calo_px, &b_calo_px);
   fChain->SetBranchAddress("calo_py", &calo_py, &b_calo_py);
   fChain->SetBranchAddress("calo_pz", &calo_pz, &b_calo_pz);
   fChain->SetBranchAddress("calo_pt", &calo_pt, &b_calo_pt);
   fChain->SetBranchAddress("calo_e", &calo_e, &b_calo_e);
   fChain->SetBranchAddress("calo_eta", &calo_eta, &b_calo_eta);
   fChain->SetBranchAddress("calo_phi", &calo_phi, &b_calo_phi);
   fChain->SetBranchAddress("calo_m", &calo_m, &b_calo_m);
   fChain->SetBranchAddress("calo_cl", &calo_cl, &b_calo_cl);
   fChain->SetBranchAddress("calo_deposit_id", &calo_deposit_id, &b_calo_deposit_id);
   fChain->SetBranchAddress("calo_e19", &calo_e19, &b_calo_e19);
   fChain->SetBranchAddress("calo_e49", &calo_e49, &b_calo_e49);
   fChain->SetBranchAddress("calo_ecal", &calo_ecal, &b_calo_ecal);
   fChain->SetBranchAddress("calo_prs_m", &calo_prs_m, &b_calo_prs_m);
   fChain->SetBranchAddress("calo_prs", &calo_prs, &b_calo_prs);
   fChain->SetBranchAddress("calo_spd", &calo_spd, &b_calo_spd);
   fChain->SetBranchAddress("calo_prs_e19", &calo_prs_e19, &b_calo_prs_e19);
   fChain->SetBranchAddress("calo_prs_e49", &calo_prs_e49, &b_calo_prs_e49);
   fChain->SetBranchAddress("calo_prs_e4_max", &calo_prs_e4_max, &b_calo_prs_e4_max);
   fChain->SetBranchAddress("calo_tr_match", &calo_tr_match, &b_calo_tr_match);
   fChain->SetBranchAddress("calo_is_not_e", &calo_is_not_e, &b_calo_is_not_e);
   fChain->SetBranchAddress("calo_is_not_h", &calo_is_not_h, &b_calo_is_not_h);
   fChain->SetBranchAddress("calo_photon_id", &calo_photon_id, &b_calo_photon_id);
   fChain->SetBranchAddress("calo_shower_shape", &calo_shower_shape, &b_calo_shower_shape);
   fChain->SetBranchAddress("calo_hcal_ecal", &calo_hcal_ecal, &b_calo_hcal_ecal);
   //fChain->SetBranchAddress("mergedpi0_idx", &mergedpi0_idx, &b_mergedpi0_idx);
   //fChain->SetBranchAddress("mergedpi0_idx_pvr", &mergedpi0_idx_pvr, &b_mergedpi0_idx_pvr);
   //fChain->SetBranchAddress("mergedpi0_pid", &mergedpi0_pid, &b_mergedpi0_pid);
   //fChain->SetBranchAddress("mergedpi0_px", &mergedpi0_px, &b_mergedpi0_px);
   //fChain->SetBranchAddress("mergedpi0_py", &mergedpi0_py, &b_mergedpi0_py);
   //fChain->SetBranchAddress("mergedpi0_pz", &mergedpi0_pz, &b_mergedpi0_pz);
   //fChain->SetBranchAddress("mergedpi0_pt", &mergedpi0_pt, &b_mergedpi0_pt);
   //fChain->SetBranchAddress("mergedpi0_e", &mergedpi0_e, &b_mergedpi0_e);
   //fChain->SetBranchAddress("mergedpi0_eta", &mergedpi0_eta, &b_mergedpi0_eta);
   //fChain->SetBranchAddress("mergedpi0_phi", &mergedpi0_phi, &b_mergedpi0_phi);
   //fChain->SetBranchAddress("mergedpi0_m", &mergedpi0_m, &b_mergedpi0_m);
   //fChain->SetBranchAddress("mergedpi0_cl", &mergedpi0_cl, &b_mergedpi0_cl);
   //fChain->SetBranchAddress("mergedpi0_deposit_id", &mergedpi0_deposit_id, &b_mergedpi0_deposit_id);
   //fChain->SetBranchAddress("mergedpi0_e19", &mergedpi0_e19, &b_mergedpi0_e19);
   //fChain->SetBranchAddress("mergedpi0_e49", &mergedpi0_e49, &b_mergedpi0_e49);
   //fChain->SetBranchAddress("mergedpi0_ecal", &mergedpi0_ecal, &b_mergedpi0_ecal);
   //fChain->SetBranchAddress("mergedpi0_prs_m", &mergedpi0_prs_m, &b_mergedpi0_prs_m);
   //fChain->SetBranchAddress("mergedpi0_prs", &mergedpi0_prs, &b_mergedpi0_prs);
   //fChain->SetBranchAddress("mergedpi0_spd", &mergedpi0_spd, &b_mergedpi0_spd);
   //fChain->SetBranchAddress("mergedpi0_prs_e19", &mergedpi0_prs_e19, &b_mergedpi0_prs_e19);
   //fChain->SetBranchAddress("mergedpi0_prs_e49", &mergedpi0_prs_e49, &b_mergedpi0_prs_e49);
   //fChain->SetBranchAddress("mergedpi0_prs_e4_max", &mergedpi0_prs_e4_max, &b_mergedpi0_prs_e4_max);
   //fChain->SetBranchAddress("mergedpi0_tr_match", &mergedpi0_tr_match, &b_mergedpi0_tr_match);
   //fChain->SetBranchAddress("mergedpi0_is_not_e", &mergedpi0_is_not_e, &b_mergedpi0_is_not_e);
   //fChain->SetBranchAddress("mergedpi0_is_not_h", &mergedpi0_is_not_h, &b_mergedpi0_is_not_h);
   //fChain->SetBranchAddress("mergedpi0_photon_id", &mergedpi0_photon_id, &b_mergedpi0_photon_id);
   //fChain->SetBranchAddress("mergedpi0_shower_shape", &mergedpi0_shower_shape, &b_mergedpi0_shower_shape);
   //fChain->SetBranchAddress("mergedpi0_hcal_ecal", &mergedpi0_hcal_ecal, &b_mergedpi0_hcal_ecal);
   fChain->SetBranchAddress("cnv_idx", &cnv_idx, &b_cnv_idx);
   fChain->SetBranchAddress("cnv_idx_pvr", &cnv_idx_pvr, &b_cnv_idx_pvr);
   fChain->SetBranchAddress("cnv_idx_e1", &cnv_idx_e1, &b_cnv_idx_e1);
   fChain->SetBranchAddress("cnv_idx_e2", &cnv_idx_e2, &b_cnv_idx_e2);
   fChain->SetBranchAddress("cnv_pid", &cnv_pid, &b_cnv_pid);
   fChain->SetBranchAddress("cnv_px", &cnv_px, &b_cnv_px);
   fChain->SetBranchAddress("cnv_py", &cnv_py, &b_cnv_py);
   fChain->SetBranchAddress("cnv_pz", &cnv_pz, &b_cnv_pz);
   fChain->SetBranchAddress("cnv_pt", &cnv_pt, &b_cnv_pt);
   fChain->SetBranchAddress("cnv_e", &cnv_e, &b_cnv_e);
   fChain->SetBranchAddress("cnv_eta", &cnv_eta, &b_cnv_eta);
   fChain->SetBranchAddress("cnv_phi", &cnv_phi, &b_cnv_phi);
   fChain->SetBranchAddress("cnv_m", &cnv_m, &b_cnv_m);
   fChain->SetBranchAddress("cnv_dls", &cnv_dls, &b_cnv_dls);
   fChain->SetBranchAddress("cnv_ctau", &cnv_ctau, &b_cnv_ctau);
   fChain->SetBranchAddress("cnv_chi2", &cnv_chi2, &b_cnv_chi2);
   fChain->SetBranchAddress("cnv_ndof", &cnv_ndof, &b_cnv_ndof);
   fChain->SetBranchAddress("cnv_dira", &cnv_dira, &b_cnv_dira);
   fChain->SetBranchAddress("cnv_vrt_x", &cnv_vrt_x, &b_cnv_vrt_x);
   fChain->SetBranchAddress("cnv_vrt_y", &cnv_vrt_y, &b_cnv_vrt_y);
   fChain->SetBranchAddress("cnv_vrt_z", &cnv_vrt_z, &b_cnv_vrt_z);
   fChain->SetBranchAddress("cnv_ve_ns", &cnv_ve_ns, &b_cnv_ve_ns);
   fChain->SetBranchAddress("cnv_x", &cnv_x, &b_cnv_x);
   fChain->SetBranchAddress("cnv_y", &cnv_y, &b_cnv_y);
   fChain->SetBranchAddress("cnv_z", &cnv_z, &b_cnv_z);
   fChain->SetBranchAddress("cnv_dx", &cnv_dx, &b_cnv_dx);
   fChain->SetBranchAddress("cnv_dy", &cnv_dy, &b_cnv_dy);
   fChain->SetBranchAddress("cnv_dz", &cnv_dz, &b_cnv_dz);
   fChain->SetBranchAddress("e_idx", &e_idx, &b_e_idx);
   fChain->SetBranchAddress("e_idx_pvr", &e_idx_pvr, &b_e_idx_pvr);
   fChain->SetBranchAddress("e_pid", &e_pid, &b_e_pid);
   fChain->SetBranchAddress("e_pt", &e_pt, &b_e_pt);
   fChain->SetBranchAddress("e_px", &e_px, &b_e_px);
   fChain->SetBranchAddress("e_py", &e_py, &b_e_py);
   fChain->SetBranchAddress("e_pz", &e_pz, &b_e_pz);
   fChain->SetBranchAddress("e_e", &e_e, &b_e_e);
   fChain->SetBranchAddress("e_eta", &e_eta, &b_e_eta);
   fChain->SetBranchAddress("e_phi", &e_phi, &b_e_phi);
   fChain->SetBranchAddress("e_m", &e_m, &b_e_m);
   fChain->SetBranchAddress("e_pid_e", &e_pid_e, &b_e_pid_e);
   fChain->SetBranchAddress("e_pid_mu", &e_pid_mu, &b_e_pid_mu);
   fChain->SetBranchAddress("e_pid_k", &e_pid_k, &b_e_pid_k);
   fChain->SetBranchAddress("e_pid_p", &e_pid_p, &b_e_pid_p);
   fChain->SetBranchAddress("e_pnn_e", &e_pnn_e, &b_e_pnn_e);
   fChain->SetBranchAddress("e_pnn_mu", &e_pnn_mu, &b_e_pnn_mu);
   fChain->SetBranchAddress("e_pnn_pi", &e_pnn_pi, &b_e_pnn_pi);
   fChain->SetBranchAddress("e_pnn_k", &e_pnn_k, &b_e_pnn_k);
   fChain->SetBranchAddress("e_pnn_p", &e_pnn_p, &b_e_pnn_p);
   fChain->SetBranchAddress("e_pnn_ghost", &e_pnn_ghost, &b_e_pnn_ghost);
   fChain->SetBranchAddress("e_charge", &e_charge, &b_e_charge);
   fChain->SetBranchAddress("e_type", &e_type, &b_e_type);
   fChain->SetBranchAddress("e_x", &e_x, &b_e_x);
   fChain->SetBranchAddress("e_y", &e_y, &b_e_y);
   fChain->SetBranchAddress("e_z", &e_z, &b_e_z);
   fChain->SetBranchAddress("e_chi2", &e_chi2, &b_e_chi2);
   fChain->SetBranchAddress("e_ndof", &e_ndof, &b_e_ndof);
   fChain->SetBranchAddress("e_prob_chi2", &e_prob_chi2, &b_e_prob_chi2);
   fChain->SetBranchAddress("e_clone_dist", &e_clone_dist, &b_e_clone_dist);
   fChain->SetBranchAddress("e_ip", &e_ip, &b_e_ip);
   fChain->SetBranchAddress("e_ip_chi2", &e_ip_chi2, &b_e_ip_chi2);
}

Bool_t Plot_hists_X2ApGm_TomsCuts::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef Plot_hists_X2ApGm_TomsCuts_cxx
