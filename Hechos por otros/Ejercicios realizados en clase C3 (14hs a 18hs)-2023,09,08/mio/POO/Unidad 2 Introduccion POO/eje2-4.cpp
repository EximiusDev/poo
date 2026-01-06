#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class VectorDinamico{
private:
	int *p;
	int size;
public:
	VectorDinamico(int x);
	~VectorDinamico(){size=1;delete[]p;}
	void Duplicar();
	int VerElemento(int x){return *(p+x);}
	int VerSize(){return size;}
};

VectorDinamico::VectorDinamico(int x){
	size=x;
	p=new int[size];
	srand(time(0));
	for(int i=0;i<size;i++)
		*(p+i)=rand()%90+10;
}
void VectorDinamico::Duplicar(){
	int *aux=new int[2*size];
	for(int i=0;i<size;i++) 
		*(aux+i)=*(p+i);
	for(int i=size;i<2*size;i++) 
		*(aux+i)=rand()%1000+1000;
	size=2*size;
	delete []p;
	p=aux;
}


int main(int argc, char *argv[]) {
	VectorDinamico v(5);
	cout<<"\nvector original, cantidad de elementos: "<<v.VerSize()<<endl;
	for(int i=0;i<v.VerSize();i++) { 
		cout<<"  "<<v.VerElemento(i);
	}
	v.Duplicar();
	cout<<"\n\nvector duplicado, cantidad de elementos: "<<v.VerSize()<<endl;
	for(int i=0;i<v.VerSize();i++) { 
		cout<<"  "<<v.VerElemento(i);
	}
	v.Duplicar();
	cout<<"\n\nvector duplicado, cantidad de elementos: "<<v.VerSize()<<endl;
	for(int i=0;i<v.VerSize();i++) { 
		cout<<"  "<<v.VerElemento(i);
	}
	
	return 0;
}

