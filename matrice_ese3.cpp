//Caricare i primi 36 valori della prima colonna del file bgo.dat
//in una matrice 6x6, creare una seconda tabella con le stesse
//dimensioni della prima e caricare la seconda matrice con con
//I dati della prima ma con la regola che le colonne della prima
//siano le righe della seconda.

#include <iostream>
#include <fstream>
using namespace std;

int main(){
ifstream leggimi("bgo.dat");
if(!leggimi.is_open()){
  cout<<"non trovo il file\n";
  return 1 ;
}
//prenoto la matrice e la sua trasposta
float matr[6][6], trasp[6][6];
float babbu;
for(int i=0; i<6; i++){
  for(int j=0; j<6; j++){
    leggimi>>matr[i][j]>>babbu;
  }
}
for(int i=0; i<6; i++){
  for(int j=0; j<6; j++){
  trasp[j][i] =   matr[i][j] ;
  }
}

cout<<"Stampo la matrice originale\n\n";

for(int i=0; i<6; i++){
  for(int j=0; j<6; j++){
    cout<<matr[i][j]<<"  ";
  }
  cout<<endl;
}

cout<<"Stampo la matrice trasposta\n\n";

for(int i=0; i<6; i++){
  for(int j=0; j<6; j++){
    cout<<trasp[i][j]<<"  ";
  }
  cout<<endl;
}

return 0;
}
