#include <iostream>
#include <cmath>
using namespace std;

int main(){
   float a, b, c;
   int spia=1;

   while(spia==1){
   cout<<"mi dai il primo coefficiente a"<<endl;
   cin>>a;
   cout<<"mi dai il secondo coefficiente b"<<endl;
   cin>>b;
   cout<<"mi dai il primo coefficiente c"<<endl;
   cin>>c;
   cout<<"ecco la equazione da risolvere "<<a<<"x^2+"<<b<<"x+"<<c<<"=0"<<endl;
  float delta = pow(b,2)-4*a*c;
   cout<<"il delta vale = "<<delta<<endl;

   if(delta<0){
    cout<<"l'equazione non ammette soluzioni reali \n"; //\n equivale a <<endl;

   }
   else{  //sono sicuro che è>=0
     if(delta>0){
       cout<<"la prima radice vale"<< (-b+sqrt(delta))/(2*a)<<endl;
         cout<<"la seconda radice vale"<< (-b-sqrt(delta))/(2*a)<<endl;     }
     else{
       cout<<"delta = 0, la radice vale = "<<-b/(2*a)<<endl;
     }
   }

    cout<<"carissim* vuoi risolvere un altra equazione? \n";
    cout<<" se si digita 1, altrimenti un numero qualsiasi";

     cin>>spia; //leggo il valore che controlla il while
 }
      cout<<"il programma è terminato, grazie e arivederci ;) "<<endl;

  return 0;
}
