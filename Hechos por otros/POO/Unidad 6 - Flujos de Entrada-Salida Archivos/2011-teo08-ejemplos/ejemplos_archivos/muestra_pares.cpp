#include <iostream>
#include <fstream>
using namespace std;

struct par {
	int i;
	double d;
};

int main(int argc, char *argv[]) {
	ifstream archi("pares.dat",ios::binary|ios::ate);
	if (!archi.is_open()) {
		cerr<<"No se pudo abrir el archivo."<<endl;
		return 1;
	}
	
	int tamanio_archivo=archi.tellg();
	int n=tamanio_archivo/sizeof(par);
	cout<<"Cantidad de pares: "<<n<<endl;
	par p;
	archi.seekg(0,ios::beg);
	for (int i=0;i<n;i++) {
		cout<<"Entero y doble: ";
		archi.read((char*)&p,sizeof(par));
		cout<<p.i<<" "<<p.d<<endl;
	}
	
	archi.close();
	return 0;
}

