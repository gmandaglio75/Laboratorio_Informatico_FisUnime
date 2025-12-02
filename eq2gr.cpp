#include <iostream>
#include <cmath> //libreria necessaria per usare la funzione pow
using namespace std;
int main(){
  float a,b,c,delta;
  cout<<"risolvo equazioni di 2 gr ax^2+bx+c"<<endl;
  cout<<"dammi i tre valori consecutivamente separati da spazio e poi invio\n";
  cin>>a>>b>>c; //carico direttamente tutte e tre i valori
  delta=pow(b,2)-4*a*c; //calcolo il delta
  if(delta>=0){//discrimina tra maggiore uguale a zero e minore
    if(delta>0){//discrimina tra maggiore e uguale
      cout<<"la prima radice vale = "<<(-b-sqrt(delta))/(2*a)<<endl;
      cout<<"la seconda radice vale = "<<(-b+sqrt(delta))/(2*a)<<endl;
    }
    else//uguale a zero
    {
      cout<<"la prima radice vale = "<<-b/(2*a)<<endl;
    }
  }
  else//minore di zero
  {
    cout<<"l'equazione non ammette soluzioni reali\n";
  }
  return 0;
}
