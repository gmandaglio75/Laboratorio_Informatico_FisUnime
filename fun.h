#include <iostream>
using namespace std;
int stamparello(){
   cout<<"chisumu priati!"<<endl;
  return 0;
}
void pariodispari(int numerello){
  if(numerello%2 ==0){
    cout<<"il numero "<<numerello<<" è pari"<<endl;
  }
  else{
    cout<<"il numero "<<numerello<<" è dispari"<<endl;
  }
  return;
}

double sommo(double a, double b){
  return a+b;
}

void scambio(double *a, double *b){
   double pippo;
    pippo=*a;
    *a=*b;
    *b=pippo;
  return;
}

