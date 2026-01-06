/*
Modifique el ejercicio anterior de manera que sea posible reservar memoria para
una matriz de tamaño arbitrario (tanto para filas como columnas) mediante un
arreglo de punteros. Responda: ¿se almacenan los datos en memoria de la misma
forma que en una matriz convencional?
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int i,j,f,filas,columnas;
	double suma;
	cout<<"ingrese las filas: ";
	cin>>filas;
	cout<<"ingrese las columnas: ";
	cin>>columnas;
	
	double  **m=new double * [filas]; 
	for(i=0;i<filas;i++) { 
		*(m+i)=new double [columnas];
	}
	
	srand(time(0));
	for(i=0;i<filas;i++) 
		for(j=0;j<columnas;j++) 
			//*(*(m+i)+j)=rand()%90+10 + (rand()%90+10)/100.0;
		*(*(m+i)+j)=rand()%10;
	
	for(i=0;i<filas;i++){ 
		for(j=0;j<columnas;j++) 
	    	cout<<setw(8)<< *(*(m+i)+j);
		cout<<endl;
	}
	cout<<"\nIngrese fila (comenzando de 0):";
	cin>>f;
	suma=0;
	for(int i=0;i<columnas;i++) { 
		suma+=*(*(m+f)+i);
	}
	cout<<"Promedio: "<<suma/columnas;
		
	cout<<"\n\nSuma de columnas:\n";
	for(i=0;i<columnas;i++) { 
		suma=0;
		for(j=0;j<filas;j++) { 
			suma+=*(*(m+j)+i);
		}
		cout<<"total columna "<<i<<" = "<<suma<<endl;
	}
	for(i=0;i<filas;i++) { 
		delete [](m+i);
	}
	delete []m;
	return 0;
}

//no, se almacena en forma contigua solamente cada vector para cada fila  
