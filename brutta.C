{
  ifstream leggo("datisin.dat");
  if(!leggo.is_open()){

    cout<<" non trovo una mazza!!!\n";
    return;
  }
  float a;
  TH1F *histo = new TH1F("histo","",200,0,0);
   while(leggo>>a) histo->Fill(a);
   histo->Draw();
ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Genetic");
   //guardando la figura immagino che il modello appropriato sia il seguent
   // A sin (bx + c) +d  una funzione a 4 parametri
   TF1 *gino = new TF1("gino","[0]*sin([1]*x+[2]) + [3]",-1,10);
   gino->SetParameters( 3000, 2, 2 , 5500);
   gino->SetLineColor(2);
   //gino->Draw("same");

   histo->Fit("gino");

  
}
