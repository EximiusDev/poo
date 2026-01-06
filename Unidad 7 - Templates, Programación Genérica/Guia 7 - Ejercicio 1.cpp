#include <iostream>
#include <vector>
using namespace std;
/* Ejercicio 1
Implemente una función templatizada llamada Mayor(...) que reciba dos valores y
devuelva el mayor. Compruebe el correcto funcionamiento de la rutina probándola
desde un programa cliente con valores de tipo int, float y string.
a. Programe una sobrecarga de la función Mayor(...) que reciba un vector y
retorne el mayor elemento del mismo. Pruebe la función sobrecargada
desde un programa cliente con diversos tipos de datos.
b. Responda: ¿Servirán las funciones anteriores con datos del tipo mostrado
en el recuadro? Justifique su respuesta.

struct Persona{
string nombre;
string apellido;
int dni;
};
c. Implemente los cambios necesarios, utilizando su propio criterio, para que
las funciones desarrolladas funcionen con el tipo de dato del recuadro.
*/

/// b) no funcionas las clases creadas
/// c) 
struct Persona{
	string nombre;
	string apellido;
	int dni;
};

template<typename T> /// funcion con tipo de variables genericas 
// sino template<class T> // T es el nombre del tipo de variable generica
T Mayor(T x, T y){ /// los tipos de datos son genericos (T)
	if(x>y)return x;
	else return y;
}

/*
int Mayor(int x, int y){
	if(x>y)return x;
	else return y;
}*/
	
/// a)
template<typename T>
T Mayor(vector<T>v){
	T mayor = v[0];
	for(unsigned int i=0;i<v.size();i++) { 
		if(mayor< v[i]) mayor = v[i];
	}
	return mayor;
}
	/*
int Mayor(vector<int>v){
	int mayor = v[0];
	for(unsigned int i=0;i<v.size();i++) { 
		if(mayor< v[i]) mayor = v[i];
	}
	return mayor;
}*/

int main() {
	cout<<Mayor<int>(1,2.0)<<endl;
	cout<<Mayor<float>(4.7,7.5)<<endl; /// 4.6f /// la f lo toma como flotante, generalmente lo toma como double
	cout<<Mayor<string>("Juan","Aaron")<<endl;
	cout<<Mayor("X","E")<<endl;
	cout<<Mayor(2.2,1.1)<<endl;
	
	cout<<endl;
	cout<<endl;
	
	///a)
	
	vector<int> vect1(10);
	vector<float> vect2(10);
	
	for(unsigned int i=0;i<vect1.size();i++) { 
		vect1[i]= rand() % 100;
		vect2[i]= rand() % 100 +  rand() % 100/10.0;
		cout<<vect1[i]<<"  "<<vect2[i]<<endl;
	}
	cout<<endl;
	cout<<Mayor(vect1)<<"  "<<Mayor(vect2)<<endl;
	
	cout<<endl;
	cout<<endl;
	
	/// b) no andan las funciones
	/// c) 
	
	Persona P1 = {"juan","perez", 42000000}; 
	Persona P2 = {"Anita","Guerfanita", 44000000}; 
	
	
	return 0;
}

