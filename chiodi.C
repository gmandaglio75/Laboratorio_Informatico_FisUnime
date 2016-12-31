{
  Int_t mymarkerstyle=20;
  float mymarkersize=0.6;
  float mytextsize=0.06;
  float mylabsize=0.055;
  TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",600,450);
//   gStyle->SetOptStat(1);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetLeftMargin(0.15);
    Canvas_1->SetRightMargin(0.055);
   Canvas_1->SetTopMargin(0.01);
   Canvas_1->SetBottomMargin(0.15);
 //  Canvas_1->SetGridx();
 //  Canvas_1->SetGridy();
  // Canvas_1->SetLogy();
   Canvas_1->SetTickx(1);
   Canvas_1->SetTicky(1);
  
   //ROOT::Math::MinimizerOptions::SetDefaultMinimizer("GSLMultiMin");
   ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit2");
   TH1F *h1 = new TH1F("h1"," ",30,6.8,7.2);  
  // h1->SetStats(1111); 
   gStyle->SetOptFit(1);

// Set stat options
   gStyle->SetStatY(0.99);                
// // Set y-position (fraction of pad size)
   gStyle->SetStatX(0.99);                
// // Set x-position (fraction of pad size)
   gStyle->SetStatW(0.25);                
// // Set width of stat-box (fraction of pad size)
   gStyle->SetStatH(0.22);                
// // Set height of stat-box (fraction of pad size)


   h1->GetXaxis()->SetTitleSize(mytextsize);
   h1->GetYaxis()->SetTitleSize(mytextsize);
   h1->GetXaxis()->SetTitleFont(132);
   h1->GetYaxis()->SetTitleFont(132);
   h1->GetXaxis()->SetLabelSize(mylabsize);
   h1->GetXaxis()->SetNdivisions(909);
   h1->GetYaxis()->SetLabelSize(mylabsize);
   h1->GetXaxis()->SetLabelFont(132);
   h1->GetYaxis()->SetLabelFont(132);
   h1->GetXaxis()->CenterTitle(1);
   h1->GetYaxis()->CenterTitle(1);
   h1->GetYaxis()->SetTitleOffset(1.1);
   h1->GetXaxis()->SetTitleOffset(0.98);
   h1->SetTitle("");
   h1->GetYaxis()->SetTitle("Frequenza assoluta");
   h1->GetXaxis()->SetTitle("Lunghezza dei chiodi (cm)");
   h1->SetMarkerStyle(20);
   h1->SetMarkerColor(4);
   for (i=0;i<2000;i++) h1->Fill(gRandom->Gaus(7,0.05));

   h1->Draw();

   Canvas_1->SaveAs("chiodiist.pdf");
   h1->Draw("e1p");
   
   Canvas_1->SaveAs("chiodiistp.pdf");
   h1->Fit("gaus");

   Canvas_1->SaveAs("chiodiistpf.pdf");
  
}
