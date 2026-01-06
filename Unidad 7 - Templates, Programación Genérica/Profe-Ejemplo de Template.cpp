#include <iostream>
using namespace std;

template <typename T> /// uso de template
///int mayor(int x, int y){ /// si no estuviera "templatizado" seria asi
T mayor(T x, T y){ /// es exactamente igual a una funcion pero genrica
	if (x>y) return x;
	return y;
}

///template <typenane T> /// formas alternativas
///template <typenane H>
///template <typenane C>
///template <class T>



int main() {
	
	cout<< mayor<int>(5,9)<<endl; /// para usar el template necesitamos definir el tipo de la variable al llamarlo
	cout<< mayor<float>(3.4,6.5)<<endl; /// para usar el template necesitamos definir el tipo de la variable al llamarlo
	cout<< mayor<string>("carlitos", "lucia")<<endl; /// tambien se pueden comparar sin decir el tipo pasando directamente
	cout<< mayor("carlitos", "lucia")<<endl; /// no lo toma como tipo string
	cout<< mayor("carlitos"s, "lucia"s)<<endl; /// ahora si  lo toma como string
	cout<< mayor(4, 8)<<endl; /// tambien se pueden comparar sin decir el tipo pasando directamente, aunque puede no usar el tipo esperado
	cout<< mayor('A', 'b')<<endl; /// tambien se pueden comparar sin decir el tipo pasando directamente, aunque puede no usar el tipo esperado
	/// cout<< mayor(1, 2.1)<<endl; /// da error porque usa 2 tipos de variables distintos
	
	
	return 0;
}

