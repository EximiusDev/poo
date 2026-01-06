#include <iostream>
using namespace std;

struct ParArreglos {
	int *p1, n1, *p2, n2;
};

ParArreglos separar(int *com, int *pos, int *fin) {
	ParArreglos par;
	
	par.n1 = pos-com;
	if (par.n1==0) {
		par.p1 = nullptr;
	} else {
		par.p1 = new int[par.n1];
		for (int i=0; i<par.n1; ++i) 
			par.p1[i] = com[i];
//			*(par.p1+i) = *(com+i);
	}
	
	par.n2 = fin-pos-1;
	if (par.n2==0) {
		par.p2 = nullptr;
	} else {
		par.p2 = new int[par.n2];
		for (int i=0; i<par.n2; ++i) 
			par.p2[i] = pos[i+1];
//			*(par.p2+i) = *(pos+i+1);
	}
	
	return par;
}

int main() {
	int x[] = { 2,5,3,6,7,8,9,0,1 };
	ParArreglos par = separar(x,x,x+9);
	
	cout << "1er arreglo:";
	for (int i=0; i<par.n1; ++i) 
		cout << " " << par.p1[i];
	cout << endl;
	
	cout << "2do arreglo:";
	for (int i=0; i<par.n2; ++i) 
		cout << " " << par.p2[i];
	cout << endl;
		
	delete [] par.p1;
	delete [] par.p2;
}

