#include<iostream>
using namespace std;

int* demo(int *a) //return type- address of integer array
{
	// int a[4]; //array declared as static
	for(int i = 0; i<5; i++)
	{
		a[i] = i; //array initialisation
	}

	return a; //address of a returned
}

int main()
{
int pino[5];
	int* ptr; //pointer to hold address
	int i;
	ptr = demo(pino); //address of a
	cout<<"Array is: ";
	for(i=0 ; i<5; i++)
		cout<<ptr[i]<<"\t"; //ptr[i] is equivalent to *(ptr+i)
		
	return 0;
}

