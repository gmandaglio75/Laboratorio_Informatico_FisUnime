
//  Created by Alberto Altadonna on 21/10/21.
//


#include <iostream>
#include <fstream>

using namespace std;
int main () {
    ifstream leggo ("gaus.dat");
    if (!leggo.is_open ()){
        cout <<"non trovo il file"<<endl;
        }
    int contami = 0;
    double a;
    double minimo, massimo;
    leggo>>a;
    contami++; //incremento di una unità perchè ho fatto una lettura
    minimo=a;//inizializzo minimo e massimo ad un elemnto dell'insieme
    massimo=a;

    while (leggo>>a){
        if(minimo>a) minimo=a;
        if(massimo<a) massimo=a;
        contami = contami +1;
        //cout<<a<<endl;
    }
    double dati [contami];
    leggo.close();
    leggo.open("gaus.dat");
    for (int i=0; i<contami; i++){
        leggo>>dati [i];
        }
         leggo.close();

         int ndivisioni;
         int continua = 0 ;//per pilotare il do-while
         do{
             cout<<"dimmi quante divisioni vuoi per calcolare l'istogramma?\n"<<endl;
             cin>>ndivisioni;
         double delta = (massimo - minimo)/ndivisioni;

         double istogramma[ndivisioni];//contiene le frequenze assolute dell'istogramma
         for(int k=0; k<ndivisioni; k++){
        istogramma [k]=0;//inizializziamo a zero
    }
         for(int i=0; i<contami; i++){//cicla i dati
        for(int j=0; j<ndivisioni; j++){ //cicliamo sugli intervalli dell'isto
            if (dati [i]>=minimo+j*delta&&dati [i]<minimo+(j+1)*delta){
                istogramma [j]++;
            }
        }

    }
         istogramma[ndivisioni-1]++;//abbiamo messo la toppa
         for(int k=0; k<ndivisioni; k++){
        cout<<(minimo+delta/2.) + k*delta<<"  "<<istogramma[k]<<endl;
    }

        cout<<" se vuoi cambiare il binning digita 1 altrimenti 0"<<endl;
        cin>>continua;
    }while (continua ==1);
         cout<<"grazie per aver usato questo programma"<<endl;




    return 0;
}
