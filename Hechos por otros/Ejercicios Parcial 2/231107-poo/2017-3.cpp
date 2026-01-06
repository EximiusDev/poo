/**
2017 - Parcial 2 - Tema A

Ejercicio 3 [30 pts] Defina Carta (clase o struct) para representar a un naipe que
tiene un número y un palo. Diseñe una clase llamada Mazo que permita manejar los 
datos de un grupo de cartas. La clase debe poseer métodos para: a) Guardar los
datos de las cartas en un archivo binario. b) Cargar los datos de los cartas desde 
un archivo binario. c) Agregar una nueva carta . d) Eliminar una carta indicando su
palo y número, e) retornar una carta dada su posición en el mazo. Tener en cuenta 
que no hay cartas repetidas en el mazo.
**/
	
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct Carta {
	char palo[16];
	int nro;
};

bool operator==(Carta c1, Carta c2) {
	return c1.nro==c2.nro and string(c1.palo)==c2.palo;
}

class Mazo {
public:
	Mazo(string fname) {
		ifstream f(fname,ios::binary|ios::ate);
		int n = f.tellg() / sizeof(Carta);
		m_v.resize(n);
		f.seekg(0);
		for(Carta &c : m_v) 
			f.read(reinterpret_cast<char*>(&c),sizeof(Carta));
//		ifstream f(fname,ios::binary);
//		Carta c;
//		while (f.read(reinterpret_cast<char*>(&c),sizeof(Carta)))
//			m_v.push_back(c);
	}
	void Guardar(string fname) {
		ofstream f(fname,ios::binary|ios::trunc);
		for(Carta &c : m_v) 
			f.write(reinterpret_cast<char*>(&c),sizeof(Carta));
	}
	void Agregar(Carta c) { m_v.push_back(c); }
	
	int Cantidad() { return m_v.size(); }
	Carta Ver(int i) { return m_v[i]; }

	void Eliminar(Carta c) {
		auto it = find(m_v.begin(),m_v.end(),c);
		if (it!=m_v.end()) m_v.erase(it);
	}
private:
	vector<Carta> m_v;
};

