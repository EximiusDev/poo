#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// 0   1  2  3  4  5  6  7  8  9
//{11,22,33,44,55,66,77,88,99}
// c^    ^p1   ^p2           ^fin

int calc_tam(int *com, int *p1, int *p2, int *fin) {
	int n_completo = fin-com;
	int n_recortar = p2-p1+1;
	return n_completo-n_recortar;
}
int *recortar(int *com, int *p1, int *p2, int *fin) {
	int *nuevo = new int[calc_tam(com,p1,p2,fin)];
	int i=0;
	for(int *p=com; p<p1; ++p) {
		nuevo[i] = *p;
		++i;
	}
	for(int *p=p2+1; p<fin; ++p) {
		nuevo[i] = *p;
		++i;
	}
	return nuevo;
}

int main() {
	srand(time(0));
	int n = 9;
//	cin >> n;
	int *v = new int[n];
	for (int i=0; i<n; ++i) { 
//		cin >> v[i];
		v[i] = (i+1)+(i+1)*10;
	}
	for (int i=0; i<10; ++i) { 
		int i1 = rand()%n;
		int i2 = rand()%n;
		if (i1>i2) swap(i1,i2);
		cout << "Probando con i1=" << i1 << " e i2=" << i2 << ":" << endl << "   ";
		int * v_recortado = recortar(v, v+i1, v+i2, v+n);
		int n_recortado = calc_tam(v, v+i1, v+i2, v+n);
		for (int i=0; i<n_recortado; ++i) { 
			cout << v_recortado[i] << " ";
		}
		cout << endl;
		delete [] v_recortado;
	}
	
	delete [] v;
	return 0;
}

