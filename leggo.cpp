#include <iostream>
#include <fstream>
//la libreria fstream include
//le classi ifstream e ofstream
using namespace std;
int main(){
    ifstream pippo; //pippo è una variabile (scopriremo un oggetto) di tipo ifstream
    pippo.open("dati.dat");

    int numerello;
    for(int i=0; i<8;i++){
    pippo>>numerello;
    cout<<"cosa ho letto = "<<numerello<<endl;
  }
  return 0;
}
