#include <iostream>
using namespace std;

/// SIN TERMINAR////////////////////////////////////////////////
/*
Ejercicio 7
Observe la porción de código C++ del recuadro y
determine la salida que se obtiene de los flujos de salida
cout propuestos. Considere que las variables se han
almacenado en memoria a partir de la dirección
0x000FF09 en forma contigua en el orden en que fueron
declaradas. Responda: ¿sería posible revisar si su
respuesta fue correcta compilando y ejecutando este
código? Justifique su respuesta
*/

int main() {
	
	int a=90; 
	int *p = &a;
	int b = (*p)++; // cout<<b<<endl;
	int *q = p+2;
	
	cout<<endl;
	
	cout<<p<<" "<<*p<<" "<<endl;
	cout<<q<<" "<<*q<<" "<<endl;
	
	cout<<endl;
	
	a = *(++q); // cout<<a<<endl;
	b = *(++p); // cout<<b<<endl;
	(*p)++;
	
	cout<<endl;
	
	cout<<p<<" "<<&p<<" "<<endl;
	cout<<q<<" "<<&q<<" "<<endl;
	
	return 0;
}

