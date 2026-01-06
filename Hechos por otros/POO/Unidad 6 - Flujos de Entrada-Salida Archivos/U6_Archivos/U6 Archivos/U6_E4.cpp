//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/moodle/
//Guia de estudios Nº 6 - Ejercicio Nº 4

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int crea_aux(){//Genera archivo Auxiliar.txt con nombres y promedios.-
	int nota1, nota2, nota3;
	char nombre[50];
	ofstream Aux("/POO/Auxiliar.txt");
	ifstream lista("/POO/lista1.txt");
	if (!Aux.is_open()){cout<<"Error al abrir el archivo"<<endl;return 0;}
	if (!lista.is_open()){cout<<"Error al abrir el archivo"<<endl;return 0;}
	//Comienza la lectura de datos en lista1.
	while(lista.getline(nombre,50)){
		lista >> nota1 >> nota2 >> nota3;
		lista.ignore();//para el enter de fin de linea
		Aux<<nombre<<setw(10)<<float(float(nota1+nota2+nota3)/3.0)<<endl;
	}//del while*/
	lista.close();//Cierro el archivo
	//abro el segundo archivo
	ifstream lista2("/POO/lista2.txt");
	if (!lista2.is_open()){cout<<"Error al abrir el archivo"<<endl;return 0;}
	//leo los datos y escribo el promedio en auxiliar
	while (lista2.getline(nombre,50)){ // Cargo los datos de 8 alumnos
		lista2>>nota1>>nota2>>nota3;
		lista2.ignore();
		Aux<<nombre<<setw(10)<<float(float(nota1+nota2+nota3)/3.0)<<endl;
	}//del while*/
	Aux.close();lista2.close();//Cierro archivos.-	
	return 1;
}
int agrega_promedios(){//Genera lista11.txt y lista22.txt con nombres, notas y promedios
	int nota1, nota2, nota3;
	char nombre[50];
	ofstream lista11("/POO/lista11.txt");
	ifstream lista("/POO/lista1.txt");
	if (!lista11.is_open()){cout<<"Error al abrir el archivo"<<endl;return 0;}
	if (!lista.is_open()){cout<<"Error al abrir el archivo"<<endl;return 0;}
	//Comienza la lectura de datos en lista1.
	while(lista.getline(nombre,50)){
		lista >> nota1 >> nota2 >> nota3;
		lista.ignore();//para el enter de fin de linea
		lista11<<nombre<<endl;
		lista11<<setw(4)<<nota1<<setw(4)<<nota2<<setw(4)<<nota3
			<<setw(10)<<float(float(nota1+nota2+nota3)/3.0)<<endl;
	}//del while*/
	lista11.close();
	lista.close();//Cierro el archivo
	//abro el segundo archivo
	ifstream lista2("/POO/lista2.txt");
	if (!lista2.is_open()){cout<<"Error al abrir el archivo"<<endl;return 0;}
	ofstream lista22("/POO/lista22.txt");
	if (!lista22.is_open()){cout<<"Error al abrir el archivo"<<endl;return 0;}
	//leo los datos y escribo el promedio en auxiliar
	while (lista2.getline(nombre,50)){ // Cargo los datos de 8 alumnos
		lista2>>nota1>>nota2>>nota3;
		lista2.ignore();
		lista22<<nombre<<endl;
		lista22<<setw(4)<<nota1<<setw(4)<<nota2<<setw(4)<<nota3
			<<setw(10)<<float(float(nota1+nota2+nota3)/3.0)<<endl;
	}//del while*/
	lista22.close();lista2.close();//Cierro archivos.-	
	return 1;
}

int main(int argc, char *argv[]) {
	if (crea_aux()){
		cout<<"Operacion con archivos exitosa. Se ha generado /POO/Auxiliar.txt"<<endl;
	}else{
		cout<<"Se han detectado errores.";
	}
	if (agrega_promedios()){
		cout<<"Operacion con archivos exitosa. Se han agregado los promedios"<<endl;
	}else{
		cout<<"Se han detectado errores.";
	}
	return 0;
}//FICH - PROGRAMACION ORIENTADA A OBJETOS - C++ - Prof. Gerardo Sas.
