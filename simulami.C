{
  //leggiamo i dati usando la classe di c++ ifstream
  ifstream leggo("dati2.dat");
  //variabile di lettura
  float usami;
  TH1F *isto = new TH1F("histo","",130,-3,10);
  //leggiamo i dati e li passiamo all'oggetto isto della classe TH1F
  while(leggo>>usami){
    isto->Fill(usami);
  }
  //usiamo il metodo Draw per visualizzare il grafico
  TCanvas gino;
  isto->Draw();
  //creiamo la cumulativa
  //ci serve una variabile per fare la sommatoria
  float somma = 0; //inizializziamo all'elemento neutro della sommatoria
  TH1F *cumulativa = new TH1F("cumulativa","",130,-3,10);

  for(int i=1; i< 131; i++){//parte da 1 percheè l'istogramma conta da 1

    somma = somma + isto->GetBinContent(i);
    cumulativa->SetBinContent(i, somma);
  }
  TCanvas gina;

 cumulativa->Scale(1/somma);
  cumulativa->Draw();
  TGraph *invertimi = new TGraph();
  for(int i=1; i< 131; i++){//parte da 1 percheè l'istogramma conta da 1

    invertimi->SetPoint(i-1,cumulativa->GetBinContent(i),cumulativa->GetBinCenter(i));
  }
  TCanvas pina;
  //abbiamo usato un TGraph per invertire per punti "la cumulativa"
  invertimi->Draw();

  //prenotiamo un oggetto della classe TRandom3
  TRandom3 generoso(0); //generoso è capace di restituire numeri casuali
  for(int i=0; i<10; i++){
  cout<<generoso.Uniform()<<endl;
}

  TH1F *generato = new TH1F("generato","",130,-3,10);
    TH1F *unif = new TH1F("unif","",100,0,1);
    TCanvas *beddi = new TCanvas("beddi","",600,500);

    TCanvas *beddi2 = new TCanvas("beddi2","",600,500);

    for(int i =0; i<1000; i++){
       beddi->cd();
       double a;
       a= generoso.Uniform();
       generato->Fill(invertimi->Eval(a));
      generato->Draw();
      beddi->Update();
      beddi->Clear();
      beddi2->cd();
      unif->Fill(a);
      unif->Draw();
      beddi2->Update();
      beddi2->Clear();
    }
    beddi->cd();
    generato->Draw();
    beddi2->cd();
    unif->Draw();
TH1F *generato2 = new TH1F("generato2","",130,-3,10);
    for(int i=0; i<1000; i++){
     generato2->Fill(histo->GetRandom());

    }
    TCanvas pino;
    generato2->Draw();
}
