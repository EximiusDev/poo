/** 
Ejemplo 1) escriba un programa para leer una lista de nombres y notas de 3
parciales de un curso de POO de un archivo de texto como el siguiente
**/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Alumno {
	string nombre;
	int n1,n2,n3;
	float prom() { return float(n1+n2+n3)/3; }
};

int main(int argc, char *argv[]) {
	
	Alumno v[100];
	int n=0;
	
	ifstream archi_in("notas1.txt");
	if (!archi_in.is_open()) {
		cerr<<"Error al abrir el archivo."<<endl;
		return 1;
	}
	string nom;
	while(true) {
		getline(archi_in,v[n].nombre);
		archi_in>>v[n].n1>>v[n].n2>>v[n].n3;
		if (archi_in.eof()) break;
		n++;
		archi_in.ignore();
	}
	archi_in.close();
	
	// escribo en otro para no perder los datos de entrada, pero el ejercicio 
	// pedia escribir en el mismo, para eso poner otra vez "notas1.txt"
	ofstream archi_out("notas2.txt"); 
	if (!archi_out.is_open()) {
		cerr<<"Error al abrir el archivo."<<endl;
		return 2;
	}
	for (int i=0;i<n;i++) {
		archi_out<<v[i].nombre<<" "<<fixed<<setprecision(2)<<v[i].prom()<<endl;
	}
	archi_out.close();
	return 0;
}

