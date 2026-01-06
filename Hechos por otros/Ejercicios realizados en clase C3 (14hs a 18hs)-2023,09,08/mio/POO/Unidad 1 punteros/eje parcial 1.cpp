/*Ej 2 (pts) a) Escriba una función que reciba tres punteros, uno apuntando al comienzo de un arreglo, otro
apuntando a un elemento del arreglo (que puede ser cualquiera) y otro apuntando al final del arreglo (la
dirección justo después del último elemento). La función debe generar un nuevo arreglo donde los elementos
que estaban en el arreglo original después del señalado por el 2do puntero ahora estén antes; y los que
estaban antes en el nuevo arreglo estén después. Por ejemplo, si el arreglo inicial es {1,2,3,4,5,6,7,8} y el 2do
puntero apunta al 3, entonces el nuevo arreglo deberá ser {4,5,6,7,8,3,1,2}. Notar que la cantidad de
elementos antes y después puede no ser igual.
b) Escriba un programa cliente que le permita al usuario ingresar un arreglo (el usuario indica el tamaño y los
valores), y luego elegir un elemento para probar la función (un elemento o una posición para usar como 2do
argumento). El programa debe mostrar luego de invocar a la función ambos arreglos.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int* modifica(int *pi, int *pelem, int *pf){
	int *aux=new int [pf-pi];
	int j=0;
	for(int i=pelem-pi+1;i<pf-pi;i++) {
		aux[j]=*(pi+i);	
		j++;
	}
	aux[j]=*pelem;
	j++;
	for(int i=0;i<pelem-pi;i++) {
		aux[j]=*(pi+i);	
		j++;
	
	}
	delete []pi;
	return aux;
}

int main(int argc, char *argv[]) {
	int N;
	cin>>N;
	int*v=new int [N]	;
	srand(time(0));
	for(int i=0;i<N;i++) { 
		*(v+i)=rand()%100;
		cout<<*(v+i)<<"  ";
	}
	cout<<endl<<endl;
	int pos;
	cout<<"posicion: "; cin>>pos;
	v=modifica(v,v+pos,v+N);
	for(int i=0;i<N;i++) { 
		cout<<*(v+i)<<"  ";
	}
	delete[]v;
	return 0;
}

