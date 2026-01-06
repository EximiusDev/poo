/*
Ejercicio 10
Generar aleatoriamente una matriz de números reales de doble precisión de 10
filas por 6 columnas mediante un puntero a un arreglo. Usando notación de
punteros determine e informe: a) el promedio de la fila que el usuario ingrese como
dato; b) la suma de cada columna.
Analice: ¿sería posible, manteniendo la estructura de puntero a arreglo, que el
usuario ingresara el tamaño de la matriz (filas x columnas)
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int i,j,f;
	double suma;
	double  (*m)[6]=new double [10][6]; 
	
	srand(time(0));
	for(i=0;i<10;i++) 
		for(j=0;j<6;j++) 
			//*(*(m+i)+j)=rand()%90+10 + (rand()%90+10)/100.0;
		*(*(m+i)+j)=rand()%10;
	
	for(i=0;i<10;i++){ 
		for(j=0;j<6;j++) 
	    	cout<<setw(8)<< *(*(m+i)+j);
		cout<<endl;
	}
	cout<<"\nIngrese fila (comenzando de 0):";
	cin>>f;
	suma=0;
	for(int i=0;i<6;i++) { 
		suma+=*(*(m+f)+i);
	}
	cout<<"Promedio: "<<suma/6.0;
		
	cout<<"\n\nSuma de columnas:\n";
	for(int i=0;i<6;i++) { 
		suma=0;
		for(int j=0;j<10;j++) { 
			suma+=*(*(m+j)+i);
		}
		cout<<"total columna "<<i<<" = "<<suma<<endl;
	}
	delete []m;
	return 0;
}

