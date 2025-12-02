#include <iostream>
#include <fstream> //libreria per accedere alle classi lettura scrittua da e su file

using namespace std;
int main(){
  ifstream leggimi("/home/gmandaglio75/MeD2223/dati/gaus.dat");
  if(leggimi.is_open()){
    cout<<"perfetto vai alla grande!"<<endl;
  }
  else{
    cout<<"non trovo il file"<<endl;
    return 1;
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
  leggimi.open("./dati/gaus.dat");
  for(int i=0; i< contami; i++){
    leggimi>>dati[i];//riempiamo il vettore con i dati
    cout<<dati[i]<<endl;//perchè non ci fidiamo
  }
//.....da qui in poi abbiamo i dati e li dobbiamo ordinare

    int spy=1;
    float bicchierevuoto;

    while(spy==1){
      spy=999;//disinnesco il ciclo infinto
      for(int i=0; i<contami-1; i++){
        if(dati[i]>dati[i+1]){
           bicchierevuoto = dati[i]; //questi tre comandi fanno lo scambio
           dati[i] = dati[i+1];
           dati[i+1] = bicchierevuoto;
           spy=1; //testimonio che almeno uno scambio è stato fatto e reinnesco il while
        }//if
      }//for
    }//while
    for(int i=0; i< contami; i++){
      cout<<dati[i]<<endl;//questi dovrebbero essere ordinati
    }

  return 0;
}
