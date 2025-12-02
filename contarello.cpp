#include <iostream>
#include <fstream>//mi consente di usare le classi ifstream ofstream
using namespace std;

int main(){

	int contami =0; //il nostro contatore
	float poveraccio; //variabile ch esi immola alla lettura
	ifstream leggimi("gaus.dat");
	if(leggimi.is_open()){
		cout<<"OK ho il file"<<endl;
	}
	else{
		cout<<"non trovo nulla"<<endl;
		return 1;
	}
	while(leggimi>>poveraccio){
		cout<<poveraccio<<endl;
		contami++;
	}
	cout<<"il file contiene "<<contami<<" valori"<<endl;
        float dati[contami]; //il contenitore delle dimensioni giuste per caricare tutti i dati

	leggimi.close(); //chiudo la connessione con il file
	leggimi.open("gaus.dat"); //riapro lo stesso file //è un trucco per riavvolgere il nastro

	for(int i=0; i<contami; i++){
		leggimi>>dati[i];
		cout<<dati[i]<<endl;
	
	}


return 0;
}
