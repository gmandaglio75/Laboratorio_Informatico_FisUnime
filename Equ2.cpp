#include <iostream>
#include <cmath>
using namespace std;
class Equ2{
   float a,b,c; //per default tutto è privato

 public: //da qui in poi pubblico fino a prova contraria

   Equ2(){ //Costruttore che non fa nulla a patto di scrivere
     cout<<"ciao ti ho appena creato un oggetto della classe Equ2\n";
     return;
   }
   Equ2(float x,float y, float z){ //costruttore che carica i dati
      a=x;
      b=y;
      c=z;
     return;
   }
   Equ2(string nome){ //costruttore che carica i dati
    cout<<"ciao "<<nome<< " dammi i coefficienti che ti risolvo un'equazione di secondo grado\n";
     return;
   }
   void Coefficienti(float x,float y, float z){ //metodi di input
      a=x;
      b=y;
      c=z;
     return;
   }
   void A(float x){//metodo di input per modificare un dato interno alla classe
      a=x;
     return;
   }
  void B(float x){//metodo di input per modificare un dato interno alla classe
      b=x;
     return;
   }
   void C(float x){//metodo di input per modificare un dato interno alla classe
      c=x;
     return;
   }
   float Delta(); //DICHIARO IL METODO MA LO IMPLEMENTO SOTTO ESTERNAMENTE
/*   float Delta(){
     return b*b-4*a*c;
   }
   */
   void Soluzioni(){//Se lo invochi ti dice cosa ti devi aspettare per le soluzioni
     if(Delta()>0){
       cout<<"ci sono due soluzioni reali"<<endl;
     }
     else{
       if(Delta()==0){
         cout<<"Una soluzione"<<endl;
       }
       else{
         cout<<"Non ci sonosoluzioni reali"<<endl;
       }
     }
   }
   float Sol1(){ //fornisce una soluzione
       if(Delta() <0){
         cout<< "nessuna soluzione reale"<<endl;
         return 666;
       }
       return (-b+sqrt(Delta()))/(2*a);

   }

   float Sol2(){//fornisce la seconda soluzione
       if(Delta() <0){
         cout<< "nessuna soluzione reale"<<endl;
         return 666;
       }
       return (-b-sqrt(Delta()))/(2*a);

   }

   float* dueSol(){ //Restituisce contemporaneamete tutte due le soluzioni
     static float soluzioni[2];
     if(Delta() <0){
       cout<< "nessuna soluzione reale"<<endl;
       return NULL;//se non ci sono soluzioni restituisco il puntatore nullo
     }
     if(Delta()==0){
       cout<< "due soluzioni reali coincidenti!"<<endl;
     }

     soluzioni[0] = (-b+sqrt(Delta()))/(2*a);
     soluzioni[1] = (-b-sqrt(Delta()))/(2*a);
     return soluzioni;
   }

    ~Equ2(){ //DIstruttore...normalmente non si mette nulla dentro
      cout<<"sono morto! ciao ci vedimo..."<<endl;
      return;
    }
};
//esempio di implementazione esterna di un metodo della classe Equ2
float Equ2::Delta(){
   return b*b-4*a*c;
 }



int main(){
//La classe e le sue regole sono state implementate ora le usiamo
  Equ2 test(1,4,4); //esempio che usa la dichiarazione tipo variabile e il costruttore che carica i dati
  test.Soluzioni();
  test.A(12);
  test.Soluzioni();
  test.A(1);
  test.B(5);
  float *contenitoresoluzioni;
  contenitoresoluzioni = test.dueSol();
  if(contenitoresoluzioni!=NULL){
  cout<<"soluzione 1 = "<<contenitoresoluzioni[0]<<"  soluzione 2 = "<<contenitoresoluzioni[1]<<endl;
}
//  test.~Equ2(); //il distruttore viene chiamato sempre e comunque fando il codice termina prova a girare il codice commentanto e scommentando questa riga
  Equ2 *puntarello = new Equ2("Giuseppe");
  float p,s,t;
  cout<<"dammi di seguito i coifficienti dell'equazione ax^2+bx+c"<<endl;
  cin>>p>>s>>t;
  puntarello->Coefficienti(p,s,t);
  contenitoresoluzioni = puntarello->dueSol();
  if(contenitoresoluzioni!=NULL){
  cout<<"soluzione 1 = "<<contenitoresoluzioni[0]<<"  soluzione 2 = "<<contenitoresoluzioni[1]<<endl;
  }
  return 0;
}
