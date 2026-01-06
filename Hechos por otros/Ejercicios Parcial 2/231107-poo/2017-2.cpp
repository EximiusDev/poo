/**
2017 - Parcial 2 - Tema A

Ejercicio 2 [25 pts] Se dispone de un archivo de textos USUARIOS.TXT donde cada línea 
contiene el código, sector, el apellido y el nombre . El código es un número entero y
el sector es una sola palabra, y cada usuario tiene un solo nombre y apellido separado
por un espacio en blanco. Escriba una clase que posea entre sus métodos: a) la función
GeneraPassword(), encargada de crear un password concatenando el sector con la primer
letra del nombre y el apellido completo de cada usuario y otra función CreaBinario()
que genere un archivo binario que contenga los datos referentes al código, nombre, 
apellido y password generado de cada usuario. Programa los métodos adicionales que
considere necesarios.
**/

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

struct DatosIn {
	int cod; string sec, ape, nom, pass;
};

struct DatosOut {
	int cod;
	char nom[32];
	char ape[32];
	char pass[64];
};

class Usuarios {
public:
	Usuarios() {
		ifstream f("USUARIOS.TXT");
		DatosIn d;
		while(f >> d.cod >> d.sec >> d.ape >> d.nom)
			m_datos_in.push_back(d);
	}
	void GenerarPasswords() {
		for(DatosIn &d : m_datos_in) 
			d.pass = d.sec + d.nom[0] + d.ape;
	}
	void CreaBinario() {
		ofstream f("usuarios.bin",ios::binary|ios::trunc);
		for(DatosIn din : m_datos_in) {
			DatosOut dout;
			dout.cod = din.cod;
			strcpy(dout.nom,din.nom.c_str());
			strcpy(dout.ape,din.ape.c_str());
			strcpy(dout.pass,din.pass.c_str());
			f.write(reinterpret_cast<char*>(&dout),sizeof(DatosOut));
		}
	}
private:
	vector<DatosIn> m_datos_in;
};
