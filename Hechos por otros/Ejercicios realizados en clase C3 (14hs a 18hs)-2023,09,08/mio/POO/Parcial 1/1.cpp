#include <iostream>
#include <iomanip>
using namespace std;

tuple<int*, int>ordenado(int *inicio, int *ultimo){
	int contador=0;
	int *aux=new int [ultimo-inicio];
	
	*(aux)=*(inicio);
	contador++;
	
	for(int i=1; i<ultimo-inicio;i++){
		if(*(inicio+i)>*(aux+i-1)) {
			*(aux+i)=*(inicio+i);
			contador++;
		}
		else break;
	}
	int *resultado= new int[contador];
	for(int i=0; i<contador;i++){
		*(resultado+i)=*(aux+i);
	}
	delete []aux;
	return make_tuple(resultado, contador);
	
}

int main() {
	cout<<"Tamaño arreglo: ";
	int tamanio;
	cin>>tamanio;
	int *arreglo=new int[tamanio];
	for(int i=0;i<tamanio;++i){
		cout<<"arreglo["<<i<<"]: "; cin>>*(arreglo+i);
	}
	int *arreglo_ordenado; int tamanio_ordenado;
	tie(arreglo_ordenado, tamanio_ordenado)= ordenado(arreglo, arreglo+tamanio);
	cout<<endl<<"Arreglo ordenado: ";
	for (int i=0; i<tamanio_ordenado;++i){
		cout<<*(arreglo_ordenado+i)<<" ";
	}
	
	delete []arreglo;
	delete []arreglo_ordenado;
	
	return 0;
}

