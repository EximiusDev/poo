/*Ejercicio 3
Escriba una función que utilice punteros para buscar y retornar la dirección de un
entero dentro de un arreglo. Se pasan como parámetros el arreglo, su tamaño y el
entero a buscar. Si el dato no se encuentra, debe retornar la dirección de memoria
nula (nullptr). ¿Desde un programa cliente, cómo se obtiene el índice del elemento
encontrado cuando la función no devuelve nullptr?
*/
#include <iostream>
using namespace std;

int *buscar(int* , int , int );

int main() {
	int n;
	cin>>n;
	int *arDim = new int[n]; //creo un arreglo dinamico ("vector" hecho con un puntero)
	for(int i=0;i<n;i++) { 
		*(arDim+i) = rand() %501 +1000;
		cout<<i<<"  1"<<(arDim+i)<<": "<<*(arDim+i)<<endl;
	}
	int buscado;
	cin>>buscado;
	/*
	/// arDim, n buscado;
	for(int i=0;i<n;i++) { 
		if(*arDim == buscado){
			///return arDim;
		}
	}
	// no lo encontro
	///return nullptr;
	*/
	int *val; // no hacer falta poner: = new int;
	// la variable no necesita destruirse porque no uso espacio de memoria porque es una variable estatica
	val = buscar(arDim, n, buscado);
	
	if(val != nullptr){
		cout<<val<<" "<<*val<<" indice "<<val-arDim<<endl; /// val - arDim, me da como resultado el numero de datos (de la resta val - arDim)
	}
	else{
		cout<<"Valor no encontrado";		
	}
	
	
	delete []arDim;
	return 0;
}



int *buscar(int *v, int n, int valor){
	
	for(int i=0;i<n;i++) { 
		if(*(v+i) == valor){
			return (v+i); // lo encontro
		}
	}
	// no lo encontro
	return nullptr;
}
