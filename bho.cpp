#include <iostream>
using namespace std;

int main(){
  int N;
   cout<<"dammi un numero intero"<<endl;
   cin>>N;
   int peppe=1;
   for(int i=0; i<N; i++){
    peppe = peppe*(N-i);
   }
   cout<<peppe<<endl;
  return 0;
}
