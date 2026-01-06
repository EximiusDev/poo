#include <iostream>
#include <ctime>
using namespace std;

void insertar(int* &v,int &n,int m,int p){
	if (p<n){
		*(v+p-1) = m;
	}
	else{ /// HACE UN ARREGLO NUEVO PARA METER UN VALOR EN UN NUEVO ESPACIO
		int * aux= new int [p];
			for(int i=0;i<n;i++) { 
				*(aux+i) = *(v+i);
			}
			for(int i=n;i<p;i++) {
				*(aux+i) = 0;
			}
			*(aux+p-1) = m;
		n=p;
		delete []v;
		v = aux;
	}
}

int main() {
	srand(time(0));
	
	int n = rand()%5 + 5;
	cout<<n<<endl;
	
	int* ar = new int [n];
	for(int i=0;i<n;i++) { 
		*(ar + i) = rand()%1000 + 100;
		cout<<i+1<<". "<<(ar + i)<<": "<<*(ar + i)<<endl;
	}
	
	int m;
	int p;
	cin>>m>>p;
	///if(n<p) cout<<"ERROR";
	
	insertar(ar,n,m,p);
	
	for(int i=0;i<n;i++) { 
		cout<<i+1<<". "<<(ar + i)<<": "<<*(ar + i)<<endl;
	}
	
	return 0;
}

