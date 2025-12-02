//Realizzare un grafico dei dati contenuti nel file bgo.dat.
//Rappresentare il grafico, scrivere sull’asse delle x la
//label “canali”, sull’asse delle y la label “conteggi”,
//salvare la figura in formato pdf.
//Profare a fittare localmente I due picchi presenti nei dati.

//## nota l'esercizio chiede di realizzare un grafico con i dati
//presenti nel file...non parla di istogrammi!!!!!!!!!!!
{
  TGraph grafico("bgo.dat");
  //metto i dati a grafico per vedere dove sono presenti i picchi
  //di cui parla l'esercizio
  grafico.GetXaxis()->SetTitle("Canali");   //label asse x
  grafico.GetYaxis()->SetTitle("Conteggi"); //label asse y
  grafico.Draw();
  //creo i modelli per i fit
  TF1 *modello1 = new TF1("modello1","gaus",100,400);
  modello1->SetLineColor(2);//cambio colore alla curva altrimenti non si vede
  TF1 *modello2 = new TF1("modello2","gaus",1600,2100);
  modello2->SetLineColor(4);//come sopra
  grafico.Fit("modello1","R");

  grafico.Fit("modello2","R+");
}
