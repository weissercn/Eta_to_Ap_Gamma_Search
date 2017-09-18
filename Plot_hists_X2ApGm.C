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
   if (option == "All"){f = new TFile("NTuple_X2ApGm_all_files_plots.root","RECREATE");}
   else if (option == "Test"){f = new TFile("NTuple_X2ApGm_all_files_plots_test.root","RECREATE");}
   else{ std::cout << std::endl << std::endl << "NO VALID OPTION" << std::endl << std::endl;}

   pass_separately =false;

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

   // H I S T O G R A M S

   fM = new TH1F("M", "M;$/mu /mu$ M [MeV];TEvts", nmbins, mbins);
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
   fM_require_calo_at_m_eta = new TH1F("M_require_cal_at_m_eta", "M_require_calo_at_m_eta ;mu mu M [MeV] when calo photon required and 440 < m(mu mu gamma) < 455 MeV;TEvts", nmbins, mbins);


   fM_tag_calo = new TH1F("M_tag_calo", "M_tag_calo ;mu mu calo M [MeV];TEvts", nmbins, mbins);



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
     std::cout << "entry : " << entry/1000 << std::endl;
   }





   for (unsigned mum=0; mum < tag_m->size(); mum++) {
     if (tag_idx_pvr->at(mum) >=0 ) {
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


  prt_bool_l0         = (bool(tag_l0_tos1->at(mum)) || bool(tag_l0_tis->at(mum))); //L0MuonDecision or TIS L0HadronDecision
  prt_bool_hlt1       = bool(tag_hlt1_tos4->at(mum)) || bool(tag_hlt1_tos5->at(mum)); //Tos Hlt1TrackMVA or [Tos Hlt1TwoTrackMVA for mass >1000 MeV]
  prt_bool_hlt2       = bool(tag_hlt2_tos0->at(mum)); //Hlt2ExoticaDisplDiMuonDecision
  prt_bool_strip      = true;
  //prt_bool_strip       = bool(tag_fd_r > 2) && ( bool(tag_m->at(mum) < 425 )  || bool(tag_m->at(mum) > 525 ) ) && (prt_pnn_mu->at(idx_mu) > 0.95); //stripping is a passthrough
  prt_bool_kin        = (tag_eta->at(mum) > 2) && (tag_eta->at(mum) < 4.5) && (tag_pt->at(mum) > 1000); // kinematics
  prt_bool_kin        = prt_bool_kin && (mu_eta > 2) && (mu_eta < 4.5) && (h_eta > 2) && (h_eta < 4.5);

  //prt_bool_data_consistency = true;
  prt_bool_data_consistency      = tag_dtf_chi2->at(mum) < 8; //DTF is calulated with respect to primary vertex. need tertiary with respect to secondary vertex
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


  prt_bool_pid        = (prt_pnn_mu->at(idx_mu) > 0.7) && (prt_pnn_mu->at(idx_h) > 0.7);



  ////////////////////////////////////////////////////////////////////////////
  ///////////////////////////   Summary   ////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

  prt_bool_trigger_cuts = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip);
  prt_bool_necessary_cuts   = (prt_bool_l0 && prt_bool_hlt1 && prt_bool_hlt2 && prt_bool_strip && prt_bool_kin && prt_bool_data_consistency && prt_bool_patho && prt_bool_pid);
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

  fM->Fill(tag_m->at(mum));


  this->Ap_Plots(mum);

  for (unsigned calo=0; calo < calo_px->size(); calo++) {
    if (calo_idx_pvr->at(calo) == tag_idx_pvr->at(mum)){
      this->Calo_Plots(calo, mum);
    }
  }

}

void Plot_hists_X2ApGm::Ap_Plots(unsigned mum)
  {

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

  if (prt_bool){if (prt_bool_hf){fM_hf_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_hf;}

  if (prt_bool){if (prt_bool_fd_r){fM_fd_r_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_fd_r;}

  if (prt_bool){if (prt_bool_pid){fM_pid_p->Fill(tag_dtf_m->at(mum));}}
  if (not pass_separately) {prt_bool = prt_bool && prt_bool_pid;}
  if (not pass_separately) {assert (prt_bool==prt_bool_full);}


}



void Plot_hists_X2ApGm::Calo_Plots(unsigned calo, unsigned mum)
{
  double tag_calo_m = pow(tag_dtf_e->at(mum) + calo_e->at(calo) , 2.0) - pow(tag_dtf_px->at(mum) + calo_px->at(calo) , 2.0) - pow(tag_dtf_py->at(mum) + calo_py->at(calo) , 2.0) - pow(tag_dtf_pz->at(mum) + calo_pz->at(calo) , 2.0);
  if (tag_calo_m < 1200.0){ // Only if the calo A' pair has mass less than 1.2 GeV fill hists.
    if (prt_bool_necessary_cuts) {
      fM_require_calo->Fill(tag_dtf_m->at(mum));
      fM_tag_calo->Fill(tag_calo_m);
      if ((540 < tag_calo_m ) && (555 > tag_calo_m )){
        fM_require_calo_at_m_eta->Fill(tag_dtf_m->at(mum));
      }
    }
  }

}

void Plot_hists_X2ApGm::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Plot_hists_X2ApGm::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   std::cout << "Writing Hists to File" << std::endl;

   //gDirectory->Add(l_x_scatter);
   gDirectory->ls();

   f->Write();
   f->Close();

   std::cout << "Saying goodbye" << std::endl;

}
