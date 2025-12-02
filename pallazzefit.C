{
  int mymarkerstyle=20;
  float mymarkersize=1.;
  float mytextsize=0.06; //dimensione percentuale del testo
  float mytextlabel=0.07; //dimensione percentuale del testo
  int mytextfont=132;//times new roman

 TCanvas *scatola = new TCanvas("scatola","",650,500);
   scatola->SetBorderSize(2);
   //***controllo distanza degli assi delle figure dai bordi della scatola***//
   scatola->SetLeftMargin(0.12);//18% della larghezza della scatola
   scatola->SetRightMargin(0.05);
   scatola->SetTopMargin(0.03);//3% dell'altezza della scatola
   scatola->SetBottomMargin(0.16);
   //************************************************************************//
   scatola->SetTickx(1);
   scatola->SetTicky(1);
  TH1D *dati = new TH1D("dati","",8,6.1,6.4);
  ifstream leggimi("esperimentopalline3.txt");
  float a;
  while(leggimi>>a)dati->Fill(a);
   gStyle->SetOptStat(0);

dati->SetTitle("");
  //dati->SetNdivisions(908);
  dati->GetXaxis()->SetTitleSize(mytextlabel);
  dati->GetYaxis()->SetTitleSize(mytextlabel);
  dati->GetXaxis()->SetLabelSize(mytextsize);
  dati->GetYaxis()->SetLabelSize(mytextsize);
  dati->GetXaxis()->SetTitleFont(mytextfont);
  dati->GetYaxis()->SetTitleFont(mytextfont);
  dati->GetXaxis()->SetLabelFont(mytextfont);
  dati->GetYaxis()->SetLabelFont(mytextfont);
  dati->GetYaxis()->CenterTitle(1);
  dati->GetXaxis()->CenterTitle(1);
 //distanza del titolo dell'asse dall'asse//
  dati->GetYaxis()->SetTitleOffset(0.85);
  dati->GetXaxis()->SetTitleOffset(1.10);
  //**************************************//
     dati->GetXaxis()->SetTitle("diametro sfere (mm)");
	 dati->GetYaxis()->SetTitle("misure");


  dati->Draw();
  TF1 * modello = new TF1("modello","gaus",6.1,6.4);
  modello->SetLineColor(2); // cambio il colore di default della classe impostando a mano il colore rosso
  dati->Fit("modello","R");
TLatex *pino = new TLatex(6.28, 37 ,Form("media = %5.3f #pm  %5.3f",modello->GetParameter(1), modello->GetParError(1)));
    pino->SetTextFont(132);
    pino->SetTextSize(0.05);
    pino->Draw();
    TLatex *pina = new TLatex(6.28, 34,Form("#sigma = %5.3f #pm  %6.4f",modello->GetParameter(2), modello->GetParError(2)));
        pina->SetTextFont(132);
        pina->SetTextSize(0.05);
        pina->Draw();


	TLegend *leg = new TLegend(0.7,0.6,0.9,0.7,NULL,"brNDC");
  leg->SetBorderSize(1);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetTextSize(0.05);
  leg->SetTextFont(132);
  leg->SetFillStyle(1001);
  leg->AddEntry(pino,"Exp. data","l");
  leg->AddEntry(modello,"fit","l");
  leg->Draw();

  scatola->SaveAs("FigAlefit.pdf");
  scatola->SaveAs("FigAlefit.jpeg");

}
