#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a = 0; //inizializzo il contatore
	for(float pippo =0; pippo<10; pippo= pippo +0.01){
		a++;
		cout<<a<<"   "<< pippo<<"   "<<sin(pippo)<<endl;
	}
return 0;
}
