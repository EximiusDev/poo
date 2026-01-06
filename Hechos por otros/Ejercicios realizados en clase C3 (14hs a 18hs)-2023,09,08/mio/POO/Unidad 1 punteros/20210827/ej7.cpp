#include <iostream>
using namespace std;

struct vec_din {
	int *p;
	int size;
};

void mostrar(vec_din v) {
	for (int i=0; i<v.size; ++i)
		cout << v.p[i] << " ";
	cout << endl;
}

void mostrar(int *e, int *t) {
	for (int *p = e; p!=t; ++p)
		cout << *p << " ";
	cout << endl;
}

void redimensionar(vec_din &v, int cant_ceros) {
	int *aux = new int[v.size+cant_ceros];
	for (int i=v.size; i<v.size+cant_ceros; ++i)
		aux[i] = 0; // *(aux+i)=0;
	for (int i=0; i<v.size; ++i)
		aux[i] = v.p[i];
	delete [] v.p;
	v.p = aux; v.size += cant_ceros;
}

int main() {
	
	vec_din v;
	v.size = 5;
	v.p = new int[v.size];
	
	for (int i=0; i<v.size; ++i) { 
		*(v.p+i) = rand()%501+1000;
	}
	cout << endl;
	
	mostrar(v);
	redimensionar(v,20);
	mostrar(v.p, v.p+20);	
	
	delete [] v.p;
	return 0;
}

