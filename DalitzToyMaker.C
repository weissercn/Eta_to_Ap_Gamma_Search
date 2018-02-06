#define DalitzToyMaker_cxx
// The class definition in DalitzToyMaker.h has been generated automatically
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
// root> T->Process("DalitzToyMaker.C")
// root> T->Process("DalitzToyMaker.C","some options")
// root> T->Process("DalitzToyMaker.C+")
//


#include "DalitzToyMaker.h"
#include <TH2.h>
#include <TStyle.h>

void DalitzToyMaker::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void DalitzToyMaker::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   //pnn_eff_file = new TFile("$EFF_HISTS/eff_pnn_95.root");
   pnn_eff_file = new TFile("/Users/weisser/MIT_Dropbox/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/eff_pnn_95.root");
   pnn_eff_hist = (TH2F*)pnn_eff_file->Get("h2pnn");
   //trig_eff_file = new TFile("$EFF_HISTS/eff_tistos.root");
   trig_eff_file = new TFile("/Users/weisser/MIT_Dropbox/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/eff_tistos.root");
   trig_eff_hist = (TH2F*)trig_eff_file->Get("h2tistos");

   outfile = new TFile("eta_dalitz_toy.root","recreate");
   outtree = new TTree("toy_tree","recreate");

   pyg.readString("ProcessLevel:all = off");
   pyg.readString("Print:quiet = on");
   pyg.readString("221:oneChannel = 1 0.0031 11 22 13 -13");
   pyg.init();

   outtree->Branch("pv_x",&pv_x);
   outtree->Branch("pv_y",&pv_y);
   outtree->Branch("pv_z",&pv_z);

   outtree->Branch("mom_pt",&mom_pt);
   outtree->Branch("mom_px",&mom_px);
   outtree->Branch("mom_py",&mom_py);
   outtree->Branch("mom_pz",&mom_pz);
   outtree->Branch("mom_e",&mom_e);
   outtree->Branch("mom_eta",&mom_eta);
   outtree->Branch("mom_phi",&mom_phi);
   outtree->Branch("mom_m",&mom_m);
   outtree->Branch("mom_pnn_wgt",&mom_pnn_wgt);
   outtree->Branch("mom_tistos_wgt",&mom_tistos_wgt);

   outtree->Branch("dimu_pt",&dimu_pt);
   outtree->Branch("dimu_px",&dimu_px);
   outtree->Branch("dimu_py",&dimu_py);
   outtree->Branch("dimu_pz",&dimu_pz);
   outtree->Branch("dimu_e",&dimu_e);
   outtree->Branch("dimu_eta",&dimu_eta);
   outtree->Branch("dimu_phi",&dimu_phi);
   outtree->Branch("dimu_m",&dimu_m);

   outtree->Branch("mu1_pt",&mu1_pt);
   outtree->Branch("mu1_px",&mu1_px);
   outtree->Branch("mu1_py",&mu1_py);
   outtree->Branch("mu1_pz",&mu1_pz);
   outtree->Branch("mu1_e",&mu1_e);
   outtree->Branch("mu1_eta",&mu1_eta);
   outtree->Branch("mu1_phi",&mu1_phi);

   outtree->Branch("mu2_pt",&mu2_pt);
   outtree->Branch("mu2_px",&mu2_px);
   outtree->Branch("mu2_py",&mu2_py);
   outtree->Branch("mu2_pz",&mu2_pz);
   outtree->Branch("mu2_e",&mu2_e);
   outtree->Branch("mu2_eta",&mu2_eta);
   outtree->Branch("mu2_phi",&mu2_phi);

   outtree->Branch("gm_pt",&gm_pt);
   outtree->Branch("gm_px",&gm_px);
   outtree->Branch("gm_py",&gm_py);
   outtree->Branch("gm_pz",&gm_pz);
   outtree->Branch("gm_e",&gm_e);
   outtree->Branch("gm_eta",&gm_eta);
   outtree->Branch("gm_phi",&gm_phi);
   outtree->Branch("gm_end_x",&gm_end_x);
   outtree->Branch("gm_end_y",&gm_end_y);
   outtree->Branch("gm_end_z",&gm_end_z);
   outtree->Branch("gm_in_ecal",&gm_in_ecal);



}


double DalitzToyMaker::TrigEff(Pythia8::Vec4 p1, Pythia8::Vec4 p2){
  // Get the TISTOS efficiency of a dimuon pair.
  Pythia8::Vec4 ptot = p1 + p2;
  double xval = TMath::Max(TMath::Min(TMath::Sqrt(p1.pT()*p2.pT()), 19.999),
			   1.001); // Only defined for pt<20 GeV
  double yval = TMath::Max(TMath::Min(ptot.eta(), 4.499), 2.001); // Only defined for 2.0<eta<4.5.
  double eff = (double)trig_eff_hist->GetBinContent(trig_eff_hist->GetXaxis()->FindBin(xval),
						    trig_eff_hist->GetYaxis()->FindBin(yval));
  //if (eff<0 || eff> 2) cout << "TrigEff xval, yval, eff " << xval << ",\t" << yval << ",\t" << eff <<endl;
  eff = TMath::Max(eff, 0.);
  if (eff<0 || eff> 2) cout << "TrigEff xval, yval, eff " << xval << ",\t" << yval << ",\t" << eff <<endl;
  //return eff;
  return TMath::Min(eff, 1.);
}

