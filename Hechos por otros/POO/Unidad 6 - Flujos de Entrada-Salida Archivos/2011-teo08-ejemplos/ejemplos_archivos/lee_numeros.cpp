/// programa para leer un archivo binario que contiene solo enteros

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	
	ifstream archi("numeros.dat",ios::binary|ios::ate);
	if (!archi.is_open()){
		cerr<<"No se pudo abrir el archivo."<<endl;
		return 1;
	}
	
	int tamanio_archivo=archi.tellg(); // porque lo abri con ios::ate
	int n=tamanio_archivo/sizeof(int);
	
	archi.seekg(0,ios::beg);
	int x;
	for(int i=0;i<n;i++) { 
		archi.read((char*)&x,sizeof(int));
		cout<<x<<endl;
	}
	
	archi.close();
	return 0;
	
}

