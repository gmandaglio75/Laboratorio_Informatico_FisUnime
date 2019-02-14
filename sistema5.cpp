//Implementazione di un codice capace di risolvere un sistema lineare
//in tre incognite con il metodo della tringolarizzazione di Gauss

#include <iostream>
#include <fstream>

using namespace std;

int main(){
/* struttura degli indici dei termini noti del sistema
   (0,0)x + (0,1)y + (0,2)z = (0,3)
   (1,0)x + (1,1)y + (1,2)z = (1,3)
   (2,0)x + (2,1)y + (2,2)z = (2,3)

Lo scopo è azzerare i coifficienti (1,0), (2,0), e (2,1)
è faciele vedere come questi formino un triangolo sotto la 
diagonale della tabella dei coefficienti delle incognite.
L'azzeramento avviene attraverso operazioni lineari tra
le righe della tabella
*/

// Contenitore dei coefficienti
  int numrighe = 4;
//  int numcol   =5; 
  double coef[numrighe][numrighe+1]; //coefficienti 3 righe 4 colonne

  ifstream pippo("dati.dat"); //file che contiene i coefficienti del sistema
  cout<<"i coefficienti di un sistema 4 incognite sono"<<endl;
//lettura dei coefficienti del sistema!! 
  for(int i =0; i<numrighe; i++){
    for(int j=0; j<numrighe+1;j++){
      pippo>>coef[i][j];
    }
  }
//***************************!!

//stampa dei coefficienti del sistema!! 
  for(int i =0; i<numrighe; i++){
    for(int j=0; j<numrighe+1;j++){
      cout<<coef[i][j]<<"  ";
    }
    cout<<endl;
  }
  cout<<endl;
  cout<<endl;
//***************************!!

//variabili di servizio per il processo di triangolarizzazione!!
  double denom, numen,secchio;
  int xx=1;//serve per trovare la riga con cui fare lo scambio
//***************************!!


  for(int k =0; k<numrighe-1;k++){ //ciclo sulle colone da azzerare
    
    numen=coef[k][k];
// se questo coefficiente è uguale a zero non ci consente di effettuare la triangolarizzazione
// quindi si procede a cercare una riga il cui primo elemento sia diverso da zero in modo
// da fare un semplice s
    if(numen==0){
//questo ciclo while cerca la prima riga utile per fare lo scambio
      while(coef[k+xx][k]==0){
	xx++;
      }
//il ciclo for effettua l'operazione di scambio delle righe
      for(int m =0; m<numrighe+1;m++){
	secchio = coef[k][m];
	coef[k][m]=coef[k+xx][m];
	coef[k+xx][m]=secchio;
      }
//si aggiorna il valore della variabile numen per gli usi successivi
      numen=coef[k][k];
//si reinizializza xx a 1 nel caso ci sia bisogno nuovamente di questa procedura di controllo
      xx=1; 
    }

    for(int i =k+1; i<numrighe; i++){
   // le colonne
      denom=coef[i][k];
      //condizione che protegge dagli zeri sul triangolo, se zero non faccio nulla e passo al prossimo
      if(denom!=0){ 
	for(int j=k; j<numrighe+1; j++){
	  coef[i][j] =  coef[k][j]- (coef[i][j]/denom)*numen;
	}//ciclo su j
      }//if proteggi sono già zero
    }//ciclo su i
  }//ciclo su k

  //stampo il risultato finale
  for(int i =0; i<numrighe; i++){
    for(int j=0; j<numrighe+1;j++){
      cout<<coef[i][j]<<"  ";
    }
    cout<<endl;
    
  }
  
double sol[numrighe];

for(int i=numrighe-1; i>-1;i--){
sol[i]=coef[i][numrighe];

for(int j=i;j<numrighe-1;j++){
sol[i]-= sol[j+1]*coef[i][j+1];
}

sol[i]= sol[i]/coef[i][i];

}

for(int i =0; i<numrighe;i++){
cout<<"soluzione "<<i+1<<" = "<<sol[i]<<endl;
}


  return 0;
}

