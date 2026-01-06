#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* buscar_direccion(int *&ar_d, int n, int bus){
	for(int i=0;i<n;i++) { 
		if(bus == *(ar_d + i)) return (ar_d + i);
	}
	return nullptr;
}

int main() {
	
	/* /// /////////////// Arreglo estatico
	int Arreglo[5]; 
	for(int i=0;i<5;i++) { 
		Arreglo[i] = rand()%10;
		cout<<i<<" "<<Arreglo[i]<<endl;
	}
	*/
	int n = 5;
	
	srand(time(0));
	
	int * Arreglo_Dinamico = new int [n];
	
	for(int i=0;i<n;i++) { 
		*(Arreglo_Dinamico+i) = rand()%10;
		cout<<(Arreglo_Dinamico+i)<<": "<<*(Arreglo_Dinamico+i)<<endl;
	}
	
	int buscado;
	cin>>buscado;
	
	int *d;
	d = buscar_direccion(Arreglo_Dinamico, n, buscado);
	
	if(d != nullptr) cout<<"ENCONTRADO:"<<&d<<" "<<d<<": "<<*d;
	else cout<<"NO ENCONTRADO"<<endl; ///cout<<"ENCONTRADO:"<<&d<<" "<<d<<": "<<*d;
	
	delete []Arreglo_Dinamico;
	return 0;
}

