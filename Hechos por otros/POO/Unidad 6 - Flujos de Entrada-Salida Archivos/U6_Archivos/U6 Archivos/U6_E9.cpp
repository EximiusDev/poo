//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/moodle/
//Guia de estudios Nº 6 - Ejercicio Nº 9
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cstring>
using namespace std;


void createWellDessing(string nombre,int tamanio){
	//Declaro el objeto 
	fstream archi(nombre.c_str(), ios::binary |ios::in|ios::out|ios::trunc);
	if(!archi.is_open()){cout<<"E R R O R - al crear archivo: "<<nombre<<endl;
	}else{
	for (int c=0; c<=(tamanio/sizeof(c)); c++){
		//Escribo el archivo con numeros al azar
		int num= rand()%256;
		archi.write(reinterpret_cast<char*>( &num), sizeof(num));
	}//El archivo ya fue creado
	archi.seekg(0,ios::end);//Me posciono al final del archivo
	int largo= (archi.tellg());//Calculo cantidad de elementos
	cout<<nombre<<"; Largo en cantidad de bytes: "<<largo<<endl;
	archi.close();
	}
}

void arreglar(string nombre){
	fstream archi(nombre.c_str(), ios::binary |ios::in|ios::out);
	if(!archi.is_open()){cout<<"E R R O R - al crear archivo: "<<nombre<<endl;
	}else{
		cout<<"Apertura exitosa de "<<nombre<<endl;
		archi.seekp(0,ios::end);
		cout<<"Tamaño de archivo en bytes: "<<archi.tellp()<<endl;
		archi.seekp(178,ios::beg);
		char cadena[5];
		strcpy(cadena,"msw09");
		archi.write(cadena,sizeof(cadena));
		int anio= 2014;
		archi.seekp(239,ios::beg);
		archi.write(reinterpret_cast<char*>(&anio), sizeof(anio));
	}
}

int main(int argc, char *argv[]) {
	string nombre="",aux1="",aux2="";
	char cad[2], cad0[11];
	strcpy(cad0,"/POO/desing");
	int contArchivos;
	for(contArchivos=1; contArchivos <= 5; contArchivos++){
		nombre="";aux1="";aux2="";strcpy(cad0,"/POO/desing");
		//char *  itoa ( int value, char * str, int base );
		itoa(contArchivos,cad,10);
		cout<<cad<<endl;
		aux1+= cad0;
		aux2+= cad;
		nombre+= aux1;
		nombre+= aux2;
		nombre+= ".wds";
		cout<<"Creando "<<nombre<<endl;
		createWellDessing(nombre, rand()%100+300);
	}
	
	for(contArchivos=1; contArchivos <= 5; contArchivos++){
		nombre="";aux1="";aux2="";strcpy(cad0,"/POO/desing");
		//char *  itoa ( int value, char * str, int base );
		itoa(contArchivos,cad,10);
		cout<<cad<<endl;
		aux1+= cad0;
		aux2+= cad;
		nombre+= aux1;
		nombre+= aux2;
		nombre+= ".wds";
		cout<<"arreglando "<<nombre<<endl;
		arreglar(nombre);
		cout<<"arreglado!!! "<<nombre<<endl;
	}
	return 0;
}
