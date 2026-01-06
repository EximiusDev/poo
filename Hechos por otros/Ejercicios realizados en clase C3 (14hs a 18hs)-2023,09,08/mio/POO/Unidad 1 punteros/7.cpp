#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct vector_int_dinamico {
	int *p;
	int size;
};

vector_int_dinamico redimensionar (vector_int_dinamico &x, int c){
	vector_int_dinamico aux;
	aux.size = x.size+c;
	aux.p = new int[x.size+c];
	for(int i=0;i<x.size;i++)
		*(aux.p+i)= *(x.p+i);
	for(int i=x.size;i<aux.size;i++) 
		*(aux.p+i)=0;
	delete []x.p;
	return aux;
}


	
int main(int argc, char *argv[]) {
	vector_int_dinamico arreglo;
	int N,ceros;
	cout<<"cant: ";
	cin>>N;
	arreglo.size=N;
	arreglo.p=new int[N];
	srand(time(0));
	for(int i=0;i<arreglo.size;i++) { 
		*(arreglo.p+i)=rand()%90+10;     
		cout<<" "<<*(arreglo.p+i);	
	}
	cout<<"\nCantidad de elementos: "<<arreglo.size<<endl;
	cout<<"ingrese la cantidad de ceros: ";
	cin>>ceros;
	arreglo= redimensionar(arreglo,ceros);
	cout<<"\narreglo final:\n";
	for (int *i=arreglo.p; i != arreglo.p + arreglo.size; i++)
		cout<<" "<<*i;
	cout<<"\nCantidad de elementos: "<<arreglo.size<<endl;
	delete []arreglo.p;
	return 0;
}

