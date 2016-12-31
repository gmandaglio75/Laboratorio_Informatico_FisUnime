void istogrammami()
{
int i=0;
double a;
int num_dati=0;  				//contatore dei valori all'interno del file
float media;				//media dei numeri
double somma=0; 			//somma dei numeri
double somm=0;				//sommatoria (per lo scarto quadratico medio)			
double sqm; 				//scarto quadratico medio

char nome[20];

cout<<"Mi dici il nome del file che vuoi analizzare?"<<endl;
cin>>nome;  //stringa di caratteri per chiedere il nome (come Antonino)


//calcola la somma e la media

ifstream leggimi(nome);           //legge dal file dati.dat
while(!leggimi.eof()){  
leggimi>>a;				//attribuisce i valori del file alla variabile a, finchè non siamo arrivati alla fine del file
somma=somma+a;
if(!leggimi.eof()){			
//cout<<a<<endl;				//stampa i valori del file
num_dati++;
}
}
media = somma /num_dati;				//calcola la media
cout<<endl;
cout<<"Hai stampato "<<num_dati<<" numeri."<<endl;
cout<<"La somma dei numeri stampati e' "<<somma<<".\n";
cout<<"La media dei numeri stampati e' "<<media<<" \n";
//leggimi.close();			//chiude il file

//calcola lo scarto quadratico medio

//leggimi.open("dati.dat");		//riapre il file (serve a mettere il "cursore" dell'ifstream all'inizio del file)

// Trucchetto alternativo al chiudi - apri ;)
leggimi.clear(); //resetta le etichette di errore, è necessaria prima di una operazione di rewind
leggimi.seekg(0); //rimettiamo il riferimento del sistema di lettura al primo elemento
float *misure = new float[num_dati];
//float misure[num_dati];
for(i=0; i<num_dati; i++){			//crea un vettore contenente tutti i valori
leggimi>>misure[i];
somm=somm+pow((misure[i]-media),2);
}
sqm=pow((somm/num_dati), 0.5);			//calcolo scarto quadratico medio
cout<<"Lo scarto quadratico medio e' "<<sqm<<".\n";

//restituisce il valore massimo e il valore minimo

float maxi, mini;				//calcolo del massimo e minimo tramite un confronto tra gli elementi dei vettori max e min
maxi=misure[0];
mini=misure[0];
for(i=0; i<num_dati; i++){			
if(misure[i]>maxi)
maxi=misure[i];
else if(misure[i]<mini)
mini=misure[i];
}

cout<<"Il valore minimo e': "<<mini<<endl;
cout<<"Il valore massimo e': "<<maxi<<endl;

//creare istogramma
int r;
do{							//per ripetere il ciclo, se si vuole
int nint;						//nint=numero intervalli
cout<<"\nInserisci il numero di intervalli in cui dividere i valori al fine di creare un istogramma: \n";
cin>>nint;
float l=(maxi-mini)/(float)nint;				//lunghezza intervalli		
cout<<"Misura intervalli: "<<l<<endl;
int bin[nint];						//crea un vettore grande quanti sono gli intervalli
for(i=0;i<nint;i++)	   
bin[i]=0;                                               //pone=0 i valori di ogni intervallo

for(i=0;i<nint;i++)
for(int v=0; v<num_dati; v++) 
if((misure[v]>=mini+i*l)&&(misure[v]<=mini+(i+1)*l))      //per ogni intervallo conta quali valori cadono entro l'intervallo stesso
bin[i]++;                                     	        //incrementa il numero di valori per l'intervallo preso in considerazione
//cout << scientific;
cout << fixed; //risolve il problema dell'allineamento
cout<<"\nIstogramma:"<<endl;
for(int n=0; n<nint; n++)                               //stampa i valori trovati; anche "ad occhio" si può vedere la formazione di un 		
cout<<mini+l/2+n*l<<"\t"<<bin[n]<<endl;                //stampa istogramma e valori medi di ogni intervallino

cout<<"\nCalcolare l'istogramma con un numero diverso di intervalli? (Se si, premere 1):\n";
cin>>r;
}while(r==1);

//nota: nell'if ho usato il <= e il >=, altrimenti non venivano considerati il valore massimo e il valore minimo, dunque nell'istogramma mancavano due dati.

}










