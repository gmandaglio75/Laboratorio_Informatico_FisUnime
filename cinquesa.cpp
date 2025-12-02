//Caricare i primi centro valori contenuti nel file  dati20210124_2.dat  in un vettore,
//e i successivi 100 in un secondo vettore. Implementare il prodotto scalare dei due
//vettori : consiste nella somma del prodotto ordinato delle componenti x[i]*y[i].

#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream leggo("dati20210124_2.dat");
  if(!leggo.is_open()){
    cout<<"il file non lo trovo....opputi"<<endl;
  }
  float primo[100];
  for(int i=0; i<100;i++){
    leggo>>primo[i];
  }

  float secondo[100];
  for(int i=0; i<100;i++){
    leggo>>secondo[i];
  }
   float prodottoscalare =0;
   for(int i=0; i<100; i++){
     prodottoscalare = prodottoscalare + primo[i]*secondo[i];
   }
cout<<"il prodotto scalare è uguale a "<<prodottoscalare<<endl;


  return 0;
}
