#include <iostream>
#include <cstdlib>
#include <tuple>
using namespace std;

tuple<int*,int*,int> miFuncion(int* v, int* p, int* f, int size){
	int* nuevo1 = new int[size];
	int* nuevo2 = new int[size];
	int pos_int;
	for(int i=0;i<size;i++) { 
		if(v+i==p) { pos_int = i; }
	}
	for(int i=0;i<pos_int;i++) { 
		*(nuevo1+i) = *(v+i);
	}
	int aux = 0;
	for(int i=pos_int+1;i<size;i++) { 
		*(nuevo2+aux) = *(v+i);
		aux++;
	}
	return make_tuple(nuevo1,nuevo2,pos_int);
}

int main() {
	
	cout << "Ingrese array size" << endl;
	int n; cin >> n;
	
	int* v = new int[n];
	for(int i=0;i<n;i++) { 
		*(v+i) = rand()%16;
	}
	
	cout << "vector original:" << endl;
	for(int i=0;i<n;i++) { 
		cout << *(v+i) << " ";
	}
	cout << endl;
	
	cout << "Ingrese posicion intermedia" << endl;
	int pos; cin >> pos;
	
	int newsize, *n1, *n2; tie(n1,n2,newsize) = miFuncion(v,v+pos,v+n,n);
	cout << "Vectores nuevos:" << endl;
	for(int i=0;i<newsize;i++) { 
		cout << *(n1+i) << " ";
	}
	cout << endl;
	
	for(int i=0;i<n;i++) { 
		cout << *(n2+i) << " ";
	}
	cout << endl;
	
	return 0;
}

