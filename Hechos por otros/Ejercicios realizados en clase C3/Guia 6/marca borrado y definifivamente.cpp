#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*a) Considere el struct Legajo { bool borrado; char, ape[64], nom[64]; unsigned int dni,
antigüedad; float salario;} que se ha utilizado para organizar los datos de los empleados de una
empresa. La empresa dispone de un archivo binario que contiene una base de datos de registros de tipo
Legajo generada por un programa C++. Cuando un usuario borra un registro, el programa marca el
registro como borrado colocando true en el campo borrado, pero no lo quita del archivo. El archivo es
ahora demasiado extenso. Escriba un programa C++ que abra el archivo y lo limpie eliminando
definitivamente todos los registros con miembro borrado en true . La función también debe guardar en
un archivo de texto la lista de dnis eliminados.
b) Escriba una segunda función que dado un número de dni, retorne true si éste se encuentra en la lista
de eliminados (en el archivo de texto)*/


struct Legajo {
	bool borrado; 
	char ape[64], nom[64]; 
	unsigned int dni;
	unsigned int antiguedad; 
	float salario;
};


void borrar(int dniaborrar){
	fstream archi("base_datos.dat",ios::binary|ios::in|ios::out|ios::ate);
	int cant=archi.tellg()/sizeof(Legajo);
	Legajo aux;
	archi.seekg(0);
	int i;
	for(i=0;i<cant;i++) { 
		archi.read(reinterpret_cast<char*>(&aux),sizeof(aux));
		if(aux.dni==dniaborrar)
			   break;
	}
	if(i<cant){
		aux.borrado=true;
		archi.seekp(i* sizeof(Legajo));
		archi.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	    }	
	archi.close();
}
	
	
void borrarDefinitivamenteArchivo(){
	fstream archi("base_datos.dat",ios::binary|ios::in|ios::out|ios::ate);
	ofstream t("dniborrados.txt",ios::trunc);
	vector<Legajo>v;
	int cant=archi.tellg()/sizeof(Legajo);
	Legajo aux;
	archi.seekg(0);
	int i;
	for(i=0;i<cant;i++) { 
		archi.read(reinterpret_cast<char*>(&aux),sizeof(aux));
		if(!aux.borrado)
			v.push_back(aux);
		else
			t<<aux.dni<<endl;
	}
	t.close();
	archi.close();
	archi.open("base_datos.dat",ios::binary|ios::in|ios::out|ios::trunc);
	for(auto x:v)
		archi.read(reinterpret_cast<char*>(&x),sizeof(x));
	archi.close();
}
	
	
	
	bool trueonotrue(int dni){
		ifstream archi("eliminados");
		int aux;
		while(archi >> aux){
			if(dni==aux){
				return true;
			}
			else return false;
			
		}
		return false;
	}
		
		
		int main() {
			
			return 0;
		} 
