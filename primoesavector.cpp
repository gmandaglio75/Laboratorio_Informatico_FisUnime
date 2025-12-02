//Scrivere un programma capace di leggere i dati nel file dati20210124_1.dat 
//e di calcolare la deviazione standard del campione. 
//Stampare a schermo il risultato del calcolo.

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;


int main(){
ifstream leggo("dati20210124_1.dat");
if(!leggo.is_open()){
	cout<<"non apro il file\n";
	return 1;
       }
float a;
vector<double> ciccio;
while(leggo>>a){
ciccio.push_back (a); //la classe vector consente di construire il vettore dinaminacamente
// man mano che carico i dati con il metodo push_back il vettore cresce esattamente come
// il giochino del vermetto
}
double media = 0;
for(int i=0; i< ciccio.size();i++){
media+=ciccio[i]/ciccio.size();
}
double devstand =0;
for(int i=0; i< ciccio.size();i++){
devstand+=pow(ciccio[i]-media,2)/ciccio.size();
}
devstand = sqrt(devstand);

cout<<"ecco la media = " <<media <<endl;

cout<<"ecco la deviazione standard = "<<devstand<<endl;


return 0;
}
