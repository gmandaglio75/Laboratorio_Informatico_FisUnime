/* We read data from dati2.dat file to fill the histogram */
{
TCanvas *campione1= new TCanvas("campione1","campione1",600,700);
double a,b;
TH1D *spettro= new TH1D("spettro","",100,a,b);
ifstream leggi("dati2.dat");
double dati;
while(leggi>>dati){
spettro->Fill(dati);
}

//by looking the figure we note the presence of two structure peak-like
//then we decide to model by two Gaussian functions and ....
TF1 *f1=new TF1("f1","gaus",-2,3);
//f1->SetParameters(100.,1.5,3); //starting value of parameters
f1->SetParNames("a","b","c"); 
f1->SetLineColor(2);
f1->SetLineStyle(2);

 TF1 *f2=new TF1("f2","gaus",4,7);
// f2->SetParNames("d","e","f");  //remane the variables in order to avoid confusion between the two Gaussian fuctions
 f2->SetParameters(100.,5.8,1.5);
 f2->SetLineColor(2);
 f2->SetLineStyle(2);


 TF1 *f3=new TF1("f3","pol1",8,10); //..and a linear background shape
 f3->SetParNames("h","i");
 f3->SetParameters(0.2,0);
 f3->SetLineColor(2);
 f3->SetLineStyle(2);





TF1 *Fsomma=new TF1("Fsomma","f2+f1+f3",-3,9.);//we define the function defined as the sum of the previous ones.
Fsomma->SetLineColor(1);
Fsomma->SetLineStyle(1);
Fsomma->SetLineWidth(2);

Double_t par[8];//this vector will contain the results of the singular fit
spettro->Draw("same");
//spettro->Fit("f1","R"); //singular fit performed in a limited range, defined by the definition interval of f1,f2,f3
//spettro->Fit("f2","R+");
//spettro->Fit("f3","R+");

f1->GetParameters(&par[0]);//we get back the value of the single fits and we use it as stanting value for the global fit
f2->GetParameters(&par[3]);
f3->GetParameters(&par[6]);
//Fsomma->SetParameters(par);
spettro->Fit("Fsomma","R+");
campione1->SaveAs("fillaandfit.pdf");

}

