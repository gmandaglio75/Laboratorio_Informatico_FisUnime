//Implementare un codice capace di mettere a grafico un istogramma con i dati
//maggiori di 10. Provate a modellizzare questo campione con un fit.
{
  ifstream leggo("dati20210124_2.dat");
  TH1D pino("pino","",30,0,0);

  double a;
  while(leggo>>a){
    if(a>10){
    pino.Fill(a);
  }
  }
    pino.Draw();
    pino.Fit("gaus");
}
