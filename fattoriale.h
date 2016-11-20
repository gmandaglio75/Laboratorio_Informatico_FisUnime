#include <iostream>
using namespace std;
double fatt (double n)
{
if (n<0){cout<<"Operazione non valida"<<endl; return -100;}
if (n==0) return 1;
return (n<2)?1:n*fatt(n-1);
}
