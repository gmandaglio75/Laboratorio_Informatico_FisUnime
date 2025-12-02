#include <iostream>
#include <fstream>

using namespace std;

int main(){
        int i, pino;
	ifstream leggimi("gaus.dat");

	double matrice1[5][6], matrice2[5][6], matricesomma[5][6];

	for(i=0; i<5; i++){
		for(pino =0; pino<6; pino++){
			leggimi>>matrice1[i][pino];
	        cout<<matrice1[i][pino]<<"  ";
		}
		cout<<endl;
	}

	cout<<endl<<endl;
	for(i=0; i<5; i++){
		for(pino =0; pino<6; pino++){
			leggimi>>matrice2[i][pino];
	        cout<<matrice2[i][pino]<<"  ";
		}
		cout<<endl;
	}

	for(i=0; i<5; i++){
		for(pino =0; pino<6; pino++){
			matricesomma[i][pino] = matrice1[i][pino] + matrice2[i][pino];
		}
	}
return 0;
}
