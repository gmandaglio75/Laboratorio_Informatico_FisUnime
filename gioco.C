{
TGraph *pino = new TGraph();

double x,y,step,a;
step=0.1;
a=1;
TCanvas *oooh=new TCanvas("oooh","",1200,1200);
for(int i=0;i<10009;i++){
a=double(i)*step;

x= a*cos(a);
y= a*sin(a);
//cout<< i <<"  "<<x<<"  "<<y<<endl;
//cout<<x<<"  "<<y<<endl;
pino->SetPoint(i,x,y);
pino->Draw();
oooh->Update();
oooh->Clear();
}



}
