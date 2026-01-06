/*
Ejercicio 6
Amplíe el programa anterior para que, luego de generar el arreglo aleatoriamente,
permita ingresar un valor M que debe ser insertado en la posición P de dicho
arreglo y muestre el vector modificado. Para la inserción, implemente una función
insertar() utilizando notación de punteros.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void insertar(int *x, int c, int vi,int po){
	for(int i=c-1;i>=po;i--)
		*(x+i+1)=*(x+i);
	*(x+po)=vi;
}

int main() {
    int N,i,valor, posicion;
	cout<<"Ingrese la cantidad de elementos: ";
	cin>>N;
	int *p=new int[N+1];    //porque voy a insertar uno mas
	srand(time(0));
	for(i=0;i<N;i++) {
		*(p+i)=rand()%501+1000;
		cout<<i<<") "<<(p+i)<<":  "<<*(p+i)<<endl;
	}
	cout<<"\nIngrese el valor a insertar y la posición: ";
	cin>>valor>>posicion;
	insertar(p,N,valor,posicion);
	cout<<"\nArreglo resultante:\n";
	for(i=0;i<N+1;i++) {
		cout<<i<<") "<<(p+i)<<":  "<<*(p+i)<<endl;
	}	
	delete []p;
	return 0;
}

