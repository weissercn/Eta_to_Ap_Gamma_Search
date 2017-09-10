#define Plot_hists_RHNu_cxx
// The class definition in Plot_hists_RHNu.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("Plot_hists_RHNu.C")
// root> T->Process("Plot_hists_RHNu.C","some options")
// root> T->Process("Plot_hists_RHNu.C+")
//

#include "Plot_hists_RHNu.h"
#include <TH2.h>
#include <TStyle.h>
#include <stdlib.h>
#include <math.h>




void Plot_hists_RHNu::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   option = GetOption();

}

void Plot_hists_RHNu::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   option = GetOption();

   std::cout << "Plot_hists_RHNu The option is : " << option << std::endl;

   f = 0;
   if (option == "Di"){f = new TFile("NTuple_RHNu_all_files_plots_DiRHNu.root","RECREATE");}
   else if (option == "All"){f = new TFile("NTuple_RHNu_all_files_plots.root","RECREATE");}
   else if (option == "Test"){f = new TFile("NTuple_RHNu_all_files_plots_test.root","RECREATE");}
   else{ std::cout << std::endl << std::endl << "NO VALID OPTION" << std::endl << std::endl;}

   //f = new TFile("NTuple_RHNu_all_files_plots_M1M2_equalcuts.root","RECREATE");
   //f = new TFile("NTuple_RHNu_all_files_plots.root","RECREATE");
   //f = new TFile("NTuple_RHNu_all_files_plots_small.root","RECREATE");
   pass_separately =false;
   //f = new TFile("NTuple_RHNu_all_files_plots_pass_separately.root","RECREATE");
   //pass_separately = true;

   n_nn = 0; n_yn = 0; n_ny = 0; n_yy = 0;

   n_accepted =0; n_more_than_1_cand =0;


   int nmbins(1000);
   double m_min(200.), m_max(500000.);
   double diff_ln = (log(m_max) - log(m_min))/float(nmbins);
   //std::cout << diff_ln << std::endl;
   int asjdsk; //This needs to be here for some really bizare reason; any type any name
   double mbins[nmbins+1];
   double placeholder;

   for (int counter = 0; counter <nmbins+1 ; counter++){
      placeholder = m_min * exp(counter * diff_ln);
      //std::cout << placeholder << std::endl;
      mbins[counter] = placeholder;
    }

    int nm2bins(1000);
    double m2_min(200.), m2_max(500000.);
    double diff_ln2 = (log(m2_max) - log(m2_min))/float(nm2bins);
    //std::cout << diff_ln2 << std::endl;
    //int asjdsk2; //This needs to be here for some really bizare reason; any type any name
    double m2bins[nm2bins+1];
    double placeholder2;

    for (int counter2 = 0; counter2 <nm2bins+1 ; counter2++){
       placeholder2 = m2_min * exp(counter2 * diff_ln2);
       //std::cout << placeholder2 << std::endl;
       m2bins[counter2] = placeholder2;
     }

     int ntbins(1000);
     double t_min(0), t_max(100);
     double diff = (t_max - t_min)/float(ntbins);
     double tbins[ntbins+1];

     for (int counter = 0; counter <ntbins+1 ; counter++){
        placeholder = t_min + counter * diff;
        //std::cout << placeholder << std::endl;
        tbins[counter] = placeholder;
      }


  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////




   fmu_pnnmu = new TH1F("mu_pnnmu", "RHNu -> #mu h;ProbNNmu mu;TEvts", 100, 0., 1.);
   fh_pnnmu  = new TH1F("h_pnnmu",  "RHNu -> #mu h;ProbNNmu h; TEvts", 100, 0., 1.);
   fh_pnnk  = new TH1F("h_pnnk",  "RHNu -> #mu h;ProbNNk h; TEvts", 100, 0., 1.);
   fh_pnnpi  = new TH1F("h_pnnpi",  "RHNu -> #mu h;ProbNNpi h; TEvts", 100, 0., 1.);
   fmu_isMuon  = new TH1F("mu_isMuon",  "RHNu -> #mu h;isMuon mu; TEvts", 100, -0.1, 1.1);
   fh_isMuon  = new TH1F("h_isMuon",  "RHNu -> #mu h;isMuon h; TEvts", 100, -0.1, 1.1);

   fzx = new TH2F("zx", "RHNu -> #mu h;z [mm];x [mm]", 1000, -200., 800., 40, -20., 20.);

   fd2 = new TH1F("d2", "d2;#Delta x-y first hits [mm];TEvts", 100, 0., 10.);
   fd2_no_matveto_cut = new TH1F("d2_no_matveto_cut", "RHNu -> #mu h No Mat Veto;#Delta x-y first hits [mm];TEvts", 100, 0., 10.);
   fdmat = new TH1F("dmat", "dmat;Material distance;TEvts", 200, 0., 4.);
   fdmat_rescaled = new TH1F("dmat_rescaled", "dmat_rescaled;Material distance;TEvts", 200, 0., 4.);
   fdmat_rescaled_I = new TH1F("dmat_rescaled_I", "dmat_rescaled_I;Material distance;TEvts", 200, 0., 4.);
   fdmat_rescaled_II = new TH1F("dmat_rescaled_II", "dmat_rescaled_II;Material distance;TEvts", 200, 0., 4.);
   fdmat_rescaled_III = new TH1F("dmat_rescaled_III", "dmat_rescaled_III;Material distance;TEvts", 200, 0., 4.);
   fxxx = new TH1F("xxx", "RHNu -> #mu h ; #Delta x-y / pitch distance;TEvts", 200, 0., 10.);


   ffd_r = new TH1F("fd_r", "fd_r ;SV radial flight distance [mm];TEvts", 200, 0., 40.);
   ffd_r_I = new TH1F("fd_r_I", "fd_r_I ;SV radial flight distance [mm];TEvts", 200, 0., 40.);
   ffd_r_II = new TH1F("fd_r_II", "fd_r_II ;SV radial flight distance [mm];TEvts", 200, 0., 40.);
   ffd_r_III = new TH1F("fd_r_III", "fd_r_III ;SV radial flight distance [mm];TEvts", 200, 0., 40.);
   ffd_r_IV = new TH1F("fd_r_IV", "fd_r_IV ;SV radial flight distance [mm];TEvts", 200, 0., 40.);

   fiv_hf = new TH1F("iv_hf", "RHNu -> #mu h tau < 2ps;B_s to #mu #mu isolation Velo;TEvts", 200, -1., 1.);
   fiv_sig = new TH1F("iv_sig", "RHNu -> #mu h tau > 2ps;B_s to #mu #mu isolation Velo;TEvts", 200, -1., 1.);
   fil_hf = new TH1F("il_hf", "RHNu -> #mu h tau < 2ps;B_s to #mu #mu isolation Long;TEvts", 200, -1., 1.);
   fil_sig = new TH1F("il_sig", "RHNu -> #mu h tau > 2ps;B_s to #mu #mu isolation Long;TEvts", 200, -1., 1.);

   fQ = new TH1F("Q", "RHNu -> #mu h;Q [MeV];TEvts", 20, 0., 200.);


   //histograms for stages. p is pass f is fail
   fM = new TH1F("M", "M;RHNu M [MeV];TEvts", nmbins, mbins);
   fM_l0_p = new TH1F("M_l0_p", "M_l0_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_l0_f = new TH1F("M_l0_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_hlt1_p = new TH1F("M_hlt1_p", "M_hlt1_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_hlt1_f = new TH1F("M_hlt1_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_hlt2_p = new TH1F("M_hlt2_p", "M_hlt2_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_hlt2_f = new TH1F("M_hlt2_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_kin_p = new TH1F("M_kin_p", "M_kin_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_kin_f = new TH1F("M_kin_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_data_consistency_p = new TH1F("M_data_consistency_p", "M_data_consistency_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_data_consistency_f = new TH1F("M_data_consistency_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_patho_p = new TH1F("M_patho_p", "M_patho_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_patho_f = new TH1F("M_patho_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_hf_p = new TH1F("M_hf_p", "M_hf_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_hf_f = new TH1F("M_hf_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_fd_r_p = new TH1F("M_fd_r_p", "M_fd_r_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_fd_r_f = new TH1F("M_fd_r_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_material_p = new TH1F("M_material_p", "M_material_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_material_f = new TH1F("M_material_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_pid_p = new TH1F("M_pid_p", "M_pid_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_pid_f = new TH1F("M_pid_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_strip_p  = new TH1F("M_strip_p", "M_strip_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_strip_f  = new TH1F("M_strip_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);

   fM_trigger_cuts = new TH1F("M_trigger_cuts", "M_trigger_cuts;RHNu M [MeV];TEvts", nmbins, mbins);
   fM_necessary_cuts = new TH1F("M_necessary_cuts", "M_necessary_cuts;RHNu M [MeV];TEvts", nmbins, mbins);
   fM_necessary_and_material_cuts = new TH1F("M_necessary_and_material_cuts", "M_necessary_and_material_cuts;RHNu M [MeV];TEvts", nmbins, mbins);
   fM_necessary_and_hf_cuts = new TH1F("M_necessary_and_hf_cuts", "M_necessary_and_hf_cuts;RHNu M [MeV];TEvts", nmbins, mbins);
   fM_necessary_and_hf_and_material_cuts = new TH1F("M_necessary_and_hf_and_material_cuts", "M_necessary_and_hf_and_material_cuts;RHNu M [MeV];TEvts", nmbins, mbins);

   fM_pid_I_p = new TH1F("M_pid_I_p", "M_pid_I_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_pid_II_p = new TH1F("M_pid_II_p", "M_pid_II_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_pid_III_p = new TH1F("M_pid_III_p", "M_pid_III_p;RHNu M [MeV];Evts", nmbins, mbins);
   fM_pid_IV_p = new TH1F("M_pid_IV_p", "M_pid_IV_p;RHNu M [MeV];Evts", nmbins, mbins);

   fM_material_h_modmiss_p = new TH1F("M_material_h_modmiss_p", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_material_h_modmiss_f = new TH1F("M_material_h_modmiss_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_material_mu_modmiss_p = new TH1F("M_material_mu_modmiss_p", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_material_mu_modmiss_f = new TH1F("M_material_mu_modmiss_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_material_cutFM_p = new TH1F("M_material_cutFM_p", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);
   fM_material_cutFM_f = new TH1F("M_material_cutFM_f", "RHNu -> #mu h;RHNu M [MeV];Evts", nmbins, mbins);


   fMT = new TH2F("MT", "MT;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_l0_p = new TH2F("MT_l0_p", "MT_l0_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_l0_f = new TH2F("MT_l0_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_hlt1_p = new TH2F("MT_hlt1_p", "MT_hlt1_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_hlt1_f = new TH2F("MT_hlt1_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_hlt2_p = new TH2F("MT_hlt2_p", "MT_hlt2_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_hlt2_f = new TH2F("MT_hlt2_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_kin_p = new TH2F("MT_kin_p", "MT_kin_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_kin_f = new TH2F("MT_kin_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_data_consistency_p = new TH2F("MT_data_consistency_p", "MT_data_consistency_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_data_consistency_f = new TH2F("MT_data_consistency_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_patho_p = new TH2F("MT_patho_p", "MT_patho_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_patho_f = new TH2F("MT_patho_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_hf_p = new TH2F("MT_hf_p", "MT_hf_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_hf_f = new TH2F("MT_hf_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_fd_r_p = new TH2F("MT_fd_r_p", "MT_fd_r_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_fd_r_f = new TH2F("MT_fd_r_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_material_p = new TH2F("MT_material_p", "MT_material_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_material_f = new TH2F("MT_material_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_pid_p = new TH2F("MT_pid_p", "MT_pid_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_pid_f = new TH2F("MT_pid_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_strip_p  = new TH2F("MT_strip_p", "MT_strip_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_strip_f  = new TH2F("MT_strip_f", "RHNu -> #mu h;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);

   fMT_pid_I_p = new TH2F("MT_pid_I_p", "MT_pid_I_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_pid_II_p = new TH2F("MT_pid_II_p", "MT_pid_II_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_pid_III_p = new TH2F("MT_pid_III_p", "MT_pid_III_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);
   fMT_pid_IV_p = new TH2F("MT_pid_IV_p", "MT_pid_IV_p;RHNu M [MeV];Decay Time [ps]", nm2bins, m2bins, ntbins, tbins);


   int nm3bins(1000);
   double m3_min(200.), m3_max(500000.);
   double diff_ln3 = (log(m3_max) - log(m3_min))/float(nm3bins);
   //std::cout << diff_ln2 << std::endl;
   //int asjdsk2; //This needs to be here for some really bizare reason; any type any name
   double m3bins[nm3bins+1];
   double placeholder3;

   for (int counter3 = 0; counter3 <nm3bins+1 ; counter3++){
      placeholder3 = m3_min * exp(counter3 * diff_ln3);
      //std::cout << placeholder2 << std::endl;
      m3bins[counter3] = placeholder3;
    }



   fM1M2 = new TH2F("M1M2", "M1M2;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_tau_1to2 = new TH2F("M1M2_tau_1to2", "M1M2_tau_1to2;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_tau_2to5 = new TH2F("M1M2_tau_2to5", "M1M2_tau_2to5;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_tau_5to10 = new TH2F("M1M2_tau_5to10", "M1M2_tau_5to10;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_dtf_chi2_0to2 = new TH2F("M1M2_dtf_chi2_0to2", "M1M2_dtf_chi2_0to2;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_dtf_chi2_2to5 = new TH2F("M1M2_dtf_chi2_2to5", "M1M2_dtf_chi2_2to5;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_dtf_chi2_5to8 = new TH2F("M1M2_dtf_chi2_5to8", "M1M2_dtf_chi2_5to8;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);

   fM1M2_trigger_cuts = new TH2F("M1M2_trigger_cuts", "M1M2_trigger_cuts;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_necessary_cuts = new TH2F("M1M2_necessary_cuts", "M1M2_necessary_cuts;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_necessary_and_hf_cuts = new TH2F("M1M2_necessary_and_hf_cuts", "M1M2_necessary_and_hf_cuts;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_necessary_and_material_cuts = new TH2F("M1M2_necessary_and_material_cuts", "M1M2_necessary_and_material_cuts;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_necessary_and_hf_and_material_cuts = new TH2F("M1M2_necessary_and_hf_and_material_cuts", "M1M2_necessary_and_hf_and_material_cuts;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);



   fM1M2_l0 = new TH2F("M1M2_l0", "M1M2_l0;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_hlt1 = new TH2F("M1M2_hlt1", "M1M2_hlt1;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_hlt2 = new TH2F("M1M2_hlt2", "M1M2_hlt2;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_strip = new TH2F("M1M2_strip", "M1M2_strip;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_kin = new TH2F("M1M2_kin", "M1M2_kin;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_data_consistency = new TH2F("M1M2_data_consistency", "M1M2_data_consistency;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_patho = new TH2F("M1M2_patho", "M1M2_patho;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_material = new TH2F("M1M2_material", "M1M2_material;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_hf = new TH2F("M1M2_hf", "M1M2_hf;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_fd_r = new TH2F("M1M2_fd_r", "M1M2_fd_r;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);
   fM1M2_pid = new TH2F("M1M2_pid", "M1M2_pid;RHNu M 1 [MeV];RHNu M 2 [MeV]", nm3bins, m3bins, nm3bins, m3bins);

   fMdmat_necessary_cuts = new TH2F("Mdmat_necessary_cuts", "Mdmat_necessary_cuts;RHNu M [MeV];Material distance", nmbins, mbins, 200, 0., 4.);
   fMdmat_rescaled_necessary_cuts = new TH2F("Mdmat_rescaled_necessary_cuts", "Mdmat_rescaled_necessary_cuts;RHNu M [MeV];Material distance", nmbins, mbins, 200, 0., 4.);
   fMdmat_necessary_cuts_diRHNu = new TH2F("Mdmat_necessary_cuts_diRHNu", "Mdmat_necessary_cuts_diRHNu;RHNu M [MeV];Material distance", nmbins, mbins, 200, 0., 4.);
   fMdmat_rescaled_necessary_cuts_diRHNu = new TH2F("Mdmat_rescaled_necessary_cuts_diRHNu", "Mdmat_rescaled_necessary_cuts_diRHNu;RHNu M [MeV];Material distance", nmbins, mbins, 200, 0., 4.);

   fM_il_necessary_cuts = new TH2F("M_il_necessary_cuts", "M_il_necessary_cuts;RHNu M [MeV];B_s to mu mu isolation long", nmbins, mbins, 200, -1., 1.);
   fM_iv_necessary_cuts = new TH2F("M_iv_necessary_cuts", "M_iv_necessary_cuts;RHNu M [MeV];B_s to mu mu isolation velo", nmbins, mbins, 200, -1., 1.);
   fM_il_necessary_cuts_diRHNu = new TH2F("M_il_necessary_cuts_diRHNu", "M_il_necessary_cuts_diRHNu;RHNu M [MeV];B_s to mu mu isolation long", nmbins, mbins, 200, -1., 1.);
   fM_iv_necessary_cuts_diRHNu = new TH2F("M_iv_necessary_cuts_diRHNu", "M_iv_necessary_cuts_diRHNu;RHNu M [MeV];B_s to mu mu isolation velo", nmbins, mbins, 200, -1., 1.);


   reject_l0 = reject_hlt1 = reject_hlt2 = reject_kin = reject_dec_topo = reject_patho = reject_hf = reject_material = reject_pid = 0;
   n_candidates_orig = 0;

   int nm4bins(1000);
   double m4_min(200.), m4_max(1000000.);
   double diff_ln4 = (log(m4_max) - log(m4_min))/float(nm4bins);
   //std::cout << diff_ln2 << std::endl;
   //int asjdsk2; //This needs to be here for some really bizare reason; any type any name
   double m4bins[nm4bins+1];
   double placeholder4;

   for (int counter4 = 0; counter4 <nm4bins+1 ; counter4++){
      placeholder4 = m4_min * exp(counter4 * diff_ln4);
      //std::cout << placeholder2 << std::endl;
      m4bins[counter4] = placeholder4;
    }

   fM2nMavg = new TH2F("M2nMavg", "M2nMavg;M A' [MeV];Average M RHNu [MeV]", nm4bins, m4bins, nm2bins, m2bins);



}

Bool_t Plot_hists_RHNu::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Plot_hists_RHNu::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   GetEntry(entry);  // load event
   //if (entry <100000) {GetEntry(entry); } // load event


   if (entry %10000 ==0) {
     std::cout << "entry : " << entry/1000 << " k\ttag_m size :" << tag_m->size() << "\t" << evt_n << std::endl;
   }

   //int counter(0);



   for (unsigned mum=0; mum < tag_m->size(); mum++) {
     //When only one right handed neutrino is needed
     this->SingleRHNu_Plots(mum);
   }

   if (tag_m->size() > 1) {
     n_more_than_1_cand += 1;
     //When two right handed neutrinos pointing to the same primary vertex are needed


     for (unsigned first_id_test=0; first_id_test < tag_m->size()-1; first_id_test++){
       // THIS LOOKS AT ALL POSSIBLE RHNu COMBINATIONS ORIGINATING FROM THE SAME PV. In rare cases can have double counting
       for (unsigned second_id_test=first_id_test+1; second_id_test < tag_m->size(); second_id_test++){
         idx_mu_1  = tag_idx_prt0->at(first_id_test);
         idx_h_1   = tag_idx_prt1->at(first_id_test);
         idx_mu_2  = tag_idx_prt0->at(second_id_test);
         idx_h_2   = tag_idx_prt1->at(second_id_test);
         if (tag_idx_pvr->at(first_id_test)==tag_idx_pvr->at(second_id_test)) {
           if ((prt_isDiRHNu->at(idx_mu_1) == 1) && (prt_isDiRHNu->at(idx_mu_2) == 1) ) {
             this->DiRHNu_Plots(first_id_test, second_id_test);
           }
         }

         n_nn +=1;
         if ((prt_isDiRHNu->at(idx_mu_1) == 1) && (prt_isDiRHNu->at(idx_mu_2) == 1) ) { n_yn +=1;}
         if (tag_idx_pvr->at(first_id_test)==tag_idx_pvr->at(second_id_test)) { n_ny +=1; if ((prt_isDiRHNu->at(idx_mu_1) == 1) && (prt_isDiRHNu->at(idx_mu_2) == 1) ) {n_yy +=1;}}
       }
     }


     //std::pair<int, int> DiRHNu_indices = this->Find_DiRHNu_Indices();
     //if (DiRHNu_indices.first != -1){this->DiRHNu_Plots(DiRHNu_indices.first, DiRHNu_indices.second);}

   }

   return kTRUE;
}


void Plot_hists_RHNu::DiRHNu_Plots(unsigned first_id_test, unsigned second_id_test)
{
  //std::cout << "Combination " << first_id_test << " , " << second_id_test << endl;
  first_variables = this->Simple_Variables_Calculation(first_id_test);
  second_variables = this->Simple_Variables_Calculation(second_id_test);
  DiRHNu_variables = this->DiRHNu_Variables_Calculation(first_id_test, second_id_test);


  prt_bool_full_1     = bool(first_variables[std::string("prt_bool_full")]);
  tag_tau_ps_1        = first_variables[std::string("tag_tau_ps")];
  tag_d2_1            = first_variables[std::string("tag_d2")];
  prt_bool_l0_1       = bool(first_variables[std::string("prt_bool_l0")]);
  prt_bool_hlt1_1     = bool(first_variables[std::string("prt_bool_hlt1")]);
  prt_bool_hlt2_1     = bool(first_variables[std::string("prt_bool_hlt2")]);
  prt_bool_strip_1    = bool(first_variables[std::string("prt_bool_strip")]);
  prt_bool_kin_1      = bool(first_variables[std::string("prt_bool_kin")]);
  prt_bool_data_consistency_1       = bool(first_variables[std::string("prt_bool_data_consistency")]);
  prt_bool_patho_1    = bool(first_variables[std::string("prt_bool_patho")]);
  prt_bool_material_1 = bool(first_variables[std::string("prt_bool_material")]);
  prt_bool_hf_1       = bool(first_variables[std::string("prt_bool_hf")]);
  prt_bool_fd_r_1     = bool(first_variables[std::string("prt_bool_fd_r")]);
  prt_bool_pid_1      = bool(first_variables[std::string("prt_bool_pid")]);

  prt_bool_trigger_cuts_1        = bool(first_variables[std::string("prt_bool_trigger_cuts")]);
  prt_bool_necessary_cuts_1      = bool(first_variables[std::string("prt_bool_necessary_cuts")]);

  prt_bool_full_2     = bool(second_variables[std::string("prt_bool_full")]);
  tag_tau_ps_2        = second_variables[std::string("tag_tau_ps")];
  tag_d2_2            = second_variables[std::string("tag_d2")];
  prt_bool_l0_2       = bool(second_variables[std::string("prt_bool_l0")]);
  prt_bool_hlt1_2     = bool(second_variables[std::string("prt_bool_hlt1")]);
  prt_bool_hlt2_2     = bool(second_variables[std::string("prt_bool_hlt2")]);
  prt_bool_strip_2    = bool(second_variables[std::string("prt_bool_strip")]);
  prt_bool_kin_2      = bool(second_variables[std::string("prt_bool_kin")]);
  prt_bool_data_consistency_2       = bool(second_variables[std::string("prt_bool_data_consistency")]);
  prt_bool_patho_2    = bool(second_variables[std::string("prt_bool_patho")]);
  prt_bool_material_2 = bool(second_variables[std::string("prt_bool_material")]);
  prt_bool_hf_2       = bool(second_variables[std::string("prt_bool_hf")]);
  prt_bool_fd_r_2     = bool(second_variables[std::string("prt_bool_fd_r")]);
  prt_bool_pid_2      = bool(second_variables[std::string("prt_bool_pid")]);

  prt_bool_trigger_cuts_2        = bool(second_variables[std::string("prt_bool_trigger_cuts")]);
  prt_bool_necessary_cuts_2      = bool(second_variables[std::string("prt_bool_necessary_cuts")]);

  //tag_m_1       = tag_m->at(first_id_test);
  //tag_m_2       = tag_m->at(second_id_test);
  tag_m_1       = tag_dtf_m->at(first_id_test);
  tag_m_2       = tag_dtf_m->at(second_id_test);



  m_diff       = tag_dtf_m->at(second_id_test) - tag_dtf_m->at(first_id_test);
  delta_m_diff = sqrt(pow(tag_dtf_dm->at(first_id_test),2.0) + pow(tag_dtf_dm->at(second_id_test),2.0));
  sig_m_diff   = abs(m_diff) / delta_m_diff;
  m_avg       = (tag_dtf_m->at(first_id_test) + tag_dtf_m->at(second_id_test))/2.; // Average mass of RHNu

  // Mass of DIRHNu
  m_2N  = sqrt(pow(tag_e->at(first_id_test) + tag_e->at(second_id_test), 2.) - pow(tag_px->at(first_id_test) + tag_px->at(second_id_test), 2.) - pow(tag_py->at(first_id_test) + tag_py->at(second_id_test), 2.) - pow(tag_pz->at(first_id_test) + tag_pz->at(second_id_test), 2.));

  Q = m_2N - tag_m_1 - tag_m_2;

  if (prt_bool_necessary_cuts_1 && prt_bool_necessary_cuts_2){
    fMdmat_necessary_cuts_diRHNu->Fill(tag_m_1,tag_dmat->at(first_id_test));
    fMdmat_necessary_cuts_diRHNu->Fill(tag_m_2,tag_dmat->at(second_id_test));

    if (tag_dmat_isRescaled->at(first_id_test) && tag_dmat_isRescaled->at(second_id_test)){
      fMdmat_rescaled_necessary_cuts_diRHNu->Fill(tag_m_1,tag_dmat->at(first_id_test));
      fMdmat_rescaled_necessary_cuts_diRHNu->Fill(tag_m_2,tag_dmat->at(second_id_test));
    }

    fM_il_necessary_cuts_diRHNu->Fill(tag_m_1,tag_il->at(first_id_test));
    fM_il_necessary_cuts_diRHNu->Fill(tag_m_2,tag_il->at(second_id_test));

    fM_iv_necessary_cuts_diRHNu->Fill(tag_m_1,tag_iv->at(first_id_test));
    fM_iv_necessary_cuts_diRHNu->Fill(tag_m_2,tag_iv->at(second_id_test));

  }






  if (prt_bool_full_1 && prt_bool_full_2){
    fM1M2->Fill(tag_m_1,tag_m_2);
    //Atom: Use Cmd+Shift+L to edit multiple lines
    //if (tag_tau_ps_1 > 1 && tag_tau_ps_1 < 2){fM1M2_tau_1to2->Fill(tag_m_1,tag_m_2);}
    //if (tag_tau_ps_1 > 2 && tag_tau_ps_1 < 5){fM1M2_tau_2to5->Fill(tag_m_1,tag_m_2);}
    //if (tag_tau_ps_1 > 5 && tag_tau_ps_1 < 10){fM1M2_tau_5to10->Fill(tag_m_1,tag_m_2);}
    //if (tag_dtf_chi2_1 > 0 && tag_dtf_chi2_1 < 2){fM1M2_dtf_chi2_0to2->Fill(tag_m_1,tag_m_2);}
    //if (tag_dtf_chi2_1 > 2 && tag_dtf_chi2_1 < 5){fM1M2_dtf_chi2_2to5->Fill(tag_m_1,tag_m_2);}
    //if (tag_dtf_chi2_1 > 5 && tag_dtf_chi2_1 < 8){fM1M2_dtf_chi2_5to8->Fill(tag_m_1,tag_m_2);}

    if (tag_tau_ps_1 > 1 && tag_tau_ps_1 < 2 && tag_tau_ps_2 > 1 && tag_tau_ps_2 < 2){fM1M2_tau_1to2->Fill(tag_m_1,tag_m_2);}
    if (tag_tau_ps_1 > 2 && tag_tau_ps_1 < 5 && tag_tau_ps_2 > 2 && tag_tau_ps_2 < 5){fM1M2_tau_2to5->Fill(tag_m_1,tag_m_2);}
    if (tag_tau_ps_1 > 5 && tag_tau_ps_1 < 10 && tag_tau_ps_2 > 5 && tag_tau_ps_2 < 10){fM1M2_tau_5to10->Fill(tag_m_1,tag_m_2);}
    if (tag_dtf_chi2_1 > 0 && tag_dtf_chi2_1 < 2 && tag_dtf_chi2_2 > 0 && tag_dtf_chi2_2 < 2){fM1M2_dtf_chi2_0to2->Fill(tag_m_1,tag_m_2);}
    if (tag_dtf_chi2_1 > 2 && tag_dtf_chi2_1 < 5 && tag_dtf_chi2_2 > 2 && tag_dtf_chi2_2 < 5){fM1M2_dtf_chi2_2to5->Fill(tag_m_1,tag_m_2);}
    if (tag_dtf_chi2_1 > 5 && tag_dtf_chi2_1 < 8 && tag_dtf_chi2_2 > 5 && tag_dtf_chi2_2 < 8){fM1M2_dtf_chi2_5to8->Fill(tag_m_1,tag_m_2);}

    fQ->Fill(Q);

    if (sig_m_diff < 5){ //if the RHNu masses are similar
      fM2nMavg->Fill(m_2N, m_avg);

    }


  }

  if (prt_bool_trigger_cuts_1 && prt_bool_trigger_cuts_2){  fM1M2_trigger_cuts->Fill(tag_m_1,tag_m_2); }
  //if (prt_bool_necessary_cuts_1 && prt_bool_necessary_cuts_2){  fM1M2_necessary_cuts->Fill(tag_m_1,tag_m_2); }
  if (prt_bool_necessary_cuts_1 && prt_bool_necessary_cuts_2){  fM1M2_necessary_cuts->Fill(tag_m_1,tag_m_2); }
  if (prt_bool_necessary_cuts_1 && prt_bool_necessary_cuts_2 && prt_bool_hf_1 && prt_bool_hf_2){  fM1M2_necessary_and_hf_cuts->Fill(tag_m_1,tag_m_2); }
  if (prt_bool_necessary_cuts_1 && prt_bool_necessary_cuts_2 && prt_bool_material_1 && prt_bool_material_2){  fM1M2_necessary_and_material_cuts->Fill(tag_m_1,tag_m_2); }
  if (prt_bool_necessary_cuts_1 && prt_bool_necessary_cuts_2 && prt_bool_hf_1 && prt_bool_hf_2 && prt_bool_material_1 && prt_bool_material_2){  fM1M2_necessary_and_hf_and_material_cuts->Fill(tag_m_1,tag_m_2); }

  prt_bool            = true;

  if (prt_bool){ if (prt_bool_l0_1 && prt_bool_l0_2){ fM1M2_l0->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_l0_1 && prt_bool_l0_2;}

  if (prt_bool){ if (prt_bool_hlt1_1 && prt_bool_hlt1_2){ fM1M2_hlt1->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_hlt1_1 && prt_bool_hlt1_2;}

  if (prt_bool){ if (prt_bool_hlt2_1 && prt_bool_hlt2_2){ fM1M2_hlt2->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_hlt2_1 && prt_bool_hlt2_2;}

  if (prt_bool){ if (prt_bool_strip_1 && prt_bool_strip_2){ fM1M2_strip->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_strip_1 && prt_bool_strip_2;}

  if (prt_bool){ if (prt_bool_kin_1 && prt_bool_kin_2){ fM1M2_kin->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_kin_1 && prt_bool_kin_2;}

  if (prt_bool){ if (prt_bool_data_consistency_1 && prt_bool_data_consistency_2){ fM1M2_data_consistency->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_data_consistency_1 && prt_bool_data_consistency_2;}

  if (prt_bool){ if (prt_bool_patho_1 && prt_bool_patho_2){ fM1M2_patho->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_patho_1 && prt_bool_patho_2;}

  if (prt_bool){ if (prt_bool_material_1 && prt_bool_material_2){ fM1M2_material->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_material_1 && prt_bool_material_2;}

  if (prt_bool){ if (prt_bool_hf_1 && prt_bool_hf_2){ fM1M2_hf->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_hf_1 && prt_bool_hf_2;}

  if (prt_bool){ if (prt_bool_fd_r_1 && prt_bool_fd_r_2){ fM1M2_fd_r->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_fd_r_1 && prt_bool_fd_r_2;}

  if (prt_bool){ if (prt_bool_pid_1 && prt_bool_pid_2){ fM1M2_pid->Fill(tag_m_1,tag_m_2); } }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_pid_1 && prt_bool_pid_2;}


}


std::map<std::string, double>  Plot_hists_RHNu::Simple_Variables_Calculation(int mum)
{

  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////   C U T S   ///////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  idx_mu  = tag_idx_prt0->at(mum);
  idx_h   = tag_idx_prt1->at(mum);
  idx_pvr = tag_idx_pvr->at(mum);

  // ->at(idx_mu)
  // ->at(idx_h)
  // ->at(idx_pvr)

  tag_p   = sqrt(pow(tag_px->at(mum), 2.0)+pow(tag_py->at(mum), 2.0)+pow(tag_pz->at(mum), 2.0));
  tag_pt  = sqrt(pow(tag_px->at(mum), 2.0)+pow(tag_py->at(mum), 2.0));
  tag_beta = 1./sqrt(1.+pow(tag_m->at(mum),2.0)/pow(tag_p,2.0));
  tag_gamma = 1./sqrt(1.-pow(tag_beta,2.0));
  tag_eta = atanh(tag_pz->at(mum)/tag_p);

  mu_p   = sqrt(pow(prt_px->at(idx_mu), 2.0)+pow(prt_py->at(idx_mu), 2.0)+pow(prt_pz->at(idx_mu), 2.0));
  mu_eta = atanh(prt_pz->at(idx_mu)/mu_p);

  h_p   = sqrt(pow(prt_px->at(idx_h), 2.0)+pow(prt_py->at(idx_h), 2.0)+pow(prt_pz->at(idx_h), 2.0));
  h_eta = atanh(prt_pz->at(idx_h)/h_p);


  prt_trk_dist_mu_h = sqrt(pow(prt_x0->at(idx_h) - prt_x0->at(idx_mu), 2.0) +  pow(prt_y0->at(idx_h) - prt_y0->at(idx_mu), 2.0));
  tag_d2 = prt_trk_dist_mu_h;
  tag_fd_r  = sqrt( pow(tag_x->at(mum) - pvr_x->at(idx_pvr), 2.0) + pow(tag_y->at(mum) - pvr_y->at(idx_pvr), 2.0));
  tag_fd  = sqrt( pow(tag_x->at(mum) - pvr_x->at(idx_pvr), 2.0) + pow(tag_y->at(mum) - pvr_y->at(idx_pvr), 2.0) + pow(tag_z->at(mum) - pvr_z->at(idx_pvr), 2.0));

  tag_flighttime = tag_fd/(tag_beta)*10./2.998;
  tag_tau_ps = tag_flighttime/tag_gamma;


  ////////////////////////////////////////////////////////////////////////////
  //////////////////////////   Basic Cuts   //////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////


  prt_bool_l0         = (bool(tag_l0_tos1->at(mum)) || bool(tag_l0_tos2->at(mum)) || bool(tag_l0_tis->at(mum))); //L0 cuts
  prt_bool_hlt1       = bool(tag_hlt1_tos4->at(mum)) || bool(tag_hlt1_tos5->at(mum)); //Tos Hlt1TrackMVA or [Tos Hlt1TwoTrackMVA for mass >1000 MeV]
  prt_bool_hlt2       = bool(tag_hlt2_tos0->at(mum)); //Hlt2ExoticaRHNuDecision
  prt_bool_strip       = bool(tag_fd_r > 2) && ( bool(tag_m->at(mum) < 425 )  || bool(tag_m->at(mum) > 525 ) ) && (prt_pnn_mu->at(idx_mu) > 0.95);
  prt_bool_kin        = (tag_eta > 2) && (tag_eta < 4.5) && (tag_pt > 1000); // kinematics
  prt_bool_kin        = prt_bool_kin && (mu_eta > 2) && (mu_eta < 4.5) && (h_eta > 2) && (h_eta < 4.5);

  prt_bool_data_consistency      = tag_dtf_chi2->at(mum) < 8;
  prt_bool_data_consistency      = prt_bool_data_consistency && bool(tag_z->at(mum) - pvr_z->at(idx_pvr) > 0); // SV downstream of PV

  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////   Material Veto   /////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  prt_bool_patho_mu   = bool(abs(prt_z0->at(idx_mu) - prt_z1->at(idx_mu)) < 3) &&
                        bool( prt_z0->at(idx_mu) - tag_z->at(mum) > 0); // first hit is downstream of SV
  prt_bool_patho_h    = bool(abs(prt_z0->at(idx_h)  - prt_z1->at(idx_h)) < 3) &&
                        bool( prt_z0->at(idx_mu) - tag_z->at(mum) > 0); // first hit is downstream of SV


  prt_bool_patho_srd  = tag_z->at(mum) < 495 &&
  //                        abs(prt_z0->at(idx_mu)  - prt_z0->at(idx_h)) < 1 &&
  //                        abs(prt_z1->at(idx_mu)  - prt_z1->at(idx_h)) < 1 &&
  //                        prt_id0->at(idx_mu) != prt_id0->at(idx_h) &&
  //                        prt_id1->at(idx_mu) != prt_id1->at(idx_h) &&
  //                        prt_trk_dist_mu_h > .12 &&
                          tag_ve_ns->at(mum) < 8;

  prt_bool_patho      = prt_bool_patho_mu && prt_bool_patho_h && prt_bool_patho_srd;

  //material_veto       = bool(h_velo_tip->at(mum)) || bool(h_velo_miss->at(mum)) || bool(mu_velo_tip->at(mum)) || bool(mu_velo_miss->at(mum));
  material_veto        = bool(tag_veto_h_modmiss->at(mum)) || bool(tag_veto_mu_modmiss->at(mum)) || bool(tag_veto_cutFM->at(mum));
  prt_bool_material_h_modmiss = (!bool(tag_veto_h_modmiss->at(mum)));
  prt_bool_material_mu_modmiss = (!bool(tag_veto_mu_modmiss->at(mum)));
  prt_bool_material_cutFM   = !bool(tag_veto_cutFM->at(mum));
  prt_bool_material        = !material_veto;
  assert((prt_bool_material == (prt_bool_material_h_modmiss && prt_bool_material_mu_modmiss && prt_bool_material_cutFM)));



  //prt_bool_material        = prt_bool_material && bool(tag_dmat->at(mum)> ? )




  ////////////////////////////////////////////////////////////////////////////
  //////////////////////   Heavy Flavor Veto   ///////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  hf_veto             = bool(tag_hlt1_tis->at(mum)) || (tag_il->at(mum) > 0.2) || (tag_iv->at(mum) > 0.3) || ((tag_fd_r < 5) && ((tag_il->at(mum) > 0.07) || (tag_iv->at(mum) > 0.23)));
  prt_bool_hf        = !hf_veto;

  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////   fd_r   //////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  //prt_bool_fd_r      = bool(tag_fd_r > 5);
  prt_bool_fd_r      = true;

  ////////////////////////////////////////////////////////////////////////////
  ///////////////////////////   PID Cuts   ///////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////


  prt_bool_pid        = (prt_pnn_mu->at(idx_mu) > 0.7) && !bool(prt_isMuon->at(idx_h));


  ////////////////////////////////////////////////////////////////////////////
  ///////////////////////////   Summary   ////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  prt_bool_trigger_cuts = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip);
  prt_bool_necessary_cuts   = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip && prt_bool_kin && prt_bool_data_consistency && prt_bool_patho && prt_bool_pid);
  prt_bool_full        = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip && prt_bool_kin && prt_bool_data_consistency && prt_bool_patho && prt_bool_material && prt_bool_hf && prt_bool_fd_r && prt_bool_pid);

  ////////////////////////////////////////////////////////////////////////////
  /////////////////////////   Region Cuts   //////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  //prt_bool_region_1 = (tag_dtf_m->at(mum) < 400 ) &&
  //                        abs(prt_z0->at(idx_mu)  - prt_z0->at(idx_h)) < 1 &&
  //                        abs(prt_z1->at(idx_mu)  - prt_z1->at(idx_h)) < 1;
  prt_bool_region_I = (tag_dtf_m->at(mum) < 400 );
  prt_bool_region_II = (tag_dtf_m->at(mum) > 525 ) && (tag_dtf_m->at(mum) < 2000 );
  prt_bool_region_III = (tag_dtf_m->at(mum) > 2000 );

  prt_bool_region_IV = (tag_dtf_m->at(mum) > 525 ) && (tag_dtf_m->at(mum) < 1500 );



  std::map<std::string, double> var_dict;
  var_dict[std::string("prt_bool_full")] = double(prt_bool_full);
  var_dict[std::string("tag_tau_ps")] = tag_tau_ps;
  var_dict[std::string("tag_d2")] = tag_d2;
  var_dict[std::string("tag_fd_r")] = tag_fd_r;
  var_dict[std::string("prt_bool_l0")] = double(prt_bool_l0);
  var_dict[std::string("prt_bool_hlt1")] = double(prt_bool_hlt1);
  var_dict[std::string("prt_bool_hlt2")] = double(prt_bool_hlt2);
  var_dict[std::string("prt_bool_strip")] = double(prt_bool_strip);
  var_dict[std::string("prt_bool_kin")] = double(prt_bool_kin);
  var_dict[std::string("prt_bool_data_consistency")] = double(prt_bool_data_consistency);
  var_dict[std::string("prt_bool_patho")] = double(prt_bool_patho);
  var_dict[std::string("prt_bool_material")] = double(prt_bool_material);
  var_dict[std::string("prt_bool_hf")] = double(prt_bool_hf);
  var_dict[std::string("prt_bool_fd_r")] = double(prt_bool_fd_r);
  var_dict[std::string("prt_bool_pid")] = double(prt_bool_pid);
  var_dict[std::string("prt_bool_region_I")] = double(prt_bool_region_I);
  var_dict[std::string("prt_bool_region_II")] = double(prt_bool_region_II);
  var_dict[std::string("prt_bool_region_III")] = double(prt_bool_region_III);
  var_dict[std::string("prt_bool_region_IV")] = double(prt_bool_region_IV);

  var_dict[std::string("prt_bool_trigger_cuts")] = double(prt_bool_trigger_cuts);

  var_dict[std::string("prt_bool_necessary_cuts")] = double(prt_bool_necessary_cuts);


  var_dict[std::string("prt_bool_material_h_modmiss")] = double(prt_bool_material_h_modmiss);
  var_dict[std::string("prt_bool_material_mu_modmiss")] = double(prt_bool_material_mu_modmiss);
  var_dict[std::string("prt_bool_material_cutFM")] = double(prt_bool_material_cutFM);


  assert (prt_bool_full     == bool(var_dict[std::string("prt_bool_full")]));
  assert (tag_tau_ps        == var_dict[std::string("tag_tau_ps")]);
  assert (tag_d2            == var_dict[std::string("tag_d2")]);
  assert (prt_bool_l0       == bool(var_dict[std::string("prt_bool_l0")]));
  assert (prt_bool_hlt1     == bool(var_dict[std::string("prt_bool_hlt1")]));
  assert (prt_bool_hlt2     == bool(var_dict[std::string("prt_bool_hlt2")]));
  assert (prt_bool_strip    == bool(var_dict[std::string("prt_bool_strip")]));
  assert (prt_bool_kin      == bool(var_dict[std::string("prt_bool_kin")]));
  assert (prt_bool_data_consistency       == bool(var_dict[std::string("prt_bool_data_consistency")]));
  assert (prt_bool_patho    == bool(var_dict[std::string("prt_bool_patho")]));
  assert (prt_bool_material == bool(var_dict[std::string("prt_bool_material")]));
  assert (prt_bool_hf       == bool(var_dict[std::string("prt_bool_hf")]));
  assert (prt_bool_fd_r     == bool(var_dict[std::string("prt_bool_fd_r")]));
  assert (prt_bool_pid      == bool(var_dict[std::string("prt_bool_pid")]));

  assert (prt_bool_material_h_modmiss      == bool(var_dict[std::string("prt_bool_material_h_modmiss")]));
  assert (prt_bool_material_mu_modmiss      == bool(var_dict[std::string("prt_bool_material_mu_modmiss")]));
  assert (prt_bool_material_cutFM        == bool(var_dict[std::string("prt_bool_material_cutFM")]));

  return var_dict;
  //return std::make_tuple(prt_bool_full, tag_tau_ps, tag_d2, prt_bool_l0, prt_bool_hlt1, prt_bool_hlt2, prt_bool_strip, prt_bool_kin, prt_bool_data_consistency, prt_bool_patho, prt_bool_material, prt_bool_hf, prt_bool_pid, prt_bool_region_1, prt_bool_region_2, prt_bool_region_3, prt_bool_region_4);
  //return std::make_tuple(prt_bool_full, tag_tau_ps, tag_d2, prt_bool_l0, prt_bool_hlt1, prt_bool_hlt2, prt_bool_strip, prt_bool_kin, prt_bool_data_consistency, prt_bool_patho, prt_bool_material, prt_bool_hf, prt_bool_pid);
}

std::tuple<double, double>  Plot_hists_RHNu::DiRHNu_Variables_Calculation(unsigned first_id_test, unsigned second_id_test)
{
  return std::make_tuple(1.,2.);
}




void Plot_hists_RHNu::SingleRHNu_Plots(unsigned mum)
{
   // Executed for each right handed neutrino candidate

   idx_mu  = tag_idx_prt0->at(mum);
   idx_h   = tag_idx_prt1->at(mum);
   idx_pvr = tag_idx_pvr->at(mum);

   first_variables = this->Simple_Variables_Calculation(mum);

   prt_bool_full     = bool(first_variables[std::string("prt_bool_full")]);
   tag_tau_ps        = first_variables[std::string("tag_tau_ps")];
   tag_d2            = first_variables[std::string("tag_d2")];
   tag_fd_r          = first_variables[std::string("tag_fd_r")];
   prt_bool_l0       = bool(first_variables[std::string("prt_bool_l0")]);
   prt_bool_hlt1     = bool(first_variables[std::string("prt_bool_hlt1")]);
   prt_bool_hlt2     = bool(first_variables[std::string("prt_bool_hlt2")]);
   prt_bool_strip    = bool(first_variables[std::string("prt_bool_strip")]);
   prt_bool_kin      = bool(first_variables[std::string("prt_bool_kin")]);
   prt_bool_data_consistency       = bool(first_variables[std::string("prt_bool_data_consistency")]);
   prt_bool_patho    = bool(first_variables[std::string("prt_bool_patho")]);
   prt_bool_material = bool(first_variables[std::string("prt_bool_material")]);
   prt_bool_hf       = bool(first_variables[std::string("prt_bool_hf")]);
   prt_bool_fd_r     = bool(first_variables[std::string("prt_bool_fd_r")]);
   prt_bool_pid      = bool(first_variables[std::string("prt_bool_pid")]);

   prt_bool_necessary_cuts = bool(first_variables[std::string("prt_bool_necessary_cuts")]);

   prt_bool_region_I      = bool(first_variables[std::string("prt_bool_region_I")]);
   prt_bool_region_II      = bool(first_variables[std::string("prt_bool_region_II")]);
   prt_bool_region_III      = bool(first_variables[std::string("prt_bool_region_III")]);
   prt_bool_region_IV      = bool(first_variables[std::string("prt_bool_region_IV")]);

   prt_bool_trigger_cuts = bool(first_variables[std::string("prt_bool_trigger_cuts")]);


   prt_bool_material_h_modmiss      = bool(first_variables[std::string("prt_bool_material_h_modmiss")]);
   prt_bool_material_mu_modmiss      = bool(first_variables[std::string("prt_bool_material_mu_modmiss")]);
   prt_bool_material_cutFM        = bool(first_variables[std::string("prt_bool_material_cutFM")]);

   //prt_bool_full     = std::get<0>(first_variables);
   //tag_tau_ps        = std::get<1>(first_variables);
   //tag_d2            = std::get<2>(first_variables);
   //prt_bool_l0       = std::get<3>(first_variables);
   //prt_bool_hlt1     = std::get<4>(first_variables);
   //prt_bool_hlt2     = std::get<5>(first_variables);
   //prt_bool_strip    = std::get<6>(first_variables);
   //prt_bool_kin      = std::get<7>(first_variables);
   //prt_bool_data_consistency      = std::get<8>(first_variables);
   //prt_bool_patho    = std::get<9>(first_variables);
   //prt_bool_material = std::get<10>(first_variables);
   //prt_bool_hf       = std::get<11>(first_variables);
   //prt_bool_pid      = std::get<12>(first_variables);

   //prt_bool_region_1      = std::get<13>(first_variables);
   //prt_bool_region_2      = std::get<14>(first_variables);
   //prt_bool_region_3      = std::get<15>(first_variables);
   //prt_bool_region_4      = std::get<16>(first_variables);

   if (prt_bool_necessary_cuts) {
     fMdmat_necessary_cuts->Fill(tag_m->at(mum), tag_dmat->at(mum));

     if (tag_dmat_isRescaled->at(mum)){
       fMdmat_rescaled_necessary_cuts->Fill(tag_m->at(mum), tag_dmat->at(mum));
     }

     fM_il_necessary_cuts->Fill(tag_m->at(mum),tag_il->at(mum));
     fM_iv_necessary_cuts->Fill(tag_m->at(mum),tag_iv->at(mum));

   }



   if (prt_bool_full){
     x_scatter.push_back(tag_x->at(mum));
     y_scatter.push_back(tag_y->at(mum));
     z_scatter.push_back(tag_z->at(mum));
     n_accepted++;
     if (prt_bool_region_I){
       x_scatter_I.push_back(tag_x->at(mum));
       y_scatter_I.push_back(tag_y->at(mum));
       z_scatter_I.push_back(tag_z->at(mum));
     }else if (prt_bool_region_II){
       x_scatter_II.push_back(tag_x->at(mum));
       y_scatter_II.push_back(tag_y->at(mum));
       z_scatter_II.push_back(tag_z->at(mum));
     }else if (prt_bool_region_III){
       x_scatter_III.push_back(tag_x->at(mum));
       y_scatter_III.push_back(tag_y->at(mum));
       z_scatter_III.push_back(tag_z->at(mum));
     }else if (prt_bool_region_IV){
       x_scatter_IV.push_back(tag_x->at(mum));
       y_scatter_IV.push_back(tag_y->at(mum));
       z_scatter_IV.push_back(tag_z->at(mum));
     }
   }





   //prt_bool_no_matveto_cut = prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip && prt_bool_kin && prt_bool_data_consistency && prt_bool_patho && prt_bool_hf && prt_bool_pid;
   prt_bool_no_matveto_cut = prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip && prt_bool_kin && prt_bool_data_consistency && prt_bool_patho && prt_bool_hf && prt_bool_pid;
   //prt_bool_no_matveto_cut = true;

   if (prt_bool_no_matveto_cut){
     x_scatter_no_matveto_cut.push_back(tag_x->at(mum));
     y_scatter_no_matveto_cut.push_back(tag_y->at(mum));
     z_scatter_no_matveto_cut.push_back(tag_z->at(mum));
   }

   if ((!prt_bool_full) && prt_bool_no_matveto_cut){
     x_scatter_matveto_reject.push_back(tag_x->at(mum));
     y_scatter_matveto_reject.push_back(tag_y->at(mum));
     z_scatter_matveto_reject.push_back(tag_z->at(mum));
   }






   if (prt_bool_no_matveto_cut){fd2_no_matveto_cut->Fill(tag_d2);}

   if (prt_bool_trigger_cuts){
     fdmat->Fill(tag_dmat->at(mum));
     if (tag_dmat_isRescaled->at(mum)) {
       fd2->Fill(tag_d2);
       fxxx->Fill(tag_xxx->at(mum));
       fdmat_rescaled->Fill(tag_dmat->at(mum));

       if (prt_bool_region_I){
         fdmat_rescaled_I->Fill(tag_dmat->at(mum));
       }else if (prt_bool_region_II){
         fdmat_rescaled_II->Fill(tag_dmat->at(mum));
       }else if (prt_bool_region_III){
         fdmat_rescaled_III->Fill(tag_dmat->at(mum));
       }
     }
   }

   if (prt_bool_full){
     ffd_r->Fill(tag_fd_r);
     if (prt_bool_region_I){ ffd_r_I->Fill(tag_fd_r);}
     else if (prt_bool_region_II){ ffd_r_II->Fill(tag_fd_r);}
     else if (prt_bool_region_III){ ffd_r_III->Fill(tag_fd_r);}
     else if (prt_bool_region_IV){ ffd_r_IV->Fill(tag_fd_r);}

   }


   if (prt_bool_full){
     // Bs->mu mu Isolation
     if (tag_tau_ps < 2){
       fiv_hf->Fill(tag_iv->at(mum));
       fil_hf->Fill(tag_il->at(mum));
     }else{
       fiv_sig->Fill(tag_iv->at(mum));
       fil_sig->Fill(tag_il->at(mum));
     }
   }

   //if (prt_bool_hf){
   if (prt_bool_full){
   //if (prt_bool_trigger_cuts){
     fmu_pnnmu->Fill(prt_pnn_mu->at(idx_mu));
     fh_pnnmu->Fill(prt_pnn_mu->at(idx_h));

     fh_pnnk->Fill(prt_pnn_k->at(idx_h));
     fh_pnnpi->Fill(prt_pnn_pi->at(idx_h));

     fmu_isMuon->Fill(prt_isMuon->at(idx_mu));
     fh_isMuon->Fill(prt_isMuon->at(idx_h));
   }





   if (prt_bool_trigger_cuts){fM_trigger_cuts->Fill(tag_m->at(mum));}
   if (prt_bool_necessary_cuts){fM_necessary_cuts->Fill(tag_m->at(mum));}
   if (prt_bool_necessary_cuts && prt_bool_hf){fM_necessary_and_hf_cuts->Fill(tag_m->at(mum));}
   if (prt_bool_necessary_cuts && prt_bool_material){fM_necessary_and_material_cuts->Fill(tag_m->at(mum));}
   if (prt_bool_necessary_cuts && prt_bool_hf && prt_bool_material){fM_necessary_and_hf_and_material_cuts->Fill(tag_m->at(mum));}



  //Filling histograms
  n_candidates_orig++;
  fMT->Fill(tag_m->at(mum),tag_tau_ps);
  fM->Fill(tag_m->at(mum));

  prt_bool            = true;

  if (prt_bool){
    if (prt_bool_l0){
      fMT_l0_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_l0_p->Fill(tag_m->at(mum));
    } else {
      fMT_l0_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_l0_f->Fill(tag_m->at(mum));
      reject_l0++;
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_l0;}

  if (prt_bool){
    if (prt_bool_hlt1){
      fMT_hlt1_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_hlt1_p->Fill(tag_m->at(mum));
    } else {
      fMT_hlt1_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_hlt1_f->Fill(tag_m->at(mum));
      reject_hlt1++;
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_hlt1;}

  if (prt_bool){
    if (prt_bool_hlt2){
      fMT_hlt2_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_hlt2_p->Fill(tag_m->at(mum));
    } else {
      fMT_hlt2_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_hlt2_f->Fill(tag_m->at(mum));
      reject_hlt2++;
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_hlt2;}

  if (prt_bool){
    if (prt_bool_strip){
      fMT_strip_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_strip_p->Fill(tag_m->at(mum));
    } else {
      fMT_strip_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_strip_f->Fill(tag_m->at(mum));
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_strip;}

  if (prt_bool){
    if (prt_bool_kin){
      fMT_kin_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_kin_p->Fill(tag_m->at(mum));
    } else {
      fMT_kin_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_kin_f->Fill(tag_m->at(mum));
      reject_kin++;
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_kin;}

  if (prt_bool){
    if (prt_bool_data_consistency){
      fMT_data_consistency_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_data_consistency_p->Fill(tag_m->at(mum));
    } else {
      fMT_data_consistency_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_data_consistency_f->Fill(tag_m->at(mum));
      reject_kin++;
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_data_consistency;}

  if (prt_bool){
    if (prt_bool_patho){
      fMT_patho_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_patho_p->Fill(tag_m->at(mum));
    } else {
      fMT_patho_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_patho_f->Fill(tag_m->at(mum));
      reject_patho++;
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_patho;}

  if (prt_bool){
    if (prt_bool_material){
      fMT_material_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_material_p->Fill(tag_m->at(mum));
    } else {
      fMT_material_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_material_f->Fill(tag_m->at(mum));
      reject_material++;
    }
  }

  if (prt_bool){
    if (prt_bool_material_h_modmiss){
      fM_material_h_modmiss_p->Fill(tag_m->at(mum));
    } else {
      fM_material_h_modmiss_f->Fill(tag_m->at(mum));
      reject_material++;
    }
  }
  if (prt_bool){
    if (prt_bool_material_mu_modmiss){
      fM_material_mu_modmiss_p->Fill(tag_m->at(mum));
    } else {
      fM_material_mu_modmiss_f->Fill(tag_m->at(mum));
      reject_material++;
    }
  }

  if (prt_bool){
    if (prt_bool_material_cutFM){
      fM_material_cutFM_p->Fill(tag_m->at(mum));
    } else {
      fM_material_cutFM_f->Fill(tag_m->at(mum));
      reject_material++;
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_material;}

  if (prt_bool){
    if (prt_bool_hf){
      fMT_hf_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_hf_p->Fill(tag_m->at(mum));
    } else {
      fMT_hf_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_hf_f->Fill(tag_m->at(mum));
      reject_hf++;
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_hf;}

  if (prt_bool){
    if (prt_bool_fd_r){
      fMT_fd_r_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_fd_r_p->Fill(tag_m->at(mum));
    } else {
      fMT_fd_r_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_fd_r_f->Fill(tag_m->at(mum));
    }
  }

  if (not pass_separately) {prt_bool = prt_bool && prt_bool_fd_r;}


  if (prt_bool){
    if (prt_bool_pid){
      fMT_pid_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_pid_p->Fill(tag_m->at(mum));
    } else {
      fMT_pid_f->Fill(tag_m->at(mum),tag_tau_ps);
      fM_pid_f->Fill(tag_m->at(mum));
      reject_pid++;
    }
  }

  if (prt_bool_pid && prt_bool){
    if (prt_bool_region_I){
      fMT_pid_I_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_pid_I_p->Fill(tag_m->at(mum));
    }else if (prt_bool_region_II){
      fMT_pid_II_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_pid_II_p->Fill(tag_m->at(mum));
    }else if (prt_bool_region_III){
      fMT_pid_III_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_pid_III_p->Fill(tag_m->at(mum));
    }else if (prt_bool_region_IV){
      fMT_pid_IV_p->Fill(tag_m->at(mum),tag_tau_ps);
      fM_pid_IV_p->Fill(tag_m->at(mum));
    }
  }



  if (not pass_separately) {prt_bool = prt_bool && prt_bool_pid;}

  assert (prt_bool==prt_bool_full);



}

void Plot_hists_RHNu::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Plot_hists_RHNu::Plot_Scatter_Graphs()
{
  std::ofstream scatter_file;

  if (option == "Di"){scatter_file.open("plots/Di_scatter.csv");}
  else if (option == "All"){scatter_file.open("plots/All_scatter.csv");}
  else if (option == "Test"){scatter_file.open("plots/Test_scatter.csv");}
  //scatter_file.open("plots/scatter.csv");

  for (unsigned j=0; j < x_scatter.size(); j++) {
    scatter_file << x_scatter.at(j)<<",";
    scatter_file << y_scatter.at(j)<<",";
    scatter_file << z_scatter.at(j)<<"\n";
  }

  scatter_file.close();

  /////////////////////////////////

  std::ofstream scatter_I_file;

  if (option == "Di"){scatter_I_file.open("plots/Di_scatter_I.csv");}
  else if (option == "All"){scatter_I_file.open("plots/All_scatter_I.csv");}
  else if (option == "Test"){scatter_I_file.open("plots/Test_scatter_I.csv");}
  //scatter_I_file.open("plots/scatter_I_.csv");

  for (unsigned j=0; j < x_scatter_I.size(); j++) {
    scatter_I_file << x_scatter_I.at(j)<<",";
    scatter_I_file << y_scatter_I.at(j)<<",";
    scatter_I_file << z_scatter_I.at(j)<<"\n";
  }

  scatter_I_file.close();

  /////////////////////////////////

  std::ofstream scatter_II_file;

  if (option == "Di"){scatter_II_file.open("plots/Di_scatter_II.csv");}
  else if (option == "All"){scatter_II_file.open("plots/All_scatter_II.csv");}
  else if (option == "Test"){scatter_II_file.open("plots/Test_scatter_II.csv");}
  //scatter_II_file.open("plots/scatter_II_.csv");

  for (unsigned j=0; j < x_scatter_II.size(); j++) {
    scatter_II_file << x_scatter_II.at(j)<<",";
    scatter_II_file << y_scatter_II.at(j)<<",";
    scatter_II_file << z_scatter_II.at(j)<<"\n";
  }

  scatter_II_file.close();

  /////////////////////////////////

  std::ofstream scatter_III_file;

  if (option == "Di"){scatter_III_file.open("plots/Di_scatter_III.csv");}
  else if (option == "All"){scatter_III_file.open("plots/All_scatter_III.csv");}
  else if (option == "Test"){scatter_III_file.open("plots/Test_scatter_III.csv");}
  //scatter_III_file.open("plots/scatter_III_.csv");

  for (unsigned j=0; j < x_scatter_III.size(); j++) {
    scatter_III_file << x_scatter_III.at(j)<<",";
    scatter_III_file << y_scatter_III.at(j)<<",";
    scatter_III_file << z_scatter_III.at(j)<<"\n";
  }

  scatter_III_file.close();

  /////////////////////////////////

  std::ofstream scatter_IV_file;

  if (option == "Di"){scatter_IV_file.open("plots/Di_scatter_IV.csv");}
  else if (option == "All"){scatter_IV_file.open("plots/All_scatter_IV.csv");}
  else if (option == "Test"){scatter_IV_file.open("plots/Test_scatter_IV.csv");}
  //scatter_IV_file.open("plots/scatter_IV_.csv");

  for (unsigned j=0; j < x_scatter_IV.size(); j++) {
    scatter_IV_file << x_scatter_IV.at(j)<<",";
    scatter_IV_file << y_scatter_IV.at(j)<<",";
    scatter_IV_file << z_scatter_IV.at(j)<<"\n";
  }

  scatter_IV_file.close();

  /////////////////////////////////

  std::ofstream scatter_file_no_matveto_cut;

  if (option == "Di"){scatter_file_no_matveto_cut.open("plots/Di_scatter_no_matveto_cut.csv");}
  else if (option == "All"){scatter_file_no_matveto_cut.open("plots/All_scatter_no_matveto_cut.csv");}
  else if (option == "Test"){scatter_file_no_matveto_cut.open("plots/Test_scatter_no_matveto_cut.csv");}
  //scatter_file_no_matveto_cut.open("plots/scatter_no_matveto_cut.csv");

  for (unsigned j=0; j < x_scatter_no_matveto_cut.size(); j++) {
    scatter_file_no_matveto_cut << x_scatter_no_matveto_cut.at(j)<<",";
    scatter_file_no_matveto_cut << y_scatter_no_matveto_cut.at(j)<<",";
    scatter_file_no_matveto_cut << z_scatter_no_matveto_cut.at(j)<<"\n";
  }

  scatter_file_no_matveto_cut.close();

  /////////////////////////////////

  std::ofstream scatter_file_matveto_reject;

  if (option == "Di"){scatter_file_matveto_reject.open("plots/Di_scatter_matveto_reject.csv");}
  else if (option == "All"){scatter_file_matveto_reject.open("plots/All_scatter_matveto_reject.csv");}
  else if (option == "Test"){scatter_file_matveto_reject.open("plots/Test_scatter_matveto_reject.csv");}
  //scatter_file_matveto_reject.open("plots/scatter_matveto_reject.csv");

  for (unsigned j=0; j < x_scatter_matveto_reject.size(); j++) {
    scatter_file_matveto_reject << x_scatter_matveto_reject.at(j)<<",";
    scatter_file_matveto_reject << y_scatter_matveto_reject.at(j)<<",";
    scatter_file_matveto_reject << z_scatter_matveto_reject.at(j)<<"\n";
  }

  scatter_file_matveto_reject.close();







}

void Plot_hists_RHNu::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   this->Plot_Scatter_Graphs();

   std::cout << "reject_pid : " << reject_pid << " out of ?" << std::endl;

   std::cout << "Writing Hists to File" << std::endl;

   //gDirectory->Add(l_x_scatter);
   gDirectory->ls();

   f->Write();
   f->Close();

   std::cout << "n_nn : \t" << n_nn << std::endl;
   std::cout << "n_yn : \t" << n_yn << std::endl;
   std::cout << "n_ny : \t" << n_ny << std::endl;
   std::cout << "n_yy : \t" << n_yy << std::endl;

   std::cout << "n_more_than_1_cand : " << n_more_than_1_cand << std::endl;

   std::cout << "Saying goodbye" << std::endl;

}
