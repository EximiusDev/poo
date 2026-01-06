//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/moodle/
//Guia de estudios Nº 6 - Ejercicio Nº 1
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

typedef struct{
	char apeynomb[50];
	int telefono;
} persona;

class agenda{
	char nombreArchi[50];
	persona p[100];
	int cantidad;
public:
	agenda(string nArch){strcpy(nombreArchi,nArch.c_str());};
	void carga();
	persona buscar(string cad);
};
void agenda::carga(){
	ifstream archi(nombreArchi);
	if(!archi.is_open()){
		cout<<"Error en apertura de archivo"<<endl;
		getchar();
	}else{
		cantidad=0;
		while(archi.getline(p[cantidad].apeynomb,50)){
			archi>>p[cantidad].telefono;
			archi.ignore();
			cout<<cantidad<<"- "<<p[cantidad].apeynomb<<", Tel: "<<p[cantidad].telefono<<endl;
			cantidad++;
		}
		archi.close();
	}
}
persona agenda::buscar(string cad){
	persona aux;
	int c=0;
	while(c<cantidad){
		if(strcmp(p[c].apeynomb,cad.c_str())==0){
			aux= p[c];
			return aux;
		}
		c++;
	}
	strcpy(aux.apeynomb,"No Encontrado");
	aux.telefono=0;
	return aux;
}
int main(int argc, char *argv[]) {
	agenda A("C:/POO/archivo.txt");
	A.carga();
	persona aux;
	aux= A.buscar("Garcia Ana");
	cout<<aux.apeynomb<<endl;
	cout<<aux.telefono<<endl;
	return 0;
}
