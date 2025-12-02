#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(){
   string nome;
   cout<<"dimmi il nome del file che vuoi analizzare\n";
   cin>>nome;
   ifstream leggimi(nome);
   if(leggimi.is_open()){
     cout<<"ok"<<endl;
   }
   else{
     cout<<"non trovo il file"<<endl;
     return 1;
   }
   double a;
   vector<float> dati;
   while(leggimi>>a){
     dati.push_back(a);
   }
    cout<<"ho letto un numero di dati pari a "<<dati.size()<<endl;
    double somma=0;
    for(int i =0; i<int(dati.size()); i++){
      cout<<dati.at(i)<<"  "<<dati[i]<<endl;
      somma+= dati[i]; //somma = somma + dati[i];
    }
    double media = somma/ dati.size();
    cout<<media<<endl;
  return 0;
}
