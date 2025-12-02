//librerie
#include <iostream>
using namespace std;

int main(){
	int decidi = 0; //int vuol dire che decidi può contenere un intero, = 0 inizializza la variabile a zero
	float giacomo, enrico;
	//risultato= giacomo + enrico;//N00000ooooooooooooooooooooooooooooooooooooo
	cout<<"sono un programma che sa fare le operazioni fondamentali\n";//\n è equivalente a <<endl;
  cout<<"quale operazione vuoi fare? digita 1 per +, 2 per -, 3 per *, 4 per / \n";
	cin>>decidi;//da questo momento in poi la decisone è presa
    if(decidi<1 ||decidi>4){
			cout<<"non ho capito, ciao"<<endl;
			return 1;
		}


	cout<<"dammi il primo valore"<<endl;
	cin>>giacomo;
    cout<<"dammi il secondo valore\n";
    cin>>enrico;
    if(decidi==1){
    	cout<<"ecco quanto vale somma = "<<giacomo + enrico<<endl;
		}
		if(decidi==2){
    	cout<<"ecco quanto vale differenza = "<<giacomo - enrico<<endl;
		}
		if(decidi==3){
    	cout<<"ecco quanto vale il prodotto = "<<giacomo * enrico<<endl;
		}
		if(decidi==4){
			 if(enrico != 0){
    	cout<<"ecco quanto vale la divisione = "<<giacomo / enrico<<endl;
		}
		else{
				cout<<"il denominatore è zero, quindi nessuno numero diverso da infinito, cioa"<<endl;

		}

		}

	return 0;
	}
