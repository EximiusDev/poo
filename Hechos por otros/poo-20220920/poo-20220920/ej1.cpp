/// Parcial 1 2020 - Ej 1

#include <iostream>
using namespace std;

float promedio(const float *v, int n) {
	float p = 0;
	for (int i=0; i<n; ++i) {
		p += *(v+i); // v[i];
	}
	return p/n;
}

int contar(const float *v, int n, float prom) {
	int c = 0;
	for (int i=0; i<n; ++i) {
		if (*(v+i)>prom) {
			++c;
		}
	}
	return c;
}

int superaProm(const float *v, int n) {
	float prom = promedio(v,n);
	return contar(v,n,prom);
}

int main() {
	int n1;
	cin >> n1;
	float *v1 = new float[n1];
	for (int i=0; i<n1; ++i) { 
		cin >> *(v1+i);
	}
	
	int n2 = superaProm(v1,n1);
	float prom = promedio(v1,n1);
	float *v2 = new float[n2];
	int j=0;
	for (int i=0; i<n1; ++i) { 
		if (*(v1+i)>prom) {
			*(v2+j) = *(v1+i);
			++j;
		}
	}
	
	for (int i=0; i<n2; ++i) { 
		cout << *(v2+i) << " ";
	}
	
	delete [] v2;
	delete [] v1;
	return 0;
}

