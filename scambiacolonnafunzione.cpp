#include <iostream>
#include <fstream>
using namespace std;
void scambiami (float **pippo, int prima, int seconda){
        //effettuiamo lo scambio di due colonne
	float *bicchiere;
	bicchiere = pippo[prima];
	pippo[prima] = pippo[seconda];
	pippo[seconda] = bicchiere;
return;
}
int main(){
	ifstream leggo("daterellicutted.dat");
	if(!leggo.is_open()){
		cout<<"non trovo il file"<<endl;
		return 1;
	}
	//prima dobbiamo creare la tabella per farlo dobbiamo sapere quante righe ci sono
	float a;
	int contami=0;
	while(leggo>>a) contami++; //maleducatamente non metto le graffe...pace

	int righe = contami/3;
	float **tabella = new float*[3];
	for(int i =0; i<3; i++){
		//notiamo che la definizione di chi è riga chi colonna è convenzionale...
		tabella[i] = new float[righe]; //in questo modo il primo indice indica le colonne il secondo le righe
	}
        leggo.close();
	leggo.open("daterellicutted.dat");
	for(int i=0; i<righe; i++){
		for(int j=0; j<3;j++){
		leggo>>tabella[j][i]; //j colonna i riga
		}
	}
	for(int i=0; i<righe; i++){
                for(int j=0; j<3;j++){
                cout<<tabella[j][i]<<"  ";
                }
		cout<<endl;
        }
         scambiami(tabella,0,2); //passiamo alla funzione il puntatore doppio, e gli indici delle colonne che vogliamo scambiare
//ristampiamo per verificare che è vero
       cout<<"******************"<<endl;
	for(int i=0; i<righe; i++){
                for(int j=0; j<3;j++){
                cout<<tabella[j][i]<<"  ";
                }
                cout<<endl;
        }
return 0;
}
