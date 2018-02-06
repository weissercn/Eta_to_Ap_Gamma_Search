bool process(TString fname){

  TFile* f = new TFile(fname);
  TTree* t = (TTree*)f->Get("data");
  //t->Process("/Users/weisser/MIT_Dropbox/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/DalitzToyMaker.C+");
  t->Process("/Users/weisser/MIT_Dropbox/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/DalitzToyMaker.C");
  //t->Process("Plot_hists_X2ApGm.C+","prmpt_99");
  return kTRUE;

}

void runDalitzToy(){

  //gSystem->Load("libEG");
  gSystem->Load("/Users/weisser/Documents/pythia8230/lib/libpythia8.dylib");
  //gSystem->Load("/home/weisser/pythia8230/lib/libpythia8.dylib");
  gSystem->Load("libEGPythia8");
  gSystem->Load("libpythia8");
  process("/Users/weisser/MIT_Dropbox/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/NTuple_X2ApGm_all_files_noip_44_part.root");
  //process("/Users/weisser/MIT_Dropbox/LbVMWeisser_shared/Analyses/Eta_to_Ap_Gamma_Search/NTuple_X2ApGm_all_files_noip_44_part.root");

}

void Plot_hists_X2ApGm_deploy(){

  TFile *_file0 = 0;
  TString file_name;

  file_name = "NTuple_X2ApGm_all_files_noip_44_part.root";
  _file0 = TFile::Open(file_name);

  TTree * t = (TTree *) _file0->Get("data");

  cout << t->GetEntries() << "  Entries " <<endl;




  t->Process("Plot_hists_X2ApGm.C+","prmpt_99");


}
