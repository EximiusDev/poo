#include <iostream>
using namespace std;

	
int *buscar(int *v, int n, int x) {
	for (int i=0; i<n; ++i) { 
		if (v[i]==x)
			return v+i;
	}
	return nullptr;
}

int main() {
	
	int *v = new int[10];
	for (int i=0; i<10; ++i) { 
		v[i] = rand()%501+1000; // o *(v+i)=...
		cout << v[i] << " "; // o cout << *(v+i)...
	}
	cout << endl;
	
	int x; cin >> x;
	int *p = buscar(v,10,x);
	if (p==nullptr)
		cout << "No lo encontro" << endl;
	else
		cout << "Esta en las pos " << p-v << endl;
		
	delete [] v;
	return 0;
}

