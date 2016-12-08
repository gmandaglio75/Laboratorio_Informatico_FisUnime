//macro root per analizzare dati raccolti nell'esperimento
//misura diametro palline corso di Laboratorio 1
//tutti i dati
{
   int mymarkerstyle=20;
      float mymarkersize=1.;
         float mytextsize=0.065;
         int mytextfont=132;

        TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",600,500);
        gStyle->SetOptStat("");

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
   TH2F *hpx = new TH2F("hpx"," ",10,3.6,4,10,0.,100);

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


   TH1F *pippo = new TH1F("pippo"," ",10,3.6,4);
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

    pippo->Draw("same");

   Canvas_1->SaveAs("palline.pdf");


}
