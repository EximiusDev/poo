#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

///SIN TERMINAR (REVISAR)

/* Ejercicio 2
En un archivo de texto llamado lista.txt, como el que se
muestra a la derecha, se encuentran los nombres y notas
de los alumnos de una comisión de Programación
Orientada a Objetos.
a) Escriba una función modificar que reciba el nombre
de un alumno y dos notas, y modifique el archivo
reemplazando las dos notas de ese alumno.
b) Escriba una función que lea la lista del archivo y genere otro archivo de texto
promedios.txt con una tabla donde cada línea posea el nombre, el promedio,
y la condición final de cada uno de los alumnos.
Ayuda: utilice manipuladores de flujo (setw, right, left, fixed, setprecision) para dar
formato a la tabla del archivo que se genera en b).
*/

struct Alumno{
	string Nom_Ape;
	int nota1, nota2;
};

void Modificar_Notas(Alumno Mod_Alu){
	vector<Alumno>Lista;
	Alumno list;
	
	ifstream Archi_lect("lista.txt");
	if(Archi_lect.is_open()){
		while(getline(Archi_lect, list.Nom_Ape)){
			Archi_lect >> list.nota1;
			Archi_lect >> list.nota2;
			Lista.push_back(list);
			//cout<<list.Nom_Ape<<", "<<list.nota1<<" "<<list.nota2<<endl;
			if(list.Nom_Ape == Mod_Alu.Nom_Ape){
				list.nota1 = Mod_Alu.nota1;
				list.nota2 = Mod_Alu.nota2;
			}
			
			Archi_lect.ignore();
		}
		Archi_lect.close();
	}else cout<<"No se pudo abrir el archivo"<<endl;
	
	/*
	for(int i=0;i<Lista.size();i++) { 
		if(Lista[i].Nom_Ape == Mod_Alu.Nom_Ape){
			Lista[i].nota1 = Mod_Alu.nota1;
			Lista[i].nota2 = Mod_Alu.nota2;
		}
	}
	for(int i=0;i<Lista.size();i++) { 
		cout<<Lista[i].Nom_Ape<<", "<<Lista[i].nota1<<" "<<Lista[i].nota2<<endl;
	}*/
	
}

/*
// leo al archivo devuelvo promedios.txt
*/

int main() {
	
	vector<Alumno>Lista;
	Alumno list;
	Alumno Mod_Alu;
	Mod_Alu.Nom_Ape = "hola";
	Mod_Alu.nota1 = 10;
	Mod_Alu.nota2 = 100;
		
	
	ifstream Archi_lect("lista.txt");
	if(Archi_lect.is_open()){
		while(getline(Archi_lect, list.Nom_Ape)){
			Archi_lect >> list.nota1;
			Archi_lect >> list.nota2;
			
			Lista.push_back(list);
			
			cout<<list.Nom_Ape<<", "<<list.nota1<<" "<<list.nota2<<endl;
			
			Archi_lect.ignore();
		}
		
		Archi_lect.close();
	}else cout<<"No se pudo abrir el archivo"<<endl;
	
	cout<<endl;
	cout<<endl;
	
	for(int i=0;i<Lista.size();i++) { 
		if(Lista[i].Nom_Ape == Mod_Alu.Nom_Ape){
			Lista[i].nota1 = Mod_Alu.nota1;
			Lista[i].nota2 = Mod_Alu.nota2;
		}
	}
	
	for(int i=0;i<Lista.size();i++) { 
		cout<<Lista[i].Nom_Ape<<", "<<Lista[i].nota1<<" "<<Lista[i].nota2<<endl;
	}
	
	ofstream Archi_escr("lista_mod_alumno.txt");
	for(int i=0;i<Lista.size();i++) { 
		Archi_escr<<Lista[i].Nom_Ape<<endl;
		Archi_escr<<Lista[i].nota1<<" "<<Lista[i].nota2<<endl;
	}
	Archi_escr.close();
	
	ofstream Archi_escr2("promedios.txt");
	for(int i=0;i<Lista.size();i++) { 
		Archi_escr2<<Lista[i].Nom_Ape<<"; ";
		float prom = (Lista[i].nota1 + Lista[i].nota2)/2.0;
		Archi_escr2<<prom<<", ";
		if(prom < 40) Archi_escr2<<"Libre"<<endl;
		else Archi_escr2<<"Regular"<<endl;
	}
	Archi_escr.close();
	
	return 0;
}

