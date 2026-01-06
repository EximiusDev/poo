/*Ejercicio 4
Se tiene un arreglo dinámico de n enteros, y se quiere aumentar su tamaño a un
nuevo tamaño c. Implemente una función redimensionar() que reserve
dinámicamente memoria para un nuevo arreglo que contenga lugar suficiente para
guardar c datos (los n datos anteriores y los c-n nuevos). Copie en la nueva
memoria los datos del vector viejo e inicialice con ceros los nuevos elementos. La
memoria del primer arreglo debe ser liberada y el struct actualizado para que el
programa cliente pueda seguir operando con el nuevo arreglo. La función debería
poder invocarse de la siguiente manera:

vector_int_dinamico arreglo; (Teoría Pág. 10)
...
redimensionar( arreglo, c );

Finalmente, implemente un programa cliente que muestre el arreglo resultante.
*/


#include <iostream>
using namespace std;

struct vector_int_dinamico {
	int *p;
	int size;
};

void redimensionar( vector_int_dinamico & , int );

int main() {
	
	vector_int_dinamico arreglo; 
	arreglo.size = 10;
	cout<<arreglo.size<<endl;
	///cin>>arreglo.size;
	
	arreglo.p = new int[arreglo.size];
	
	for(int i=0;i<arreglo.size;i++) {
		*(arreglo.p + i) = rand()% 101 + 1000;
		cout<<(arreglo.p + i)<<" : "<<*(arreglo.p + i)<<endl;
	}
	cout<<endl;
	
	int c = 12;
	///redimensionar( arreglo, c );
	redimensionar( arreglo, c );
	
	return 0;
}

void redimensionar( vector_int_dinamico & arreglo, int c){
	/*
	int *v = new int [arreglo.size];
	
	for(int i=0;i<arreglo.size;i++) { 
		//(v+i) = (arreglo.p + i); ///NO FUNCIONA, porque asigno i punteros cuando hay uno solo
	}
	
	v = arreglo.p;
	for(int i=0;i<arreglo.size;i++) { 
		cout<<(v + i)<<" : "<<*(v + i)<<endl;
	}
	*/
	
	vector_int_dinamico ar = arreglo;
	ar.size = c;
	for(int i=0;i<ar.size;i++) { 
		if ( (c - arreglo.size) > (arreglo.size - i +1)){
			*(ar.p + i) = 0;
		}
		cout<<(ar.p + i)<<" : "<<*(ar.p + i)<<endl;
	}
	
	
}
