/*Ejercicio 1
	Declare una variable entera estática y otra variable entera dinámica almacenando
	su dirección de memoria en un puntero. Asigne a la primera variable el valor 10 y a
	la segunda variable un valor ingresado por el usuario. Muestre luego las posiciones
	de memoria de ambas variables. Luego corra el programa varias veces y responda:
	¿las direcciones de las variables son siempre las mismas cada vez que el
	programa corre? IMPORTANTE: No olvide liberar la memoria de la segunda
	variable antes de salir.
*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int x;
	int *p=new int;
	x=10;
	cout<<"ingrese un valor:";
	cin>>*p;
	cout<<"direccion primer variable: "<< &x <<"      valor: "<<x<<endl;
	cout<<"direccion segunda variable: "<< p <<"      valor: "<<*p<<endl;
    delete p;
	return 0;
}

/*
  No siempre son las mismas direcciones
*/
