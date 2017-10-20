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
   if (option == "displ"){f = new TFile("NTuple_X2ApGm_all_files_plots_displ.root","RECREATE");}
   else if (option == "prmpt"){f = new TFile("NTuple_X2ApGm_all_files_plots_prmpt.root","RECREATE");}
   else if (option == "Test"){f = new TFile("NTuple_X2ApGm_all_files_plots_test.root","RECREATE");}
   else{ std::cout << std::endl << std::endl << "NO VALID OPTION" << std::endl << std::endl;}

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



   // H I S T O G R A M S

   fM = new TH1F("M", "M;A' M [MeV];TEvts", nmbins, mbins);
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


   fM_tag_calo = new TH1F("M_tag_calo", "M_tag_calo ;mu mu calo M [MeV];TEvts", nmbins2, mbins2);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0 = new TH1F("M_calo_mu0", "M_calo_mu0 ; calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1 = new TH1F("M_calo_mu1", "M_calo_mu1 ; calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fangle_calo_mu0 = new TH1F("angle_calo_mu0", "angle_calo_mu0 ; angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1 = new TH1F("angle_calo_mu1", "angle_calo_mu1 ; angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0 = new TH1F("Dphi_calo_mu0", "Dphi_calo_mu0 ; Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1 = new TH1F("Dphi_calo_mu1", "Dphi_calo_mu1 ; Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0 = new TH1F("Deta_calo_mu0", "Deta_calo_mu0 ; Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1 = new TH1F("Deta_calo_mu1", "Deta_calo_mu1 ; Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0 = new TH1F("DR_calo_mu0", "DR_calo_mu0 ; Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1 = new TH1F("DR_calo_mu1", "DR_calo_mu1 ; Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl = new TH1F("calo_cl", "calo_cl ; Calo Confidence Level;TEvts", 100, 0., 1.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_m_eta = new TH1F("M_calo_mu0_m_eta", "M_calo_mu0_m_eta ; signal calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_m_eta = new TH1F("M_calo_mu1_m_eta", "M_calo_mu1_m_eta ; signal calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fangle_calo_mu0_m_eta = new TH1F("angle_calo_mu0_m_eta", "angle_calo_mu0_m_eta ; signal angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_m_eta = new TH1F("angle_calo_mu1_m_eta", "angle_calo_mu1_m_eta ; signal angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_m_eta = new TH1F("Dphi_calo_mu0_m_eta", "Dphi_calo_mu0_m_eta ; signal Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_m_eta = new TH1F("Dphi_calo_mu1_m_eta", "Dphi_calo_mu1_m_eta ; signal Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_m_eta = new TH1F("Deta_calo_mu0_m_eta", "Deta_calo_mu0_m_eta ; signal Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_m_eta = new TH1F("Deta_calo_mu1_m_eta", "Deta_calo_mu1_m_eta ; signal Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_m_eta = new TH1F("DR_calo_mu0_m_eta", "DR_calo_mu0_m_eta ; signal Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_m_eta = new TH1F("DR_calo_mu1_m_eta", "DR_calo_mu1_m_eta ; signal Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_m_eta = new TH1F("calo_cl_m_eta", "calo_cl_m_eta ; Calo Confidence Level;TEvts", 100, 0., 1.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_not_m_eta = new TH1F("M_calo_mu0_not_m_eta", "M_calo_mu0_not_m_eta ; sideband calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_not_m_eta = new TH1F("M_calo_mu1_not_m_eta", "M_calo_mu1_not_m_eta ; sideband calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fangle_calo_mu0_not_m_eta = new TH1F("angle_calo_mu0_not_m_eta", "angle_calo_mu0_not_m_eta ; sideband angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_not_m_eta = new TH1F("angle_calo_mu1_not_m_eta", "angle_calo_mu1_not_m_eta ; sideband angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_not_m_eta = new TH1F("Dphi_calo_mu0_not_m_eta", "Dphi_calo_mu0_not_m_eta ; sideband Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_not_m_eta = new TH1F("Dphi_calo_mu1_not_m_eta", "Dphi_calo_mu1_not_m_eta ; sideband Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_not_m_eta = new TH1F("Deta_calo_mu0_not_m_eta", "Deta_calo_mu0_not_m_eta ; sideband Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_not_m_eta = new TH1F("Deta_calo_mu1_not_m_eta", "Deta_calo_mu1_not_m_eta ; sideband Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_not_m_eta = new TH1F("DR_calo_mu0_not_m_eta", "DR_calo_mu0_not_m_eta ; sideband Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_not_m_eta = new TH1F("DR_calo_mu1_not_m_eta", "DR_calo_mu1_not_m_eta ; sideband Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_not_m_eta = new TH1F("calo_cl_not_m_eta", "calo_cl_not_m_eta ; Calo Confidence Level;TEvts", 100, 0., 1.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_m_eta_backgr_subtr = new TH1F("M_calo_mu0_m_eta_backgr_subtr", "M_calo_mu0_m_eta_backgr_subtr ; signal calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_m_eta_backgr_subtr = new TH1F("M_calo_mu1_m_eta_backgr_subtr", "M_calo_mu1_m_eta_backgr_subtr ; signal calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fangle_calo_mu0_m_eta_backgr_subtr = new TH1F("angle_calo_mu0_m_eta_backgr_subtr", "angle_calo_mu0_m_eta_backgr_subtr ; signal angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_m_eta_backgr_subtr = new TH1F("angle_calo_mu1_m_eta_backgr_subtr", "angle_calo_mu1_m_eta_backgr_subtr ; signal angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_m_eta_backgr_subtr = new TH1F("Dphi_calo_mu0_m_eta_backgr_subtr", "Dphi_calo_mu0_m_eta_backgr_subtr ; signal Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_m_eta_backgr_subtr = new TH1F("Dphi_calo_mu1_m_eta_backgr_subtr", "Dphi_calo_mu1_m_eta_backgr_subtr ; signal Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_m_eta_backgr_subtr = new TH1F("Deta_calo_mu0_m_eta_backgr_subtr", "Deta_calo_mu0_m_eta_backgr_subtr ; signal Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_m_eta_backgr_subtr = new TH1F("Deta_calo_mu1_m_eta_backgr_subtr", "Deta_calo_mu1_m_eta_backgr_subtr ; signal Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_m_eta_backgr_subtr = new TH1F("DR_calo_mu0_m_eta_backgr_subtr", "DR_calo_mu0_m_eta_backgr_subtr ; signal Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_m_eta_backgr_subtr = new TH1F("DR_calo_mu1_m_eta_backgr_subtr", "DR_calo_mu1_m_eta_backgr_subtr ; signal Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_m_eta_backgr_subtr = new TH1F("calo_cl_m_eta_backgr_subtr", "calo_cl_m_eta_backgr_subtr ; Calo Confidence Level;TEvts", 100, 0., 1.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_m_450_500 = new TH1F("M_calo_mu0_m_450_500", "M_calo_mu0_m_450_500 ; calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_m_450_500 = new TH1F("M_calo_mu1_m_450_500", "M_calo_mu1_m_450_500 ; calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fangle_calo_mu0_m_450_500 = new TH1F("angle_calo_mu0_m_450_500", "angle_calo_mu0_m_450_500 ; angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_m_450_500 = new TH1F("angle_calo_mu1_m_450_500", "angle_calo_mu1_m_450_500 ; angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_m_450_500 = new TH1F("Dphi_calo_mu0_m_450_500", "Dphi_calo_mu0_m_450_500 ; Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_m_450_500 = new TH1F("Dphi_calo_mu1_m_450_500", "Dphi_calo_mu1_m_450_500 ; Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_m_450_500 = new TH1F("Deta_calo_mu0_m_450_500", "Deta_calo_mu0_m_450_500 ; Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_m_450_500 = new TH1F("Deta_calo_mu1_m_450_500", "Deta_calo_mu1_m_450_500 ; Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_m_450_500 = new TH1F("DR_calo_mu0_m_450_500", "DR_calo_mu0_m_450_500 ; Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_m_450_500 = new TH1F("DR_calo_mu1_m_450_500", "DR_calo_mu1_m_450_500 ; Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_m_450_500 = new TH1F("calo_cl_m_450_500", "calo_cl_m_450_500 ; Calo Confidence Level;TEvts", 100, 0., 1.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_m_600_650 = new TH1F("M_calo_mu0_m_600_650", "M_calo_mu0_m_600_650 ; calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_m_600_650 = new TH1F("M_calo_mu1_m_600_650", "M_calo_mu1_m_600_650 ; calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fangle_calo_mu0_m_600_650 = new TH1F("angle_calo_mu0_m_600_650", "angle_calo_mu0_m_600_650 ; angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_m_600_650 = new TH1F("angle_calo_mu1_m_600_650", "angle_calo_mu1_m_600_650 ; angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_m_600_650 = new TH1F("Dphi_calo_mu0_m_600_650", "Dphi_calo_mu0_m_600_650 ; Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_m_600_650 = new TH1F("Dphi_calo_mu1_m_600_650", "Dphi_calo_mu1_m_600_650 ; Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_m_600_650 = new TH1F("Deta_calo_mu0_m_600_650", "Deta_calo_mu0_m_600_650 ; Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_m_600_650 = new TH1F("Deta_calo_mu1_m_600_650", "Deta_calo_mu1_m_600_650 ; Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_m_600_650 = new TH1F("DR_calo_mu0_m_600_650", "DR_calo_mu0_m_600_650 ; Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_m_600_650 = new TH1F("DR_calo_mu1_m_600_650", "DR_calo_mu1_m_600_650 ; Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_m_600_650 = new TH1F("calo_cl_m_600_650", "calo_cl_m_600_650 ; Calo Confidence Level;TEvts", 100, 0., 1.);

   ////////////////////////////////////////////////////////////////////////////////////////////////////////

   fM_calo_mu0_sideband = new TH1F("M_calo_mu0_sideband", "M_calo_mu0_sideband ; calo mu0 M [MeV];TEvts", nmbins2, mbins2);
   fM_calo_mu1_sideband = new TH1F("M_calo_mu1_sideband", "M_calo_mu1_sideband ; calo mu1 M [MeV];TEvts", nmbins2, mbins2);

   fangle_calo_mu0_sideband = new TH1F("angle_calo_mu0_sideband", "angle_calo_mu0_sideband ; angle between calo and mu0 momenta[rad];TEvts", 160, 0., 0.16);
   fangle_calo_mu1_sideband = new TH1F("angle_calo_mu1_sideband", "angle_calo_mu1_sideband ; angle between calo and mu1 momenta[rad];TEvts", 160, 0., 0.16);

   fDphi_calo_mu0_sideband = new TH1F("Dphi_calo_mu0_sideband", "Dphi_calo_mu0_sideband ; Delta phi calo and mu0 momenta[rad];TEvts", 100, -1., 1.);
   fDphi_calo_mu1_sideband = new TH1F("Dphi_calo_mu1_sideband", "Dphi_calo_mu1_sideband ; Delta phi calo and mu1 momenta[rad];TEvts", 100, -1., 1.);

   fDeta_calo_mu0_sideband = new TH1F("Deta_calo_mu0_sideband", "Deta_calo_mu0_sideband ; Delta eta calo and mu0 momenta;TEvts", 100, -0.8, 0.8);
   fDeta_calo_mu1_sideband = new TH1F("Deta_calo_mu1_sideband", "Deta_calo_mu1_sideband ; Delta eta calo and mu1 momenta;TEvts", 100, -0.8, 0.8);

   fDR_calo_mu0_sideband = new TH1F("DR_calo_mu0_sideband", "DR_calo_mu0_sideband ; Delta R calo and mu0 momenta;TEvts", 100, 0., 1.5);
   fDR_calo_mu1_sideband = new TH1F("DR_calo_mu1_sideband", "DR_calo_mu1_sideband ; Delta R calo and mu1 momenta;TEvts", 100, 0., 1.5);

   fcalo_cl_sideband = new TH1F("calo_cl_sideband", "calo_cl_sideband ; Calo Confidence Level;TEvts", 100, 0., 1.);


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

   GetEntry(entry);  // load event
   //if (entry <100000) {GetEntry(entry); } // load event


   if (entry %10000 ==0) {
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
  mu_eta = atanh(prt_pz->at(idx_mu)/mu_p);

  h_p   = sqrt(pow(prt_px->at(idx_h), 2.0)+pow(prt_py->at(idx_h), 2.0)+pow(prt_pz->at(idx_h), 2.0));
  h_eta = atanh(prt_pz->at(idx_h)/h_p);


  prt_trk_dist_mu_h = sqrt(pow(prt_x0->at(idx_h) - prt_x0->at(idx_mu), 2.0) +  pow(prt_y0->at(idx_h) - prt_y0->at(idx_mu), 2.0));
  tag_d2 = prt_trk_dist_mu_h;

  // Flight distance is between secondary and tertiary vertex, not primary and tertiary
  tag_fd_r  = sqrt( pow(tag_x->at(mum) - pvr_x->at(idx_pvr), 2.0) + pow(tag_y->at(mum) - pvr_y->at(idx_pvr), 2.0));
  tag_fd  = sqrt( pow(tag_x->at(mum) - pvr_x->at(idx_pvr), 2.0) + pow(tag_y->at(mum) - pvr_y->at(idx_pvr), 2.0) + pow(tag_z->at(mum) - pvr_z->at(idx_pvr), 2.0));
  tag_flighttime = tag_fd/(tag_beta)*10./2.998;
  tag_tau_ps = tag_flighttime/tag_gamma;


  ////////////////////////////////////////////////////////////////////////////
  //////////////////////////   Basic Cuts   //////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////


  prt_bool_l0         = (bool(tag_l0_tos1->at(mum)) || bool(tag_l0_tos3->at(mum)) || bool(tag_l0_tis->at(mum))); //L0MuonDecision or L0DiMuonDecision or TIS L0HadronDecision
  if (option == "prmpt") {prt_bool_hlt1       = true;}
  if (option == "displ") {prt_bool_hlt1       = bool(tag_hlt1_tos4->at(mum)) || bool(tag_hlt1_tos5->at(mum));} //Tos Hlt1TrackMVA or [Tos Hlt1TwoTrackMVA for mass >1000 MeV]
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

  prt_bool_pid        = true;
  //prt_bool_pid        = (prt_pnn_mu->at(idx_mu) > 0.7) && (prt_pnn_mu->at(idx_h) > 0.7);



  ////////////////////////////////////////////////////////////////////////////
  ///////////////////////////   Summary   ////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  prt_bool_trigger_cuts = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip);
  prt_bool_necessary_cuts   = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip && prt_bool_kin && prt_bool_data_consistency && prt_bool_patho && prt_bool_material && prt_bool_pid);
  prt_bool_full        = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip && prt_bool_kin && prt_bool_data_consistency && prt_bool_patho && prt_bool_material && prt_bool_hf && prt_bool_fd_r && prt_bool_pid);





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

  prt_bool_trigger_cuts = bool(first_variables[std::string("prt_bool_trigger_cuts")]);


  prt_bool_material_h_modmiss      = bool(first_variables[std::string("prt_bool_material_h_modmiss")]);
  prt_bool_material_mu_modmiss      = bool(first_variables[std::string("prt_bool_material_mu_modmiss")]);
  prt_bool_material_cutFM        = bool(first_variables[std::string("prt_bool_material_cutFM")]);



  this->Ap_Plots(mum);

  for (unsigned calo=0; calo < calo_px->size(); calo++) {
    //if (calo_idx_pvr->at(calo) == tag_idx_pvr->at(mum)){ //YOu never know where a calo photon came from
      this->Calo_Plots(calo, mum);
    //}
  }

}

void Plot_hists_X2ApGm::Ap_Plots(unsigned mum)
  {

  fM->Fill(tag_dtf_m->at(mum));
  prt_bool            = true;
  if (prt_bool){if (prt_bool_l0){fM_l0_p->Fill(tag_dtf_m->at(mum));} }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_l0;}

  if (prt_bool){if (prt_bool_hlt1){fM_hlt1_p->Fill(tag_dtf_m->at(mum));} }
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_hlt1;}

  if (prt_bool){if (prt_bool_hlt2){fM_hlt2_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_hlt2;}

  if (prt_bool){if (prt_bool_strip){fM_strip_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_strip;}

  if (prt_bool){if (prt_bool_kin){fM_kin_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_kin;}

  if (prt_bool){if (prt_bool_data_consistency){fM_data_consistency_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_data_consistency;}

  if (prt_bool){if (prt_bool_patho){fM_patho_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_patho;}

  if (prt_bool){if (prt_bool_material){fM_material_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_material;}

  if (not pass_separately) {assert (prt_bool==prt_bool_necessary_cuts);}

  if (prt_bool){if (prt_bool_pid){fM_pid_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_pid;}

  //if (prt_bool){if (prt_bool_hf){fM_hf_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_hf;}

  //if (prt_bool){if (prt_bool_fd_r){fM_fd_r_p->Fill(tag_dtf_m->at(mum));}}
  //if (not pass_separately) {prt_bool = prt_bool && prt_bool_fd_r;}

  //if (not pass_separately) {assert (prt_bool==prt_bool_full);}


}



void Plot_hists_X2ApGm::Calo_Plots(unsigned calo, unsigned mum)
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


  assert(1.1==1.2);
  assert(tag_calo_mu0_mu1_m == Lp_calo_mu0_mu1.M());
  assert(tag_calo_mu0_m == Lp_calo_mu0.M());
  assert(tag_calo_mu1_m == Lp_calo_mu1.M());
  assert(tag_mu0_mu1_m == Lp_mu0_mu1.M());

  if(1.1==1.2){std::cout << "Assertions not working\n\n";}

  if (((tag_calo_mu0_mu1_m - Lp_calo_mu0_mu1.M())/ (tag_calo_mu0_mu1_m + Lp_calo_mu0_mu1.M())) > 0.001 ){std::cout << "calo mu0 mu1 assertion error! \n\n" << std::endl;}
  if (((tag_calo_mu0_m - Lp_calo_mu0.M())/ (tag_calo_mu0_m + Lp_calo_mu0.M())) >0.001){std::cout << "calo mu0 assertion error! \n\n" << std::endl;}
  if (((tag_calo_mu1_m - Lp_calo_mu1.M())/ (tag_calo_mu1_m + Lp_calo_mu1.M())) >0.001){std::cout << "calo mu1 assertion error! \n\n" << std::endl;}
  if (((tag_mu0_mu1_m - Lp_mu0_mu1.M())/ (tag_mu0_mu1_m + Lp_mu0_mu1.M())) > 0.001){std::cout << "mu0 mu1 assertion error! \n\n" << std::endl;}


  //std::cout << "tag_calo_mu1_mu2_m : " << tag_calo_mu1_mu2_m << std::endl;
  if ((tag_calo_mu0_mu1_m < 1100.0) && (calo_eta->at(calo) > 2.) && (calo_eta->at(calo) <4.5)){ // Only if the calo A' pair has mass less than 1.1 GeV fill hists.
    if (prt_bool_necessary_cuts) {
      fM_require_calo->Fill(tag_dtf_m->at(mum));
      fM_tag_calo->Fill(tag_calo_mu0_mu1_m);



      // Fill Histograms in strict calo mu mu bins.
      if ((500 < tag_calo_mu0_mu1_m ) && (600 > tag_calo_mu0_mu1_m )){
        fM_require_calo_at_m_eta->Fill(tag_dtf_m->at(mum));
        if ( (tag_nu_brem_0->at(mum) == 0) &&  (tag_nu_brem_0->at(mum) == 0) ){fM_require_calo_at_m_eta_no_brem->Fill(tag_dtf_m->at(mum));}

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


        fangle_calo_mu0_m_eta->Fill(Lp_calo.Angle(Lp_mu0.Vect()));
        fangle_calo_mu1_m_eta->Fill(Lp_calo.Angle(Lp_mu1.Vect()));

        fDphi_calo_mu0_m_eta->Fill(Lp_calo.DeltaPhi(Lp_mu0));
        fDphi_calo_mu1_m_eta->Fill(Lp_calo.DeltaPhi(Lp_mu1));

        fDeta_calo_mu0_m_eta->Fill(Lp_calo.Eta() - Lp_mu0.Eta() );
        fDeta_calo_mu1_m_eta->Fill(Lp_calo.Eta() - Lp_mu1.Eta() );

        fDR_calo_mu0_m_eta->Fill(Lp_calo.DeltaR(Lp_mu0));
        fDR_calo_mu1_m_eta->Fill(Lp_calo.DeltaR(Lp_mu1));

        fM_calo_mu0_m_eta->Fill(tag_calo_mu0_m);
        fM_calo_mu1_m_eta->Fill(tag_calo_mu1_m);

        fcalo_cl_m_eta->Fill(calo_cl->at(calo));
      } else{
        dalitz_mu0_mu1_not_m_eta.push_back(tag_mu0_mu1_m);
        dalitz_calo_mu0_not_m_eta.push_back(tag_calo_mu0_m);
        dalitz_calo_mu1_not_m_eta.push_back(tag_calo_mu1_m);

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
      }





      // Fill the sidebands for the background substraction
      // For Prompt
      if ((450 < tag_calo_mu0_mu1_m ) && (500 > tag_calo_mu0_mu1_m )){

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
      } else if ((600 < tag_calo_mu0_mu1_m ) && (650 > tag_calo_mu0_mu1_m )){
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

      }

      // Do the background substraction
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

      // Fill for any mass range

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

  if (option == "prmpt"){scatter_file.open("plots/Prmpt_X2ApGm_dalitz.csv");}
  else if (option == "displ"){scatter_file.open("plots/Displ_X2ApGm_dalitz.csv");}
  else if (option == "Test"){scatter_file.open("plots/Test_X2ApGm_dalitz.csv");}

  for (unsigned j=0; j < dalitz_mu0_mu1.size(); j++) {
    scatter_file << dalitz_mu0_mu1.at(j)<<",";
    scatter_file << dalitz_calo_mu0.at(j)<<",";
    scatter_file << dalitz_calo_mu1.at(j)<<"\n";
  }

  scatter_file.close();

  /////////////////////////////////

  if (option == "prmpt"){scatter_file.open("plots/Prmpt_X2ApGm_dalitz_m_eta.csv");}
  else if (option == "displ"){scatter_file.open("plots/Displ_X2ApGm_dalitz_m_eta.csv");}
  else if (option == "Test"){scatter_file.open("plots/Test_X2ApGm_dalitz_m_eta.csv");}

  for (unsigned j=0; j < dalitz_mu0_mu1_m_eta.size(); j++) {
    scatter_file << dalitz_mu0_mu1_m_eta.at(j)<<",";
    scatter_file << dalitz_calo_mu0_m_eta.at(j)<<",";
    scatter_file << dalitz_calo_mu1_m_eta.at(j)<<"\n";
  }

  scatter_file.close();

  /////////////////////////////////

  if (option == "prmpt"){scatter_file.open("plots/Prmpt_X2ApGm_dalitz_not_m_eta.csv");}
  else if (option == "displ"){scatter_file.open("plots/Displ_X2ApGm_dalitz_not_m_eta.csv");}
  else if (option == "Test"){scatter_file.open("plots/Test_X2ApGm_dalitz_not_m_eta.csv");}

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

    if (option == "prmpt"){scatter_file.open("plots/Prmpt_X2ApGm_dalitz_m_eta_m_mu0_mu1_" + lower_boundary_name+ "_" + upper_boundary_name + ".csv");}
    else if (option == "displ"){scatter_file.open("plots/Displ_X2ApGm_dalitz_m_eta_m_mu0_mu1_" + lower_boundary_name+ "_" + upper_boundary_name + ".csv");}
    else if (option == "Test"){scatter_file.open("plots/Test_X2ApGm_dalitz_m_eta_m_mu0_mu1_" + lower_boundary_name+ "_" + upper_boundary_name + ".csv");}

    for (unsigned j=0; j < dalitz_mu0_mu1_m_eta_m_mu0_mu1_separated[i].size(); j++) {
      scatter_file << dalitz_mu0_mu1_m_eta_m_mu0_mu1_separated[i].at(j)<<",";
      scatter_file << dalitz_calo_mu0_m_eta_m_mu0_mu1_separated[i].at(j)<<",";
      scatter_file << dalitz_calo_mu1_m_eta_m_mu0_mu1_separated[i].at(j)<<"\n";
    }

    scatter_file.close();
  }

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
