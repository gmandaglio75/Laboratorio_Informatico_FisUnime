//Scrivere un programma capace di leggere i dati nel file dati20210124_1.dat 
//e di calcolare la deviazione standard del campione. 
//Stampare a schermo il risultato del calcolo.

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


int main(){
ifstream leggo("dati20210124_1.dat");

if(!leggo.is_open()){
	cout<<"non apro il file\n";
	return 1;
       }
float a;
int contami =0;
while(leggo>>a){
contami++;
}
//da qui in poi conosco quanti numeri contiene il file
float vettore[contami];
//chiudo e riapro il file per riavvolgere il nastro.
leggo.close();
leggo.open("dati20210124_1.dat");

//a questo punto mi carico i dati nel vettore
//utilizzo un for perchè conosco quando deve finire
for(int i=0; i<contami; i++){
leggo>>vettore[i];
}

double somma =0; //inizializzo all'elemento neutro della somma

for(int i=0; i<contami; i++){
somma = somma + vettore[i];
}

double media = somma / contami ;

double scartoquadratico = 0;

for(int i=0; i<contami; i++){
scartoquadratico+= pow(vettore[i]-media,2);//scartoquadratico = scartoquadratico +pow(vettore[i]-media,2);
}
double devstand = sqrt(scartoquadratico/contami);

cout<<"ecco la media = " <<media <<endl;

cout<<"ecco la deviazione standard = "<<devstand<<endl;


return 0;
}
