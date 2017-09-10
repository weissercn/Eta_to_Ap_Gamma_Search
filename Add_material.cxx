#include "TFile.h"
#include "TTree.h"

#include <iostream>

bool modMiss(TVector3 &sv, TVector3 &p3, double zmod, ModuleMaterial &mmat){
  // This removes events where the first hit is missed. intersect a module in which they don't have hits.
  double zhit=-1e6,rhit=0;
  double zstep=sv.Z();
  while(rhit < 8){ // z increases from sv more and more until the particle would be 8mm off the z axis. the first R module goes up to 8mm (I think)
    double xstep = sv.X() + (zstep-sv.Z())*p3.X()/p3.Z();
    double ystep = sv.Y() + (zstep-sv.Z())*p3.Y()/p3.Z();
    TLorentzVector inter
    = mmat.intersect(xstep,ystep,zstep,p3.X(),p3.Y(),p3.Z());
    if(inter.T() == 0) break; //no intersection at all found, so ok either way. return false.
    rhit = (inter.Vect() - TVector3(0.84,-0.18,0)).Perp();
    zhit = inter.Z();
    zstep = inter.Z()+1;
  }
  if(abs(zhit - zmod) > 1) return true;
  return false;
}

double modMiss_returns_rhit(TVector3 &sv, TVector3 &p3, double zmod, ModuleMaterial &mmat){
  // This removes events where the first hit is missed. intersect a module in which they don't have hits.
  double zhit=-1e6,rhit=0;
  double zstep=sv.Z();
  while(rhit < 8){ // z increases from sv more and more until the particle would be 8mm off the z axis. the first R module goes up to 8mm (I think)
    double xstep = sv.X() + (zstep-sv.Z())*p3.X()/p3.Z();
    double ystep = sv.Y() + (zstep-sv.Z())*p3.Y()/p3.Z();
    TLorentzVector inter
    = mmat.intersect(xstep,ystep,zstep,p3.X(),p3.Y(),p3.Z());
    if(inter.T() == 0) break; //no intersection at all found, so ok either way. return false.
    rhit = (inter.Vect() - TVector3(0.84,-0.18,0)).Perp();
    zhit = inter.Z();
    zstep = inter.Z()+1;
  }
  if(abs(zhit - zmod) > 1) return rhit;
  return 0.;
}

bool cutFM(TVector3 &sv, TVector3 &p3, FoilMaterial &fmat, ModuleMaterial &mmat){
  // This removes events with conversions near the tip of the Foil Material (or something like that)
  double dzfmp = fmat.intersect(sv.X(),sv.Y(),sv.Z(),p3.X(),p3.Y(),p3.Z()).Z();
  dzfmp = abs(dzfmp - mmat.z(mmat.sensor(sv.Z(),0)));
  double dzfmm = fmat.intersect(sv.X(),sv.Y(),sv.Z(),-p3.X(),-p3.Y(),-p3.Z()).Z();
  dzfmm = abs(dzfmm - mmat.z(mmat.sensor(sv.Z(),0)));
  double dzfm = dzfmp < dzfmm ? dzfmp : dzfmm;
  return (dzfm < 1);
}

double getDMat(TVector3 &sv,double dx,double dy,double dz, ModuleMaterial &mmat, FoilMaterial &fmat, TLorentzVector &vmat){
  TLorentzVector vmat_tmp;
  double x=sv.X(),y=sv.Y(),z=sv.Z();
  vmat = mmat.distance(x,y,z,dx,dy,dz,-1);
  double dmm = vmat.T();
  double dm_min = dmm;
  vmat_tmp = mmat.distance(x,y,z,dx,dy,dz,+1);
  double dmp = vmat_tmp.T();
  if(dmp < dm_min){vmat = vmat_tmp; dm_min = dmp;}
  vmat_tmp = fmat.distance(x,y,z,dx,dy,dz,-1,0,-1);
  double dfm1 = vmat_tmp.T();
  if(dfm1 < dm_min){vmat = vmat_tmp; dm_min = dfm1;}
  vmat_tmp = fmat.distance(x,y,z,dx,dy,dz,-1,0,+1);
  double dfm2 = vmat_tmp.T();
  if(dfm2 < dm_min){vmat = vmat_tmp; dm_min = dfm2;}
  vmat_tmp = fmat.distance(x,y,z,dx,dy,dz,+1,0,-1);
  double dfp1 = vmat_tmp.T();
  if(dfp1 < dm_min){vmat = vmat_tmp; dm_min = dfp1;}
  vmat_tmp = fmat.distance(x,y,z,dx,dy,dz,+1,0,+1);
  double dfp2 = vmat_tmp.T();
  if(dfp2 < dm_min){vmat = vmat_tmp; dm_min = dfp2;}

  double dmat = 1/(1/dmm + 1/dmp + 1/dfm1 + 1/dfm2 + 1/dfp1 + 1/dfp2);
  return dmat;
}


