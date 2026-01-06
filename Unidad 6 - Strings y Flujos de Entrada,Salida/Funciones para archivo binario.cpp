#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*Ejercicio 3
Escriba un programa que genere un archivo binario con una lista de 100 enteros
ordenados de forma creciente (por ejemplo: 0, 5, 10, 15, 20, 25...). Luego escriba
otro programa que permita insertar (no reemplazar) un nuevo dato de tipo entero,
ingresado por el usuario, en el archivo manteniendo el orden creciente. Evite utilizar
vectores auxiliares.
*/
int Tamanio_Archi(fstream &Archi){
	int tamanio = Archi.tellg();
	return tamanio;
}
int Posicion_Archi(fstream &Archi, int pos){
	
//	return Archi.seekg(pos*(sizeof (int)));
	return pos*(sizeof (int));
}
void Mover_Pos_Archi(fstream &Archi, int pos){
	Archi.seekp(pos*(sizeof (int)));
}
void Escribir_fin_Archi(fstream &Archi, int val){
	//Archi.seekp(final);
	Archi.write(reinterpret_cast<char*>(&val),sizeof(int));
}
vector<int> Leer_Archi(fstream &Archi){
	vector<int> v;
	int n = Tamanio_Archi(Archi)/sizeof(int); /// cantidad de elementos
	Archi.seekp(0);
	int aux;
	for(int i=0;i<n;i++) { 
		Archi.read(reinterpret_cast<char*>(&aux),sizeof(int));
		v.push_back(aux);
	}
	return v;
}
int Leer_Pos_Archi(fstream &Archi, int pos){
	int pos_origen = Archi.tellg();
	int valor;
	Mover_Pos_Archi(Archi,pos);
	Archi.read(reinterpret_cast<char*>(&valor),sizeof(int));
	Archi.seekg(pos_origen);
	return valor;
}
void Escribir_Pos_Archi(fstream &Archi, int pos, int valor){
	int pos_origen = Archi.tellg();
	Mover_Pos_Archi(Archi,pos);
	Archi.write(reinterpret_cast<char*>(&valor),sizeof(int));
	Archi.seekg(pos_origen);
}
void Borrar_dato_Archi(fstream &Archi)//, int pos, int dato){
	///Tengo que leer los datos (guardarlos), modificar en el vector de datos guardado
	///despues escribir todo el archivo con el los datos modificados
{//Archi.open(ios::binary|ios::trunc);
Archi.getloc();
}
/// //////////////////////////////////////////////////////////////////////////
int main() {
	fstream Archi("Datos.bin",ios::binary|ios::in|ios::out|ios::ate);
	
	int tam = Tamanio_Archi(Archi); /// tamanio en binario (para saber la cantidad de elementos dividir por el tamanio de dato o numero)
	float num = tam / sizeof(int)*1.0f;
	vector<int> Arc_Leido = Leer_Archi(Archi);
	Escribir_fin_Archi(Archi, 1000);
	Escribir_Pos_Archi(Archi, 5, 999);
	int pos_leida = Leer_Pos_Archi(Archi, 0);
	Borrar_dato_Archi(Archi);
	vector<int> Arc_Leido2 = Leer_Archi(Archi);
	
	cout<<"Tamanio archivo: "<<tam<<endl;
	cout<<"Cantidad de elementos: "<<num<<endl;
	cout<<endl;
	
	cout<<"Elementos del archivo: "<<endl;
	for(unsigned int i=0;i<Arc_Leido.size();i++) { 
		cout<<i<<". "<<Arc_Leido[i]<<endl;
	}
	
	cout<<"Elementos del archivo modificado: "<<endl;
	for(unsigned int i=0;i<Arc_Leido2.size();i++) { 
		cout<<i<<". "<<Arc_Leido2[i]<<endl;
	}
	cout<<endl;
	cout<<"1er valor: "<<pos_leida<<endl;
	
	Archi.close();
	return 0;
}

