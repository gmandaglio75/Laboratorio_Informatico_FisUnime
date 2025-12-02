#include <iostream>

using namespace std;

int main(){
	int a = 0; //inizializzo il contatore
	for(int pippo =0; pippo<10; pippo ++){
	a = a + pippo;
	cout<< " a = a  + "<< pippo<<" = " <<a <<endl;
	}
	cout<<"il ciclo è finito"<<endl;
	cout<<"il risultato vale "<<a<<endl;
return 0;
}
