#include <iostream>
using namespace std;

void func(int *s, int *e, int *sum){
	(*sum)=0;
	for(int *p=s;p<e;p++) { 
		(*sum) += * p;
	}		
}

int main() {
	int x[6]={12,34,56,78,39,90};
	int suma;
	func(x, x+6, &suma);
	cout<<suma<<endl;	
	return 0;
}

/*
a. ¿Qué tipo de parámetros actuales se emplean para llamar a func()?
se emprean variables de tipo int, y una variable pasada como referencia

b. ¿Qué tipos de parámetros formales se definen en func()?.
Se definen punteros en func, para las variables y la referencia

c. ¿Qué tipo de información devuelve la función func()?.
no devuelve informacion, solo sobrescribe suma sumandole los valores de x
mediante un puntero (p) que tiene los valores de x

d. ¿Cuál es la salida que se obtiene en el programa propuesto?Se obtiene la misma suma que fue usada como puntero
y se les asignaron los valores de las posiciones de p 
(p incrementa de posicion por ser puntero)
hasta llegar a la posicion de e
*/
