void Add_material_deploy(TString option){
  //cout << "Running on all_files_SMALL for now" << endl;
  // it sounds like "Cogito, ergo sum" said by HAL9000 ...
  //
  //gROOT->LoadMacro("velo.C+");
  //gROOT->ProcessLine(".L velo_old.C+");
  gROOT->ProcessLine(".L velo.C+");
  gROOT->ProcessLine(TString(".x Add_material.cxx(\"")+option+ TString("\")"));


}
