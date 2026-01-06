#include <iostream>
using namespace std;

int * buscar(int *x, int c, int vb){
	for(int i=0;i<c;i++) { 
		if(*(x+i)==vb)
			return x+i;
	}
	return nullptr;
}

void ver(int *x,int c){
	for(int i=0;i<c;i++) 
		cout<<*(x+i)<<"  ";
	cout<<endl;
}
	

int main(int argc, char *argv[]) {
	int N;
	cout<<"ingrese cantidad de elementos: ";
	cin>>N;
	int *pv=new int[N];
	for(int i=0;i<N;i++) {
		cout<<"valor: ";
		cin>>*(pv+i);   //cin>>pv[i];
	}
	ver(pv,N);
	int valor;
	cout<<"ingrese valor a buscar:";
	cin>>valor;
	int *puntero = buscar(pv,N,valor);
	
	if(puntero != nullptr){
		cout<<"valor encontrado\n";
		cout<<"indice: "<<puntero-pv;
	}
	else{
	   cout<<"valor no encontrado\n";
	}
	
	delete []pv;
	
	return 0;
}

