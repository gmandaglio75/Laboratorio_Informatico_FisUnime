#include <iostream>
#include <cmath>

using namespace std;

double gaus(double nino){
  return exp(-pow(nino,2));
}

double xseno(double nino){
  return nino*sin(nino);
}

double integrale(double lowedge, double highedge, double precisione, int tipofunzione){

        int ndivisioni=0;
	double somma =100000;
        double sommatemp;
	do{
		sommatemp=somma;
		ndivisioni++;

	double delta = (highedge-lowedge) /ndivisioni;
         somma =0;
	for (int i=0; i<ndivisioni; i++){
		if(tipofunzione==1){
       			 somma = somma + gaus(lowedge+delta/2.+i*delta) * delta;
		}
		if(tipofunzione==2){
                         somma = somma + xseno(lowedge+delta/2.+i*delta) * delta;
                }
     //cout<<gaus(a+delta/2.+i*delta) * delta<<endl;
      }


	}while(fabs(somma-sommatemp)>precisione);
    return somma;

}


int main(){
     double a, b,pasquale;
     int scelta;
     cout<<"Questo programma è capace di calcolare l'integrale numerico "<<endl;
     cout<<"della funzione gaussiana e della funzione x*sin(x) "<<endl;
     cout<<"Scegli la funzione da integrare: digita 1 per la gaussiana 2 per x*sin(x)"<<endl;
     cin>>scelta;
     
     cout<<"Dimmi gli estremi di integrazione"<<endl;
     cin>>a>>b;
     //per distratti
      if(b<a){
          double c;
	  c=a;
	  a=b;
	  b=c;
      }

      cout<<"dammi la precisione con cui vuoi il calcolo numerico"<<endl;
      cin>>pasquale;

      cout<<"il valore dell'integrale vale "<<integrale(a,b,pasquale, scelta)<<endl;


  return 0;

}
