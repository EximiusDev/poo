/*
Ejercicio 1
	Realice una función llamada intercala(...) que recibe como parámetros 2 punteros a vectores de enteros La función debe
	devolver un nuevo vector con los elementos intercalados de los vectores pasados como parámetro 
(por ejemplo si a=[2,4,5,1,6,3] y b=[10,20] se deberá obtener [2,10,4,20,5,1,6,3]. Utilice la función en un programa cliente. 
NOTAS: No usar la clase vector. Usar solo notación de punteros (no usar operador [ ]).
*/
#include <iostream>
using namespace std;

int * Intercala(int *v1,int *v2, int n1, int n2){
	int n = n1+ n2;
	int * aux = new int [n];
	int x=0;
	int y=0;
	for(int i=0;i<n;i++) { 
		
		if((i%2)==0){
			//cout<<i<<"Par"<<endl;
			if(n1>x){
				*(aux + i) = *(v1 + x);
				x++;
			}
			else{
				*(aux + i) = *(v2 + y);
				y++;
			}
		}
		else{
			//cout<<i<<"Impar"<<endl;
			if(n2>y){
				*(aux + i) = *(v2 + y);
			y++;
			}
			else{
				*(aux + i) = *(v1 + x);
				x++;
			}
			
		}
	}
	return aux;
}

int main() {
	int n1=3;
	int n2=8;
	cin>>n1>>n2;
	
	int *v1 = new int [n1];
	int *v2 = new int [n2];
	
	for(int i=0;i<n1;i++) { 
		*(v1+i) = rand()%100+1000;
		cout<<i<<". "<<*(v1+i)<<endl;
	}
	cout<<endl;
	for(int i=0;i<n2;i++) { 
		*(v2+i) = rand()%100;
		cout<<i<<". "<<*(v2+i)<<endl;
	}
	cout<<endl;
	cout<<endl;
	int n = n1+n2;
	int *v = Intercala( v1, v2,  n1,  n2);
	
	for(int i=0;i<n;i++) { 
		cout<<i<<". "<<*(v+i)<<endl;
	}
	
	return 0;
}

