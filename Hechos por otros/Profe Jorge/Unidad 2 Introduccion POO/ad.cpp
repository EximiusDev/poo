#include <iostream>
using namespace std;

/*
int && a;     
significa que "a" es una referencia de valor r.
&& normalmente solo se usa para declarar un parámetro de una función. 
Y solo se necesita una expresión de valor r.
	
En pocas palabras, un valor r es un valor que no tiene una dirección de memoria.
Por ejemplo, el número 6 y el carácter 'v' son valores r. 
int a, a es un valor l, sin embargo (a + 2) es un valor r.
*/


void foo(int&& a)
{
	//Some magical code...
}
int main()
{
	int b;
//	foo(b);       //Error. An rValue reference cannot be pointed to a lValue.
	foo(5);       //Compiles with no error.
	foo(b+3);     //Compiles with no error.
	//int&& c = b;  //Error. An rValue reference cannot be pointed to a lValue.
	int&& d = 5;  //Compiles with no error.
	
	cout<<d;
	return 0;
}

