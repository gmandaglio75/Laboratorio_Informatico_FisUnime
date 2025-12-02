{
  vector<double> x,y;
  ifstream gino("dati_modo1.dat")  ;

  double a,b;
  while(gino>>a>>b){
    x.push_back(a);
    y.push_back(b);
  }

  TH1F *histo = new TH1F("histo","",x.size(),x[0]-(x[1]-x[0])/2.,x[x.size()-1]+(x[1]-x[0])/2.);
  for(int i=0; i<y.size(); i++){
     histo->SetBinContent(i+1,y[i]);
  }
    histo->Draw();

}
