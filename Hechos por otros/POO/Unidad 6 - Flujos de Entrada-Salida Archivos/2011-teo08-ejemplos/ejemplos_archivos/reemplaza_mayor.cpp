/// reemplaza el mayor por -1 en un binario con enteros
// generar con genera_numeros y ver com lee_numeros

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	
	fstream archi("numeros.dat",ios::in|ios::out|ios::binary|ios::ate);
	if (!archi.is_open()){
		cerr<<"No se pudo abrir el archivo."<<endl;
		return 1;
	}
	
	int tamanio_archivo=archi.tellg(); // porque lo abri con ios::ate
	int n=tamanio_archivo/sizeof(int);
	
	archi.seekg(0,ios::beg);
	int aux,may, pos=0;
	archi.read((char*)&may,sizeof(int));
	for(int i=1;i<n;i++) { 
		archi.read((char*)&aux,sizeof(int));
		if (aux>may) {
			may=aux;
			pos=i;
		}
	}
	
	archi.seekp(pos*sizeof(int),ios::beg);
	int menos_uno=-1;
	archi.write((char*)&menos_uno,sizeof(int));
	
	archi.close();
	return 0;
	
}

