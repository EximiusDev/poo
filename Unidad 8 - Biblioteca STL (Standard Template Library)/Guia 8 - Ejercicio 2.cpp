#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Ejercicio 8.2
Escriba un programa que defina un vector dinámico de 30 enteros aleatorios
menores que 25. Luego:
a. Ordene en forma descendente los elementos ubicados entre las posiciones
10 y 20 inclusive, y muestre el vector.
b. Inserte en un nuevo vector los elementos que fueron ordenados en el
apartado anterior, y quítelos del vector original.
c. Permita ingresar un valor por teclado, y muestre cuántas veces aparece
dicho valor en el vector.
d. Elimine todas las ocurrencias del valor ingresado en el punto c, utilizando la
función remove. Responda: ¿Pueden las funciones globales de la STL
eliminar realmente los elementos (liberando la memoria de un contenedor)?
*/

int Val_Aleatorios(){
	return rand()%25;
}

int main() {
	int n = 10; /// n = 30;
	
	int pos1 = 5; //pos1 = 10;
	int pos2 = 8; //pos1 = 20;
	
	vector<int> v(n );
	generate(v.begin(),v.end(),Val_Aleatorios);
	for(int x:v){
		cout<<x<<endl;
	}
	
	
	sort(v.begin()+pos1, v.begin()+pos2);
	cout<<endl;
	for(int x:v){
		cout<<x<<"  ";
	}
	reverse(v.begin()+ pos1, v.begin()+ pos2);
	
	cout<<endl;
	for(int x:v){
		cout<<x<<"  ";
	}
	
	cout<<endl;
	
	return 0;
}

