#include <iostream>
#include <fstream>
#include "fun.h"

using namespace std;

int main(){
    ifstream leggo("gaus.dat");
    if(!leggo.is_open()){//operatore logico negazione : !
      cout<<"non trovo il file"<<endl;
      return 1;
    }
    double a;
    int dim=0;
    while(leggo>>a) dim++; //contieamo gli elementi di gaus.dat

    double enrico[dim]; //creiamo un vettore di dimensione dim di nome enrico
    leggo.clear(); //resetta le etichette di errore, è necessaria prima di una operazione di rewind
    leggo.seekg(0); //rimettiamo il riferimento del sistema di lettura al primo elemento
    int i =0;
    while(leggo>>enrico[i])i++;
    //for(int i=0; i<dim; i++){
    //  cout<<enrico[i]<<endl;
    //}
    int spia=12;
    while(spia==12){ //ciclo infinito
      spia=33; //disinnesco il ciclo
      for(int i=0; i<dim-1; i++){
        if(enrico[i]>enrico[i+1]){
          scambio(&enrico[i],&enrico[i+1]);
          spia=12; //reinnesco il ciclo
        }
      }
    }


    for(int i=0; i<100; i++){
      cout<<enrico[i]<<endl;
    }
  return 0;
}
