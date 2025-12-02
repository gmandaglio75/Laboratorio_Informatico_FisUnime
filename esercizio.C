{
  TH1F *grafico1 = new TH1F("g1", "", 100, 0, 0);
  TH1F *grafico2 = new TH1F("g2", "", 100, 0, 0);
  TH1F *grafico3 = new TH1F("g3", "", 100, 0, 0);
  TH1F *grafico4 = new TH1F("g4", "", 100, 0, 0);
  ifstream leggo("dati1.dat");
  if(leggo.is_open()) cout<<"Tutto ok\n";
  float dato;
  ofstream file("prova.dat");
  int i = 0;
  while(leggo>>dato){
	 
    if(i < 10){
      grafico1->Fill(dato);
    }
    if(i < 100){
      grafico2->Fill(dato);
    }
    if(i < 1000){
      grafico3->Fill(dato);
    }
    if(i < 10000){
      grafico4->Fill(dato);
    }
    i++;
  }

  TCanvas *box = new TCanvas("box", "", 1200, 1200);
  box->Divide(2, 2);
  box->cd(1);
  grafico1->Draw();
  box->cd(2);
  grafico2->Draw();
  box->cd(3);
  grafico3->Draw();
  box->cd(4);
  grafico4->Draw();



}
