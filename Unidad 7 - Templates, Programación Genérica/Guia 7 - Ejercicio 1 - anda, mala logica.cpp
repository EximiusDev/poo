#include <iostream>
using namespace std;

struct Persona{
	string Nombre;
	int dni;
};

template <typename T> /// uso de template

///int mayor(int x, int y){ /// si no estuviera "templatizado" seria asi
T mayor(T x, T y){ /// es exactamente igual a una funcion pero genrica
	
	if (x.dni > y.dni) return x;
	return y;
}


///template <typenane T> /// formas alternativas
///template <typenane T>
///template <typenane C>
///template <class T>



int main() {
	
	Persona p1, p2;
	p1.dni = 44;
	p2.dni = 33;
	
	//Persona p3 = mayor(p1,p2);
	//cout<< p3.dni <<endl; /// para usar el template necesitamos definir el tipo de la variable al llamarlo
	cout<< mayor(p1,p2).dni <<endl; /// para usar el template necesitamos definir el tipo de la variable al llamarlo
	
	
	
	return 0;
}

