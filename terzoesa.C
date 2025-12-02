//Implementare un codice capace di mettere a grafico i dati appena
//generati sottoforma di tabella. Provare a fittare i dati con la
// funzione utilizzata per produrre la successione numerica.

//y = x+x3 -1.
{
  //per la rappresentazione dei dati diretta la classe più congeniale
  //è TGraph, se il file è strutturato come una tabella x y
  TGraph *pino = new TGraph("daterelli.dat"); //con l'uso di questo costruttore automaticamente i dati sono caricati

  pino->Draw();
//le classi utilizzate per creare i modelli da passare alle procedure di Fit sono le TF1
TF1 *modello = new TF1("modello","[0]*x+[1]*pow(x,3)+[2]",0,100);
   modello->SetLineColor(2);
   modello->SetLineStyle(10);
   pino->Fit("modello");


}
