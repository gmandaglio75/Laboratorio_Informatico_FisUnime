//macro root per analizzare dati raccolti nell'esperimento
//misura diametro palline corso di Laboratorio 1
//parte dei dati + implementazione di un fit gaussiano

{
   int mymarkerstyle=20;
      float mymarkersize=1.;
         float mytextsize=0.065;
         int mytextfont=132;

        TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",600,500);

   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetLeftMargin(0.18);
   Canvas_1->SetRightMargin(0.12);
   Canvas_1->SetTopMargin(0.03);
   Canvas_1->SetBottomMargin(0.16);
 //  Canvas_1->SetGridx();
 //  Canvas_1->SetGridy();
   Canvas_1->SetTickx(1);
   Canvas_1->SetTicky(1);

   //Canvas_1->SetLogy();
////ZOOM SCATOLA////////////////////////////////////
   TH2F *hpx = new TH2F("hpx"," ",8,3.75,3.97,10,0.,100);

   hpx->SetStats(0);
   hpx->SetNdivisions(905);
   hpx->GetXaxis()->SetTitleSize(mytextsize);
   hpx->GetYaxis()->SetTitleSize(mytextsize);
   hpx->GetXaxis()->SetLabelSize(mytextsize);
   hpx->GetYaxis()->SetLabelSize(mytextsize);
   hpx->GetXaxis()->SetTitleFont(mytextfont);
   hpx->GetYaxis()->SetTitleFont(mytextfont);
   hpx->GetXaxis()->SetLabelFont(mytextfont);
   hpx->GetYaxis()->SetLabelFont(mytextfont);
   hpx->GetYaxis()->CenterTitle(1);
   hpx->GetXaxis()->CenterTitle(1);
   hpx->GetYaxis()->SetTitleOffset(1.2);
   hpx->GetXaxis()->SetTitleOffset(1.10);
//   hpx->GetXaxis()->SetLabelColor(0);
   hpx->SetTitle("");
   hpx->GetYaxis()->SetTitle("Conteggi");
   hpx->GetXaxis()->SetTitle("Diametro Palline (mm)");

        hpx->Draw();
/////////////////////////////////////////////////////////////////////


   TH1F *pippo = new TH1F("pippo"," ",7,3.75,3.97);
        gStyle->SetOptStat(1111);
   pippo->SetStats(1);
   pippo->SetLineWidth(2);
   pippo->SetLineColor(1);
   ifstream leggimi("Misure.dat");
   double a;
   while(!leggimi.eof()){
   leggimi>>a;
   if(!leggimi.eof()){
     pippo->Fill(a);
    }
    }


float media,sigma,chi,ndf;


    pippo->Draw("same");
    pippo->Fit("gaus");

 TLegend *leg = new TLegend(0.2,0.8,0.55,0.95,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
    leg->SetTextSize(0.05);
    leg->SetTextFont(132);
   leg->SetFillStyle(1001);
media=gaus->GetParameter(1);
sigma=gaus->GetParameter(2);
chi=gaus->GetChisquare();
ndf=gaus->GetNDF();
leg->AddEntry(pippo,Form("#chi^{2} / ndf = %6.2f / %3.0f",chi,ndf),"");
leg->AddEntry(pippo,Form("Diametro=%5.2f #pm %5.2f",media,sigma),"");

leg->Draw();
   Canvas_1->SaveAs("pallinefit.pdf");


}
