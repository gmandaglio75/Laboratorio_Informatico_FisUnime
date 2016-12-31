void carteggio_funz()
{
double a,b;
a=10; b=100;
cout<<a+b<<endl;
TF1 *pippo = new TF1("pippo","sin(x)+cos(x)",0,1);
pippo->Draw();
cout<<pippo->Eval(0.3)<<endl;
return;
}
