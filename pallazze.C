{
  int mymarkerstyle=20;
  float mymarkersize=1.;
  float mytextsize=0.06; //dimensione percentuale del testo
  float mytextlabel=0.07; //dimensione percentuale del testo
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
  TH1D *dati = new TH1D("dati","",8,6.1,6.4);
  ifstream leggimi("esperimentopalline3.txt");
  float a;
  while(leggimi>>a)dati->Fill(a);

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
  dati->GetYaxis()->SetTitleOffset(1.2);
  dati->GetXaxis()->SetTitleOffset(1.10);
  //**************************************//
     dati->GetXaxis()->SetTitle("diametro sfere (mm)");
	 dati->GetYaxis()->SetTitle("misure");


  dati->Draw();

  dati->Fit("gaus");

  scatola->SaveAs("FigAle.pdf");
  scatola->SaveAs("FigAle.jpeg");

}
