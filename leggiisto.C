{

   TFile apriti("imieiisto.root");
   TH1F *histo = (TH1F*)apriti.Get("histozoom2_0");
   histo->Draw();
   //histozoom2_0->Draw();

   ofstream scrivo1("dati_modo1.dat");
   ofstream scrivo2("dati_modo2.dat");
   for(int i=1; i< histo->GetNbinsX(); i++){
   scrivo1<<histo->GetBinCenter(i)<<"  "<<histo->GetBinContent(i)<<endl;
   scrivo2<<histo->GetBinContent(i)<<endl;

   }
   scrivo2<<"gli estremi dell'istogramma sono"<<endl;
   scrivo2<<histo->GetBinCenter(1)-histo->GetBinWidth(1)/2<<endl;
  scrivo2<<histo->GetBinCenter(histo->GetNbinsX())+histo->GetBinWidth(1)/2<<endl;



}
