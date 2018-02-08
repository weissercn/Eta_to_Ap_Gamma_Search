bool inFid(TLorentzVector *p4){
  if(p4->Pt() < 500) return false;
  if(p4->P() < 10000) return false;
  if(p4->Eta() < 2) return false;
  if(p4->Eta() > 4.5) return false;
  return true;
}

bool inFidP(TLorentzVector *p4){
  if(p4->Pt() < 1000) return false;
  if(p4->P() < 20000) return false;
  if(p4->Eta() < 2) return false;
  if(p4->Eta() > 4.5) return false;
  return true;
}

void toyEtaDecay(int num, int which=0){ // 0 = eta, 1 = omega
  lhcbStyle();

  double ptbins[7] = {1000,2000,3000,5000,7500,10000,20e3};
  TH1F hpt("hpt","",6,ptbins);
  TH1F hpt2("hpt2","",6,ptbins);
  TH1F hm("hm","",100,200,600);
  TH1F hm1("hm1","",100,200,600);
  TH1F hm2("hm2","",100,200,600);
  TH1F hath("hath","",50,0,10);
  TH2F hmhel("hmhel","",100,200,600,20,-1,1);

  TFile feo("eoy.root");
  TH1F *hy = (TH1F*)feo.Get("he");
  if(which == 1) hy = (TH1F*)feo.Get("ho");

  TFile fpnn95("eff_pnn_95.root");
  TH2F *hpnn95 = (TH2F*)fpnn95.Get("h2pnn");
  TFile fpnn50("eff_pnn_50.root");
  TH2F *hpnn50 = (TH2F*)fpnn50.Get("h2pnn");
  TFile fl0("eff_tistos.root");
  TH2F *hel0 = (TH2F*)fl0.Get("h2tistos");

  TLorentzVector p4eta;
  double m_mu = 105, m_pi = 135, m_eta = 548, L = 1000/sqrt(1.94);

  TGenPhaseSpace gen_mm,gen_mmg;
  double masses_mm[2]={m_mu,m_mu},masses_mmg[2]={0,0};

  if(which == 1) {
    L = 1000/sqrt(2.23);
    masses_mmg[1] = m_pi;
  }

  // eta --> mumu to get pt(eta) weights
  for(int i=0; i<1e6; i++){
    double e = gRandom->Uniform(2,4.5);
    double pt = gRandom->Uniform(1000,11e3);
    if(which == 1) m_eta = gRandom->BreitWigner(782,8.4);
    p4eta.SetPtEtaPhiM(pt,e,0,m_eta);
    gen_mm.SetDecay(p4eta,2,masses_mm);
    gen_mm.Generate();
    TLorentzVector *p4p = gen_mm.GetDecay(0);
    TLorentzVector *p4m = gen_mm.GetDecay(1);
    double ptpt = sqrt(p4p->Pt()/1000. * p4m->Pt()/1000.);
    if(ptpt < 1) ptpt = 1;
    if(ptpt >= 10) ptpt = 9.9;
    int bl0 = hel0->FindBin(ptpt,p4eta.Eta());
    double eff_l0 = hel0->GetBinContent(bl0);
    if(gRandom->Gaus(p4p->Pt(),0.2*p4p->Pt()) > 1600 || gRandom->Gaus(p4m->Pt(),0.2*p4m->Pt()) > 1600) eff_l0 += 0.85*0.6*(1-eff_l0);
    //eff_l0 = 1;
    int bpid = hpnn50->FindBin(p4p->Pt()/1000.,p4p->Eta());
    double eff_pidp = hpnn50->GetBinContent(bpid);
    bpid = hpnn50->FindBin(p4m->Pt()/1000.,p4m->Eta());
    double eff_pidm = hpnn50->GetBinContent(bpid);
    double wt = 1;
    if(p4p->Vect().Angle(p4m->Vect()) < 0.003) wt *= (1 - 0.9*(0.003 - p4p->Vect().Angle(p4m->Vect()))/0.003);
    if(inFid(p4p) && inFid(p4m)) hpt.Fill(pt,(eff_l0+0.5*(1-eff_l0))*eff_pidp*eff_pidm*wt);
    if(inFidP(p4p) && inFidP(p4m)){
      bpid = hpnn95->FindBin(p4p->Pt()/1000.,p4p->Eta());
      eff_pidp = hpnn95->GetBinContent(bpid);
      bpid = hpnn95->FindBin(p4m->Pt()/1000.,p4m->Eta());
      eff_pidm = hpnn95->GetBinContent(bpid);
      hpt2.Fill(pt,eff_l0*eff_pidp*eff_pidm*wt);
    }
  }

  double nemm1 = 0, nemm2 = 0;
  for(int b=1; b<=6; b++){
    double wt = hy->GetBinContent(b)/hpt.GetBinContent(b);
    nemm1 += wt*hpt.GetBinContent(b);
    nemm2 += wt*hpt2.GetBinContent(b);
  }
  cout << hy->Integral() << " " << nemm1 << " " << nemm2 << " " << nemm1/nemm2 << endl;


  double ntot=0,nreco=0,ntrig=0;
  for(int i=0; i<num; i++){
    if(which == 1){
      m_eta = gRandom->BreitWigner(782,8.4);
      if(m_eta < m_pi + 2*m_mu) continue;
    }
    double M = gRandom->Uniform(2*m_mu,m_eta-masses_mmg[1]);
    double wt_M = M/(M*M)*pow(1-M*M/(m_eta*m_eta),3)*(1+2*m_mu*m_mu/(M*M))*sqrt(1-4*m_mu*m_mu/(M*M))*pow(1-M*M/(L*L),-2);
    if(which == 1){
      if(M > 650) continue;
      wt_M = M/(M*M)*(1+2*m_mu*m_mu/(M*M))*sqrt(1-4*m_mu*m_mu/(M*M))*pow(pow(1+M*M/(m_eta*m_eta - m_pi*m_pi),2)-4*m_eta*m_eta*M*M/pow(m_eta*m_eta-m_pi*m_pi,2),3/2.)*pow(1-M*M/(L*L),-2);
    }
    double e = gRandom->Uniform(2,4.5);
    double pt = gRandom->Uniform(1000,11e3);
    int bpt = hpt.FindBin(pt);
    double wt_pt = hy->GetBinContent(bpt)/hpt.GetBinContent(bpt) * 1e6;
    p4eta.SetPtEtaPhiM(pt,e,0,m_eta);
    masses_mmg[0]=M;
    gen_mmg.SetDecay(p4eta,2,masses_mmg);
    gen_mmg.Generate();
    TLorentzVector *p4mumu = gen_mmg.GetDecay(0);
    gen_mm.SetDecay(*p4mumu,2,masses_mm);
    gen_mm.Generate();
    TLorentzVector *p4p = gen_mm.GetDecay(0);
    TLorentzVector *p4m = gen_mm.GetDecay(1);
    TLorentzVector p4prf(*p4p),p4erf(p4eta);
    p4prf.Boost(-(p4mumu->BoostVector()));
    p4erf.Boost(-(p4mumu->BoostVector()));
    double hel = p4prf.CosTheta();
    double ct = cos(p4prf.Vect().Angle(p4erf.Vect()));
    double wt_ct = 1 + ct*ct + pow(2*m_mu/M,2)*(1-ct*ct);
    hm.Fill(M,wt_M*wt_ct);
    //double ptmax = p4p->Pt() > p4m->Pt() ? p4p->Pt() : p4m->Pt();
    if(p4mumu->Pt() < 1000 || p4mumu->Eta() < 2 || p4mumu->Eta() > 4.5) continue;
    double ptpt = sqrt(p4p->Pt()/1000. * p4m->Pt()/1000.);
    if(ptpt >= 10) ptpt = 9.9;
    //double ptpt_tmp = ptpt > 3 ? 3 : ptpt;
    double wt_tmp = 1;
    if(p4p->Vect().Angle(p4m->Vect()) < 0.003) wt_tmp = (1 - (ptpt/2.)*(0.003 - p4p->Vect().Angle(p4m->Vect()))/0.003);
    if(wt_tmp < 0.1) wt_tmp = 0.1;
    wt_pt *= wt_tmp;
    if(ptpt < 1) ptpt = 1;
    double wt = wt_M*wt_ct*wt_pt;

    int bl0 = hel0->FindBin(ptpt,p4eta.Eta());
    double eff_l0 = hel0->GetBinContent(bl0);

    if(gRandom->Gaus(p4p->Pt(),0.2*p4p->Pt()) > 1600 || gRandom->Gaus(p4m->Pt(),0.2*p4m->Pt()) > 1600) eff_l0 += 0.85*0.6*(1-eff_l0);
    //eff_l0 = 1;
    int bpid = hpnn50->FindBin(p4p->Pt()/1000.,p4p->Eta());
    double eff_pidp = hpnn50->GetBinContent(bpid);
    bpid = hpnn50->FindBin(p4m->Pt()/1000.,p4m->Eta());
    double eff_pidm = hpnn50->GetBinContent(bpid);

    ntot += wt;
    ntrig += wt*eff_l0;
    nreco += wt*eff_pidp*eff_pidm;

    if(inFid(p4p) && inFid(p4m)){
      double q2 = (M*M - 4*m_mu*m_mu);
      q2 += gRandom->Gaus(0,9);
      M = sqrt(4*m_mu*m_mu + q2);
      hm1.Fill(M,wt*(eff_l0 +0.5*(1-eff_l0))*eff_pidp*eff_pidm);
      if(inFidP(p4p) && inFidP(p4m)){
        bpid = hpnn95->FindBin(p4p->Pt()/1000.,p4p->Eta());
        eff_pidp = hpnn95->GetBinContent(bpid);
        bpid = hpnn95->FindBin(p4m->Pt()/1000.,p4m->Eta());
        eff_pidm = hpnn95->GetBinContent(bpid);
        hm2.Fill(M,wt*eff_pidp*eff_pidm*eff_l0);
        hmhel.Fill(M,hel,wt*eff_pidp*eff_pidm*eff_l0);

        if(M < 250) hath.Fill(p4p->Vect().Angle(p4m->Vect())*1000);
      }
    }
  }
  double scale = (310/5.8)/hm.Integral();
  if(which == 1) scale = (14/7.)/hm.Integral();
  hm1.Scale(scale);

  cout << ntrig/ntot << " " << nreco/ntot << endl;

  //if(which == 0) scale *= (nemm1/nemm2)/5.6;
  //if(which == 1) scale *= (nemm1/nemm2)/6.4;
  //if(which == 0) scale *= 1.2;
  //if(which == 1) scale *= 1;

  hm2.Scale(scale);
  //  cout << scale << endl;
  cout << hm1.Integral() << endl;

  TCanvas *c1 = new TCanvas("c1","",25,25,700,500);
  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.05);
  c1->SetTopMargin(0.05);
  c1->SetBottomMargin(0.15);

  hy->DrawCopy();
  cout << hy->Integral() << endl;
  cout << hpt.Integral() << endl;
  hpt.Scale(hy->Integral()/hpt.Integral());
  for(int b=1; b<=6; b++) hpt.SetBinError(b,0);
  hpt.DrawCopy("same");

  c1 = new TCanvas("c2","",225,25,700,500);
  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.05);
  c1->SetTopMargin(0.05);
  c1->SetBottomMargin(0.15);

  hm2.SetLineColor(2);
  for(int b=1; b<=100; b++){hm1.SetBinError(b,0);hm2.SetBinError(b,0);}
  hm1.DrawCopy();
  hm2.DrawCopy("same");

  return;
  char str[100];
  sprintf(str,"hel_toy_%d.root",which);
  TFile fo(str,"recreate");
  fo.cd();
  hm1.Write();
  hm2.Write();
  hmhel.Write();

  c1 = new TCanvas("c3","",425,25,700,500);
  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.05);
  c1->SetTopMargin(0.05);
  c1->SetBottomMargin(0.15);

  TH1F hm1copy(hm1);
  hm1copy.SetName("hm1copy");
  hm1copy.Divide(&hm2);
  hm1copy.DrawCopy();

  hath.DrawCopy();

}