void Add_material(TString option){
  std::cout << "adding the material variables to the root file" << std::endl;
  //std::cout << "Running on all_files_SMALL for now" << std::endl;
  //
  //gROOT->LoadMacro("velo.C+");
  //cout<<(gDirectory->GetPath())<<endl;

  std::cout << "Add_material The option is : " << option << std::endl;

  TFile * f = 0;
  if (option == "DiAll") {f = TFile::Open("NTuple_X2RHNuGm_all_files.root", "update");}
  if (option == "Test") {f = TFile::Open("outfile.root", "update");}


  TTree * t = (TTree *) f->Get("data");


  vector<double> *tag_x(0), *tag_y(0), *tag_z(0), *tag_dx(0), *tag_dy(0), *tag_dz(0), *tag_dtf_px(0), *tag_dtf_py(0), *tag_dtf_pz(0), *pvr_x(0), *pvr_y(0), *pvr_z(0), *prt_x0(0), *prt_y0(0), *prt_z0(0), *prt_px(0), *prt_py(0), *prt_pz(0);
  vector<double> *tag_idx_prt0(0), *tag_idx_prt1(0), *tag_idx_pvr(0);

  vector<double> tag_dmat, tag_xxx, tag_dmat_isRescaled;
  vector<double> tag_veto_h_modmiss, tag_veto_mu_modmiss, tag_veto_cutFM;
  //vector<double> tag_veto_h_modmiss_rhit;

  TBranch *b_tag_dmat = t->Branch("tag_dmat",&tag_dmat);
  TBranch *b_tag_xxx = t->Branch("tag_xxx",&tag_xxx);
  TBranch *b_tag_dmat_isRescaled = t->Branch("tag_dmat_isRescaled",&tag_dmat_isRescaled);
  TBranch *b_tag_veto_h_modmiss = t->Branch("tag_veto_h_modmiss",&tag_veto_h_modmiss);
  TBranch *b_tag_veto_mu_modmiss = t->Branch("tag_veto_mu_modmiss",&tag_veto_mu_modmiss);
  TBranch *b_tag_veto_cutFM = t->Branch("tag_veto_cutFM",&tag_veto_cutFM);
  //TBranch *b_tag_veto_h_modmiss_rhit = t->Branch("tag_veto_h_modmiss_rhit",&tag_veto_h_modmiss_rhit);

  double dmat, dmat_isRescaled;
  double tag_veto_h_modmiss_j, tag_veto_mu_modmiss_j, tag_veto_cutFM_j;
  //double tag_veto_h_modmiss_rhit_j;



  t->SetBranchAddress("tag_x",&tag_x);
  t->SetBranchAddress("tag_y",&tag_y);
  t->SetBranchAddress("tag_z",&tag_z);
  t->SetBranchAddress("tag_dx",&tag_dx);
  t->SetBranchAddress("tag_dy",&tag_dy);
  t->SetBranchAddress("tag_dz",&tag_dz);
  t->SetBranchAddress("tag_dtf_px",&tag_dtf_px);
  t->SetBranchAddress("tag_dtf_py",&tag_dtf_py);
  t->SetBranchAddress("tag_dtf_pz",&tag_dtf_pz);
  t->SetBranchAddress("pvr_x",&pvr_x);
  t->SetBranchAddress("pvr_y",&pvr_y);
  t->SetBranchAddress("pvr_z",&pvr_z);
  t->SetBranchAddress("prt_x0",&prt_x0);
  t->SetBranchAddress("prt_y0",&prt_y0);
  t->SetBranchAddress("prt_z0",&prt_z0);
  t->SetBranchAddress("prt_px",&prt_px);
  t->SetBranchAddress("prt_py",&prt_py);
  t->SetBranchAddress("prt_pz",&prt_pz);

  t->SetBranchAddress("tag_idx_prt0",&tag_idx_prt0);
  t->SetBranchAddress("tag_idx_prt1",&tag_idx_prt1);
  t->SetBranchAddress("tag_idx_pvr",&tag_idx_pvr);



  int idx_mu, idx_h, idx_pvr;

  double x, y, z, dx, dy, dz, deltaz_mu, deltaz_h, px, py, pz, pvx, pvy, pvz, px0, py0, pz0, px1, py1, pz1, prt_trk_dist_mu_h, d2;
  double xxx;
  //std::cout << "Before VeloMaterial declaration" << std::endl;

  // this is how to configure the code
  ModuleMaterial mmat("HE16.1_pars.root");
  ModuleMaterial mmat2("HE16.1_pars.root");
  FoilMaterial fmat("HE16.1_pars.root");
  mmat.configDistance(0.25);
  fmat.configDistance(0.25);
  mmat.configSensor(fmat);

  TVector3 sv, pv, p3, p0, p1;

  // this is the material distance
  TLorentzVector vmat;

  // this function is used to rescale the material distance based on the distance between the first hit on each track

  TF1 fcn("FCN","[0]+[1]*exp(-[2]*x)+[3]*exp(-[4]*x)",0.04,0.6);
  fcn.SetParameters(0.184,0.163,0.266,1.001,2.173);

  std::cout << "Before Event Loop" << std::endl;

  Long64_t nentries = t->GetEntries();

  //nentries = 1000;
  for (Long64_t i=0;i<nentries;i++) {
      //std::cout << "Before GetEntry" << std::endl;
      t->GetEntry(i);
      //std::cout << "After GetEntry" << std::endl;

      if (i %10000 ==0) {
        std::cout << "entry : " << i/1000 << " k\ttag_x size :" << tag_x->size() << std::endl;
      }

      //std::cout << "Before Clearing vector" << std::endl;


      tag_dmat.clear();
      tag_xxx.clear();
      tag_dmat_isRescaled.clear();
      tag_veto_h_modmiss.clear();
      tag_veto_mu_modmiss.clear();
      tag_veto_cutFM.clear();

      //std::cout << "Before Looping over vector" << std::endl;


      for (Long64_t mum=0;mum<tag_x->size();mum++){

        idx_mu  = tag_idx_prt0->at(mum);
        idx_h   = tag_idx_prt1->at(mum);
        idx_pvr = tag_idx_pvr->at(mum);

        x   = tag_x->at(mum);
        y   = tag_y->at(mum);
        z   = tag_z->at(mum);
        dx  = tag_dx->at(mum);
        dy  = tag_dy->at(mum);
        dz  = tag_dz->at(mum);
        px  = tag_dtf_px->at(mum);
        py  = tag_dtf_py->at(mum);
        pz  = tag_dtf_pz->at(mum);
        pvx = pvr_x->at(idx_pvr);
        pvy = pvr_y->at(idx_pvr);
        pvz = pvr_z->at(idx_pvr);
        px0 = prt_px->at(idx_mu);
        py0 = prt_py->at(idx_mu);
        pz0 = prt_pz->at(idx_mu);
        px1 = prt_px->at(idx_h);
        py1 = prt_py->at(idx_h);
        pz1 = prt_pz->at(idx_h);

        prt_trk_dist_mu_h = sqrt(pow(prt_x0->at(idx_h) - prt_x0->at(idx_mu), 2.0) +  pow(prt_y0->at(idx_h) - prt_y0->at(idx_mu), 2.0));

        dmat_isRescaled = (abs(prt_z0->at(idx_mu)  - prt_z0->at(idx_h)) < 1);

        deltaz_mu = prt_z0->at(idx_mu) - z;
        deltaz_h = prt_z0->at(idx_h) - z;
        d2  = prt_trk_dist_mu_h;  // d2 is the 2-d x-y distance between the 1st hit on each muon


        // I set some minimum dx, dy, dz on the SV by hand

        if(dz <= 1) dz = 1;
        if(z > 300 && dx < 0.5) dx = 0.5;
        if(z > 300 && dy < 0.5) dy = 0.5;

        sv = TVector3(x,y,z);
        pv = TVector3(pvx,pvy,pvz);
        p3 = TVector3(px,py,pz);
        double r = (sv-pv).Perp();

        // these are the 3-momenta of the particles in the 2-body decay
        p0 = TVector3(px0,py0,pz0);
        p1 = TVector3(px1,py1,pz1);

        // I make these cuts
        tag_veto_mu_modmiss_j   = 0.; //false;
        tag_veto_h_modmiss_j  = 0.; //false;
        tag_veto_cutFM_j       = 0.; //false;
        if(modMiss(sv,p0,(z+deltaz_mu),mmat2)) tag_veto_mu_modmiss_j   = 1.; //true;
        if(modMiss(sv,p1,(z+deltaz_h),mmat2)) tag_veto_h_modmiss_j  = 1.; //true;
        if(cutFM(sv,p3,fmat,mmat2)) tag_veto_cutFM_j       = 1.; //true;
        //tag_veto_h_modmiss_rhit_j = modMiss_returns_rhit(sv,p0,(z+deltaz),mmat2);

        // this is the material distance
        vmat = TLorentzVector();
        double dmat = getDMat(sv,dx,dy,dz,mmat,fmat,vmat);

        if (dmat_isRescaled){
          deltaz = (deltaz_mu + deltaz_h)/2.;
          // this is how I rescale it
          double rhit = r + deltaz*tan(p3.Theta());
          double rpit = 0.04 + 0.05*(rhit-8)/(35-8);
          double ppit = 0.0046;
          if(rhit > 18) ppit = 0.0023;
          double dr2 = pow(rpit,2);
          double dp2 = pow(rhit*ppit,2);
          xxx = d2/sqrt(dr2 + dp2); // d2 is the 2-d x-y distance between the 1st hit on each muon

          double dscale = fcn.Eval(xxx);
          if(dscale > 0.7) dscale = 0.7;
          if(dscale < 0.23) dscale = 0.23;
          dscale /= 0.23;
          dmat /= dscale;
        }else{
          xxx = 0.;
        }

        if(r > 0 && r < 8) dmat *= 0.65/0.95;
        if(r > 8 && r < 11) dmat *= 0.65/0.72;
        if(r > 13 && r < 15) dmat *= 0.65/0.75;
        if(r > 16 && r < 18) dmat *= 0.65/1.45;
        if(r > 20) dmat *= 0.65/0.78;


        //h_velo_tip_j  = material_veto_tool->tip(tag_x->at(mum),tag_y->at(mum),tag_z->at(mum),prt_px->at(idx_h),prt_py->at(idx_h),prt_pz->at(idx_h));
        //h_velo_miss_j = material_veto_tool->miss(tag_x->at(mum),tag_y->at(mum),tag_z->at(mum),prt_px->at(idx_h),prt_py->at(idx_h),prt_pz->at(idx_h),prt_z0->at(idx_h));

        //mu_velo_tip_j  = material_veto_tool->tip(tag_x->at(mum),tag_y->at(mum),tag_z->at(mum),prt_px->at(idx_mu),prt_py->at(idx_mu),prt_pz->at(idx_mu));
        //mu_velo_miss_j = material_veto_tool->miss(tag_x->at(mum),tag_y->at(mum),tag_z->at(mum),prt_px->at(idx_mu),prt_py->at(idx_mu),prt_pz->at(idx_mu),prt_z0->at(idx_mu));




        //std::cout << "h_velo_miss_j : " << h_velo_miss_j << std::endl;



        tag_dmat.push_back(dmat);
        tag_xxx.push_back(xxx);
        tag_dmat_isRescaled.push_back(dmat_isRescaled);
        tag_veto_h_modmiss.push_back(tag_veto_h_modmiss_j);
        tag_veto_mu_modmiss.push_back(tag_veto_mu_modmiss_j);
        tag_veto_cutFM.push_back(tag_veto_cutFM_j);

        //tag_veto_h_modmiss_rhit.push_back(tag_veto_h_modmiss_rhit_j);

      }

      //for(int ij=0; ij < h_velo_miss.size(); ij++){
      //    std::cout << h_velo_miss[ij] << endl;
      //}

      //for (std::vector<double>::const_iterator ij = h_velo_miss.begin(); ij != h_velo_miss.end(); ++ij){ std::cout << *ij << ' ';}


      b_tag_dmat->Fill();
      b_tag_xxx->Fill();
      b_tag_dmat_isRescaled->Fill();
      b_tag_veto_h_modmiss->Fill();
      b_tag_veto_mu_modmiss->Fill();
      b_tag_veto_cutFM->Fill();

      //b_tag_veto_h_modmiss_rhit->Fill();

  }

  //std::cout << "Before write" << std::endl;
  //f->cd();

  //cout<<(gDirectory->GetPath())<<endl;
  //t->SetBranchStatus("*",1);

  //t->Write();
  //f->Write();

  std::cout << "Finished adding the material variables. Now writing to file" << std::endl;
  //Create a new file + a clone of old tree in new file

  TFile *newfile = 0;
  if (option == "DiAll") {newfile = new TFile("NTuple_X2RHNuGm_all_files_with_materials.root","recreate");}
  if (option == "Test") {newfile = new TFile("NTuple_X2RHNuGm_all_files_with_materials_test.root","recreate");}

  //TFile *newfile = new TFile("NTuple_RHNu_all_files_smooth_with_materials_small.root","recreate"); // ONLY FOR TESTING
  TTree *newtree = t->CloneTree();

  //newtree->Print();
  newfile->Write();
  delete f;
  delete newfile;

  std::cout << "Goodbye" << std::endl;


}
