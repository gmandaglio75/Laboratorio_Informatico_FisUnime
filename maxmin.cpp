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
  float poveraccio;//serve per le letture farlocche
  int contami =0;//per contare le letture
  while(leggimi>>poveraccio){//quando la lettura fallisce da falso ed esce dal ciclo
    contami++;//contiamo le operazione di lettura
  }
  cout<<contami<<endl;//se non ci fidiamo
  float dati[contami];
  //trucco per riavvolgere il nastro
  leggimi.close();
  leggimi.open("gaus.dat");
  for(int i=0; i< contami; i++){
    leggimi>>dati[i];//riempiamo il vettore con i dati
    cout<<dati[i]<<endl;//perchè non ci fidiamo
  }
//.....da qui in poi abbiamo i dati e dobbiamo trovare il massimo e il minimo assoluti

   float massimo, minimo; //definisco le variabili
   massimo = dati[0];//le inizializzo a un valore dell'insieme contenuto nel vettore
   minimo = dati[0];
   for(int i=1; i<contami; i++){
     if(massimo<dati[i]){//se il massimo corrente è più piccolo dell'elemento della lista, lo sostituisco con l'elemento della lista
       massimo=dati[i];
     }
       if(minimo>dati[i]){//se il minimo corrente è più grande dell'elemento della lista, lo sostituisco con l'elemento della lista
         minimo=dati[i];
       }
   }

   cout<<"il massimo vale "<<massimo<<" il minimo vale "<<minimo<<endl;
  return 0;
}
