/*
Ejercicio 7
Se tiene un arreglo dinámico de n enteros, y se quiere insertar al final c ceros.
Implemente una función redimensionar() que reserve dinámicamente un nuevo
arreglo que contenga lugar para guardar los n datos anteriores y los c ceros que
serán insertados, luego copie en la nueva memoria los datos del vector viejo y
agregue los ceros al final. La memoria del primer arreglo debe ser liberada y la
dirección del arreglo nuevo será retornada para que el programa cliente actualice
su puntero. La función debería poder invocarse de la siguiente manera:
vector_int_dinamico arreglo; (Teoría Pág. 10)
...
arreglo = redimensionar( arreglo, c );
Finalmente, implemente un programa cliente que muestre el arreglo resultante.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct vector_int_dinamico {
	int *p;
	int size;
};

vector_int_dinamico redimensionar(vector_int_dinamico x, int ca){
	vector_int_dinamico aux;
	aux.size=x.size+ca;
	aux.p=new int[aux.size];
	for(int i=0;i<x.size;i++) { 
		*(aux.p+i)=*(x.p+i);
	}
	for(int i=x.size;i<aux.size;i++) { 
		*(aux.p+i)=0;
	}
	delete []x.p;
	return aux;
}
	
vector_int_dinamico redimensionar2(vector_int_dinamico x, int ca){
		int *paux=new int[x.size+ca];
		for(int i=0;i<x.size;i++) { 
			*(paux+i)=*(x.p+i);
		}
		for(int i=x.size;i<x.size+ca;i++) { 
			*(paux+i)=0;
		}
		delete []x.p;
		x.size = x.size+ca;
		x.p=paux;
		return x;
	}

int main() {
	vector_int_dinamico arreglo;
	int n,c;
	cout<<"ingrese cantidad de elementos: ";
	cin>>n;
	arreglo.size = n;
	arreglo.p = new int[arreglo.size];
	srand(time(0));
	cout<<"Arreglo original\n";
	for(int i=0;i<arreglo.size;i++) { 
		*(arreglo.p+i)=rand()%90+10;
		cout<<setw(4)<<*(arreglo.p+i);
	}
	cout<<"\n\n";
	cout<<"ingrese cantidad de 0 a agregar: ";
	cin>>c;
	
	
	arreglo = redimensionar2( arreglo, c );
	cout<<"\nNuevo arreglo:\n";
	for(int i=0;i<arreglo.size;i++) { 
		cout<<setw(4)<<*(arreglo.p+i);
	}
	cout<<"\nCantidad de elementos: "<<arreglo.size;
	
	delete []arreglo.p;
	return 0;
}

