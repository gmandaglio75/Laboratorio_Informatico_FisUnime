#include <iostream>
#include <cmath>
using namespace std;

class vettore{
   double x,y,z;

 public:

    vettore(){
      cout<<"ciao sono un costruttore ;=)"<<endl;
     return;
   }

   vettore(double a, double b){
     cout<<a+b<<endl;
    return;
  }

   vettore(double a, double b, double c){
     x=a;
     y=b;
     z=c;
     return;
   }



   void SetCoord(double a, double b, double c){
     x=a;
     y=b;
     z=c;
     return;
   }
  void SetX(double a){
    x=a;
    return;
  }
  void SetY(double a){
    y=a;
    return;
  }

  void SetZ(double a){
    z=a;
    return;
  }

   double GetModule(){
     return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
   }
double GetPhi(){
  return atan2(y,x)/M_PI*180;
}

};

int main() {
//classe   oggetto
  vettore gino(3,4,6); //è perfettamente equivalente ifstream leggimi("ciao.dat");
  cout<<gino.GetModule()<<endl;
  vettore piscopallo(3.2,2.3);
  vettore nino;

  return 0;
}
