{

  TCanvas *box = new TCanvas("box","",600,500);
 ifstream leggo("dati2.dat");
  double a;
  vector<TH1F*> ciccio;
  TH1F *histo = new TH1F("histo","",100, -3,10);
  int contami =0;
  int i =0;
  while(leggo>>a && i<3){
  histo->Fill(a);
  histo->Draw();
  box->Update();
  box->Clear();//non saturare la memoria grafica
  contami++;
  if(contami==1000){
    ciccio.push_back(histo);
    histo = new TH1F(Form("histo%d",i),"",100, -3,10);
    i++;

    contami=0;
  }
}
  histo->Draw();

  TFile salvami ("scanIsto.root","recreate");
  for(int i=0; i<ciccio.size(); i++)
  ciccio[i]->Write();

}
