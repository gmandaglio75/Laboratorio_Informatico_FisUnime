{
  //TGraph *grafico = new TGraph("dati.dat");
  TGraph *grafico = new TGraph("VoltageSPI-RC.txt");
  grafico->Draw();
  cout<<"numero di dati x y letti = "<< grafico->GetN()<<endl;

     TF1 *modello1 = new TF1("modello1","[0]*(1-exp(-x/[1]))",0,10);
     TF1 *modello2 = new TF1("modello2","[0]*exp(-(x-[2])/[1])",10,20);

     modello1->SetParameters(0.4,0.01);
     modello2->SetParameters(0.4,0.01,10);

     grafico->Fit("modello1","R");//R se no lo fitta dappertutto
     grafico->Fit("modello2","R+");//+ serve per sovrapporre

}
