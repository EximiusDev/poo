//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/moodle/
//Guia de estudios Nº 6 - Ejercicio Nº 8
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;


void createDummyFile(string nombre,int tamanio){
	//Declaro el objeto 
	fstream archi(nombre.c_str(), ios::binary |ios::in|ios::out|ios::trunc);
	for (int c=0; c<=(tamanio/sizeof(c)); c++){
		//Escribo el archivo con numeros al azar
		int num= rand()%256;
		archi.write(reinterpret_cast<char*>( &num), sizeof(num));
	}//El archivo ya fue creado
	int i;
	archi.seekg(0,ios::end);//Me posciono al final del archivo
	int largo= (archi.tellg()/sizeof(i));//Calculo cantidad de elementos
	archi.seekg(0,ios::beg);//llevo el puntero al inicio para comenzar la lectura
	cout<<"Lee archivo original: "<<endl;
	cout<<endl<<"Largo en cantidad de numeros: "<<largo<<endl;
	for (int c=0; c<largo; c++){
		archi.read(reinterpret_cast<char*>( &i), sizeof(i));
		//cout<<i<<"  ";
	}
	cout<<"El archivo ya fue creado";
	archi.close();
}

void createDummyFile(string nombre,string tam){
	//Busco Mb
	int total;
	unsigned int loc ;
		loc = tam.find("Mb",0);
	if( loc != string::npos ){
		string subcad = tam.substr(0,loc);
		total= atoi(subcad.c_str())*1000000;
		cout<<"Mb - tamaño en Bytes: "<<total<<endl;
	}else{
		loc = tam.find("Kb",0);
		if( loc != string::npos ){
			string subcad = tam.substr(0,loc);
			total= atoi(subcad.c_str())*1000;
			cout<<"Kb - tamaño en Bytes: "<<total<<endl;}
		else{
			loc = tam.find("b",0);
			if( loc != string::npos ){
				string subcad = tam.substr(0,loc);
				total= atoi(subcad.c_str());
				cout<<"b - tamaño en Bytes: "<<total<<endl;
			}
		}
	}
	createDummyFile(nombre, total);
}


int main(int argc, char *argv[]) {
	string nombre;
	string bytess;
	srand( time(NULL) );//Para generar numeros distintos
	cout<<"Ingrese el nombre del archivo: /POO/"; cin>>nombre;
	nombre = "/POO/"+nombre;
	cout<<"Ingrese la cantidad de Bytes (Mb - Kb - b): "; cin>> bytess;
	createDummyFile(nombre, bytess);
}
	
