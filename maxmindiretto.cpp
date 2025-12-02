#include <iostream>
#include <fstream> //libreria per accedere alle classi lettura scrittua da e su file

using namespace std;
int main(){
  ifstream leggimi("gaus.dat");
  if(leggimi.is_open()){
    cout<<"perfetto vai alla grande!"<<endl;
  }
  else{
    cout<<"non trovo il file"<<endl;
  }
  float poveraccio;//serve per le letture
  float massimo, minimo; //definisco le variabili
  leggimi >>massimo;//leggo il primo elemento del file
  minimo = massimo;//impongo che anche minimo sia uguale al primo elemento del file
  while(leggimi>>poveraccio){//quando la lettura fallisce da falso ed esce dal ciclo

      if(massimo<poveraccio){//se il massimo corrente è più piccolo dell'elemento letto, lo sostituisco con l'elemento letto
        massimo=poveraccio;
      }
        if(minimo>poveraccio){//se il minimo corrente è più grande dell'elemento letto, lo sostituisco con l'elemento letto
          minimo=poveraccio;
        }

  }


   cout<<"il massimo vale "<<massimo<<" il minimo vale "<<minimo<<endl;
  return 0;
}
