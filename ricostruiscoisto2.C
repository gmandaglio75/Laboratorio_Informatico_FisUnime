{
TH1F *histo = new TH1F("histo","",99,-1.71635,4.68554);

ifstream leggo("dati_modo2.dat");
double a;
int i=1;
while(leggo>>a){
   histo->SetBinContent(i,a);
   i++;
}
histo->Draw();
TF1 *gaussiana = new TF1("gaussiana","gaus",-3,6);

histo->Fit("gaussiana");
TF1 *funzione = new TF1("funzione","20 +10*x",-3,6);
funzione->Draw("same");
   double diff = funzione->Eval(-3)-gaussiana->Eval(-3);
   double diff2;
   vector<double> intersezione;
 for(int i=0; i<1100000; i++){
    diff2=funzione->Eval(-3+ i*0.00001)-gaussiana->Eval(-3+ i* 0.00001);
    if(diff*diff2<0){
      intersezione.push_back(-3+ i*0.00001-0.00001/2.);
    }
    diff= diff2;
  }
  cout<<"le intersezioni sono "<<endl;
  for(int i=0; i< intersezione.size(); i++){

    cout<<"intersezione a "<<intersezione[i]<<endl;
  }
 TF1 *differenza = new TF1("differenza","funzione - gaussiana",-3,6);
  TCanvas pino;
  differenza->Draw();
}
