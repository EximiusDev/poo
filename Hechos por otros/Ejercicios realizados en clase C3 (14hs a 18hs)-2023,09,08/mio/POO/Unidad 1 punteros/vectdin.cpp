#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct vector_int_dinamico {
	int *p;
	int size;
};


void insertar(int *x,int can,int po, int va){
	for(int i=can;i>po;i--) {
		*(x+i)=*(x+i-1);  //  x[i]=x[i-1]
	}
	*(x+po)=va;
}
	
vector_int_dinamico redimensionar (vector_int_dinamico &x, int c){
	vector_int_dinamico aux;
	aux.size=x.size+c;
	aux.p=new int[aux.size];
	for(int i=0;i<x.size;i++) { 
		*(aux.p+i)=*(x.p+i);
	}
	for(int i=x.size;i<aux.size;i++) { 
		*(aux.p+i)=0;
	}
	delete []x.p;
	return aux;
}
	

int main() {
	vector_int_dinamico arreglo;
	int N,ceros;
	cout<<"cant: ";
	cin>>N;
	
	arreglo.size=N;
	arreglo.p=new int [arreglo.size];
	
	srand(time(0));
	for(int i=0;i<arreglo.size;i++) { 
		*(arreglo.p+i)=rand()%100+10;     
		cout<<" "<<*(arreglo.p+i);	
	}
	cout<<"\ncantidad de elementos:"<<arreglo.size<<endl;
	
	cout<<"\ningrese cantidad de ceros: ";
	cin>>ceros;
	arreglo=redimensionar(arreglo,ceros);
	
	cout<<"\narreglo final:\n";
	for(int *i=arreglo.p;i<arreglo.p+arreglo.size;i++) { 
		cout<<" "<<*i;	
	}
	cout<<"\ncantidad de elementos:"<<arreglo.size;
	delete []arreglo.p; 
	return 0;
}

