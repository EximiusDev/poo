#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class VectorDinamico{
	int *p;
	int size;
public:
	VectorDinamico(int x);
	VectorDinamico(VectorDinamico &x);
	
	~VectorDinamico(){delete[]p;}
	int VerSize(){return size;}
	int VerElemento(int x){return *(p+x);}
	void Duplicar();
};
VectorDinamico::VectorDinamico(int x){
	p = new int[x];
	size = x;
	srand(time(0));
	for(int i=0;i<size;i++)  
		*(p+i)= rand()%10;
}

VectorDinamico::VectorDinamico(VectorDinamico &x){
	p = new int[x.size];
	size = x.size;
	for(int i=0;i<x.size;i++) 
		p[i]=x.p[i];
}

void VectorDinamico::Duplicar(){
	int *aux = new int[size*2];
	for(int i=0;i<size;i++) 
		*(aux+i)=*(p+i);
	srand(time(0));
	for(int i=size;i<2*size;i++) 
		*(aux+i)=rand()%100+100;
	size=size*2;
	delete[]p;
	p=aux;
}

int main(int argc, char *argv[]) {
	VectorDinamico v(10);
	cout<<"\nvector original, cantidad de elementos: "<<v.VerSize()<<endl;
	for(int i=0;i<v.VerSize();i++) { 
		cout<<"  "<<v.VerElemento(i);
	}
	v.Duplicar();
	cout<<"\nvector duplicado, cantidad de elementos: "<<v.VerSize()<<endl;
	for(int i=0;i<v.VerSize();i++) { 
		cout<<"  "<<v.VerElemento(i);
	}
	
	VectorDinamico w(v);
	
	cout<<"\nvector w con constructor de copia, cantidad de elementos: "<<w.VerSize()<<endl;
	for(int i=0;i<w.VerSize();i++) { 
		cout<<"  "<< w.VerElemento(i);
	}
	
	
	
	
	
	return 0;
}

