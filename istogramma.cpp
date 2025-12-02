//librerie
#include <iostream>
#include <cmath>
#include <fstream>
int b=1;
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


//leggo un file e carico un vettore
//trovo il massimo e il minimo assoluti
//decidere il numero di bin e prenotiamo un istogramma =0
//creo l'algoritmo o la regola che conta i numeri che cadono nell'intervallino
int n;
while(b==1){
cout<<"in quante parti vuoi dividere l'istogramma?"<<endl;
cin>> n;
int histo[n];
for(int j=0; j<n;j++){// azzera i contatori...fondamentale!!!!!!!!!!!
	histo[j]=0;
	}
float delta=((massimo-minimo)/n);//ampiezza intervallini reali ....fondamentale
for(int i=0; i<contami; i++){//ciclo sugli elementi dei dati
	for(int j=0; j<n;j++){//ciclo sugli intervallini
		if (dati[i]>= minimo+ j*delta && dati[i]<minimo+ (j+1)*delta){
	histo[j]++;
	j=n;//appena lo trovo, frego il ciclo for
	}// chiude if
	}// chiude for
	}// chiude for

histo[n-1]++;//per includere il massimo assoluto
for (int j=0; j<n;j++){
cout<<histo[j]<<endl;
}
ofstream scrivimi("histo.dat");
for(int j=0; j<n; j++){
   scrivimi<<minimo+delta/2 + j*delta<<"  "<<histo[j]<<endl;
	//scrivimi<<minimo+delta/2 + j*delta<<"  "<<histo[j]<<"  "<<delta/2<<"  "<<sqrt(histo[j])<<endl;
}

scrivimi.close();

cout<<"Vuoi continuare?  1)SI 2)NO \n";
cin>>b;
}




return 0;
}
