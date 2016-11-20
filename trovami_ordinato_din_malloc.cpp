#include <iostream>
#include <fstream>
#include <cmath>
//per usare malloc
#include <stdlib.h>
using namespace std; 

int main (){
float trovami;	
ifstream leggimi("trovami.dat");
int numerodiletture=0;//quanto è lunga la colonna
while(!leggimi.eof()){//gli dico di leggermi il file (trovami)
	leggimi>>trovami;
	if(!leggimi.eof()){
		numerodiletture++;
	}
}			
leggimi.close();//lo chiudiamo

leggimi.open("trovami.dat");

//ha bisogno della libreria stdlib.h compatibile con C
double** tabellina=  (double**)malloc((numerodiletture/3)*sizeof(double*));
for(int i = 0; i < numerodiletture/3; ++i)
    tabellina[i] = (double*)malloc(3*sizeof(double));
 



for(int i=0; i<numerodiletture/3; i++){//numerodiletture=righe
  for(int j=0; j<3; j++){ //3 colonne
    leggimi>>tabellina[i][j];
    //cout<<tabellina[i][j]<<"  "; //modifico per rendere la stampa oridinata
  }
//cout<<endl;
}
leggimi.close();


double min=10000000; //DEVE ESSERE UN REALE 
int indicedelminimo =0;

double *bicchierevuoto;

    for(int partenza=0; partenza<(numerodiletture/3-1); partenza++){
    min=10000000;  //è importantissimo mettere questa condizione
  for(int i=partenza; i<numerodiletture/3; i++){ 
  if(min>tabellina[i][0]){min=tabellina[i][0]; indicedelminimo=i;}
}

bicchierevuoto= tabellina[indicedelminimo];
tabellina[indicedelminimo]=tabellina[partenza];
tabellina[partenza]=bicchierevuoto;

cout<<tabellina[partenza][0]<<"  "<<tabellina[partenza][1]<<"  "<<tabellina[partenza][2]<<endl;
}

return 0;
}
