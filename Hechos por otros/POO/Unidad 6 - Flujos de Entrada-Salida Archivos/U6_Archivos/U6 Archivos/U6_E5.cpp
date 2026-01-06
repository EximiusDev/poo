//© Programación Orientada a Objetos- F.I.C.H. - U.N.L.
//Autor: Prof. Gerardo Sas.
//sitio web: http://e-fich.unl.edu.ar/moodle/
//Guia de estudios Nº 6 - Ejercicio Nº 5

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	//Creo un objeto de la clase fstream para manejar el archivo binario
		fstream archi("/POO/grupo.dat" , ios::binary |ios::in|ios::out| ios::trunc);
		if(!archi.is_open()){cout<<"E R R O R "; return 0;};
		float f; int i;
		for (int c=1; c<=200; c++)
		{ f=(float)(rand()/(1.0*rand())); // genera flotantes
		i=rand()% 1000; // genera enteros menores que 1000;
		cout<<c<<"  "<<setw(10)<<f<<", "<<setw(10)<<i;//muestro por pantalla los numeros generados
		archi.write(reinterpret_cast<char*>(&f), sizeof(f));//escribe en el archivo los flotantes
		archi.write(reinterpret_cast<char*>( &i), sizeof(i));//escribe en el archivo los enteros
		cout<<", tellp(): "<<setw(10)<<archi.tellp()<<endl;//Tellp() devuelve la posicion en byte, que en este caso es la ultima.
		};// del for
		//calculo el largo (en pares de numeros)
		archi.seekp(0,ios::end);
		int c, largo= (archi.tellp()/(sizeof(f)+sizeof(i)));
		cout<<endl<<"Cantidad de pares: "<<largo<<endl;
		archi.seekg(0,ios::beg);//muevo el puntero de lectura al principio del archivo
		for(c=0; c<largo; c++){//Comienza la lectura por pares
			archi.read(reinterpret_cast<char*>(&f), sizeof(f));
			archi.read(reinterpret_cast<char*>(&i), sizeof(i));
			cout<<c<<"  "<<setw(10)<<f<<", "<<setw(10)<<i //Muestro los pares
				<<", tellg(): "<<setw(10)<<archi.tellg()<<endl;
		}
		archi.close();
	}//Programación Orientada a Objetos - Prof. Gerardo Sas