double DalitzToyMaker::PnnEff(Pythia8::Vec4 p1, Pythia8::Vec4 p2){
  // Get the PNN efficiency of a dimuon pair.
  double xval1 = TMath::Max(TMath::Min(p1.pT(), 9.999), 0.501); // Only defined for pt<10 GeV.
  double xval2 = TMath::Max(TMath::Min(p2.pT(), 9.999), 0.501);
  double yval1 = TMath::Max(TMath::Min(p1.eta(), 4.499), 2.001); // Only defined for 2<eta<4.5.
  double yval2 = TMath::Max(TMath::Min(p2.eta(), 4.499), 2.001);
  double eff1 = (double)pnn_eff_hist->GetBinContent(pnn_eff_hist->GetXaxis()->FindBin(xval1),
						    pnn_eff_hist->GetYaxis()->FindBin(yval1));
  double eff2 = (double)pnn_eff_hist->GetBinContent(pnn_eff_hist->GetXaxis()->FindBin(xval2),
						    pnn_eff_hist->GetYaxis()->FindBin(yval2));
  //if (eff1<0 || eff1> 1) cout << "PnnEff xval, yval, eff " << xval1 << ",\t" << yval1 << ",\t" << eff1 <<endl;
  //if (eff2<0 || eff2> 1) cout << "PnnEff xval, yval, eff " << xval2 << ",\t" << yval2 << ",\t" << eff2 <<endl;
  eff1 = TMath::Max(eff1, 0.);
  eff2 = TMath::Max(eff2, 0.);

  //if (eff1<0 || eff1> 1) cout << "PnnEff xval, yval, eff " << xval1 << ",\t" << yval1 << ",\t" << eff1 <<endl;
  //if (eff2<0 || eff2> 1) cout << "PnnEff xval, yval, eff " << xval2 << ",\t" << yval2 << ",\t" << eff2 <<endl;
  return eff1*eff2;
}

Bool_t DalitzToyMaker::InEcal(double x, double y){
  // Check if a point is in ECAL acceptance.
  double dim_x = 6.3*1000.0;
  double dim_y = 7.8*1000.0;
  if(TMath::Abs(x) > dim_x/2.0 ||
     TMath::Abs(y) > dim_y/2.0) return kFALSE;
  return kTRUE;
}


