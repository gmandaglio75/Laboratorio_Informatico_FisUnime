#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
   ifstream leggo("/home/gmandaglio75/MeD2122/dati1.dat");
   //ifstream leggo;
   //leggo.open("dati1.dat");
    if(leggo.is_open()){
      cout<<"il file è stato aperto correttamente"<<endl;
    }
   else{
     cout<<"mi dispiace non trovo il file"<<endl;
     return 1;
   }
    cout<<"stampiamo a schermo il valore restituito dalla funzione is_open  "<<leggo.is_open()<<endl;
      double a;
      int i =0;
      double somma=0;

      while(leggo>>a){
        cout<<a<<endl;
        i++;//conto le letture
        somma = somma +a;//sommo tutte le letture
      }

      cout<<"il valore medio dei dati letti vale   "<<somma / i <<endl;
      leggo.close();
      leggo.open("/home/gmandaglio75/MeD2122/dati1.dat");
       double media = somma / i;

       double scarti2=0;
      while(leggo>>a){
        scarti2 = scarti2 +pow(a-media,2);//sommo tutte le letture
      }
        cout<<"la deviazione standard vale  "<<sqrt(scarti2/i)<<endl;
  return 0;
}
