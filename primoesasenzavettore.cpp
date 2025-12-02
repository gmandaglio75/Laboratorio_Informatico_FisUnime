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
double somma =0;
int contami =0;
while(leggo>>a){
contami++;
somma = somma + a;
}
double media = somma / contami;
//chiudo e riapro il file per riavvolgere il nastro.
leggo.close();
leggo.open("dati20210124_1.dat");

double scartoquadratico=0;
for(int i=0; i<contami; i++){
leggo>>a;
scartoquadratico = scartoquadratico + pow(media -a, 2); 

}

double devstand = sqrt(scartoquadratico/contami);

cout<<"ecco la media = " <<media <<endl;

cout<<"ecco la deviazione standard = "<<devstand<<endl;


return 0;
}
