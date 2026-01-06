#include <iostream>
#include <fstream>
using namespace std;

struct par {
	int i;
	double d;
};

int main(int argc, char *argv[]) {
	ofstream archi("pares.dat",ios::binary|ios::trunc);
	if (!archi.is_open()) {
		cerr<<"No se pudo abrir el archivo."<<endl;
		return 1;
	}
	int n;
	cout<<"Cantidad de pares: ";
	cin>>n;
	
	par p;
	for (int i=0;i<n;i++) {
		cout<<"Entero y doble: ";
		cin>>p.i>>p.d;
		archi.write((char*)&p,sizeof(par));
	}
	
	archi.close();
	return 0;
}

