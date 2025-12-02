#include <iostream>
#include <cmath>
using namespace std;

double funz(double pino){
  return exp(pino) + log(pino);
  //return pino*pino;
}

double integrale(double pino){
  //return pino*pino*pino/3.;
  return exp(pino)+pino*log(pino)-pino;
}

int main(){

  double a=1;
  double b=5;
  cout<<"l'integrale analitico tra 5 e 1 vale  "<<integrale(b)-integrale(a)<<endl;
  //double ndivisioni = 5;
  for(double ndivisioni=1; ndivisioni<100; ndivisioni++){
  double delta = (b-a)/ndivisioni;
  double integralenumerico = 0;
  for(int i=0; i<ndivisioni;i++){
    integralenumerico = integralenumerico + funz( a+delta/2+i*delta) * delta;
  //  cout<<integralenumerico<<"  "<<a+delta/2+i*delta<<" "<<funz( a+delta/2+i*delta)<<"  "<<delta<<endl;
  }

  cout<<"l'integrale numerico tra 5 e 1 con "<< ndivisioni<<" vale  "<<integralenumerico<<endl;
}


  return 0;
}
