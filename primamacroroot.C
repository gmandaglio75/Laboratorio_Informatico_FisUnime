{
ifstream leggimi("gaus.dat");
double a;
TH1D pinello("pinello","per Elena",100,2,7);
TCanvas pino;
while(leggimi>>a){
	pinello.Fill(a);

        pinello.Draw();
	pino.Update();
}
cout<<"media "<<pinello.GetMean()<<endl;
cout<<"dev standard "<<pinello.GetRMS()<<endl;
}
