//Implementare un programma capace di scrivere su un file
//una tabella di valori x, y tali che la x è generata
//come una successione numerica da 0 a 100
//con passo 0.1 e y = x+x3 -1.
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

float pina(float bubu) {//prende un valore reale in input e restituisce un valore reale
return bubu + pow(bubu,3) -1;
}
int main (){
   ofstream scrivo("daterelli.dat");
   for(float x=0; x<100; x+=0.1){
     //for(int i=0; i<1000; i++)//1000 viene da (100-0)/0.1
     //float x = 0. + i*0.1; //da dove parto + i che moltiplica il passo
     scrivo<<x<<"  "<<pina(x)<<endl;
   }


  return 0;
}
