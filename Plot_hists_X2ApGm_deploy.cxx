void Plot_hists_X2ApGm_deploy(TString temp_option ){
  cout << "Plot_hists_RHNu_deploy The option is : " << temp_option << endl;
  // it sounds like "Cogito, ergo sum" said by HAL9000 ...
  //
  gROOT->LoadMacro("velo.C+");

  TObjArray *t_temp_option = temp_option.Tokenize(" ");
  TString option = ((TObjString *)(t_temp_option->At(0)))->String();
  TString option2 = ((TObjString *)(t_temp_option->At(1)))->String();
  TString option3 = ((TObjString *)(t_temp_option->At(2)))->String();
  int nentries = 0;
  if(t_temp_option->GetEntries()>3){nentries = (((TObjString *)(t_temp_option->At(3)))->String()).Atoi(); std::cout << nentries << " events " << std::endl;}

  cout << "Options : " << option << ",\t" << option2 << ",\t" << option3 <<endl;


  TFile *_file0 = 0;
  TString file_name;
  ostringstream oss;

  if (option == "prmpt"){ oss << "NTuple_X2ApGm_all_files_prmpt_" << option3.Atoi() << ".root"; file_name = oss.str();}
  if (option == "displ"){ oss << "NTuple_X2ApGm_all_files_displ_" << option3.Atoi() << ".root"; file_name = oss.str();}
  if (option == "Test"){ file_name = "NTuple_X2ApGm_all_files_with_materials_test.root";}

  cout << endl << "File name : " << file_name <<endl;

  _file0 = TFile::Open(file_name);

  TTree * t = (TTree *) _file0->Get("data");

  cout << t->GetEntries() << "  Entries " <<endl;




  if (option == "Di" || option == "Test"){ t->Process("Plot_hists_X2ApGm.C",option);}
  //if (option == "prmpt" || option == "displ"){ t->Process("Plot_hists_X2ApGm.C++",option);} // force compilation
  if(t_temp_option->GetEntries()>3){if (option == "prmpt" || option == "displ"){t->Process("Plot_hists_X2ApGm.C+",option+"_"+option2, nentries);} }// compile if new
  else{if (option == "prmpt" || option == "displ"){ t->Process("Plot_hists_X2ApGm.C+",option+"_"+option2);}}// compile if new
  //t->Process("Plot_hists_RHNu.C",option);
  //t->Process("Plot_hists_RHNu.C+",option);
  //t->Process("Plot_hists_RHNu.C");

}
