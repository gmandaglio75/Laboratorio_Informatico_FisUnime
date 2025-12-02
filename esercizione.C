{
  //TGraph *grafico = new TGraph("dati.dat");
  TGraph *grafico = new TGraph("VoltageSPI-RC.txt");
  grafico->Draw();
  cout<<"numero di dati x y letti = "<< grafico->GetN()<<endl;
//allocazione dinamica della memoria
//dinamica perchè non è nota a-priori
//tipovariabile  *nomedellavariabile  = new tipovariabile[il numero di elementi che deve avere il vettore];
  double *ipsilon = new double[grafico->GetN()];//questo discende da una versione di c++ ortodossa
  //double ipsilon[grafico->GetN()]; //le versioni più moderne del compilatore c++ concedono questa scrittura
  double *ipsilondiff = new double[grafico->GetN()];

  ipsilon = grafico->GetY();
   double minimo =ipsilon[0]; //inizializzo al primo elemento del vettore
  for(int i =1; i<grafico->GetN(); i++){
    if(minimo>ipsilon[i]) minimo = ipsilon[i];
  }
    cout<<"il valore minimo assoluto delle ipsilon è pari "<<minimo<<endl;

    for(int i =0; i<grafico->GetN(); i++){//cicla da 0 a 600
      //il metodo SetPointY prende in input un intero e un reale
      //l'intero dice quale punto deve essere modificato
      //il reale fornisce il valore che sostituisce quello esistente
      grafico->SetPointY(i,ipsilon[i]+fabs(minimo));//fabs valore assoluto dei numeri float (reali)
    }

    grafico->Draw();
    double *ics = new double[grafico->GetN()];
    ics = grafico->GetX();
    TGraph *diffgrafico = new TGraph();//creiamo un TGraph vuoto

//conversione del grafico nella forma differnziale
    for (int i =0; i<grafico->GetN()-1; i++)
    {
      diffgrafico->SetPoint(i,ics[i],(ipsilon[i+1])-(ipsilon[i]));
  }

   ipsilondiff = diffgrafico->GetY();

/*
//reiteriamo l'operazione due volte
ipsilonmedio = diffgrafico->GetY();//estraimo i valori differenziali
for (int i =0; i<grafico->GetN()-3; i++)
{
diffgrafico->SetPoint(i,ics[i],(ipsilonmedio[i+2]+ipsilonmedio[i+1]+ipsilonmedio[i])/3.);
}
*/
     grafico->GetYaxis()->SetRangeUser(-0.1,3.3);
     grafico->Draw();
     diffgrafico->SetLineColor(4);

     diffgrafico->Draw("same");
     double massimo,  a, b, c;

     c= ics[grafico->GetN()-1]; //estemo finale secondo fit
       massimo = ipsilondiff[0];
       minimo = ipsilondiff[0];
      for(int i=0; i< grafico->GetN(); i++){
      //  cout<<massimo <<"   "<<ipsilondiff[i]<<endl;
        if(massimo < ipsilondiff[i]){
          a=ics[i]; //primo estremo
          massimo = ipsilondiff[i];
          //cout<<a<<endl;
        }
          if(minimo > ipsilondiff[i]){
            b=ics[i]; //secondo estremo
            minimo = ipsilondiff[i];
          }

      }

     TF1 *modello1 = new TF1("modello1","[0]*(1-exp(-x/[1]))",0,10);
     TF1 *modello2 = new TF1("modello2","[0]*exp(-(x-[2])/[1])",10,20);

     modello1->SetParameters(0.4,0.01);
     modello2->SetParameters(0.4,0.01,10);

     grafico->Fit("modello1","R");//R se no lo fitta dappertutto
     grafico->Fit("modello2","R+");//+ serve per sovrapporre

     cout<<a<<"  "<<b<<"  "<<c<<endl;
}
