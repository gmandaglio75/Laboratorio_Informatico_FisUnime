{
  gStyle->SetOptStat(1111);
  ifstream leggo("dati2.dat");
  double a;
  TH1F *histo = new TH1F("histo","",100, -3,10);
  while(leggo>>a)histo->Fill(a);
  histo->Draw();
  TF1 *g1 = new TF1("g1","gaus",-1,3);
  g1->SetParNames("A","B","C"); //cambiamo i nomi perché se usate
  //due guassiane lui mette gli stessi nomi per valore medio sigma
  //e ampiezza e poi si confonde nel fit globale
  TF1 *g2 = new TF1("g2","gaus",4,6.5);
  g2->SetParNames("D","E","F");
  TF1 *p1 = new TF1("p1","pol1",7,10);
  p1->SetParNames("G","H");

  histo->Fit("g1","R");
  histo->Fit("g2","R+");
  histo->Fit("p1","R+");

  TF1 *all = new TF1("all","g1+g2+p1",-3,10);
  all->SetLineColor(1);
  histo->Fit("all","R");
  double parametri[8];
  all->GetParameters(parametri); //carico automaticamente tutti i valori dei parametri nel vettore
  cout << "il chi2 ridotto vale = " <<all->GetChisquare()/all->GetNDF()<<endl;
  cout<<all->GetNDF()<<endl;
    cout<<all->GetChisquare()<<endl;

    g1->SetParameters(&parametri[0]); //fisso i parametri della prima componente di all, ai primi tre parametri di all

    g2->SetParameters(&parametri[3]);
    p1->SetParameters(&parametri[6]);

    g1->SetLineColor(2);//rossa
    g2->SetLineColor(3);//verde
    p1->SetLineColor(4);//blu
    g1->SetRange(-3,10);
    g2->SetRange(-3,10);
    p1->SetRange(-3,10);


    g1->Draw("same");
    g2->Draw("same");
    p1->Draw("same");

   TH1F *fondo = (TH1F*)histo->Clone();
   TH1F *pulito = (TH1F*)histo->Clone();
   fondo->Reset();
   pulito->Reset();
   fondo->Add(p1,1); //trucco uso il metodo di somma degli istogrammi per creare l'istogramma del fondo partendo dalla TF1 che parametrizza il fondo
   pulito ->Add(histo,fondo,1,-1); //sottraggo
   TCanvas pino;
   histo->Draw();
   pulito->Draw("same");
   fondo->Draw("same");
   g1->Draw("same");
   g2->Draw("same");



}
