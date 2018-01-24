#define Plot_hists_X2ApGm_cxx
// The class definition in Plot_hists_X2ApGm.h has been generated automatically
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
// root> T->Process("Plot_hists_X2ApGm.C")
// root> T->Process("Plot_hists_X2ApGm.C","some options")
// root> T->Process("Plot_hists_X2ApGm.C+")
//

#include "Plot_hists_X2ApGm.h"
#include <TH2.h>
#include <TStyle.h>


void Plot_hists_X2ApGm::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   option = GetOption();

}

void Plot_hists_X2ApGm::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   option = GetOption();

   std::cout << "Plot_hists_RHNu The option is : " << option << std::endl;

   f = 0;
   TString file_name;
   if (option == "displ"){file_name = "NTuple_X2ApGm_all_files_plots_displ.root";}
   else if (option == "prmpt"){file_name = "NTuple_X2ApGm_all_files_plots_prmpt.root";}
   else if (option == "Test"){file_name = "NTuple_X2ApGm_all_files_plots_test.root";}
   else{ std::cout << std::endl << std::endl << "NO VALID OPTION" << std::endl << std::endl;}


   //TString temp_option = GetOption();
   //TObjArray *t_temp_option = temp_option.Tokenize(" ");

   //option = ((TObjString *)(t_temp_option->At(0)))->String();
   //option2 = ((TObjString *)(t_temp_option->At(1)))->String();

   //std::cout << "Plot_hists_RHNu The option is : " << option << std::endl;

   //f = 0;
   //TString file_name;
   //if (option == "displ"){file_name = sprintf("NTuple_X2ApGm_all_files_plots_displ_%d.root", option2.Atoi());}
   //else if (option == "prmpt"){file_name = sprintf("NTuple_X2ApGm_all_files_plots_prmpt_%d.root", option2.Atoi());}
   //else if (option == "Test"){file_name = "NTuple_X2ApGm_all_files_plots_test.root";}
   //else{ std::cout << std::endl << std::endl << "NO VALID OPTION" << std::endl << std::endl;}



   cout << "Opening file : " << file_name << endl;
   f = new TFile(file_name ,"RECREATE");

   pass_separately =false;

   int nmbins(1000);
   double m_min(200.), m_max(10000.);
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

   int nmbins2(1000);
   double m_min2(200.), m_max2(1e4);
   double diff_ln2 = (log(m_max2) - log(m_min2))/float(nmbins2);
   //std::cout << diff_ln << std::endl;
   int asjdsk2; //This needs to be here for some really bizare reason; any type any name
   double mbins2[nmbins2+1];
   double placeholder2;

   for (int counter2 = 0; counter2 <nmbins2+1 ; counter2++){
      placeholder2 = m_min2 * exp(counter2 * diff_ln2);
      //std::cout << placeholder << std::endl;
      mbins2[counter2] = placeholder2;
   }

   int nmbins9(1000);
   double m_min9(50.), m_max9(10000.);
   double diff_ln9 = (log(m_max9) - log(m_min9))/float(nmbins9);
   //std::cout << diff_ln << std::endl;
   int asjdsk9; //This needs to be here for some really bizare reason; any type any name
   double mbins9[nmbins9+1];
   double placeholder9;

   for (int counter9 = 0; counter9 <nmbins9+1 ; counter9++){
      placeholder9 = m_min9 * exp(counter9 * diff_ln9);
      //std::cout << placeholder << std::endl;
      mbins9[counter9] = placeholder9;
   }



   // H I S T O G R A M S


   fn_calos = new TH1I("n_calos", "n_calos;number of calo photons for dimuons passing cuts;TEvts", 10,0,10);

   fM_dicalo = new TH1F("M_dicalo", "M_dicalo;M_calocalo;TEvts", nmbins9, mbins9);
   fM_calomumu_calocalo = new TH2F("M_calomumu_calocalo", "M_calomumu_calocalo;M_calomumu; M_calocalo;TEvts",100, 0, 1200, 100, 0, 1500 );
   fM_calomumu_calocalo_d = new TH2F("M_calomumu_calocalo_d", "M_calomumu_calocalo_d;M_calomumu; M_calocalo;TEvts",100, 0, 1200, 100, 0, 1500);
   fM_calomumu_calocalo_closepi0 = new TH2F("M_calomumu_calocalo_closepi0", "M_calomumu_calocalo_closepi0;M_calomumu; M_calocalo closest to m_pi0;TEvts",100, 0, 1200, 100, 0, 1500);
   fM_mumu_calocalo_m_eta = new TH2F("M_mumu_calocalo_m_eta", "M_mumu_calocalo_m_eta;M_mumu; M_calocalo;TEvts",100, 0, 1200, 100, 0, 1500);
   fM_mumu_calocalo_m_eta_prmptfidu = new TH2F("M_mumu_calocalo_m_eta_prmptfidu", "M_mumu_calocalo_m_eta_prmptfidu;M_mumu; M_calocalo;TEvts",100, 0, 1200, 100, 0, 1500);


   fM = new TH1F("M", "M;A' M [MeV];TEvts", nmbins, mbins);
   fM_prmptfidu = new TH1F("M_prmptfidu", "M_prmptfidu;A' M [MeV];TEvts", nmbins, mbins);
   fM_l0_p = new TH1F("M_l0_p", "M_l0_p;A' M [MeV];Evts", nmbins, mbins);
   fM_hlt1_p = new TH1F("M_hlt1_p", "M_hlt1_p;A' M [MeV];Evts", nmbins, mbins);
   fM_hlt2_p = new TH1F("M_hlt2_p", "M_hlt2_p;A' M [MeV];Evts", nmbins, mbins);
   fM_strip_p  = new TH1F("M_strip_p", "M_strip_p;A' M [MeV];Evts", nmbins, mbins);
   fM_kin_p = new TH1F("M_kin_p", "M_kin_p;A' M [MeV];Evts", nmbins, mbins);
   fM_data_consistency_p = new TH1F("M_data_consistency_p", "M_data_consistency_p;A' M [MeV];Evts", nmbins, mbins);
   fM_patho_p = new TH1F("M_patho_p", "M_patho_p;A' M [MeV];Evts", nmbins, mbins);
   fM_material_p = new TH1F("M_material_p", "M_material_p;A' M [MeV];Evts", nmbins, mbins);
   fM_hf_p = new TH1F("M_hf_p", "M_hf_p;A' M [MeV];Evts", nmbins, mbins);
   fM_fd_r_p = new TH1F("M_fd_r_p", "M_fd_r_p;A' M [MeV];Evts", nmbins, mbins);
   fM_pid_p = new TH1F("M_pid_p", "M_pid_p;A' M [MeV];Evts", nmbins, mbins);


   fM_require_calo = new TH1F("M_require_calo", "M_require_calo ;mu mu M [MeV] when calo photon required;TEvts", nmbins, mbins);
   fM_require_calo_at_m_eta = new TH1F("M_require_calo_at_m_eta", "M_require_calo_at_m_eta ;mu mu M [MeV] when calo photon required and 500 < m(mu mu calo) < 600 MeV;TEvts", nmbins, mbins);
   fM_require_calo_at_m_eta_no_brem = new TH1F("M_require_calo_at_m_eta_no_brem", "M_require_calo_at_m_eta_no_brem ;mu mu M [MeV] when calo photon required and 500 < m(mu mu calo) < 600 MeV no brem photons;TEvts", nmbins, mbins);

   fM_require_calo_at_m_eta_tau_bigger_2ps = new TH1F("M_require_calo_at_m_eta_tau_bigger_2ps", "M_require_calo_at_m_eta_tau_bigger_2ps ;mu mu M [MeV] when calo photon required and 500 < m(mu mu calo) < 600 MeV;TEvts", nmbins, mbins);
   fM_require_calo_at_m_eta_tau_smaller_2ps = new TH1F("M_require_calo_at_m_eta_tau_smaller_2ps", "M_require_calo_at_m_eta_tau_smaller_2ps ;mu mu M [MeV] when calo photon required and 500 < m(mu mu calo) < 600 MeV;TEvts", nmbins, mbins);

   fM_require_calo_at_m_eta_r_bigger_5mm = new TH1F("M_require_calo_at_m_eta_r_bigger_5mm", "M_require_calo_at_m_eta_r_bigger_5mm ;mu mu M [MeV] when calo photon required and 500 < m(mu mu calo) < 600 MeV;TEvts", nmbins, mbins);
   fM_require_calo_at_m_eta_r_smaller_5mm = new TH1F("M_require_calo_at_m_eta_r_smaller_5mm", "M_require_calo_at_m_eta_r_smaller_5mm ;mu mu M [MeV] when calo photon required and 500 < m(mu mu calo) < 600 MeV;TEvts", nmbins, mbins);

   fQ_require_calo_at_m_eta_r_bigger_5mm = new TH1F("Q_require_calo_at_m_eta_r_bigger_5mm", "Q_require_calo_at_m_eta_r_bigger_5mm ; mu mu Q [MeV] when calo photon required and 500 < m(mu mu calo) < 600 MeV;TEvts", 60, 0, 600);
   fQ_require_calo_at_m_eta_r_smaller_5mm = new TH1F("Q_require_calo_at_m_eta_r_smaller_5mm", "Q_require_calo_at_m_eta_r_smaller_5mm ;mu mu Q [MeV] when calo photon required and 500 < m(mu mu calo) < 600 MeV;TEvts", 60, 0, 600);


   fM_tag_calo = new TH1F("M_tag_calo", "M_tag_calo ;mu mu calo M [MeV];TEvts", nmbins2, mbins2);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0 = new TH1F("M_calo_mu0", "M_calo_mu0 ; calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1 = new TH1F("M_calo_mu1", "M_calo_mu1 ; calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fDphiDeta_calo_mu0 = new TH2F("DphiDeta_calo_mu0", "DphiDeta_calo_mu0 ; signal Delta phi calo and mu0 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);
   fDphiDeta_calo_mu1 = new TH2F("DphiDeta_calo_mu1", "DphiDeta_calo_mu1 ; signal Delta phi calo and mu1 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);

   fangle_calo_mu0 = new TH1F("angle_calo_mu0", "angle_calo_mu0 ; angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1 = new TH1F("angle_calo_mu1", "angle_calo_mu1 ; angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0 = new TH1F("Dphi_calo_mu0", "Dphi_calo_mu0 ; Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1 = new TH1F("Dphi_calo_mu1", "Dphi_calo_mu1 ; Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0 = new TH1F("Deta_calo_mu0", "Deta_calo_mu0 ; Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1 = new TH1F("Deta_calo_mu1", "Deta_calo_mu1 ; Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0 = new TH1F("DR_calo_mu0", "DR_calo_mu0 ; Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1 = new TH1F("DR_calo_mu1", "DR_calo_mu1 ; Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl = new TH1F("calo_cl", "calo_cl ; Calo Confidence Level;TEvts", 100, 0., 1.);

   fecal_calo_pull = new TH1F("ecal_calo_pull", "ecal_calo_pull ; Pull calo mu at ECAL;TEvts", 100, 0., 70.);
   fecal_calo_dist = new TH1F("ecal_calo_dist", "ecal_calo_dist ; Distance calo mu at ECAL;TEvts", 100, 0., 2000.);


   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_m_eta = new TH1F("M_calo_mu0_m_eta", "M_calo_mu0_m_eta ; signal calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_m_eta = new TH1F("M_calo_mu1_m_eta", "M_calo_mu1_m_eta ; signal calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fDphiDeta_calo_mu0_m_eta = new TH2F("DphiDeta_calo_mu0_m_eta", "DphiDeta_calo_mu0_m_eta ; signal Delta phi calo and mu0 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);
   fDphiDeta_calo_mu1_m_eta = new TH2F("DphiDeta_calo_mu1_m_eta", "DphiDeta_calo_mu1_m_eta ; signal Delta phi calo and mu1 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);

   fDphiDeta_calo_mu0_m_eta_prmptfidu = new TH2F("DphiDeta_calo_mu0_m_eta_prmptfidu", "DphiDeta_calo_mu0_m_eta_prmptfidu ; signal Delta phi calo and mu0 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);

   fDphiDeta_calo_m_eta = new TH2F("DphiDeta_calo_m_eta", "DphiDeta_calo_m_eta ; Phi calo[rad]; Eta;TEvts", 100, -3.2, 3.2, 100, 1.5, 5.5);
   fET_calo_m_eta = new TH1F("ET_calo_m_eta", "ET_calo_m_eta ; ET calo;TEvts", 100, 0., 4000.);

   fDphiDeta_calo_m_eta_prmptfidu = new TH2F("DphiDeta_calo_m_eta_prmptfidu", "DphiDeta_calo_m_eta_prmptfidu ; Phi calo[rad]; Eta;TEvts", 100, -3.2, 3.2, 100, 1.5, 5.5);
   fET_calo_m_eta_prmptfidu = new TH1F("ET_calo_m_eta_prmptfidu", "ET_calo_m_eta_prmptfidu ; ET calo;TEvts", 100, 0., 4000.);

   fphi_calo_m_eta = new TH1F("phi_calo_m_eta", "phi_calo_m_eta ; Phi calo[rad]; TEvts", 100, -3.2, 3.2);
   feta_calo_m_eta = new TH1F("eta_calo_m_eta", "eta_calo_m_eta ; Eta;TEvts", 100, 1.5, 5.5);

   fphi_calo_m_eta_prmptfidu = new TH1F("phi_calo_m_eta_prmptfidu", "phi_calo_m_eta_prmptfidu ; Phi calo[rad]; TEvts", 100, -3.2, 3.2);
   feta_calo_m_eta_prmptfidu = new TH1F("eta_calo_m_eta_prmptfidu", "eta_calo_m_eta_prmptfidu ; Eta;TEvts", 100, 1.5, 5.5);

   fangle_calo_mu0_m_eta = new TH1F("angle_calo_mu0_m_eta", "angle_calo_mu0_m_eta ; signal angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_m_eta = new TH1F("angle_calo_mu1_m_eta", "angle_calo_mu1_m_eta ; signal angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_m_eta = new TH1F("Dphi_calo_mu0_m_eta", "Dphi_calo_mu0_m_eta ; signal Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_m_eta = new TH1F("Dphi_calo_mu1_m_eta", "Dphi_calo_mu1_m_eta ; signal Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_m_eta = new TH1F("Deta_calo_mu0_m_eta", "Deta_calo_mu0_m_eta ; signal Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_m_eta = new TH1F("Deta_calo_mu1_m_eta", "Deta_calo_mu1_m_eta ; signal Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_m_eta = new TH1F("DR_calo_mu0_m_eta", "DR_calo_mu0_m_eta ; signal Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_m_eta = new TH1F("DR_calo_mu1_m_eta", "DR_calo_mu1_m_eta ; signal Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_m_eta = new TH1F("calo_cl_m_eta", "calo_cl_m_eta ; Calo Confidence Level;TEvts", 100, 0., 1.);

   fcalo_cl_m_eta_prmptfidu = new TH1F("calo_cl_m_eta_prmptfidu", "calo_cl_m_eta_prmptfidu ; Calo Confidence Level;TEvts", 100, 0., 1.);

   fecal_calo_pull_m_eta = new TH1F("ecal_calo_pull_m_eta", "ecal_calo_pull_m_eta ; Pull calo mu at ECAL;TEvts", 100, 0., 70.);
   fecal_calo_dist_m_eta = new TH1F("ecal_calo_dist_m_eta", "ecal_calo_dist_m_eta ; Distance calo mu at ECAL;TEvts", 100, 0., 2000.);

   fbrem_test_AP_m_eta = new TH1F("brem_test_AP_m_eta", "brem_test_AP_m_eta ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_PC_m_eta = new TH1F("brem_test_PC_m_eta", "brem_test_PC_m_eta ; PC;TEvts", 100, -1000., 1000.);
   fbrem_test_AC_m_eta = new TH1F("brem_test_AC_m_eta", "brem_test_AC_m_eta ; AC;TEvts", 100, -1000., 1000.);
   fbrem_test_BC_m_eta = new TH1F("brem_test_BC_m_eta", "brem_test_BC_m_eta ; BC;TEvts", 100, -1000., 1000.);
   fbrem_test_BP_m_eta = new TH1F("brem_test_BP_m_eta", "brem_test_BP_m_eta ; BP;TEvts", 100, -1000., 1000.);
   fbrem_test_AB_m_eta = new TH1F("brem_test_AB_m_eta", "brem_test_AB_m_eta ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_2D_m_eta = new TH2F("brem_test_2D_m_eta", "brem_test_2D_m_eta ; AP/AB; PC/AB ;TEvts", 100, -5., 5., 100, -5., 5.);

   fbrem_test_AP_m_eta_prmptfidu = new TH1F("brem_test_AP_m_eta_prmptfidu", "brem_test_AP_m_eta_prmptfidu ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_PC_m_eta_prmptfidu = new TH1F("brem_test_PC_m_eta_prmptfidu", "brem_test_PC_m_eta_prmptfidu ; PC;TEvts", 100, -1000., 1000.);
   fbrem_test_AC_m_eta_prmptfidu = new TH1F("brem_test_AC_m_eta_prmptfidu", "brem_test_AC_m_eta_prmptfidu ; AC;TEvts", 100, -1000., 1000.);
   fbrem_test_BC_m_eta_prmptfidu = new TH1F("brem_test_BC_m_eta_prmptfidu", "brem_test_BC_m_eta_prmptfidu ; BC;TEvts", 100, -1000., 1000.);
   fbrem_test_BP_m_eta_prmptfidu = new TH1F("brem_test_BP_m_eta_prmptfidu", "brem_test_BP_m_eta_prmptfidu ; BP;TEvts", 100, -1000., 1000.);
   fbrem_test_AB_m_eta_prmptfidu = new TH1F("brem_test_AB_m_eta_prmptfidu", "brem_test_AB_m_eta_prmptfidu ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_2D_m_eta_prmptfidu = new TH2F("brem_test_2D_m_eta_prmptfidu", "brem_test_2D_m_eta_prmptfidu ; AP/AB; PC/AB ;TEvts", 100, -5., 5., 100, -5., 5.);



   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_not_m_eta = new TH1F("M_calo_mu0_not_m_eta", "M_calo_mu0_not_m_eta ; sideband calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_not_m_eta = new TH1F("M_calo_mu1_not_m_eta", "M_calo_mu1_not_m_eta ; sideband calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fDphiDeta_calo_mu0_not_m_eta = new TH2F("DphiDeta_calo_mu0_not_m_eta", "DphiDeta_calo_mu0_not_m_eta ; signal Delta phi calo and mu0 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);
   fDphiDeta_calo_mu1_not_m_eta = new TH2F("DphiDeta_calo_mu1_not_m_eta", "DphiDeta_calo_mu1_not_m_eta ; signal Delta phi calo and mu1 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);

   fDphiDeta_calo_not_m_eta = new TH2F("DphiDeta_calo_not_m_eta", "DphiDeta_calo_not_m_eta ; Phi calo[rad]; Eta;TEvts", 100, -3.2, 3.2, 100, 1.5, 5.5);
   fET_calo_not_m_eta = new TH1F("ET_calo_not_m_eta", "ET_calo_not_m_eta ; ET calo;TEvts", 100, 0., 4000.);

   fphi_calo_not_m_eta = new TH1F("phi_calo_not_m_eta", "phi_calo_not_m_eta ; Phi calo[rad]; TEvts", 100, -3.2, 3.2);
   feta_calo_not_m_eta = new TH1F("eta_calo_not_m_eta", "eta_calo_not_m_eta ; Eta;TEvts", 100, 1.5, 5.5);

   fangle_calo_mu0_not_m_eta = new TH1F("angle_calo_mu0_not_m_eta", "angle_calo_mu0_not_m_eta ; sideband angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_not_m_eta = new TH1F("angle_calo_mu1_not_m_eta", "angle_calo_mu1_not_m_eta ; sideband angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_not_m_eta = new TH1F("Dphi_calo_mu0_not_m_eta", "Dphi_calo_mu0_not_m_eta ; sideband Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_not_m_eta = new TH1F("Dphi_calo_mu1_not_m_eta", "Dphi_calo_mu1_not_m_eta ; sideband Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_not_m_eta = new TH1F("Deta_calo_mu0_not_m_eta", "Deta_calo_mu0_not_m_eta ; sideband Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_not_m_eta = new TH1F("Deta_calo_mu1_not_m_eta", "Deta_calo_mu1_not_m_eta ; sideband Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_not_m_eta = new TH1F("DR_calo_mu0_not_m_eta", "DR_calo_mu0_not_m_eta ; sideband Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_not_m_eta = new TH1F("DR_calo_mu1_not_m_eta", "DR_calo_mu1_not_m_eta ; sideband Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_not_m_eta = new TH1F("calo_cl_not_m_eta", "calo_cl_not_m_eta ; Calo Confidence Level;TEvts", 100, 0., 1.);

   fecal_calo_pull_not_m_eta = new TH1F("ecal_calo_pull_not_m_eta", "ecal_calo_pull_not_m_eta ; Pull calo mu at ECAL;TEvts", 100, 0., 70.);
   fecal_calo_dist_not_m_eta = new TH1F("ecal_calo_dist_not_m_eta", "ecal_calo_dist_not_m_eta ; Distance calo mu at ECAL;TEvts", 100, 0., 2000.);

   fbrem_test_AP_not_m_eta = new TH1F("brem_test_AP_not_m_eta", "brem_test_AP_not_m_eta ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_PC_not_m_eta = new TH1F("brem_test_PC_not_m_eta", "brem_test_PC_not_m_eta ; PC;TEvts", 100, -1000., 1000.);
   fbrem_test_AC_not_m_eta = new TH1F("brem_test_AC_not_m_eta", "brem_test_AC_not_m_eta ; AC;TEvts", 100, -1000., 1000.);
   fbrem_test_BC_not_m_eta = new TH1F("brem_test_BC_not_m_eta", "brem_test_BC_not_m_eta ; BC;TEvts", 100, -1000., 1000.);
   fbrem_test_BP_not_m_eta = new TH1F("brem_test_BP_not_m_eta", "brem_test_BP_not_m_eta ; BP;TEvts", 100, -1000., 1000.);
   fbrem_test_AB_not_m_eta = new TH1F("brem_test_AB_not_m_eta", "brem_test_AB_not_m_eta ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_2D_not_m_eta = new TH2F("brem_test_2D_not_m_eta", "brem_test_2D_not_m_eta ; AP/AB; PC/AB ;TEvts", 100, -5., 5., 100, -5., 5.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_m_eta_backgr_subtr = new TH1F("M_calo_mu0_m_eta_backgr_subtr", "M_calo_mu0_m_eta_backgr_subtr ; signal calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_m_eta_backgr_subtr = new TH1F("M_calo_mu1_m_eta_backgr_subtr", "M_calo_mu1_m_eta_backgr_subtr ; signal calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fDphiDeta_calo_mu0_m_eta_backgr_subtr = new TH2F("DphiDeta_calo_mu0_m_eta_backgr_subtr", "DphiDeta_calo_mu0_m_eta_backgr_subtr ; signal Delta phi calo and mu0 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);
   fDphiDeta_calo_mu1_m_eta_backgr_subtr = new TH2F("DphiDeta_calo_mu1_m_eta_backgr_subtr", "DphiDeta_calo_mu1_m_eta_backgr_subtr ; signal Delta phi calo and mu1 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);

   fDphiDeta_calo_m_eta_backgr_subtr = new TH2F("DphiDeta_calo_m_eta_backgr_subtr", "DphiDeta_calo_m_eta_backgr_subtr ; Phi calo[rad]; Eta;TEvts", 100, -3.2, 3.2, 100, 1.5, 5.5);
   fET_calo_m_eta_backgr_subtr = new TH1F("ET_calo_m_eta_backgr_subtr", "ET_calo_m_eta_backgr_subtr ; ET calo;TEvts", 100, 0., 4000.);

   fphi_calo_m_eta_backgr_subtr = new TH1F("phi_calo_m_eta_backgr_subtr", "phi_calo_m_eta_backgr_subtr ; Phi calo[rad]; TEvts", 100, -3.2, 3.2);
   feta_calo_m_eta_backgr_subtr = new TH1F("eta_calo_m_eta_backgr_subtr", "eta_calo_m_eta_backgr_subtr ; Eta;TEvts", 100, 1.5, 5.5);

   fangle_calo_mu0_m_eta_backgr_subtr = new TH1F("angle_calo_mu0_m_eta_backgr_subtr", "angle_calo_mu0_m_eta_backgr_subtr ; signal angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_m_eta_backgr_subtr = new TH1F("angle_calo_mu1_m_eta_backgr_subtr", "angle_calo_mu1_m_eta_backgr_subtr ; signal angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_m_eta_backgr_subtr = new TH1F("Dphi_calo_mu0_m_eta_backgr_subtr", "Dphi_calo_mu0_m_eta_backgr_subtr ; signal Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_m_eta_backgr_subtr = new TH1F("Dphi_calo_mu1_m_eta_backgr_subtr", "Dphi_calo_mu1_m_eta_backgr_subtr ; signal Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_m_eta_backgr_subtr = new TH1F("Deta_calo_mu0_m_eta_backgr_subtr", "Deta_calo_mu0_m_eta_backgr_subtr ; signal Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_m_eta_backgr_subtr = new TH1F("Deta_calo_mu1_m_eta_backgr_subtr", "Deta_calo_mu1_m_eta_backgr_subtr ; signal Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_m_eta_backgr_subtr = new TH1F("DR_calo_mu0_m_eta_backgr_subtr", "DR_calo_mu0_m_eta_backgr_subtr ; signal Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_m_eta_backgr_subtr = new TH1F("DR_calo_mu1_m_eta_backgr_subtr", "DR_calo_mu1_m_eta_backgr_subtr ; signal Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_m_eta_backgr_subtr = new TH1F("calo_cl_m_eta_backgr_subtr", "calo_cl_m_eta_backgr_subtr ; Calo Confidence Level;TEvts", 100, 0., 1.);

   fecal_calo_pull_m_eta_backgr_subtr = new TH1F("ecal_calo_pull_m_eta_backgr_subtr", "ecal_calo_pull_m_eta_backgr_subtr ; Pull calo mu at ECAL;TEvts", 100, 0., 70.);
   fecal_calo_dist_m_eta_backgr_subtr = new TH1F("ecal_calo_dist_m_eta_backgr_subtr", "ecal_calo_dist_m_eta_backgr_subtr ; Distance calo mu at ECAL;TEvts", 100, 0., 2000.);

   fbrem_test_AP_m_eta_backgr_subtr = new TH1F("brem_test_AP_m_eta_backgr_subtr", "brem_test_AP_m_eta_backgr_subtr ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_PC_m_eta_backgr_subtr = new TH1F("brem_test_PC_m_eta_backgr_subtr", "brem_test_PC_m_eta_backgr_subtr ; PC;TEvts", 100, -1000., 1000.);
   fbrem_test_AC_m_eta_backgr_subtr = new TH1F("brem_test_AC_m_eta_backgr_subtr", "brem_test_AC_m_eta_backgr_subtr ; AC;TEvts", 100, -1000., 1000.);
   fbrem_test_BC_m_eta_backgr_subtr = new TH1F("brem_test_BC_m_eta_backgr_subtr", "brem_test_BC_m_eta_backgr_subtr ; BC;TEvts", 100, -1000., 1000.);
   fbrem_test_BP_m_eta_backgr_subtr = new TH1F("brem_test_BP_m_eta_backgr_subtr", "brem_test_BP_m_eta_backgr_subtr ; BP;TEvts", 100, -1000., 1000.);
   fbrem_test_AB_m_eta_backgr_subtr = new TH1F("brem_test_AB_m_eta_backgr_subtr", "brem_test_AB_m_eta_backgr_subtr ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_2D_m_eta_backgr_subtr = new TH2F("brem_test_2D_m_eta_backgr_subtr", "brem_test_2D_m_eta_backgr_subtr ; AP/AB; PC/AB ;TEvts", 100, -5., 5., 100, -5., 5.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_m_450_500 = new TH1F("M_calo_mu0_m_450_500", "M_calo_mu0_m_450_500 ; calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_m_450_500 = new TH1F("M_calo_mu1_m_450_500", "M_calo_mu1_m_450_500 ; calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fDphiDeta_calo_mu0_m_450_500 = new TH2F("DphiDeta_calo_mu0_m_450_500", "DphiDeta_calo_mu0_m_450_500 ; signal Delta phi calo and mu0 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);
   fDphiDeta_calo_mu1_m_450_500 = new TH2F("DphiDeta_calo_mu1_m_450_500", "DphiDeta_calo_mu1_m_450_500 ; signal Delta phi calo and mu1 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);

   fDphiDeta_calo_m_450_500 = new TH2F("DphiDeta_calo_m_450_500", "DphiDeta_calo_m_450_500 ; Phi calo[rad]; Eta;TEvts", 100, -3.2, 3.2, 100, 1.5, 5.5);
   fET_calo_m_450_500 = new TH1F("ET_calo_m_450_500", "ET_calo_m_450_500 ; ET calo;TEvts", 100, 0., 4000.);

   fphi_calo_m_450_500 = new TH1F("phi_calo_m_450_500", "phi_calo_m_450_500 ; Phi calo[rad]; TEvts", 100, -3.2, 3.2);
   feta_calo_m_450_500 = new TH1F("eta_calo_m_450_500", "eta_calo_m_450_500 ; Eta;TEvts", 100, 1.5, 5.5);

   fangle_calo_mu0_m_450_500 = new TH1F("angle_calo_mu0_m_450_500", "angle_calo_mu0_m_450_500 ; angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_m_450_500 = new TH1F("angle_calo_mu1_m_450_500", "angle_calo_mu1_m_450_500 ; angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_m_450_500 = new TH1F("Dphi_calo_mu0_m_450_500", "Dphi_calo_mu0_m_450_500 ; Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_m_450_500 = new TH1F("Dphi_calo_mu1_m_450_500", "Dphi_calo_mu1_m_450_500 ; Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_m_450_500 = new TH1F("Deta_calo_mu0_m_450_500", "Deta_calo_mu0_m_450_500 ; Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_m_450_500 = new TH1F("Deta_calo_mu1_m_450_500", "Deta_calo_mu1_m_450_500 ; Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_m_450_500 = new TH1F("DR_calo_mu0_m_450_500", "DR_calo_mu0_m_450_500 ; Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_m_450_500 = new TH1F("DR_calo_mu1_m_450_500", "DR_calo_mu1_m_450_500 ; Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_m_450_500 = new TH1F("calo_cl_m_450_500", "calo_cl_m_450_500 ; Calo Confidence Level;TEvts", 100, 0., 1.);

   fecal_calo_pull_m_450_500 = new TH1F("ecal_calo_pull_m_450_500", "ecal_calo_pull_m_450_500 ; Pull calo mu at ECAL;TEvts", 100, 0., 70.);
   fecal_calo_dist_m_450_500 = new TH1F("ecal_calo_dist_m_450_500", "ecal_calo_dist_m_450_500 ; Distance calo mu at ECAL;TEvts", 100, 0., 2000.);

   fbrem_test_AP_m_450_500 = new TH1F("brem_test_AP_m_450_500", "brem_test_AP_m_450_500 ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_PC_m_450_500 = new TH1F("brem_test_PC_m_450_500", "brem_test_PC_m_450_500 ; PC;TEvts", 100, -1000., 1000.);
   fbrem_test_AC_m_450_500 = new TH1F("brem_test_AC_m_450_500", "brem_test_AC_m_450_500 ; AC;TEvts", 100, -1000., 1000.);
   fbrem_test_BC_m_450_500 = new TH1F("brem_test_BC_m_450_500", "brem_test_BC_m_450_500 ; BC;TEvts", 100, -1000., 1000.);
   fbrem_test_BP_m_450_500 = new TH1F("brem_test_BP_m_450_500", "brem_test_BP_m_450_500 ; BP;TEvts", 100, -1000., 1000.);
   fbrem_test_AB_m_450_500 = new TH1F("brem_test_AB_m_450_500", "brem_test_AB_m_450_500 ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_2D_m_450_500 = new TH2F("brem_test_2D_m_450_500", "brem_test_2D_m_450_500 ; AP/AB; PC/AB ;TEvts", 100, -5., 5., 100, -5., 5.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_m_600_650 = new TH1F("M_calo_mu0_m_600_650", "M_calo_mu0_m_600_650 ; calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_m_600_650 = new TH1F("M_calo_mu1_m_600_650", "M_calo_mu1_m_600_650 ; calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fDphiDeta_calo_mu0_m_600_650 = new TH2F("DphiDeta_calo_mu0_m_600_650", "DphiDeta_calo_mu0_m_600_650 ; signal Delta phi calo and mu0 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);
   fDphiDeta_calo_mu1_m_600_650 = new TH2F("DphiDeta_calo_mu1_m_600_650", "DphiDeta_calo_mu1_m_600_650 ; signal Delta phi calo and mu1 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);

   fDphiDeta_calo_m_600_650 = new TH2F("DphiDeta_calo_m_600_650", "DphiDeta_calo_m_600_650 ; Phi calo[rad]; Eta;TEvts", 100, -3.2, 3.2, 100, 1.5, 5.5);
   fET_calo_m_600_650 = new TH1F("ET_calo_m_600_650", "ET_calo_m_600_650 ; ET calo;TEvts", 100, 0., 4000.);

   fphi_calo_m_600_650 = new TH1F("phi_calo_m_600_650", "phi_calo_m_600_650 ; Phi calo[rad]; TEvts", 100, -3.2, 3.2);
   feta_calo_m_600_650 = new TH1F("eta_calo_m_600_650", "eta_calo_m_600_650 ; Eta;TEvts", 100, 1.5, 5.5);

   fangle_calo_mu0_m_600_650 = new TH1F("angle_calo_mu0_m_600_650", "angle_calo_mu0_m_600_650 ; angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_m_600_650 = new TH1F("angle_calo_mu1_m_600_650", "angle_calo_mu1_m_600_650 ; angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_m_600_650 = new TH1F("Dphi_calo_mu0_m_600_650", "Dphi_calo_mu0_m_600_650 ; Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_m_600_650 = new TH1F("Dphi_calo_mu1_m_600_650", "Dphi_calo_mu1_m_600_650 ; Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_m_600_650 = new TH1F("Deta_calo_mu0_m_600_650", "Deta_calo_mu0_m_600_650 ; Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_m_600_650 = new TH1F("Deta_calo_mu1_m_600_650", "Deta_calo_mu1_m_600_650 ; Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_m_600_650 = new TH1F("DR_calo_mu0_m_600_650", "DR_calo_mu0_m_600_650 ; Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_m_600_650 = new TH1F("DR_calo_mu1_m_600_650", "DR_calo_mu1_m_600_650 ; Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_m_600_650 = new TH1F("calo_cl_m_600_650", "calo_cl_m_600_650 ; Calo Confidence Level;TEvts", 100, 0., 1.);

   fecal_calo_pull_m_600_650 = new TH1F("ecal_calo_pull_m_600_650", "ecal_calo_pull_m_600_650 ; Pull calo mu at ECAL;TEvts", 100, 0., 70.);
   fecal_calo_dist_m_600_650 = new TH1F("ecal_calo_dist_m_600_650", "ecal_calo_dist_m_600_650 ; Distance calo mu at ECAL;TEvts", 100, 0., 2000.);

   fbrem_test_AP_m_600_650 = new TH1F("brem_test_AP_m_600_650", "brem_test_AP_m_600_650 ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_PC_m_600_650 = new TH1F("brem_test_PC_m_600_650", "brem_test_PC_m_600_650 ; PC;TEvts", 100, -1000., 1000.);
   fbrem_test_AC_m_600_650 = new TH1F("brem_test_AC_m_600_650", "brem_test_AC_m_600_650 ; AC;TEvts", 100, -1000., 1000.);
   fbrem_test_BC_m_600_650 = new TH1F("brem_test_BC_m_600_650", "brem_test_BC_m_600_650 ; BC;TEvts", 100, -1000., 1000.);
   fbrem_test_BP_m_600_650 = new TH1F("brem_test_BP_m_600_650", "brem_test_BP_m_600_650 ; BP;TEvts", 100, -1000., 1000.);
   fbrem_test_AB_m_600_650 = new TH1F("brem_test_AB_m_600_650", "brem_test_AB_m_600_650 ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_2D_m_600_650 = new TH2F("brem_test_2D_m_600_650", "brem_test_2D_m_600_650 ; AP/AB; PC/AB ;TEvts", 100, -5., 5., 100, -5., 5.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_sideband = new TH1F("M_calo_mu0_sideband", "M_calo_mu0_sideband ; calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_sideband = new TH1F("M_calo_mu1_sideband", "M_calo_mu1_sideband ; calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fDphiDeta_calo_mu0_sideband = new TH2F("DphiDeta_calo_mu0_sideband", "DphiDeta_calo_mu0_sideband ; signal Delta phi calo and mu0 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);
   fDphiDeta_calo_mu1_sideband = new TH2F("DphiDeta_calo_mu1_sideband", "DphiDeta_calo_mu1_sideband ; signal Delta phi calo and mu1 momenta[rad];Delta eta;TEvts", 100, -1., 1., 100, -0.8, 0.8);

   fDphiDeta_calo_sideband= new TH2F("DphiDeta_calo_sideband", "DphiDeta_calo_m_sideband ; Phi calo[rad]; Eta;TEvts", 100, -3.2, 3.2, 100, 1.5, 5.5);
   fET_calo_sideband = new TH1F("ET_calo_sideband", "ET_calo_sideband ; ET calo;TEvts", 100, 0., 4000.);

   fphi_calo_sideband = new TH1F("phi_calo_sideband", "phi_calo_sideband ; Phi calo[rad]; TEvts", 100, -3.2, 3.2);
   feta_calo_sideband = new TH1F("eta_calo_sideband", "eta_calo_sideband ; Eta;TEvts", 100, 1.5, 5.5);

   fangle_calo_mu0_sideband = new TH1F("angle_calo_mu0_sideband", "angle_calo_mu0_sideband ; angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_sideband = new TH1F("angle_calo_mu1_sideband", "angle_calo_mu1_sideband ; angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_sideband = new TH1F("Dphi_calo_mu0_sideband", "Dphi_calo_mu0_sideband ; Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_sideband = new TH1F("Dphi_calo_mu1_sideband", "Dphi_calo_mu1_sideband ; Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_sideband = new TH1F("Deta_calo_mu0_sideband", "Deta_calo_mu0_sideband ; Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_sideband = new TH1F("Deta_calo_mu1_sideband", "Deta_calo_mu1_sideband ; Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_sideband = new TH1F("DR_calo_mu0_sideband", "DR_calo_mu0_sideband ; Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_sideband = new TH1F("DR_calo_mu1_sideband", "DR_calo_mu1_sideband ; Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_sideband = new TH1F("calo_cl_sideband", "calo_cl_sideband ; Calo Confidence Level;TEvts", 100, 0., 1.);

   fecal_calo_pull_sideband = new TH1F("ecal_calo_pull_sideband", "ecal_calo_pull_sideband ; Pull calo mu at ECAL;TEvts", 100, 0., 70.);
   fecal_calo_dist_sideband = new TH1F("ecal_calo_dist_sideband", "ecal_calo_dist_sideband ; Distance calo mu at ECAL;TEvts", 100, 0., 2000.);

   fbrem_test_AP_sideband = new TH1F("brem_test_AP_sideband", "brem_test_AP_sideband ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_PC_sideband = new TH1F("brem_test_PC_sideband", "brem_test_PC_sideband ; PC;TEvts", 100, -1000., 1000.);
   fbrem_test_AC_sideband = new TH1F("brem_test_AC_sideband", "brem_test_AC_sideband ; AC;TEvts", 100, -1000., 1000.);
   fbrem_test_BC_sideband = new TH1F("brem_test_BC_sideband", "brem_test_BC_sideband ; BC;TEvts", 100, -1000., 1000.);
   fbrem_test_BP_sideband = new TH1F("brem_test_BP_sideband", "brem_test_BP_sideband ; BP;TEvts", 100, -1000., 1000.);
   fbrem_test_AB_sideband = new TH1F("brem_test_AB_sideband", "brem_test_AB_sideband ; AP;TEvts", 100, -1000., 1000.);
   fbrem_test_2D_sideband = new TH2F("brem_test_2D_sideband", "brem_test_2D_sideband ; AP/AB; PC/AB ;TEvts", 100, -5., 5., 100, -5., 5.);

   dalitz_m_mu0_mu1_separation = {200, 300, 400, 500, 600, 700, 800, 900, 1000};

   for(unsigned i = 0; i < dalitz_m_mu0_mu1_separation.size()+1; i++)
	 {
		vector<Double_t> temp; // create an array, don't work directly on buff yet.
		//for(int j = 0; j < 10; j++)temp.push_back(i);
		dalitz_mu0_mu1_m_eta_m_mu0_mu1_separated.push_back(temp); // Store the array in the buffer
    dalitz_calo_mu0_m_eta_m_mu0_mu1_separated.push_back(temp);
    dalitz_calo_mu1_m_eta_m_mu0_mu1_separated.push_back(temp);
	 }


}

Bool_t Plot_hists_X2ApGm::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Plot_hists_X2ApGm::GetEntry() or TBranch::GetEntry()
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

   //if (entry %20 ==0){
   GetEntry(entry);  // load event
   //if (entry <100000) {GetEntry(entry); } // load event


   if (entry %100000 ==0) {
   //if (entry %1 ==0) {
     std::cout << "entry : " << entry/1000 << "k" << std::endl;
     //std::cout << "entry : " << entry << std::endl;
   }





   for (unsigned mum=0; mum < tag_m->size(); mum++) {
     if ((tag_idx_pvr->at(mum) >=0) && (tag_x->at(mum) < 1e20) && (tag_x->at(mum) > -1e20)) {
       //When only one right handed neutrino is needed
       this->Ap_Anal(mum);
     }
   }

   //}







   return kTRUE;
}


std::map<std::string, double>  Plot_hists_X2ApGm::Simple_Variables_Calculation(int mum)
{

  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////   C U T S   ///////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////


  idx_mu  = tag_idx_prt0->at(mum); //This is really muon 1
  idx_h   = tag_idx_prt1->at(mum); //This is really muon 2
  idx_pvr = tag_idx_pvr->at(mum);

  // ->at(idx_mu)
  // ->at(idx_h)
  // ->at(idx_pvr)

  tag_p   = sqrt(pow(tag_px->at(mum), 2.0)+pow(tag_py->at(mum), 2.0)+pow(tag_pz->at(mum), 2.0));
  //tag_pt  = sqrt(pow(tag_px->at(mum), 2.0)+pow(tag_py->at(mum), 2.0));
  tag_beta = 1./sqrt(1.+pow(tag_m->at(mum),2.0)/pow(tag_p,2.0));
  tag_gamma = 1./sqrt(1.-pow(tag_beta,2.0));
  //tag_eta = atanh(tag_pz->at(mum)/tag_p);

  mu_p   = sqrt(pow(prt_px->at(idx_mu), 2.0)+pow(prt_py->at(idx_mu), 2.0)+pow(prt_pz->at(idx_mu), 2.0));
  mu_pt   = sqrt(pow(prt_px->at(idx_mu), 2.0)+pow(prt_py->at(idx_mu), 2.0));
  mu_eta = atanh(prt_pz->at(idx_mu)/mu_p);

  h_p   = sqrt(pow(prt_px->at(idx_h), 2.0)+pow(prt_py->at(idx_h), 2.0)+pow(prt_pz->at(idx_h), 2.0));
  h_pt   = sqrt(pow(prt_px->at(idx_h), 2.0)+pow(prt_py->at(idx_h), 2.0));
  h_eta = atanh(prt_pz->at(idx_h)/h_p);


  prt_trk_dist_mu_h = sqrt(pow(prt_x0->at(idx_h) - prt_x0->at(idx_mu), 2.0) +  pow(prt_y0->at(idx_h) - prt_y0->at(idx_mu), 2.0));
  tag_d2 = prt_trk_dist_mu_h;

  // Flight distance is between secondary and tertiary vertex, not primary and tertiary
  tag_fd_r  = sqrt( pow(tag_x->at(mum) - pvr_x->at(idx_pvr), 2.0) + pow(tag_y->at(mum) - pvr_y->at(idx_pvr), 2.0));
  tag_fd  = sqrt( pow(tag_x->at(mum) - pvr_x->at(idx_pvr), 2.0) + pow(tag_y->at(mum) - pvr_y->at(idx_pvr), 2.0) + pow(tag_z->at(mum) - pvr_z->at(idx_pvr), 2.0));
  tag_flighttime = tag_fd/(tag_beta)*10./2.998;
  tag_tau_ps = tag_flighttime/tag_gamma;


  tag_Q  = sqrt( pow(tag_dtf_m->at(mum), 2.0) - pow(2*105.658, 2.0));


  ////////////////////////////////////////////////////////////////////////////
  //////////////////////////   Basic Cuts   //////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////


  prt_bool_l0         = (bool(tag_l0_tos1->at(mum)) || bool(tag_l0_tos3->at(mum)) || bool(tag_l0_tis->at(mum))); //L0MuonDecision or L0DiMuonDecision or TIS L0HadronDecision
  if (option == "prmpt") {prt_bool_hlt1       = true;}
  //if (option == "displ") {prt_bool_hlt1       = bool(tag_hlt1_tos4->at(mum)) || bool(tag_hlt1_tos5->at(mum));} //Tos Hlt1TrackMVA or Tos Hlt1TwoTrackMVA
  //if (option == "displ") {prt_bool_hlt1       = not (bool(tag_hlt1_tos4->at(mum)) || bool(tag_hlt1_tos5->at(mum)));} //Tos Hlt1TrackMVA or Tos Hlt1TwoTrackMVA
  if (option == "displ") {prt_bool_hlt1       = bool(tag_hlt1_tos3->at(mum));} //Tos Hlt1DiMuonLowMass
  //if (option == "displ") {prt_bool_hlt1       = bool(tag_hlt1_tos3->at(mum)) && not (bool(tag_hlt1_tos4->at(mum));} //Tos Hlt1DiMuonLowMass and not TIS Hlt1TrackMVA
  if (option == "prmpt") {prt_bool_hlt2       = true;}
  if (option == "displ") {prt_bool_hlt2       = bool(tag_hlt2_tos0->at(mum));} //Hlt2ExoticaDisplDiMuonDecision
  //prt_bool_hlt2       = bool(tag_hlt2_tos2->at(mum)); //Hlt2ExoticaPrmptDiMuonTurboDecision
  //prt_bool_hlt1       = true;
  //prt_bool_hlt2       = true;
  //prt_bool_strip      = bool(tag_strip_dec0->at(mum)); //StrippingHltQEEExoticaDisplDiMuonLineDecision
  prt_bool_strip      = true;
  //prt_bool_strip       = bool(tag_fd_r > 2) && ( bool(tag_m->at(mum) < 425 )  || bool(tag_m->at(mum) > 525 ) ) && (prt_pnn_mu->at(idx_mu) > 0.95); //stripping is a passthrough
  prt_bool_kin        = (tag_eta->at(mum) > 2) && (tag_eta->at(mum) < 4.5) && (tag_pt->at(mum) > 1000); // kinematics
  prt_bool_kin        = prt_bool_kin && (mu_eta > 2) && (mu_eta < 4.5) && (h_eta > 2) && (h_eta < 4.5);

  prt_bool_data_consistency = true;
  if (option == "displ") {prt_bool_data_consistency      = prt_bool_data_consistency && tag_dtf_chi2->at(mum) < 8;}
  //prt_bool_data_consistency      = prt_bool_data_consistency && (std::max(prt_pnn_mu->at(idx_mu), prt_pnn_mu->at(idx_h)) > 0.8);
  if (option == "displ") {prt_bool_data_consistency      = prt_bool_data_consistency && bool(tag_z->at(mum) - pvr_z->at(idx_pvr) > 0);} // SV downstream of PV //New earlier used for prmpt also

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

  if (option == "displ") {prt_bool_patho      = prt_bool_patho_mu && prt_bool_patho_h && prt_bool_patho_srd;}
  if (option == "prmpt") {prt_bool_patho      = true;}


  material_veto        = bool(tag_veto_h_modmiss->at(mum)) || bool(tag_veto_mu_modmiss->at(mum)) || bool(tag_veto_cutFM->at(mum));
  prt_bool_material_h_modmiss = (!bool(tag_veto_h_modmiss->at(mum)));
  prt_bool_material_mu_modmiss = (!bool(tag_veto_mu_modmiss->at(mum)));
  prt_bool_material_cutFM   = !bool(tag_veto_cutFM->at(mum));
  prt_bool_material        = !material_veto;
  assert((prt_bool_material == (prt_bool_material_h_modmiss && prt_bool_material_mu_modmiss && prt_bool_material_cutFM)));

  if (option == "displ") {prt_bool_material      = !material_veto;}
  if (option == "prmpt") {prt_bool_material      = true;}


  //if (option == "prmpt") {prt_bool_material = true;} //New earlier used for prmpt also

  //prt_bool_material        = prt_bool_material && bool(tag_dmat->at(mum)> ? )

  ////////////////////////////////////////////////////////////////////////////
  //////////////////////   Heavy Flavor Veto   ///////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  prt_bool_prmpt_displ_consistency = bool(mu_pt >1000) && bool(h_pt >1000) && bool(mu_p >20000) && bool(h_p >20000); //New



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

  prt_bool_pid        = true;
  //prt_bool_pid        = (prt_pnn_mu->at(idx_mu) > 0.7) && (prt_pnn_mu->at(idx_h) > 0.7);
  //prt_bool_pid        = (prt_pnn_mu->at(idx_mu) > 0.95) && (prt_pnn_mu->at(idx_h) > 0.95);

  prt_bool_brem        = true;
  prt_bool_brem       = (tag_nu_brem_0->at(mum) == 0) &&  (tag_nu_brem_1->at(mum) == 0); //HasBremAdded http://lhcb-doxygen.web.cern.ch/lhcb-doxygen/lhcb/latest/d0/d13/class_l_h_cb_1_1_particle.html

  ////////////////////////////////////////////////////////////////////////////
  ///////////////////////////   Summary   ////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  //prt_bool_prmpt_displ_consistency = prt_bool_prmpt_displ_consistency;
  prt_bool_trigger_cuts = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip);
  prt_bool_necessary_cuts   = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip && prt_bool_kin && prt_bool_data_consistency && prt_bool_patho && prt_bool_material && prt_bool_pid && prt_bool_brem);
  prt_bool_full        = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip && prt_bool_kin && prt_bool_data_consistency && prt_bool_patho && prt_bool_material && prt_bool_hf && prt_bool_fd_r && prt_bool_pid && prt_bool_prmpt_displ_consistency&& prt_bool_brem);





  std::map<std::string, double> var_dict;
  var_dict[std::string("prt_bool_full")] = double(prt_bool_full);
  var_dict[std::string("tag_tau_ps")] = tag_tau_ps;
  var_dict[std::string("tag_d2")] = tag_d2;
  var_dict[std::string("tag_fd_r")] = tag_fd_r;
  var_dict[std::string("tag_Q")] = tag_Q;
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

  var_dict[std::string("prt_bool_prmpt_displ_consistency")] = double(prt_bool_prmpt_displ_consistency);


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

void Plot_hists_X2ApGm::Ap_Anal(unsigned mum)
{
  // Executed for each dark photon candidate

  idx_mu  = tag_idx_prt0->at(mum);
  idx_h   = tag_idx_prt1->at(mum);
  idx_pvr = tag_idx_pvr->at(mum);

  first_variables = this->Simple_Variables_Calculation(mum);

  prt_bool_full     = bool(first_variables[std::string("prt_bool_full")]);
  tag_tau_ps        = first_variables[std::string("tag_tau_ps")];
  tag_d2            = first_variables[std::string("tag_d2")];
  tag_fd_r          = first_variables[std::string("tag_fd_r")];
  tag_Q             = first_variables[std::string("tag_Q")];
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
  prt_bool_prmpt_displ_consistency = bool(first_variables[std::string("prt_bool_prmpt_displ_consistency")]);

  prt_bool_trigger_cuts = bool(first_variables[std::string("prt_bool_trigger_cuts")]);


  prt_bool_material_h_modmiss      = bool(first_variables[std::string("prt_bool_material_h_modmiss")]);
  prt_bool_material_mu_modmiss      = bool(first_variables[std::string("prt_bool_material_mu_modmiss")]);
  prt_bool_material_cutFM        = bool(first_variables[std::string("prt_bool_material_cutFM")]);



  this->Ap_Plots(mum);

  if (prt_bool_necessary_cuts){
    fn_calos->Fill(calo_px->size());
    for (unsigned calo=0; calo < calo_px->size(); calo++) {

      vector<double> dicalo_masses;
      dicalo_masses.clear();

      for (unsigned calo2=calo+1; calo2 < calo_px->size(); calo2++) {
        TLorentzVector Lp_calo1 = TLorentzVector(calo_px->at(calo), calo_py->at(calo), calo_pz->at(calo),  calo_e->at(calo));
        TLorentzVector Lp_calo2 = TLorentzVector(calo_px->at(calo2), calo_py->at(calo2), calo_pz->at(calo2),  calo_e->at(calo2));
        TLorentzVector Lp_calo1_calo2 = Lp_calo1 + Lp_calo2;
        dicalo_masses.push_back(Lp_calo1_calo2.M());

      }

      //if (calo_idx_pvr->at(calo) == tag_idx_pvr->at(mum)){ //YOu never know where a calo photon came from
        this->Calo_Plots(calo, mum, dicalo_masses);
      //}
    }
  }

}

void Plot_hists_X2ApGm::Ap_Plots(unsigned mum)
  {

  //fM->Fill(tag_dtf_m->at(mum));
  prt_bool            = true;

  if (prt_bool_necessary_cuts){
    fM->Fill(tag_dtf_m->at(mum));
    if (prt_bool_prmpt_displ_consistency){
      fM_prmptfidu->Fill(tag_dtf_m->at(mum));
    }
  }



  //if (prt_bool){if (prt_bool_l0){fM_l0_p->Fill(tag_dtf_m->at(mum));} }
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_l0;}

  //if (prt_bool){if (prt_bool_hlt1){fM_hlt1_p->Fill(tag_dtf_m->at(mum));} }
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_hlt1;}

  //if (prt_bool){if (prt_bool_hlt2){fM_hlt2_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_hlt2;}

  //if (prt_bool){if (prt_bool_strip){fM_strip_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_strip;}

  //if (prt_bool){if (prt_bool_kin){fM_kin_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_kin;}

  //if (prt_bool){if (prt_bool_data_consistency){fM_data_consistency_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_data_consistency;}

  //if (prt_bool){if (prt_bool_patho){fM_patho_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_patho;}

  //if (prt_bool){if (prt_bool_material){fM_material_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_material;}

  //if (not pass_separately) {assert (prt_bool==prt_bool_necessary_cuts);}

  //if (prt_bool){if (prt_bool_pid){fM_pid_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_pid;}

  //if (prt_bool){if (prt_bool_hf){fM_hf_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_hf;}

  //if (prt_bool){if (prt_bool_fd_r){fM_fd_r_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_fd_r;}

  //if (not pass_separately) {assert (prt_bool==prt_bool_full);}


}



void Plot_hists_X2ApGm::Calo_Plots(unsigned calo, unsigned mum, vector<double> dicalo_masses)
{


  TLorentzVector Lp_mu0 = TLorentzVector(prt_px->at(tag_idx_prt0->at(mum)), prt_py->at(tag_idx_prt0->at(mum)), prt_pz->at(tag_idx_prt0->at(mum)), prt_e->at(tag_idx_prt0->at(mum)));
  TLorentzVector Lp_mu1 = TLorentzVector(prt_px->at(tag_idx_prt1->at(mum)), prt_py->at(tag_idx_prt1->at(mum)), prt_pz->at(tag_idx_prt1->at(mum)), prt_e->at(tag_idx_prt1->at(mum)));
  TLorentzVector Lp_calo = TLorentzVector(calo_px->at(calo), calo_py->at(calo), calo_pz->at(calo),  calo_e->at(calo));
  TLorentzVector Lp_mu0_mu1 = Lp_mu0 + Lp_mu1;
  TLorentzVector Lp_calo_mu0 = Lp_calo + Lp_mu0;
  TLorentzVector Lp_calo_mu1 = Lp_calo + Lp_mu1;
  TLorentzVector Lp_calo_mu0_mu1 = Lp_calo + Lp_mu0 + Lp_mu1;


  //TLorentzVector Lx_mu0 = TLorentzVector(prt_x->at(tag_idx_prt0->at(mum)), prt_y->at(tag_idx_prt0->at(mum)), prt_z->at(tag_idx_prt0->at(mum)));
  //TLorentzVector Lx_mu1 = TLorentzVector(prt_x->at(tag_idx_prt1->at(mum)), prt_y->at(tag_idx_prt1->at(mum)), prt_z->at(tag_idx_prt1->at(mum)));
  //TLorentzVector Lx_calo = TLorentzVector(calo_x->at(calo), calo_y->at(calo), calo_z->at(calo));


  double tag_calo_mu0_mu1_m = sqrt(pow(prt_e->at(tag_idx_prt0->at(mum)) + prt_e->at(tag_idx_prt1->at(mum)) + calo_e->at(calo) , 2.0) - pow(prt_px->at(tag_idx_prt0->at(mum)) + prt_px->at(tag_idx_prt1->at(mum)) + calo_px->at(calo) , 2.0) - pow(prt_py->at(tag_idx_prt0->at(mum)) + prt_py->at(tag_idx_prt1->at(mum)) + calo_py->at(calo) , 2.0) - pow(prt_pz->at(tag_idx_prt0->at(mum)) + prt_pz->at(tag_idx_prt1->at(mum)) + calo_pz->at(calo) , 2.0));
  double tag_calo_mu0_m = sqrt(pow(prt_e->at(tag_idx_prt0->at(mum)) + calo_e->at(calo) , 2.0) - pow(prt_px->at(tag_idx_prt0->at(mum)) + calo_px->at(calo) , 2.0) - pow(prt_py->at(tag_idx_prt0->at(mum)) + calo_py->at(calo) , 2.0) - pow(prt_pz->at(tag_idx_prt0->at(mum)) + calo_pz->at(calo) , 2.0));
  double tag_calo_mu1_m = sqrt(pow(prt_e->at(tag_idx_prt1->at(mum)) + calo_e->at(calo) , 2.0) - pow(prt_px->at(tag_idx_prt1->at(mum)) + calo_px->at(calo) , 2.0) - pow(prt_py->at(tag_idx_prt1->at(mum)) + calo_py->at(calo) , 2.0) - pow(prt_pz->at(tag_idx_prt1->at(mum)) + calo_pz->at(calo) , 2.0));
  //this should be very similar to tag_m->at(mum)
  double tag_mu0_mu1_m = sqrt(pow(prt_e->at(tag_idx_prt0->at(mum)) + prt_e->at(tag_idx_prt1->at(mum)) , 2.0) - pow(prt_px->at(tag_idx_prt0->at(mum)) + prt_px->at(tag_idx_prt1->at(mum)) , 2.0) - pow(prt_py->at(tag_idx_prt0->at(mum)) + prt_py->at(tag_idx_prt1->at(mum)) , 2.0) - pow(prt_pz->at(tag_idx_prt0->at(mum)) + prt_pz->at(tag_idx_prt1->at(mum)) , 2.0));


  //assert(1.1==1.2);
  //assert(tag_calo_mu0_mu1_m == Lp_calo_mu0_mu1.M());
  //assert(tag_calo_mu0_m == Lp_calo_mu0.M());
  //assert(tag_calo_mu1_m == Lp_calo_mu1.M());
  //assert(tag_mu0_mu1_m == Lp_mu0_mu1.M());

  if(1.1==1.2){std::cout << "Assertions not working\n\n";}

  if (((tag_calo_mu0_mu1_m - Lp_calo_mu0_mu1.M())/ (tag_calo_mu0_mu1_m + Lp_calo_mu0_mu1.M())) > 0.001 ){std::cout << "calo mu0 mu1 assertion error! \n\n" << std::endl;}
  if (((tag_calo_mu0_m - Lp_calo_mu0.M())/ (tag_calo_mu0_m + Lp_calo_mu0.M())) >0.001){std::cout << "calo mu0 assertion error! \n\n" << std::endl;}
  if (((tag_calo_mu1_m - Lp_calo_mu1.M())/ (tag_calo_mu1_m + Lp_calo_mu1.M())) >0.001){std::cout << "calo mu1 assertion error! \n\n" << std::endl;}
  if (((tag_mu0_mu1_m - Lp_mu0_mu1.M())/ (tag_mu0_mu1_m + Lp_mu0_mu1.M())) > 0.001){std::cout << "mu0 mu1 assertion error! \n\n" << std::endl;}

  // Distance between calo and muons
  double ux_prt0 = prt_ecal_face_x->at(tag_idx_prt0->at(mum)) - calo_x->at(calo);
  double uy_prt0 = prt_ecal_face_y->at(tag_idx_prt0->at(mum)) - calo_y->at(calo);
  double ux_prt1 = prt_ecal_face_x->at(tag_idx_prt1->at(mum)) - calo_x->at(calo);
  double uy_prt1 = prt_ecal_face_y->at(tag_idx_prt1->at(mum)) - calo_y->at(calo);

  double ecal_calo_dist_prt0 = sqrt( pow( ux_prt0 , 2.0) +  pow( uy_prt0 , 2.0) );
  double ecal_calo_dist_prt1 = sqrt( pow( ux_prt1 , 2.0) +  pow( uy_prt1 , 2.0) );

  double ecal_calo_dist_min = min(ecal_calo_dist_prt0, ecal_calo_dist_prt1);

  //Now uncertainty weighted distance
  // pull = u^T u / sqrt (u^T Sigma u )
  double ulen2_prt0 = pow(ux_prt0, 2.0) + pow(uy_prt0, 2.0);
  double ulen2_prt1 = pow(ux_prt1, 2.0) + pow(uy_prt1, 2.0);
  double uSu_prt0 = ux_prt0 * ux_prt0 * calo_spread_0->at(calo) +  ux_prt0 * uy_prt0 * calo_spread_1->at(calo) + ux_prt0 * uy_prt0 * calo_spread_2->at(calo) + uy_prt0 * uy_prt0 * calo_spread_3->at(calo);
  double uSu_prt1 = ux_prt1 * ux_prt1 * calo_spread_0->at(calo) +  ux_prt1 * uy_prt1 * calo_spread_1->at(calo) + ux_prt1 * uy_prt1 * calo_spread_2->at(calo) + uy_prt1 * uy_prt1 * calo_spread_3->at(calo);

  double ecal_calo_pull_prt0 = ulen2_prt0 / sqrt (uSu_prt0);
  double ecal_calo_pull_prt1 = ulen2_prt1 / sqrt (uSu_prt1);

  double ecal_calo_pull_min = min(ecal_calo_pull_prt0, ecal_calo_pull_prt1);

  // To determine whether the additional photons were brems photons we have to check the following:
  // 1. The brem photon could have been emitted upstream of the magnet. This can be checked by looking at fDphiDeta_calo_mu0 for example.
  //    The prt_bool_brem       = (tag_nu_brem_0->at(mum) == 0) &&  (tag_nu_brem_1->at(mum) == 0); cut should veto brem from here.
  // 2. The photon could have been emitted downstream of the magnet and should then hit the Ecal very
  //    close to the corresponding muon. In this case ecal_calo_pull_min and ecal_calo_dist_min would be small.
  // 3. The photon could have been emitted during the magnet. Then, the calo cluster should lie on the line between prt_ecal_face_x and prt_ecal_face_x_orig_dir.
  //    Let us calculate the projection onto this line and the distance from it

  idx_mu  = tag_idx_prt0->at(mum); //This is really muon 1
  idx_h   = tag_idx_prt1->at(mum); //This is really muon 2
  idx_pvr = tag_idx_pvr->at(mum);

  double z_ecal = 12655.;

  double prt_ecal_face_x_orig_dir0= prt_x->at(idx_mu) + prt_px->at(idx_mu) / prt_pz->at(idx_mu) * (z_ecal - prt_z->at(idx_mu));
  double prt_ecal_face_y_orig_dir0= prt_y->at(idx_mu) + prt_py->at(idx_mu) / prt_pz->at(idx_mu) * (z_ecal - prt_z->at(idx_mu));

  double prt_ecal_face_x_orig_dir1= prt_x->at(idx_h) + prt_px->at(idx_h) / prt_pz->at(idx_h) * (z_ecal - prt_z->at(idx_h));
  double prt_ecal_face_y_orig_dir1= prt_y->at(idx_h) + prt_py->at(idx_h) / prt_pz->at(idx_h) * (z_ecal - prt_z->at(idx_h));


  // A line in linear algebra is described by x = h + t * n,  where t is a scalar and n a unit vector.
  // h = a; n = (b - a) normalised;
  // Let us calculate the projection of a point p onto this line and the distance from it
  TVector2 c = TVector2(calo_x->at(calo), calo_y->at(calo));

  TVector2 a0 = TVector2(prt_ecal_face_x_orig_dir0, prt_ecal_face_y_orig_dir0); //
  TVector2 b0 = TVector2(prt_ecal_face_x->at(idx_mu), prt_ecal_face_y->at(idx_mu));
  TVector2 ab0 = b0 - a0;
  double ab_mag0 = ab0.Mod();
  TVector2 ab_unit0 = ab0.Unit();
  TVector2 ab_anti_unit0 = TVector2(-ab_unit0.Y(), ab_unit0.X());
  TVector2 p0 = a0 + (ab_unit0*(c-a0))*ab_unit0;


  TVector2 a1 = TVector2(prt_ecal_face_x_orig_dir1, prt_ecal_face_y_orig_dir1); //
  TVector2 b1 = TVector2(prt_ecal_face_x->at(idx_h), prt_ecal_face_y->at(idx_h));
  TVector2 ab1 = b1 - a1;
  double ab_mag1 = ab1.Mod();
  TVector2 ab_unit1 = ab1.Unit();
  TVector2 ab_anti_unit1 = TVector2(-ab_unit1.Y(), ab_unit1.X());
  TVector2 p1 = a1 + (ab_unit1*(c-a1))*ab_unit1;


  TVector2 p, a, b, ab_unit, ab_anti_unit;
  double ab_mag;

  if ( (c - p0).Mod() < (c - p1).Mod() ){ // Right now selecting the worse one
    p=p0; a=a0; b=b0; ab_unit=ab_unit0; ab_anti_unit=ab_anti_unit0; ab_mag=ab_mag0;
  }else{
    p=p1; a=a1; b=b1; ab_unit=ab_unit1; ab_anti_unit=ab_anti_unit1; ab_mag=ab_mag1;
  }

  //assert false;
  //assert ((c == p0 +  ab_anti_unit0* (c - p0).Mod() ) && (c == p0 -  ab_anti_unit0* (c - p0).Mod() ));
  // Following the vector formulation on https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line

  double brem_test_AP = (p - a).Mod();
  double brem_test_PC = (c - p).Mod();
  double brem_test_AC = (c - a).Mod();
  double brem_test_BC = (c - b).Mod();
  double brem_test_BP = (p - b).Mod();
  double brem_test_AB = (b - a).Mod();
  double brem_test_2D_x = ((p - a)*ab_unit) / ab_mag;
  double brem_test_2D_y = ((c - p)*ab_anti_unit) / ab_mag;





  //std::cout << "tag_calo_mu1_mu2_m : " << tag_calo_mu1_mu2_m << std::endl;
  if ((tag_calo_mu0_mu1_m < 1100.0) && (calo_eta->at(calo) > 2.) && (calo_eta->at(calo) <4.5) ){ // Only if the calo A' pair has mass less than 1.1 GeV fill hists.
    //if (prt_bool_prmpt_displ_consistency && true) {
    if (true) {  //mu mu pt cut new
      fM_require_calo->Fill(tag_dtf_m->at(mum));
      fM_tag_calo->Fill(tag_calo_mu0_mu1_m);

      double dicalo_mass_close_pi0 = -100000.;
      for(unsigned di_i = 0; di_i < dicalo_masses.size(); di_i++){
        fM_dicalo->Fill(dicalo_masses.at(di_i));
        fM_calomumu_calocalo -> Fill(tag_calo_mu0_mu1_m, dicalo_masses.at(di_i));
        fM_calomumu_calocalo_d -> Fill(tag_calo_mu0_mu1_m, dicalo_masses.at(di_i));

        if ( abs(dicalo_masses.at(di_i) - 134.98) < abs(dicalo_mass_close_pi0 - 134.98)   ) dicalo_mass_close_pi0 = dicalo_masses.at(di_i);
        //std::cout << "dicalo_mass_close_pi0 : " << dicalo_mass_close_pi0 << "\t dicalo_masses.at(di_i) " << dicalo_masses.at(di_i) << std::endl;
      }
      //std::cout << "dicalo_mass_close_pi0 : " << dicalo_mass_close_pi0 << std::endl;

      if (dicalo_mass_close_pi0 != -100000.) fM_calomumu_calocalo_closepi0 -> Fill(tag_calo_mu0_mu1_m, dicalo_mass_close_pi0);






      // Fill Histograms in strict calo mu mu bins.
      if ((500 < tag_calo_mu0_mu1_m ) && (600 > tag_calo_mu0_mu1_m )){
      //if ((500 < tag_calo_mu0_mu1_m ) && (600 > tag_calo_mu0_mu1_m ) && (tag_nu_brem_0->at(mum) == 0) &&  (tag_nu_brem_1->at(mum) == 0)){

        for(unsigned di_i = 0; di_i < dicalo_masses.size(); di_i++){
          fM_mumu_calocalo_m_eta -> Fill(tag_mu0_mu1_m, dicalo_masses.at(di_i));
          if (prt_bool_prmpt_displ_consistency){fM_mumu_calocalo_m_eta_prmptfidu -> Fill(tag_mu0_mu1_m, dicalo_masses.at(di_i));}
        }


        fM_require_calo_at_m_eta->Fill(tag_dtf_m->at(mum));
        if ( tag_tau_ps > 2) {fM_require_calo_at_m_eta_tau_bigger_2ps->Fill(tag_dtf_m->at(mum));}
        else {fM_require_calo_at_m_eta_tau_smaller_2ps->Fill(tag_dtf_m->at(mum));}

        if ( tag_fd_r > 5) {
          fM_require_calo_at_m_eta_r_bigger_5mm->Fill(tag_dtf_m->at(mum));
          fQ_require_calo_at_m_eta_r_bigger_5mm->Fill(tag_Q);
          //if (tag_dtf_m->at(mum) < 220){cout << "M : " << tag_dtf_m->at(mum) << "\t" << tag_Q <<endl;}
        }else {
          fM_require_calo_at_m_eta_r_smaller_5mm->Fill(tag_dtf_m->at(mum));
          fQ_require_calo_at_m_eta_r_smaller_5mm->Fill(tag_Q);
        }



        //if ( (tag_nu_brem_0->at(mum) == 0) &&  (tag_nu_brem_1->at(mum) == 0) ){fM_require_calo_at_m_eta_no_brem->Fill(tag_dtf_m->at(mum));}

        scatter_ecal_calo_dist_m_eta.push_back(ecal_calo_dist_min);
        scatter_ecal_calo_pull_m_eta.push_back(ecal_calo_pull_min);

        dalitz_mu0_mu1_m_eta.push_back(tag_mu0_mu1_m);
        dalitz_calo_mu0_m_eta.push_back(tag_calo_mu0_m);
        dalitz_calo_mu1_m_eta.push_back(tag_calo_mu1_m);

        //Dalitz plots
        //For Displaced



        bool pass_mu0_mu1;
        bool verbose = false;

        if(verbose) {std::cout << "tag_mu0_mu1_m : " << tag_mu0_mu1_m << std::endl;}

        for(unsigned i = 0; i < dalitz_m_mu0_mu1_separation.size()+1; i++)
     	  {
          if (i==0){ pass_mu0_mu1 = (dalitz_m_mu0_mu1_separation[i] > tag_mu0_mu1_m ) ; if (pass_mu0_mu1 && verbose) {std::cout << "lower and upper boundary : " << 0 << "\t" << dalitz_m_mu0_mu1_separation[i] << std::endl;}}
          else if (i==dalitz_m_mu0_mu1_separation.size()){ pass_mu0_mu1 = (dalitz_m_mu0_mu1_separation[i-1] < tag_mu0_mu1_m ) ; if (pass_mu0_mu1 && verbose) {std::cout << "lower and upper boundary : " << dalitz_m_mu0_mu1_separation[i-1] << "\t" << "inf" << std::endl;}}
          else {pass_mu0_mu1 = (  (dalitz_m_mu0_mu1_separation[i-1] < tag_mu0_mu1_m ) && (dalitz_m_mu0_mu1_separation[i] > tag_mu0_mu1_m ) ) ; if (pass_mu0_mu1 && verbose) {std::cout << "lower and upper boundary : " << dalitz_m_mu0_mu1_separation[i-1] << "\t" << dalitz_m_mu0_mu1_separation[i] << std::endl; }}

          if (pass_mu0_mu1){
         		dalitz_mu0_mu1_m_eta_m_mu0_mu1_separated[i].push_back(tag_mu0_mu1_m); // Store the array in the buffer
            dalitz_calo_mu0_m_eta_m_mu0_mu1_separated[i].push_back(tag_calo_mu0_m);
            dalitz_calo_mu1_m_eta_m_mu0_mu1_separated[i].push_back(tag_calo_mu1_m);
          }
     	  }

        fDphiDeta_calo_mu0_m_eta->Fill(Lp_calo.DeltaPhi(Lp_mu0), Lp_calo.Eta() - Lp_mu0.Eta());
        fDphiDeta_calo_m_eta->Fill(calo_phi->at(calo), calo_eta->at(calo));
        fET_calo_m_eta->Fill(TMath::Sqrt(pow(calo_m->at(calo),2.) + pow(calo_pt->at(calo), 2.)));

        fphi_calo_m_eta->Fill(calo_phi->at(calo));
        feta_calo_m_eta->Fill(calo_eta->at(calo));

        fcalo_cl_m_eta->Fill(calo_cl->at(calo));

        if (prt_bool_prmpt_displ_consistency){
          fDphiDeta_calo_mu0_m_eta_prmptfidu->Fill(Lp_calo.DeltaPhi(Lp_mu0), Lp_calo.Eta() - Lp_mu0.Eta());
          fDphiDeta_calo_m_eta_prmptfidu->Fill(calo_phi->at(calo), calo_eta->at(calo));
          fET_calo_m_eta_prmptfidu->Fill(TMath::Sqrt(pow(calo_m->at(calo),2.) + pow(calo_pt->at(calo), 2.)));

          fphi_calo_m_eta_prmptfidu->Fill(calo_phi->at(calo));
          feta_calo_m_eta_prmptfidu->Fill(calo_eta->at(calo));

          fcalo_cl_m_eta_prmptfidu->Fill(calo_cl->at(calo));
        }




        fangle_calo_mu0_m_eta->Fill(Lp_calo.Angle(Lp_mu0.Vect()));
        fangle_calo_mu1_m_eta->Fill(Lp_calo.Angle(Lp_mu1.Vect()));

        fDphi_calo_mu0_m_eta->Fill(Lp_calo.DeltaPhi(Lp_mu0));
        fDphi_calo_mu1_m_eta->Fill(Lp_calo.DeltaPhi(Lp_mu1));

        fDeta_calo_mu0_m_eta->Fill(Lp_calo.Eta() - Lp_mu0.Eta() );
        fDeta_calo_mu1_m_eta->Fill(Lp_calo.Eta() - Lp_mu1.Eta() );

        //if ( TMath::Sqrt(pow(Lp_calo.Eta() - Lp_mu0.Eta(), 2.0) + pow(TVector2::Phi_mpi_pi(Lp_calo.DeltaPhi(Lp_mu0)), 2.)) != Lp_calo.DeltaR(Lp_mu0) )  {  std::cout << "Problems calculating delta R" << std::endl;}
        if ( TMath::Sqrt(pow(Lp_calo.Eta() - Lp_mu0.Eta(), 2.0) + pow(Lp_calo.DeltaPhi(Lp_mu0), 2.)) != Lp_calo.DeltaR(Lp_mu0) )  {  std::cout << "Problems calculating delta R" << std::endl;}

        fDR_calo_mu0_m_eta->Fill(Lp_calo.DeltaR(Lp_mu0));
        fDR_calo_mu1_m_eta->Fill(Lp_calo.DeltaR(Lp_mu1));

        fM_calo_mu0_m_eta->Fill(tag_calo_mu0_m);
        fM_calo_mu1_m_eta->Fill(tag_calo_mu1_m);



        fecal_calo_pull_m_eta->Fill(ecal_calo_pull_min);
        fecal_calo_dist_m_eta->Fill(ecal_calo_dist_min);

        fbrem_test_AP_m_eta->Fill(brem_test_AP);
        fbrem_test_PC_m_eta->Fill(brem_test_PC);
        fbrem_test_AC_m_eta->Fill(brem_test_AC);
        fbrem_test_BC_m_eta->Fill(brem_test_BC);
        fbrem_test_BP_m_eta->Fill(brem_test_BP);
        fbrem_test_AB_m_eta->Fill(brem_test_AB);
        fbrem_test_2D_m_eta->Fill(brem_test_2D_x, brem_test_2D_y);

        if (prt_bool_prmpt_displ_consistency){
          fbrem_test_AP_m_eta_prmptfidu->Fill(brem_test_AP);
          fbrem_test_PC_m_eta_prmptfidu->Fill(brem_test_PC);
          fbrem_test_AC_m_eta_prmptfidu->Fill(brem_test_AC);
          fbrem_test_BC_m_eta_prmptfidu->Fill(brem_test_BC);
          fbrem_test_BP_m_eta_prmptfidu->Fill(brem_test_BP);
          fbrem_test_AB_m_eta_prmptfidu->Fill(brem_test_AB);
          fbrem_test_2D_m_eta_prmptfidu->Fill(brem_test_2D_x, brem_test_2D_y);
        }

      } else{

        scatter_ecal_calo_dist_not_m_eta.push_back(ecal_calo_dist_min);
        scatter_ecal_calo_pull_not_m_eta.push_back(ecal_calo_pull_min);

        dalitz_mu0_mu1_not_m_eta.push_back(tag_mu0_mu1_m);
        dalitz_calo_mu0_not_m_eta.push_back(tag_calo_mu0_m);
        dalitz_calo_mu1_not_m_eta.push_back(tag_calo_mu1_m);

        fDphiDeta_calo_mu0_not_m_eta->Fill(Lp_calo.DeltaPhi(Lp_mu0), Lp_calo.Eta() - Lp_mu0.Eta());

        fDphiDeta_calo_not_m_eta->Fill(calo_phi->at(calo), calo_eta->at(calo));
        fET_calo_not_m_eta->Fill(TMath::Sqrt(pow(calo_m->at(calo),2.) + pow(calo_pt->at(calo), 2.)));

        fphi_calo_not_m_eta->Fill(calo_phi->at(calo));
        feta_calo_not_m_eta->Fill(calo_eta->at(calo));

        fangle_calo_mu0_not_m_eta->Fill(Lp_calo.Angle(Lp_mu0.Vect()));
        fangle_calo_mu1_not_m_eta->Fill(Lp_calo.Angle(Lp_mu1.Vect()));

        fDphi_calo_mu0_not_m_eta->Fill(Lp_calo.DeltaPhi(Lp_mu0));
        fDphi_calo_mu1_not_m_eta->Fill(Lp_calo.DeltaPhi(Lp_mu1));

        fDeta_calo_mu0_not_m_eta->Fill(Lp_calo.Eta() - Lp_mu0.Eta() );
        fDeta_calo_mu1_not_m_eta->Fill(Lp_calo.Eta() - Lp_mu1.Eta() );

        fDR_calo_mu0_not_m_eta->Fill(Lp_calo.DeltaR(Lp_mu0));
        fDR_calo_mu1_not_m_eta->Fill(Lp_calo.DeltaR(Lp_mu1));

        fM_calo_mu0_not_m_eta->Fill(tag_calo_mu0_m);
        fM_calo_mu1_not_m_eta->Fill(tag_calo_mu1_m);

        fcalo_cl_not_m_eta->Fill(calo_cl->at(calo));

        fecal_calo_pull_not_m_eta->Fill(ecal_calo_pull_min);
        fecal_calo_dist_not_m_eta->Fill(ecal_calo_dist_min);

        fbrem_test_AP_not_m_eta->Fill(brem_test_AP);
        fbrem_test_PC_not_m_eta->Fill(brem_test_PC);
        fbrem_test_AC_not_m_eta->Fill(brem_test_AC);
        fbrem_test_BC_not_m_eta->Fill(brem_test_BC);
        fbrem_test_BP_not_m_eta->Fill(brem_test_BP);
        fbrem_test_AB_not_m_eta->Fill(brem_test_AB);
        fbrem_test_2D_not_m_eta->Fill(brem_test_2D_x, brem_test_2D_y);


      }





      // Fill the sidebands for the background substraction
      // For Prompt
      if ((450 < tag_calo_mu0_mu1_m ) && (500 > tag_calo_mu0_mu1_m )){

        fDphiDeta_calo_mu0_m_450_500->Fill(Lp_calo.DeltaPhi(Lp_mu0), Lp_calo.Eta() - Lp_mu0.Eta());

        fDphiDeta_calo_m_450_500->Fill(calo_phi->at(calo), calo_eta->at(calo));
        fET_calo_m_450_500->Fill(TMath::Sqrt(pow(calo_m->at(calo),2.) + pow(calo_pt->at(calo), 2.)));

        fphi_calo_m_450_500->Fill(calo_phi->at(calo));
        feta_calo_m_450_500->Fill(calo_eta->at(calo));

        fangle_calo_mu0_m_450_500->Fill(Lp_calo.Angle(Lp_mu0.Vect()));
        fangle_calo_mu1_m_450_500->Fill(Lp_calo.Angle(Lp_mu1.Vect()));

        fDphi_calo_mu0_m_450_500->Fill(Lp_calo.DeltaPhi(Lp_mu0));
        fDphi_calo_mu1_m_450_500->Fill(Lp_calo.DeltaPhi(Lp_mu1));

        fDeta_calo_mu0_m_450_500->Fill(Lp_calo.Eta() - Lp_mu0.Eta() );
        fDeta_calo_mu1_m_450_500->Fill(Lp_calo.Eta() - Lp_mu1.Eta() );

        fDR_calo_mu0_m_450_500->Fill(Lp_calo.DeltaR(Lp_mu0));
        fDR_calo_mu1_m_450_500->Fill(Lp_calo.DeltaR(Lp_mu1));

        fM_calo_mu0_m_450_500->Fill(tag_calo_mu0_m);
        fM_calo_mu1_m_450_500->Fill(tag_calo_mu1_m);

        fcalo_cl_m_450_500->Fill(calo_cl->at(calo));

        fecal_calo_pull_m_450_500->Fill(ecal_calo_pull_min);
        fecal_calo_dist_m_450_500->Fill(ecal_calo_dist_min);

        fbrem_test_AP_m_450_500->Fill(brem_test_AP);
        fbrem_test_PC_m_450_500->Fill(brem_test_PC);
        fbrem_test_AC_m_450_500->Fill(brem_test_AC);
        fbrem_test_BC_m_450_500->Fill(brem_test_BC);
        fbrem_test_BP_m_450_500->Fill(brem_test_BP);
        fbrem_test_AB_m_450_500->Fill(brem_test_AB);
        fbrem_test_2D_m_450_500->Fill(brem_test_2D_x, brem_test_2D_y);

      } else if ((600 < tag_calo_mu0_mu1_m ) && (650 > tag_calo_mu0_mu1_m )){

        fDphiDeta_calo_mu0_m_600_650->Fill(Lp_calo.DeltaPhi(Lp_mu0), Lp_calo.Eta() - Lp_mu0.Eta());

        fDphiDeta_calo_m_600_650->Fill(calo_phi->at(calo), calo_eta->at(calo));
        fET_calo_m_600_650->Fill(TMath::Sqrt(pow(calo_m->at(calo),2.) + pow(calo_pt->at(calo), 2.)));

        fphi_calo_m_600_650->Fill(calo_phi->at(calo));
        feta_calo_m_600_650->Fill(calo_eta->at(calo));

        fangle_calo_mu0_m_600_650->Fill(Lp_calo.Angle(Lp_mu0.Vect()));
        fangle_calo_mu1_m_600_650->Fill(Lp_calo.Angle(Lp_mu1.Vect()));

        fDphi_calo_mu0_m_600_650->Fill(Lp_calo.DeltaPhi(Lp_mu0));
        fDphi_calo_mu1_m_600_650->Fill(Lp_calo.DeltaPhi(Lp_mu1));

        fDeta_calo_mu0_m_600_650->Fill(Lp_calo.Eta() - Lp_mu0.Eta() );
        fDeta_calo_mu1_m_600_650->Fill(Lp_calo.Eta() - Lp_mu1.Eta() );

        fDR_calo_mu0_m_600_650->Fill(Lp_calo.DeltaR(Lp_mu0));
        fDR_calo_mu1_m_600_650->Fill(Lp_calo.DeltaR(Lp_mu1));

        fM_calo_mu0_m_600_650->Fill(tag_calo_mu0_m);
        fM_calo_mu1_m_600_650->Fill(tag_calo_mu1_m);

        fcalo_cl_m_600_650->Fill(calo_cl->at(calo));

        fecal_calo_pull_m_600_650->Fill(ecal_calo_pull_min);
        fecal_calo_dist_m_600_650->Fill(ecal_calo_dist_min);

        fbrem_test_AP_m_600_650->Fill(brem_test_AP);
        fbrem_test_PC_m_600_650->Fill(brem_test_PC);
        fbrem_test_AC_m_600_650->Fill(brem_test_AC);
        fbrem_test_BC_m_600_650->Fill(brem_test_BC);
        fbrem_test_BP_m_600_650->Fill(brem_test_BP);
        fbrem_test_AB_m_600_650->Fill(brem_test_AB);
        fbrem_test_2D_m_600_650->Fill(brem_test_2D_x, brem_test_2D_y);

      }

      // Do the background substraction
      fDphiDeta_calo_mu0_sideband->Add(fDphiDeta_calo_mu0_m_450_500, fDphiDeta_calo_mu0_m_600_650, 1., 1.);
      fDphiDeta_calo_mu1_sideband->Add(fDphiDeta_calo_mu1_m_450_500, fDphiDeta_calo_mu1_m_600_650, 1., 1.);
      fDphiDeta_calo_mu0_m_eta_backgr_subtr->Add(fDphiDeta_calo_mu0_m_eta, fDphiDeta_calo_mu0_sideband, 1., -1.);
      fDphiDeta_calo_mu1_m_eta_backgr_subtr->Add(fDphiDeta_calo_mu1_m_eta, fDphiDeta_calo_mu1_sideband, 1., -1.);

      fDphiDeta_calo_sideband->Add(fDphiDeta_calo_m_450_500, fDphiDeta_calo_m_600_650, 1., 1.);
      fET_calo_sideband->Add(fET_calo_m_450_500, fET_calo_m_600_650, 1., 1.);
      fDphiDeta_calo_m_eta_backgr_subtr->Add(fDphiDeta_calo_m_eta, fDphiDeta_calo_sideband, 1., -1.);
      fET_calo_m_eta_backgr_subtr->Add(fET_calo_m_eta, fET_calo_sideband, 1., -1.);

      fphi_calo_sideband->Add(fphi_calo_m_450_500, fphi_calo_m_600_650, 1., 1.);
      feta_calo_sideband->Add(feta_calo_m_450_500, feta_calo_m_600_650, 1., 1.);
      fphi_calo_m_eta_backgr_subtr->Add(fphi_calo_m_eta, fphi_calo_sideband, 1., -1.);
      feta_calo_m_eta_backgr_subtr->Add(feta_calo_m_eta, feta_calo_sideband, 1., -1.);

      fangle_calo_mu0_sideband->Add(fangle_calo_mu0_m_450_500, fangle_calo_mu0_m_600_650, 1., 1.);
      fangle_calo_mu1_sideband->Add(fangle_calo_mu1_m_450_500, fangle_calo_mu1_m_600_650, 1., 1.);
      fangle_calo_mu0_m_eta_backgr_subtr->Add(fangle_calo_mu0_m_eta, fangle_calo_mu0_sideband, 1., -1.);
      fangle_calo_mu1_m_eta_backgr_subtr->Add(fangle_calo_mu1_m_eta, fangle_calo_mu1_sideband, 1., -1.);

      fDphi_calo_mu0_sideband->Add(fDphi_calo_mu0_m_450_500, fDphi_calo_mu0_m_600_650, 1., 1.);
      fDphi_calo_mu1_sideband->Add(fDphi_calo_mu1_m_450_500, fDphi_calo_mu1_m_600_650, 1., 1.);
      fDphi_calo_mu0_m_eta_backgr_subtr->Add(fDphi_calo_mu0_m_eta, fDphi_calo_mu0_sideband, 1., -1.);
      fDphi_calo_mu1_m_eta_backgr_subtr->Add(fDphi_calo_mu1_m_eta, fDphi_calo_mu1_sideband, 1., -1.);

      fDeta_calo_mu0_sideband->Add(fDeta_calo_mu0_m_450_500, fDeta_calo_mu0_m_600_650, 1., 1.);
      fDeta_calo_mu1_sideband->Add(fDeta_calo_mu1_m_450_500, fDeta_calo_mu1_m_600_650, 1., 1.);
      fDeta_calo_mu0_m_eta_backgr_subtr->Add(fDeta_calo_mu0_m_eta, fDeta_calo_mu0_sideband, 1., -1.);
      fDeta_calo_mu1_m_eta_backgr_subtr->Add(fDeta_calo_mu1_m_eta, fDeta_calo_mu1_sideband, 1., -1.);

      fDR_calo_mu0_sideband->Add(fDR_calo_mu0_m_450_500, fDR_calo_mu0_m_600_650, 1., 1.);
      fDR_calo_mu1_sideband->Add(fDR_calo_mu1_m_450_500, fDR_calo_mu1_m_600_650, 1., 1.);
      fDR_calo_mu0_m_eta_backgr_subtr->Add(fDR_calo_mu0_m_eta, fDR_calo_mu0_sideband, 1., -1.);
      fDR_calo_mu1_m_eta_backgr_subtr->Add(fDR_calo_mu1_m_eta, fDR_calo_mu1_sideband, 1., -1.);

      fM_calo_mu0_sideband->Add(fM_calo_mu0_m_450_500, fM_calo_mu0_m_600_650, 1., 1.);
      fM_calo_mu1_sideband->Add(fM_calo_mu1_m_450_500, fM_calo_mu1_m_600_650, 1., 1.);
      fM_calo_mu0_m_eta_backgr_subtr->Add(fM_calo_mu0_m_eta, fM_calo_mu0_sideband, 1., -1.);
      fM_calo_mu1_m_eta_backgr_subtr->Add(fM_calo_mu1_m_eta, fM_calo_mu1_sideband, 1., -1.);

      fcalo_cl_sideband->Add(fcalo_cl_m_450_500, fcalo_cl_m_600_650, 1., 1.);
      fcalo_cl_m_eta_backgr_subtr->Add(fcalo_cl_m_eta, fcalo_cl_sideband, 1., -1.);

      fecal_calo_pull_sideband->Add(fecal_calo_pull_m_450_500, fecal_calo_pull_m_600_650, 1., 1.);
      fecal_calo_dist_sideband->Add(fecal_calo_dist_m_450_500, fecal_calo_dist_m_600_650, 1., 1.);
      fecal_calo_pull_m_eta_backgr_subtr->Add(fecal_calo_pull_m_eta, fecal_calo_pull_sideband, 1., -1.);
      fecal_calo_dist_m_eta_backgr_subtr->Add(fecal_calo_dist_m_eta, fecal_calo_dist_sideband, 1., -1.);

      fbrem_test_AP_sideband->Add(fbrem_test_AP_m_450_500, fbrem_test_AP_m_600_650, 1., 1.);
      fbrem_test_PC_sideband->Add(fbrem_test_PC_m_450_500, fbrem_test_PC_m_600_650, 1., 1.);
      fbrem_test_AC_sideband->Add(fbrem_test_AC_m_450_500, fbrem_test_AC_m_600_650, 1., 1.);
      fbrem_test_BC_sideband->Add(fbrem_test_BC_m_450_500, fbrem_test_BC_m_600_650, 1., 1.);
      fbrem_test_BP_sideband->Add(fbrem_test_BP_m_450_500, fbrem_test_BP_m_600_650, 1., 1.);
      fbrem_test_AB_sideband->Add(fbrem_test_AB_m_450_500, fbrem_test_AB_m_600_650, 1., 1.);
      fbrem_test_2D_sideband->Add(fbrem_test_2D_m_450_500, fbrem_test_2D_m_600_650, 1., 1.);

      fbrem_test_AP_m_eta_backgr_subtr->Add(fbrem_test_AP_m_eta, fbrem_test_AP_sideband, 1., -1.);
      fbrem_test_PC_m_eta_backgr_subtr->Add(fbrem_test_PC_m_eta, fbrem_test_PC_sideband, 1., -1.);
      fbrem_test_AC_m_eta_backgr_subtr->Add(fbrem_test_AC_m_eta, fbrem_test_AC_sideband, 1., -1.);
      fbrem_test_BC_m_eta_backgr_subtr->Add(fbrem_test_BC_m_eta, fbrem_test_BC_sideband, 1., -1.);
      fbrem_test_BP_m_eta_backgr_subtr->Add(fbrem_test_BP_m_eta, fbrem_test_BP_sideband, 1., -1.);
      fbrem_test_AB_m_eta_backgr_subtr->Add(fbrem_test_AB_m_eta, fbrem_test_AB_sideband, 1., -1.);
      fbrem_test_2D_m_eta_backgr_subtr->Add(fbrem_test_2D_m_eta, fbrem_test_2D_sideband, 1., -1.);




      // Fill for any mass range

      scatter_ecal_calo_dist.push_back(ecal_calo_dist_min);
      scatter_ecal_calo_pull.push_back(ecal_calo_pull_min);

      dalitz_mu0_mu1.push_back(tag_mu0_mu1_m);
      dalitz_calo_mu0.push_back(tag_calo_mu0_m);
      dalitz_calo_mu1.push_back(tag_calo_mu1_m);

      fangle_calo_mu0->Fill(Lp_calo.Angle(Lp_mu0.Vect()));
      fangle_calo_mu1->Fill(Lp_calo.Angle(Lp_mu1.Vect()));

      fDphi_calo_mu0->Fill(Lp_calo.DeltaPhi(Lp_mu0));
      fDphi_calo_mu1->Fill(Lp_calo.DeltaPhi(Lp_mu1));

      fDeta_calo_mu0->Fill(Lp_calo.Eta() - Lp_mu0.Eta() );
      fDeta_calo_mu1->Fill(Lp_calo.Eta() - Lp_mu1.Eta() );

      fDR_calo_mu0->Fill(Lp_calo.DeltaR(Lp_mu0));
      fDR_calo_mu1->Fill(Lp_calo.DeltaR(Lp_mu1));

      fM_calo_mu0->Fill(tag_calo_mu0_m);
      fM_calo_mu1->Fill(tag_calo_mu1_m);

      fcalo_cl->Fill(calo_cl->at(calo));

      fecal_calo_pull->Fill(ecal_calo_pull_min);
      fecal_calo_dist->Fill(ecal_calo_dist_min);

    }
  }

}

void Plot_hists_X2ApGm::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Plot_hists_X2ApGm::Plot_Dalitz_Graphs()
{
  std::ofstream scatter_file;

  /////////////////////////////////

  if (option == "prmpt"){scatter_file.open("csvs/Prmpt_X2ApGm_dalitz.csv");}
  else if (option == "displ"){scatter_file.open("csvs/Displ_X2ApGm_dalitz.csv");}
  else if (option == "Test"){scatter_file.open("csvs/Test_X2ApGm_dalitz.csv");}

  for (unsigned j=0; j < dalitz_mu0_mu1.size(); j++) {
    scatter_file << dalitz_mu0_mu1.at(j)<<",";
    scatter_file << dalitz_calo_mu0.at(j)<<",";
    scatter_file << dalitz_calo_mu1.at(j)<<"\n";
  }

  scatter_file.close();

  /////////////////////////////////

  if (option == "prmpt"){scatter_file.open("csvs/Prmpt_X2ApGm_dalitz_m_eta.csv");}
  else if (option == "displ"){scatter_file.open("csvs/Displ_X2ApGm_dalitz_m_eta.csv");}
  else if (option == "Test"){scatter_file.open("csvs/Test_X2ApGm_dalitz_m_eta.csv");}

  for (unsigned j=0; j < dalitz_mu0_mu1_m_eta.size(); j++) {
    scatter_file << dalitz_mu0_mu1_m_eta.at(j)<<",";
    scatter_file << dalitz_calo_mu0_m_eta.at(j)<<",";
    scatter_file << dalitz_calo_mu1_m_eta.at(j)<<"\n";
  }

  scatter_file.close();

  /////////////////////////////////

  if (option == "prmpt"){scatter_file.open("csvs/Prmpt_X2ApGm_dalitz_not_m_eta.csv");}
  else if (option == "displ"){scatter_file.open("csvs/Displ_X2ApGm_dalitz_not_m_eta.csv");}
  else if (option == "Test"){scatter_file.open("csvs/Test_X2ApGm_dalitz_not_m_eta.csv");}

  for (unsigned j=0; j < dalitz_mu0_mu1_not_m_eta.size(); j++) {
    scatter_file << dalitz_mu0_mu1_not_m_eta.at(j)<<",";
    scatter_file << dalitz_calo_mu0_not_m_eta.at(j)<<",";
    scatter_file << dalitz_calo_mu1_not_m_eta.at(j)<<"\n";
  }

  scatter_file.close();

  /////////////////////////////////

  std::string lower_boundary_name, upper_boundary_name;

  for(unsigned i = 0; i < dalitz_m_mu0_mu1_separation.size()+1; i++)
  {
    if (i==0){ lower_boundary_name=std::to_string(0); upper_boundary_name=std::to_string(dalitz_m_mu0_mu1_separation[i]);}
    else if (i==dalitz_m_mu0_mu1_separation.size()){ lower_boundary_name =std::to_string(dalitz_m_mu0_mu1_separation[i-1]); upper_boundary_name= std::to_string(std::numeric_limits<double>::infinity());}
    else {lower_boundary_name=std::to_string(dalitz_m_mu0_mu1_separation[i-1]); upper_boundary_name=std::to_string(dalitz_m_mu0_mu1_separation[i]);}

    if (option == "prmpt"){scatter_file.open("csvs/Prmpt_X2ApGm_dalitz_m_eta_m_mu0_mu1_" + lower_boundary_name+ "_" + upper_boundary_name + ".csv");}
    else if (option == "displ"){scatter_file.open("csvs/Displ_X2ApGm_dalitz_m_eta_m_mu0_mu1_" + lower_boundary_name+ "_" + upper_boundary_name + ".csv");}
    else if (option == "Test"){scatter_file.open("csvs/Test_X2ApGm_dalitz_m_eta_m_mu0_mu1_" + lower_boundary_name+ "_" + upper_boundary_name + ".csv");}

    for (unsigned j=0; j < dalitz_mu0_mu1_m_eta_m_mu0_mu1_separated[i].size(); j++) {
      scatter_file << dalitz_mu0_mu1_m_eta_m_mu0_mu1_separated[i].at(j)<<",";
      scatter_file << dalitz_calo_mu0_m_eta_m_mu0_mu1_separated[i].at(j)<<",";
      scatter_file << dalitz_calo_mu1_m_eta_m_mu0_mu1_separated[i].at(j)<<"\n";
    }

    scatter_file.close();
  }

  /////////////////////////////////

  if (option == "prmpt"){scatter_file.open("csvs/Prmpt_X2ApGm_scatter_ecal_calo_dist.csv");}
  else if (option == "displ"){scatter_file.open("csvs/Displ_X2ApGm_scatter_ecal_calo_dist.csv");}
  else if (option == "Test"){scatter_file.open("csvs/Test_X2ApGm_scatter_ecal_calo_dist.csv");}

  for (unsigned j=0; j < scatter_ecal_calo_pull.size(); j++) {
    scatter_file << scatter_ecal_calo_dist.at(j)<<",";
    scatter_file << scatter_ecal_calo_pull.at(j)<<"\n";
  }

  scatter_file.close();

  /////////////////////////////////

  if (option == "prmpt"){scatter_file.open("csvs/Prmpt_X2ApGm_scatter_ecal_calo_dist_m_eta.csv");}
  else if (option == "displ"){scatter_file.open("csvs/Displ_X2ApGm_scatter_ecal_calo_dist_m_eta.csv");}
  else if (option == "Test"){scatter_file.open("csvs/Test_X2ApGm_scatter_ecal_calo_dist_m_eta.csv");}

  for (unsigned j=0; j < scatter_ecal_calo_pull_m_eta.size(); j++) {
    scatter_file << scatter_ecal_calo_dist_m_eta.at(j)<<",";
    scatter_file << scatter_ecal_calo_pull_m_eta.at(j)<<"\n";
  }

  scatter_file.close();

  /////////////////////////////////

  if (option == "prmpt"){scatter_file.open("csvs/Prmpt_X2ApGm_scatter_ecal_calo_dist_not_m_eta.csv");}
  else if (option == "displ"){scatter_file.open("csvs/Displ_X2ApGm_scatter_ecal_calo_dist_not_m_eta.csv");}
  else if (option == "Test"){scatter_file.open("csvs/Test_X2ApGm_scatter_ecal_calo_dist_not_m_eta.csv");}

  for (unsigned j=0; j < scatter_ecal_calo_pull_not_m_eta.size(); j++) {
    scatter_file << scatter_ecal_calo_dist_not_m_eta.at(j)<<",";
    scatter_file << scatter_ecal_calo_pull_not_m_eta.at(j)<<"\n";
  }

  scatter_file.close();

  /////////////////////////////////


}

void Plot_hists_X2ApGm::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   this->Plot_Dalitz_Graphs();


   std::cout << "Writing Hists to File" << std::endl;

   //gDirectory->Add(l_x_scatter);
   gDirectory->ls();

   f->Write();
   f->Close();

   std::cout << "Saying goodbye" << std::endl;

}
