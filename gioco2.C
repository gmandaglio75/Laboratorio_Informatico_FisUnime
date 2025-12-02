{
TGraph *pino = new TGraph();
TGraph *pina = new TGraph();


double x,y,step,a,b;
step=0.1;
TCanvas *oooh=new TCanvas("oooh","",600,600);

int ombra=0;
for(int i=0;i<200;i++){ //stampiamo il primo strato
a=double(ombra)*step;
x= a;
y= sin(a);
pino->SetPoint(ombra,x,y);
pino->Draw();
oooh->Update();
ombra++;
}
int colore=2;
pina->SetLineColor(colore);
ombra=0;
bool pinoopina = 1;

for(int i=0;i<1200;i++){
a=double(ombra)*step;
x= a;
y= sin(a);
if(pinoopina)
{
pina->SetPoint(ombra,x,y);
pina->Draw("same");
}
else
{
pino->SetPoint(ombra,x,y);
pino->Draw("same");
}
oooh->Update();
ombra++;
if(i%200==0)
{
ombra=0;
pinoopina = !pinoopina;
if(pinoopina){
colore=2;
pina = new TGraph();
pina->SetLineColor(colore);
}
else
{
colore=4;
pino= new TGraph();
pino->SetLineColor(colore);
}
}

}



}
