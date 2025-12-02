#include <iostream>
#include <cmath>

using namespace std;

double gaus(double nino);


int main(){
     double a, b, delta, ndivisioni;
     a=-1;//estremo inferiore
     b=1; //estreamo superiore
     ndivisioni = 20;
     cout <<"ti calcolo l'integrale di una gaussiana \n";
     cout<<"dammi il numero di divisioni\n";
     cin>>ndivisioni;
     delta = (b-a) /ndivisioni; //intervallo;
     double integrale =0;
   for (int i=0; i<ndivisioni; i++){
     integrale = integrale +  ( gaus(a+i*delta)   +gaus(a+(i+1)*delta))*delta/2.  ;
     //cout<<gaus(a+delta/2.+i*delta) * delta<<endl;
   }
   cout<<" il valore dell'integrale con ndivisioni pari a "<<ndivisioni<<" è uguale "<<integrale<<endl;
  return 0;
}
double gaus(double nino){
  return exp(-pow(nino,2));
}
