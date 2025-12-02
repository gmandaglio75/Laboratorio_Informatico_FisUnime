//librerie
#include <iostream>
using namespace std;

int main(){
	int variabile;
	cout<<"vuoi sapere se è pari o dispari, dammi un numero\n";//\n è equivalente a <<endl;
	cin>>variabile;
  if(variabile%2==0){
		cout<<variabile<<" è un numero pari\n";
	}
	else{
		cout<<variabile<<" è un numero dispari\n";
	}
	return 0;
	}
