/**
2017 - Parcial 2 - Tema A

Ejercicio 1 [25 pts] Escriba una función genérica para cualquier tipo de elemento
llamada vector_a_lista(...) que reciba un std::vector y retorne una std::list que 
contenga los elementos del vector de entrada, sin repetidos. Debe mantener el orden 
del vector. Escriba un programa cliente que genere un vector con 40 enteros aleatorios,
utilice la función para pasarlos a una lista, y muestre la lista en pantalla.
**/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template<typename T>
list<T> vector_a_lista(const vector<T> &v) {
	list<T> l;
	for(T x:v) {
		if (find(l.begin(),l.end(),x)==l.end())
			l.push_back(x);
	}
	return l;
}

int main() {
	vector<int> v(40);
	for (int &x : v) x = rand()%50;
	
	for (int x : v) cout << x << " ";
	cout << endl;
	
	list<int> l = vector_a_lista(v);
	
	for (int x : l) cout << x << " ";
	cout << endl;
}


