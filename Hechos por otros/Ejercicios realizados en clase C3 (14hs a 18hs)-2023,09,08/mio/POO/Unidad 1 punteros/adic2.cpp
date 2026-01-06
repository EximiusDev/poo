/*
Ejercicio Adicional 2
Escriba una función que reciba un arreglo de enteros (y su tamaño), y busque
elementos repetidos dentro del mismo. La función debe retornar un struct con dos
punteros apuntando a dos elementos del arreglo que tengan el mismo valor. Si hay
más de dos elementos repetidos, la función puede retornar cualquier par de ellos.
Si no hay elementos repetidos, la función debe retornar NULL en ambos punteros.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct repe{
	int *punt1,*punt2;
};

repe repetidos (int *x, int y){
	repe z;
	z.punt1=nullptr;
	z.punt2=nullptr;
	int a;
	for(int i=0;i<y-1 && z.punt1==nullptr;i++) {
		a=*(x+i);
		for (int j=i+1;j<y;j++){
			if (a==*(x+j)){
				z.punt1=(x+i);
				z.punt2=(x+j);
				break;
			}
		}
	}
	return z;
}

int main(int argc, char *argv[]) {
	int *p=new int[10];
	repe r;
	srand(time(0));
	for(int i=0;i<10;i++) {
		*(p+i)=rand()%10;
		cout<<(p+i)<<":  "<<*(p+i)<<endl;
	}
	r=repetidos(p,10);
	cout<<"\n\nDirecciones de repetidos\n";
	cout<<r.punt1<<endl;
	cout<<r.punt2<<endl;
	delete []p;
	return 0;
}

