//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/moodle/
//Guia de estudios Nº 6 - Ejercicio Nº 3
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctype.h>
using namespace std;


int main(int argc, char *argv[]) {
	char texto[200];//arreglo de cha para leer del archivo
	int pos, contador = 0;
	string linea, cadena="";//String donde guardare todo el archivo de texto
	ifstream archi("/POO/DonQuijote.txt");//abro el archivo en modo lectura
	if(!archi.is_open()) {cout<<"ERROR";return 0;};//Si da error finalizo
	while(archi.getline(texto,200)){//mientras haya texto leo el archivo
		cadena+= texto;//concateno lo leido en el string cadena
		cout<<"texto: "<<texto<<endl;//opcional, muestro por pantalla
	}
    
	for(int c=0; c <cadena.length(); c++){//Convierto el texto a minusculas
		cadena[c]=tolower(cadena[c]);
	}
	//Muestro el texto en minusculas
	cout<<cadena<<endl;
	pos = 0;//Busco la primer ocurrencia del texto entre comillas
	unsigned int loc = cadena.find( "molinos de viento", pos );
	while( loc != string::npos ){//Mientras lo encuentre
		cout << "Encontro: " <<++contador<<" veces, posicion: "<<loc << endl;
		pos= loc + 1;//Avanzo una posicion y sigo buscando
		loc = cadena.find( "molinos de viento", pos );
	}
	//Fin
	return 0;
}

