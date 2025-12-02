#include <iostream>
using namespace std;

// ciòcherestituiscono nomedellafunzione(ciòcheprendonocomeinput){
//implementazione della funzione
//}

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


int  main() {
  /* code */
  for(int i=0; i<10; i++){
  stamparello();
}
   cout<<"dammi un numero"<<endl;
   int pino;
   cin>>pino;
   pariodispari(pino);
   pariodispari(5);
   cout<< sommo(5.65,pino)<<endl;

     double pillo =10;
     double pilla =20;
 cout<<pillo<<"  "<<pilla<<endl;
     scambio(&pillo,&pilla);
     cout<<pillo<<"  "<<pilla<<endl;

  return 0;
}
