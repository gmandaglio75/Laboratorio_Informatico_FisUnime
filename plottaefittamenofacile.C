{
  ifstream leggo("menofacile.dat");
  float a;
  TH1F pino("pino","",15,0,10);
  while (leggo>>a)pino.Fill(a);
  pino.SetMarkerStyle(29);
  pino.SetMarkerSize(2);
  pino.Draw("pe");
  TF1 modello("modello","[0]+[1]*x+[2]*x*x",-10,10);

  pino.Fit("modello");



}
