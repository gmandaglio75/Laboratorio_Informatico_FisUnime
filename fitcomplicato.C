{

  int mymarkerstyle=20;
  float mymarkersize=1.;
  float mytextsize=0.065;
  int mytextfont=132;
  
  TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",600,500);

  Canvas_1->SetFillColor(0);
  Canvas_1->SetBorderMode(0);
  Canvas_1->SetBorderSize(2);
  Canvas_1->SetLeftMargin(0.15);
  Canvas_1->SetRightMargin(0.07);
  Canvas_1->SetTopMargin(0.03);
  Canvas_1->SetBottomMargin(0.16);
 //  Canvas_1->SetGridx();
 //  Canvas_1->SetGridy();
  Canvas_1->SetTickx(1);

  gStyle->SetOptStat(1111);

  TF1 *ff=new TF1("ff","[0]*pow((sqrt(1-pow(sin(x)/[1],2))-[1]*cos(x))/(sqrt(1-pow(sin(x)/[1],2))+[1]*cos(x)),2)",25*3.14/180,75*3.14/180);
  //parametri di innesco
  ff->SetParameter(0,2320);
  ff->SetParameter(1,1.6);
  TGraph *pippo= new TGraph("datuzzi.dat");
  pippo->SetTitle("");
  pippo->GetXaxis()->SetTitleSize(mytextsize);
  pippo->GetYaxis()->SetTitleSize(mytextsize);
  pippo->GetXaxis()->SetLabelSize(mytextsize);
  pippo->GetYaxis()->SetLabelSize(mytextsize);
  pippo->GetXaxis()->SetTitleFont(mytextfont);
  pippo->GetYaxis()->SetTitleFont(mytextfont);
  pippo->GetXaxis()->SetLabelFont(mytextfont);
  pippo->GetYaxis()->SetLabelFont(mytextfont);
  pippo->GetYaxis()->CenterTitle(1);
  pippo->GetXaxis()->CenterTitle(1);
  pippo->GetYaxis()->SetTitleOffset(1.1);
  pippo->GetXaxis()->SetTitleOffset(1.10);
  pippo->GetYaxis()->SetTitle("R_{p} (mV)");
  pippo->GetXaxis()->SetTitle("#theta_{i} (rad.)");
  pippo->SetMarkerStyle(20);
  pippo->Draw("ap");
  pippo->Fit("ff");

  float media,sigma,media2,sigma2,chi,ndf;
  TLegend *leg = new TLegend(0.2,0.7,0.55,0.85,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetTextSize(0.05);
  leg->SetTextFont(132);
  leg->SetFillStyle(1001);
  media=ff->GetParameter(0);
  sigma=ff->GetParError(0);
  media2=ff->GetParameter(1);
  sigma2=ff->GetParError(1);
  chi=ff->GetChisquare();
  ndf=ff->GetNDF();
  leg->AddEntry(pippo,Form("#chi^{2} / ndf = %6.2f / %3.0f",chi,ndf),"");
  leg->AddEntry(pippo,Form("A=%5.2f #pm %5.2f",media,sigma),"");
  leg->AddEntry(pippo,Form("n2=%5.2f #pm %5.2f",media2,sigma2),"");
  leg->Draw();
  Canvas_1->SaveAs("fit.pdf");
}
