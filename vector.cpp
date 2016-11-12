// G. Mandaglio oct 17 2016
// simple program twin with a fortran version

// string::operator+=
#include <iostream>
#include <stdio.h>

using namespace std;
int main ()
{
  int indice;
  cout<<"dammi un numero"<<endl;
  cin>>indice;

   int vector[indice];

   for(int i=0;i<indice;i++) vector[i]=i;
   for(int i=0;i<indice;i++) cout<<vector[i]<<endl;

  return 0;
}
