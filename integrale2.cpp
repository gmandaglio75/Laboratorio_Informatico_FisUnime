#include <iostream>
#include <cmath>

using namespace std;

double gaus(double nino);
double integrale, integraletemp;

int main(){
     cout.precision(15);
     double a, b, delta;
     a=-1;//estremo inferiore
     b=1; //estreamo superiore
     double precisione;
     cout<<"dimmi la pricisione\n";
     cin>>precisione;
     int ndivisioni =0;
     integrale=1000;

     do{
       ndivisioni++;
      integraletemp = integrale;
     delta = (b-a) /ndivisioni; //intervallo;
      integrale =0;
   for (int i=0; i<ndivisioni; i++){
     integrale = integrale + gaus(a+delta/2.+i*delta) * delta;
     //cout<<gaus(a+delta/2.+i*delta) * delta<<endl;
   }
   cout<<" il valore dell'integrale con ndivisioni pari a "<<ndivisioni<<" è uguale "<<integrale<<endl;
 }while(fabs(integrale - integraletemp)>precisione);

 cout<<"il valore dell'integrale vale "<<integrale<<" ottenuto con un numero di divisioni pari "<<ndivisioni<<endl;
  return 0;
}
double gaus(double nino){
  return exp(-pow(nino,2));
}
