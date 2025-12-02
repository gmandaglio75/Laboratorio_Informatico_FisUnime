{
TCanvas * scatola = new TCanvas("scatola","",1200,1200);
//              c r    
scatola->Divide(2,3);

TF1 *fun = new TF1("fun","sin(x)",0,3.14);

scatola->cd(1);
fun->Draw();
scatola->cd(2);
fun->Draw();
scatola->cd(3);
fun->Draw();




}
