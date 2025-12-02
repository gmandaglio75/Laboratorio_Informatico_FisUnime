#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
  ifstream leggo("gaus.dat");//creiamo l'oggetto capace di leggere
  if(leggo.is_open()){
    cout<<"ok"<<endl;
  }
  else{
    cout<<"non lo trovo"<<endl;
    return 1;
  }

   double pino[20];
   for(int i =0; i<20; i++){
      leggo>>pino[i];
    }
   for(int i=0; i<20; i++){
     cout<<pino[i]<<endl;
   }
   double pina[20];
   for(int i =0; i<20; i++){
      leggo>>pina[i];
    }

   //int i=0;
   //double a;
   //while(leggo>>a){
   //if(i<20){
      // pino[i]=a;
   //}
   //else{
  //     pina[i-20]=a;
   //}
  // i++
 //}
    double somma[20];
    for(int i=0; i<20; i++){
      somma[i]=pino[i]+pina[i];
      cout<<i<<"   "<<pino[i]<<" + "<<pina[i]<<" = "<<somma[i]<<endl;
    }

    double lunghezza =0;
    for(int i=0; i<20; i++){
      lunghezza= lunghezza + pow(pino[i],2);
    }
    cout<<"la lunghezza di pino = "<<pow(lunghezza,0.5)<<endl;


     double scambio;


         for(int i=0; i<20;i++){
           cout<<pino[i]<<endl;
         }

     for(int i=0; i< 20 / 2; i++){
        scambio = pino[i];
        pino[i] = pino[20-1-i];
        pino[20-1-i] = scambio;
     }

    for(int i=0; i<20;i++){
      cout<<pino[i]<<endl;
    }


  return 0;
}
