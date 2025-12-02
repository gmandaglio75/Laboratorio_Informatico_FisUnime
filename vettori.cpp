#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int N;
   cout<<"dammi la dimensione dei vettori"<<endl;
   cin>>N;
   float v1[N];
   float v2[N];
   float v3[N];
   for(int i=0; i<N; i++){
     cout<<"dammi la componente "<< i+1 <<" del primo e secondo vettore\n";
     cin>>v1[i]>>v2[i];
   }
   //somma vettoriale
   for(int i=0; i<N; i++){
     v3[i] = v1[i] + v2[i];
   }
   //modulo
   float somma=0;
   for(int i=0; i<N; i++){
     somma = somma + v3[i]*v3[i];
   }
  float modulo = sqrt(somma);
  cout<<"il modulo del vettore somma vale "<<modulo<<endl;

  return 0;
}
