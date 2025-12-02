//Scrivere una classe capace di accumalare dati reali in una variabile
// privata di tipo vector, e che sia dotata dei metodi capaci di
//calcolare la media, la deviazione standard, di restituire
//il numero di dati caricati, il massimo valore caricato,
//il minimo valore caricato

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class staty{
vector<double> dati;
public:
staty(){ //costruttore
  return;
}
//metodo per caricare i dati
void getdata(double a){
   dati.push_back(a);
  return;
}
//metodo per calcolare la media...e restituirla
double media(){
   double a =0;
   for(int i=0; i<dati.size();i++){
     a+= dati[i];
   }
   return a/dati.size();
}

double devstd(){
  double a =0;
  double average = media(); //uso un metodo interno alla classe
  for(int i=0; i<dati.size();i++){
    a+= pow(dati[i]-average,2);
  }
  return sqrt(a/dati.size());
}
double massimo(){
  double a =dati[0];
  for(int i=1; i<dati.size();i++){
    if(a<dati[i]){
      a=dati[i];
    }
  }
  return a;
}

double minimo();
};
//esempio di implementazione di un metodo esternamente
double staty::minimo(){
  double a =dati[0];
  for(int i=1; i<dati.size();i++){
    if(a>dati[i]){
      a=dati[i];
    }
  }
  return a;
}


int main(){
       staty gino; //gino è un oggetto della classe staty
       gino.getdata(2);
       gino.getdata(4);
       gino.getdata(5);
       gino.getdata(6);
       cout<<gino.media()<<endl;
       cout<<gino.devstd()<<endl;
       cout<<gino.massimo()<<endl;
       cout<<gino.minimo()<<endl;
       //un modo diverso per creare un oggetto
       staty *puntarello = new staty(); //uso il costruttore
       puntarello->getdata(10);
       cout<<puntarello->minimo()<<endl;
return 0;
}
