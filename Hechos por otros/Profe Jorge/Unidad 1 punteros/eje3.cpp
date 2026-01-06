/*
A continuación se declara un arreglo a de 10 elementos enteros: int x[10]={110,
120, 130, 140, 150, 160, 170, 180, 190, 200};. El elemento inicial x[0] se ubica en la
dirección de memoria 0x00011E4. Determine lo que que representan las siguientes
expresiones:
a) x; c) (x+4); e) *x+3;
b) *x; d) *(x+4); f) (*x)+3;*/


#include <iostream>
using namespace std;

int main() {
	int x[10]={110,120, 130, 140, 150, 160, 170, 180, 190, 200};
	
	//suponiendo que comienza en 0x00011E4
	a) x;		// 0x00011E4
	b) *x; 		// 110
	c) (x+4);	// 0x00011F4
	d) *(x+4);	// 150
	e) *x+3;	// 113
	f) (*x)+3;	// 113	
	
	
	
	return 0;
}

