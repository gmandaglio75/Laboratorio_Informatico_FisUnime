#include <iostream>
#include <cmath>

using namespace std;


class caduta{
	private:
		const double g=9.806;
		double t,M;
	public:

		caduta(){
			return;
		}
		caduta(double infot, double infoM){
			t=infot;
                        M=infoM;
			return;
		}

		void dammitutto(double infot, double infoM){
			t=infot;
			M=infoM;
		        return;
		}
		void stampainfo(){

  			cout<<"t="<<t<<" M="<<M<<endl; 

			return;
		}
		void dammilat(double info){//metodo di input
			t=info;
			return;
		}
	void dammilaM(double info){//metodo di input
			M=info;
			return;
		}

               double eccolat(){
	        	return t;
	       }
               double eccolaM(){
	        	return M;
	       }

	       double volo(){
	                return g*pow(t,2)/2.;
	       }

	       double EnergiaCinetica(){
	       
	     		return M*g*volo();
	       
	       }


};



int main(){
	caduta gino;//gino è un oggetto della classe caduta

	caduta *nino= new caduta(12, 25.2);

	cout<<nino->EnergiaCinetica()<<endl;
        double dato;
        cout<<"dimmi il tempo di caduta\n";
	cin>>dato;
	gino.dammilat(dato);
	dato = dato +10;
	gino.dammilaM(dato);
	cout<<"ecco il valore passato alla classe "<<gino.eccolat()<<endl;
	cout<<"ecco il valore passato alla classe "<<gino.eccolaM()<<endl;

        gino.stampainfo();

	cout<<"ecco l'energia cinetica "<<gino.EnergiaCinetica()<<endl;

return 0;
}
