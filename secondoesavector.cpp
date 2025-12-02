//2) Scrivere un programma che legge i dati dal file  dati20210124_2.dat 
//e carica quelli maggiori di 0 in un vector e quelli minori di 0 in un 
//altro vector. Stampare a schermo il numero di elementi caricati nel 
//primo vettore e quelli nel secondo.

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;


int main(){
ifstream leggo("dati20210124_2.dat");
if(!leggo.is_open()){
	cout<<"non apro il file\n";
	return 1;
       }
float a;
vector<double> nicola;
vector<double> lina;
while(leggo>>a){
	if(a>0){
		nicola.push_back(a);
	}
	else{
	//	cout<<a<<endl;
		lina.push_back(a);
	}
}

cout<<"maggiore di 0 sono " <<nicola.size()<<endl;
cout<<"minore di 0 sono "<<lina.size()<<endl;


return 0;
}