Bool_t DalitzToyMaker::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);
   //if(entry==0) cout << "--- Processing: " << fChain->GetTree()->GetEntries() << " events" << endl;
   //if(entry==0) cout << "--- Processing: " << fChain->GetEntries() << " events" << endl;
   if(entry%10000==0) cout << "--- ... Processing event: " << entry << endl;

   //cout << "before Loop " <<endl;
   // Loop over dimuons
   int ntag = tag_idx_pvr.GetSize();
   for(int itag=0; itag<ntag; ++itag){
     //cout << "In Loop " <<endl;

     // Make a loose mass cut
     if(tag_dtf_m[itag]<400 || tag_dtf_m[itag]>700) continue;
     //cout << "after dtf mass cut " <<endl;

     // Generate dalitz decay
     int imu1 = (int)tag_idx_prt0[itag];
     int imu2 = (int)tag_idx_prt1[itag];
     Pythia8::Vec4 tagMu1Vec4(prt_px[imu1]/1000.0, prt_py[imu1]/1000.0,
			      prt_pz[imu1]/1000.0, prt_e[imu1]/1000.0);
     Pythia8::Vec4 tagMu2Vec4(prt_px[imu2]/1000.0, prt_py[imu2]/1000.0,
			      prt_pz[imu2]/1000.0, prt_e[imu2]/1000.0);
     Pythia8::Vec4 tagVec4 = tagMu1Vec4 + tagMu2Vec4;
     if(tagVec4.mCalc()<.5 || tagVec4.mCalc()>0.6) continue;
     //cout << "after tighter mass cut " <<endl;


     pyg.event.reset();
     pyg.event.append(221, 1, 0, 0, tagVec4, tagVec4.mCalc());
     pyg.next();

     // Get simulated info
     TLorentzVector gmP4(0,0,0,0);
     TLorentzVector mu1P4(0,0,0,0);
     TLorentzVector mu2P4(0,0,0,0);
     Pythia8::Vec4 mu1Vec4;
     Pythia8::Vec4 mu2Vec4;
     for(int isim=0; isim<pyg.event.size(); isim++){
       if(pyg.event[isim].id() == 22){
	 gmP4.SetPxPyPzE(1000.0*pyg.event[isim].px(),
			 1000.0*pyg.event[isim].py(),
			 1000.0*pyg.event[isim].pz(),
			 1000.0*pyg.event[isim].e());
       }
       else if(pyg.event[isim].id() == 13){
	 mu1Vec4 = pyg.event[isim].p();
	 mu1P4.SetPxPyPzE(1000.0*pyg.event[isim].px(),
			  1000.0*pyg.event[isim].py(),
			  1000.0*pyg.event[isim].pz(),
			  1000.0*pyg.event[isim].e());
       }
       else if(pyg.event[isim].id() == -13){
	 mu2Vec4 = pyg.event[isim].p();
	 mu2P4.SetPxPyPzE(1000.0*pyg.event[isim].px(),
			  1000.0*pyg.event[isim].py(),
			  1000.0*pyg.event[isim].pz(),
			  1000.0*pyg.event[isim].e());
       }
     }
     if(TMath::Sqrt(mu1Vec4.pT()*mu1Vec4.pT()) < 1 ||
	mu1Vec4.eta() < 2.0 || mu1Vec4.eta() > 4.5 ||
	mu2Vec4.eta() < 2.0 || mu2Vec4.eta() > 4.5 ||
	mu1Vec4.pT() < 0.5 || mu2Vec4.pT()<0.5) continue;

     //cout << "after acceptance cuts " <<endl;
     TLorentzVector dimuP4 = mu1P4 + mu2P4;

     //cout << "before Hists " <<endl;

     mom_pnn_wgt = PnnEff(mu1Vec4,mu2Vec4)/PnnEff(tagMu1Vec4,tagMu2Vec4);
     mom_tistos_wgt = TrigEff(mu1Vec4,mu2Vec4)/TrigEff(tagMu1Vec4,tagMu2Vec4);

     //cout << "after Hists " <<endl;

     if(mom_pnn_wgt != mom_pnn_wgt || isinf(mom_pnn_wgt) == 1) mom_pnn_wgt=0;
     if(mom_tistos_wgt != mom_tistos_wgt || isinf(mom_tistos_wgt) == 1) mom_tistos_wgt=0;

     mom_pt = 1000.0*tagVec4.pT();
     mom_px = 1000.0*tagVec4.px();
     mom_py = 1000.0*tagVec4.py();
     mom_pz = 1000.0*tagVec4.pz();
     mom_e = 1000.0*tagVec4.e();
     mom_eta = tagVec4.eta();
     mom_phi = tagVec4.phi();
     mom_m = 1000.0*tagVec4.mCalc();

     dimu_pt = dimuP4.Pt();
     dimu_px = dimuP4.Px();
     dimu_py = dimuP4.Py();
     dimu_pz = dimuP4.Pz();
     dimu_e = dimuP4.E();
     dimu_eta = dimuP4.Eta();
     dimu_phi = dimuP4.Phi();
     dimu_m = dimuP4.M();

     mu1_pt = mu1P4.Pt();
     mu1_px = mu1P4.Px();
     mu1_py = mu1P4.Py();
     mu1_pz = mu1P4.Pz();
     mu1_e = mu1P4.E();
     mu1_eta = mu1P4.Eta();
     mu1_phi = mu1P4.Phi();

     mu2_pt = mu2P4.Pt();
     mu2_px = mu2P4.Px();
     mu2_py = mu2P4.Py();
     mu2_pz = mu2P4.Pz();
     mu2_e = mu2P4.E();
     mu2_eta = mu2P4.Eta();
     mu2_phi = mu2P4.Phi();

     gm_pt = gmP4.Pt();
     gm_px = gmP4.Px();
     gm_py = gmP4.Py();
     gm_pz = gmP4.Pz();
     gm_e = gmP4.E();
     gm_eta = gmP4.Eta();
     gm_phi = gmP4.Phi();

     int ipvr = (int)tag_idx_pvr[itag]; // Photon originates from PVR
     pv_x = pvr_x[ipvr];
     pv_y = pvr_y[ipvr];
     pv_z = pvr_z[ipvr];

     double ecalz = 12.5*1000.0; // ECAL z position in mm
     gm_end_x = pv_x + (ecalz-pv_z)*TMath::ASin(gm_px/gm_pz);
     gm_end_y = pv_y + (ecalz-pv_z)*TMath::ASin(gm_py/gm_pz);
     gm_in_ecal = InEcal(gm_end_x, gm_end_y);

     outtree->Fill();

   }

   return kTRUE;
}

void DalitzToyMaker::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void DalitzToyMaker::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   outfile->Write();
   outfile->Close();

}
