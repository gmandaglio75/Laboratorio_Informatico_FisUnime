//Cricare i primi trentasei valori contenuti nel file dati20210124_1.dat
// in una matrice 6x6, stampare a schermo i dati che vivono sulle diagonali della matrice.

#include <fstream>
#include <iostream>

using namespace std;

int main(){
  ifstream leggimi("dati20210124_1.dat");

  if(!leggimi.is_open()){
     cout<<"prprprprprprprprpr!!!!!!!!!!!!!!"<<endl;
      return 1;
     }

     float matrice[6][6]; // 6 x 6

     for(int i=0; i<6; i++){
       for(int j =0; j<6; j++){
         leggimi>>matrice[i][j];
       }
     }

     //okey una cosa alla volta
     //prima mi stampo gli elementi della prima diagonale
      cout << "prima diagonale\n";
     for(int i=0; i<6; i++){
       cout<<matrice[i][i]<<endl;
     }
    //seconda diagonale
    //metodo bovino
    cout << "seconda diagonale bovina\n";
     for(int i=0; i<6; i++){
       for(int j =0; j<6; j++){
         if(i+j==6-1){
                cout<<matrice[j][i]<<endl;
         }

       }
     }
     //metodo volpino
     cout << "seconda diagonale volpina\n";
     for(int i=0; i<6; i++){
         cout<<matrice[5-i][i]<<endl;
     }


     for(int i=0; i<6; i++){
       for(int j =0; j<6; j++){
         if(i+j==6-1 || i==j){
                cout<<matrice[j][i]<<"  ";
         }
         else{
           cout<<"0   ";
         }

       }
       cout<<endl;
     }

  return 0;
}
