#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void ver(int *x,int c){
	for(int i=0;i<c;i++) 
		cout<<*(x+i)<<"  ";
	cout<<endl;
}
	
void insertar(int *x, int c, int vi, int p){
	for(int i=c-1;i>=p;i--) 
		*(x+i+1) = *(x+i);       //    x[i+1]=x[i]
	*(x+p)=vi;
}



int main(int argc, char *argv[]) {
	int N,pi,vi;
	cout<<"ingrese cantidad de elementos: ";
	cin>>N;
	int *v=new int[N+1];
	srand(time(0));
	for(int i=0;i<N;i++) {
		*(v+i)=rand()%501+1000;       // rand()%(vfinal-vinicial+1) + vinicial  
	}
	ver(v,N);
	cout<<"ingrese posicion y valor a insertar: ";
	cin>>pi>>vi;
	insertar(v,N,vi,pi);
	cout<<"\nVector modificado: \n";
	ver(v,N+1);
	
	
	return 0;
}

