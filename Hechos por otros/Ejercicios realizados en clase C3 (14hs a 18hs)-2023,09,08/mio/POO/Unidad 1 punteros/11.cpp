#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	int i,j,f,filas, columnas;
	double suma;
	cout<<"ingrese las filas: ";
	cin>>filas;
	cout<<"ingrese las columnas: ";
	cin>>columnas;
	double **m= new double*[filas];        //declaro un arreglo de punteros double 
	for(i=0;i<filas;i++){
		*(m+i)= new double[columnas];
	}
	srand(time(0));
	for(i=0;i<filas;i++) 
		for(j=0;j<columnas;j++) 
		   *(*(m+i)+j)=rand()%90+10 + (rand()%90+10)/100.0;
			//*(*(m+i)+j)=rand()%3;
	
	for(i=0;i<filas;i++){ 
		for(j=0;j<columnas;j++) 
			cout<<setw(8)<<*(*(m+i)+j);
		cout<<endl;
	}
	cout<<"\nIngrese fila (comenzando de 0):";
	cin>>f;
	suma=0;
	for(i=0;i<columnas;i++)
		suma+= *(*(m+f)+i);            //    suma = suma + m[f][i]
	cout<<"\npromedio= "<<suma/columnas;
	
	cout<<"\n\nSuma de columnas:\n";
	for(i=0;i<columnas;i++) { 
		suma=0;
		for(j=0;j<filas;j++)
			suma += *(*(m+j)+i);
		cout<<"Total columna "<<i<<" : "<<suma<<endl;
	}
	
	for(i=0;i<filas;i++){
		delete [](m+i);
	}
	delete []m;
	return 0;
}

