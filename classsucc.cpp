#include <iostream>
#include <vector>
using namespace std;
class successami{
double start, stop, passo;

	public:

	successami(){
	return;
	}

        successami(double a, double b, double c){
		start =a;
		stop = b;
		passo =c;
		return ;
	}

vector<double> pippolo(){
     vector<double> ciccio;
     for(double i=start; i<stop; i = i + passo)
     ciccio.push_back(i);
     return ciccio;
}

};

int main(){
	successami pillo(0.,10,0.1);
        vector<double> pino = pillo.pippolo();
        cout<< pino.at(0)<<endl;   
        cout<< pino.size()<<endl;  
       for(int i=0; i <100; i++)cout<<pino.at(i)<<endl;	
	return 0;
}
