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
#include <ctime>
using namespace std;

struct vector_int_dinamico {
	int *p;
	int size;
};

void redimensionar( vector_int_dinamico & , int );

int main() {
	
	srand(time(0));
	
	vector_int_dinamico arreglo; 
	
	cout<<"Tamanio del arreglo inicial"<<endl;
	
	arreglo.size = 10;
	cout<<arreglo.size<<endl;
	cin>>arreglo.size;
	
	arreglo.p = new int[arreglo.size];
	
	cout<<"Muestro el arreglo incial"<<endl;
	
	for(int i=0;i<arreglo.size;i++) {
		*(arreglo.p + i) = rand()% 101 + 1000;
		cout<<i<<". "<<(arreglo.p + i)<<" : "<<*(arreglo.p + i)<<endl;
	}
	cout<<endl;
	
	cout<<"Tamanio a redimensionar"<<endl;
	
	int c = 8;
	c = 12;
	cin>>c;
	///redimensionar( arreglo, c );
	redimensionar( arreglo, c );
	
	cout<<"Muestro el arreglo final"<<endl;
	
	for(int i=0;i<arreglo.size;i++) { 
		cout<<i<<". "<<(arreglo.p + i)<<" : "<<*(arreglo.p + i)<<endl;
	}
	
	return 0;
}

void redimensionar( vector_int_dinamico & arreglo, int c){
	
	int *v = new int [c];  ///vector auxiliar
	//int tam = arreglo.size; /// tam es para pruebas de tamanio de los arreglos(v temportal y arreglo)
	
	for(int i=0;i<c;i++) { 
		if(i < arreglo.size){
			*(v+i) = *(arreglo.p + i); 
		}
		else {
			//tam = c;
		}
	}
	/// v = arreglo.p; // no es correcto: asigno el puntero a la posicion del arreglo
	
	cout<<"Muestro el vector temporal"<<endl;
	for(int i=arreglo.size;i<c;i++) { *(v + i) = 0; } // funciona solo cuando el es mas grande
	for(int i=0;i<c;i++) { // for(int i=0;tam<c;i++) {
		cout<<i<<". "<<(v + i)<<" : "<<*(v + i)<<endl;
	}
	cout<<endl;
	cout<<endl;
	
	delete []arreglo.p; ///Libero el espacio de memoria que no voy a usar
	arreglo.p = v;
	/// v = nullptr; // no hace falta porque desaparece despues de terminada la funcion
	arreglo.size = c;
	
	/*
	vector_int_dinamico ar;
	*ar = *arreglo;
	
	ar.size = c;
	for(int i=0;i<ar.size;i++) { 
		if ( (c - arreglo.size) > (arreglo.size - i +1)){
			*(ar.p + i) = 0;
		}
		cout<<(ar.p + i)<<" : "<<*(ar.p + i)<<endl;
	}
	// arreglo = ar;
	*/
	
}
