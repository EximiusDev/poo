/*
Ejercicio 8
Analice el código C++ del recuadro de abajo para responder lo siguiente:
a. ¿Qué tipo de parámetros actuales se emplean para llamar a func()?.
b. ¿Qué tipos de parámetros formales se definen en func()?.
c. ¿Qué tipo de información devuelve la función func()?.
d. ¿Cuál es la salida que se obtiene en el programa propuesto?
*/
#include <iostream>
using namespace std;
void func (int *s, int *e, int *sum){
	(*sum)=0;
	for(int*p=s; p<e;p++)
		(*sum)+=*p;
}
int main() {
	int x[6]={12,34,56,67,39,90};
	int suma;
	func(x,x+6,&suma);
	cout<<suma<<endl;
	return 0;
}

/*
a) el nombre del arreglo al primero y la direccion del siguiente del ultimo del arreglo, y la direccion de la variable suma
b) 3 punteros a enteros
c) el puntero a una posición de memoria entera 
d) la suma de los elementos de un arreglo


*/
