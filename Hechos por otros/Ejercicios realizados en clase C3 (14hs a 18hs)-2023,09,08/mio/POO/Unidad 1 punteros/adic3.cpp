/*
Ejercicio Adicional 3
Implemente un programa cliente para la función del ejercicio anterior que elimine
de un arreglo todos sus elementos repetidos. No es necesario conservar el orden
en los elementos, por lo que puede eliminar un elemento simplemente
intercambiandolo con el último y reduciendo el tamaño del arreglo.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void eliminarepetidos (int *x, int &y){
	int a;
	for(int i=0;i<y-1;i++) {
		a=*(x+i);
		for (int j=i+1;j<y;j++){
			if (a==*(x+j)){
				*(x+j)=*(x+y-1);
				y--;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int *p=new int[10];
	int t=10;
	srand(time(0));
	for(int i=0;i<t;i++) {
		*(p+i)=rand()%10;
		cout<<(p+i)<<":  "<<*(p+i)<<endl;
	}
	eliminarepetidos(p,t);
	cout<<"\n\nLista final sin repetidos\n";
	for(int i=0;i<t;i++) {
		cout<<(p+i)<<":  "<<*(p+i)<<endl;
	}
	delete[]p;
	return 0;
}

