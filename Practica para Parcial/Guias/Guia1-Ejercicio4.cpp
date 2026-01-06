#include <iostream>
using namespace std;

struct vector_int_dinamico {
	int *p;
	int size;
};

void redimensionar(vector_int_dinamico & arreglo, int c){
	int * aux = new int [c];
	int n = arreglo.size;
	
	for(int i=0;i<n;i++) { 
		if(i<c){
			*(aux + i) = *(arreglo.p + i);
		}
	}
	delete []arreglo.p;
	if(n<c){
		for(int i=n;i<c;i++) { 
			*(aux + i) = 0;
		}	
	}
	arreglo.p = aux;
	
}

int main() {
	vector_int_dinamico arreglo;
	arreglo.size = 5;
	int n =arreglo.size;
	
	
	arreglo.p = new int [n];
	for(int i=0;i<n;i++) { 
		*(arreglo.p + i) = rand()%10 + 1;
		cout<<i<<". "<<(arreglo.p + i)<<": "<<*(arreglo.p + i)<<endl;
	}
	cout<<endl;
	
	int c=8;
	
	redimensionar(arreglo, c);
	
	for(int i=0;i<c;i++) { 
		cout<<i<<". "<<(arreglo.p + i)<<": "<<*(arreglo.p + i)<<endl;
	}
	
	
	return 0;
}

