{
  int mymarkerstyle=20;
  float mymarkersize=1.;
  float mytextsize=0.06; //dimensione percentuale del testo
  int mytextfont=132;//times new roman

 TCanvas *scatola = new TCanvas("scatola","",600,500);
   scatola->SetBorderSize(2);
   //***controllo distanza degli assi delle figure dai bordi della scatola***//
   scatola->SetLeftMargin(0.18);//18% della larghezza della scatola
   scatola->SetRightMargin(0.05);
   scatola->SetTopMargin(0.03);//3% dell'altezza della scatola
   scatola->SetBottomMargin(0.16);
   //************************************************************************//
   scatola->SetTickx(1);
   scatola->SetTicky(1);


  TGraphErrors *dati = new TGraphErrors("pianoinclinato.dat");

dati->SetTitle("");
  //dati->SetNdivisions(908);
  dati->GetXaxis()->SetTitleSize(mytextsize);
  dati->GetYaxis()->SetTitleSize(mytextsize);
  dati->GetXaxis()->SetLabelSize(mytextsize);
  dati->GetYaxis()->SetLabelSize(mytextsize);
  dati->GetXaxis()->SetTitleFont(mytextfont);
  dati->GetYaxis()->SetTitleFont(mytextfont);
  dati->GetXaxis()->SetLabelFont(mytextfont);
  dati->GetYaxis()->SetLabelFont(mytextfont);
  dati->GetYaxis()->CenterTitle(1);
  dati->GetXaxis()->CenterTitle(1);
 //distanza del titolo dell'asse dall'asse//
  dati->GetYaxis()->SetTitleOffset(1.2);
  dati->GetXaxis()->SetTitleOffset(1.10);
  //**************************************//
     dati->GetXaxis()->SetTitle("masse (grammi)");
     dati->GetYaxis()->SetTitle("Forza (Nw)");


  dati->SetMarkerStyle(20);
  dati->SetMarkerSize(1.4);
  dati->GetXaxis()->SetRangeUser(55,400);
  dati->Draw("ape");
//modello
  TF1 * modello = new TF1("modello","[0]+[1]*x",51,400);

  dati->Fit("modello","R");
  cout<<"intercetta = "<<modello->GetParameter(0)<<endl;
  cout<<"coeff ango = "<<modello->GetParameter(1)<<endl;
   //                                               %5.3f  5 è il numero totale di simboli, 3 il numero di cifre dopo la virgola, f lo specificatore di formato dei flot
TLatex *pino = new TLatex(80, 0.54,Form("Intercetta = %5.3f #pm  %5.3f",modello->GetParameter(0), modello->GetParError(0)));
    pino->SetTextFont(132);
    pino->SetTextSize(0.05);
    pino->Draw();
    TLatex *pina = new TLatex(80, 0.6,Form("Coef. ang. = %5.3f #pm  %6.4f",modello->GetParameter(1), modello->GetParError(1)));
        pina->SetTextFont(132);
        pina->SetTextSize(0.05);
        pina->Draw();

        scatola->SaveAs("pianoinclinato.pdf");

}
