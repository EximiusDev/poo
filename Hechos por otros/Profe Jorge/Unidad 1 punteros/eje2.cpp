/*
Explique el significado de las siguientes expresiones de código C++.
a) int a = 25; d) double (*v2)[20];
b) int *k = &a; e) float f(int *a, int *b);
c) double *v1[30]; f) float (*pf)(int *a, int *b);
*/
#include <iostream>
using namespace std;

int main() {
	int a = 25;      			// declara variable entera y le asigna un valor
	int *k = &a;				// declara un puntero y lo inicializa cor la dirección de la variable a
	double *v1[30];				// declara un arreglo de 30 punteros
	double (*v2)[20];			// declara un arreglo bidimensional de 20 columnas
	float f(int *a, int *b);	// funcion float con 2 punteros como parametros
	float (*pf)(int *a, int *b);// declaracion de puntero a una funcion float que tiente 2 punteros como parametros
	return 0;
}




/*  //  puntero a funcion
int multip(int x,int y){
  return y*x;
}
int main(){
	int (*pf)(int,int)= & multip;
	cout<< pf(5,7);
	
	return 0;
}

*/
