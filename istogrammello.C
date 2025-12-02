{
  TCanvas *box1 = new TCanvas("box1","",600,500);
    TCanvas *box2 = new TCanvas("box2","",600,500);
  TH1F *histo = new TH1F("histo","",100,0,0); //0,0 gli estremi se li trova da solo
  ifstream leggo("gaus.dat");
  float nino;
  while(leggo>>nino){
    histo->Fill(nino);
  }
  box1->cd();
  histo->Draw();
  histo->Fit("gaus");
  TH2D *pina = new TH2D("pina","",100,0,0,100,0,0);
  ifstream leggi2("dati_new.dat");
  float nina, babbo;
  while(leggi2>>nino>>babbo>>babbo>>nina>>babbo>>babbo>>babbo>>babbo>>babbo>>babbo>>babbo>>babbo){
    pina->Fill(nino,nina);
  }
  box2->cd();
   pina->Draw("surf2");

}
