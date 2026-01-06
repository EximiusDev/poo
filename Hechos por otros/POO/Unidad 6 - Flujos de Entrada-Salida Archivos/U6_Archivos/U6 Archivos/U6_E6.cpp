//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/moodle/
//Guia de estudios Nº 6 - Ejercicio Nº 6
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	float f,auxf; int i,auxi, pos;
	cout<<"Ingrese un float  : "; cin>> auxf;
	cout<<"Ingrese un Integer: "; cin>> auxi;
	cout<<"Ingrese una Posicion (0 a 199): "; cin>> pos;
	fstream archi("/POO/grupo.dat", ios::binary|ios::in|ios::out);
	if(!archi.is_open()){cout<<"E R R O R "; return 0;};
	archi.seekp(0,ios::end);
	int c, largo= archi.tellp()/(sizeof(f)+sizeof(i));//calculo el largo
	cout<<"Largo en pares de numeros: "<<largo<<endl;
	// desplazamos el puntero desde el inicio (beg de begin)
	//metodo seekg
	archi.seekg(pos*(sizeof(f)+sizeof(i)),ios::beg);
	//leemos el par de datos
	archi.read(reinterpret_cast<char*>(&f), sizeof(f));
	archi.read(reinterpret_cast<char*>(&i), sizeof(i));
	//muestro por pantalla
	cout<<"Par de valores del "<<pos<<" lugar:"<<setw(10)<<f<<", "<<setw(10)<<i<<endl;
	// Proceso de reemplazo
	// metodo seekp
	// nos desplazamos hacia el par a reemplazar
	archi.seekp((pos*(sizeof(f)+sizeof(i))),ios::beg);
	//ahora estamos en la posicion 
	archi.write(reinterpret_cast<char*>(&auxf), sizeof(auxf));//escribe en el archivo los flotantes
	archi.write(reinterpret_cast<char*>( &auxi), sizeof(auxi));//escribe en el archivo los enteros
	archi.seekg(0,ios::beg);//muestro desde el principio
	for(c=0; c<largo; c++){
		archi.read(reinterpret_cast<char*>(&f), sizeof(f));
		archi.read(reinterpret_cast<char*>(&i), sizeof(i));
		cout<<c<<": "<<setw(10)<<f<<", "<<setw(10)<<i<<endl;
	};
	//cerramos el archivo
	archi.close();
}
//Programación Orientada a Objetos - Prof. Gerardo Sas

