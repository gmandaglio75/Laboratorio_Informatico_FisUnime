#include <iostream>
#include "fun.h"
using namespace std;



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
