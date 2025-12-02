{
  TF1 gino("gino","-x*x+100",0,10);
  TGraph gina;
  TCanvas pino;
  for(int i=1; i<1000; i++){
     gina.SetPoint(i,i*0.01, gino.Eval(i*0.01));
     pino.Clear();
     gina.Draw();
     pino.Update();


  }

}
