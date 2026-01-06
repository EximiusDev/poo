/**
2do parcial 2016 – Tema A

Ejercicio 1 [30 pts] Escriba una función genérica (template) llamada ampliar() que reciba como
argumentos un objeto llamado archname de tipo string y un arreglo de la clase vector (STL) llamado x
que contiene structs de 2 miembros: valor (genérico) y pos (char). El string archname corresponde al
nombre de un archivo binario. La función debe agregar al archivo el dato (valor) de cada elemento del
arreglo x. Los agregados se hacen al principio del archivo si pos contiene ‘f’ y al final del archivo si
pos contiene ‘b’.
*/	
	
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
using namespace std;


template<typename T>
struct Par {
	T valor;
	char pos;
};

template<typename T>
void ampliar(string nombre, const vector<Par<T>> &v) {
	ifstream fin(nombre,ios::binary);
	list<T> l;
	T aux;
	while( fin.read(reinterpret_cast<char*>(&aux),sizeof(T)) )
		l.push_back(aux);  
	fin.close();
	
	for(Par<T> &p : v)
		if (p.pos=='f') l.push_front(p.valor);
		else            l.push_back(p.valor);
	
	ofstream fout(nombre,ios::binary);
	for(T x : l)
		fout.write( reinterpret_cast<char*>(&x),sizeof(T) );
	
}

int main() {
	
}

