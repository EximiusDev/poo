///Ejercicio 2

#include <iostream>
#include <vector>
using namespace std;

struct Persona{
	char apenom[30];
	int dni,mn, an;
};

class RecursosHumanos{
	vector <Persona> V;
	string archivo;
	
public:
	RecursosHumanos(string x){archivo = x;}
	void Cargar();
	void Grabar();
	Persona Buscar(string x);
	Persona Ver(int x){return	v[x];}
		
};

void RecursosHumanos::Cargar(){
	fstream  f (archivo, ios::binary|ios::out)
}


int main() {
	
	return 0;
}

