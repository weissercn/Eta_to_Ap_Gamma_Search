void Plot_hists_RHNu_deploy(TString option ){
  cout << "Plot_hists_RHNu_deploy The option is : " << option << endl;
  // it sounds like "Cogito, ergo sum" said by HAL9000 ...
  //
  gROOT->LoadMacro("velo.C+");

  TFile *_file0 = 0;

  //if (option == "Di"){ _file0 = TFile::Open("output.RHNu.Single.RHNu.CL.root");}

  if (option == "All"){ _file0 = TFile::Open("NTuple_X2ApGm_all_files_with_materials.root");}
  if (option == "Test"){ _file0 = TFile::Open("NTuple_X2ApGm_all_files_with_materials_test.root");}

  TTree * t = (TTree *) _file0->Get("data");

  if (option == "Di" || option == "Test"){ t->Process("Plot_hists_X2ApGm.C",option);}
  if (option == "All"){ t->Process("Plot_hists_X2ApGm.C+",option);}
  //t->Process("Plot_hists_RHNu.C",option);
  //t->Process("Plot_hists_RHNu.C+",option);
  //t->Process("Plot_hists_RHNu.C");

}
