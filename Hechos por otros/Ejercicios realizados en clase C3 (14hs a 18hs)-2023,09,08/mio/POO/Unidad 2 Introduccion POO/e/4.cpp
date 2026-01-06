#include <iostream>
using namespace std;
class VectorDinamico{
private:
	int *p;
	int cant;
public:
	VectorDinamico(VectorDinamico &x); 	//constructor de copia
	VectorDinamico(int x);	//constructor 
	int VerElemento(int x){return p[x];}
	int VerCantidad(){return cant;}
	void CargarElemento(int i, int x){p[i]=x;}
	void Duplicar();
	~VectorDinamico(){cant=0; delete []p;} //destructor
};

VectorDinamico::VectorDinamico(VectorDinamico &x){
	cant=x.cant;
	p=new int [cant];
	for(int i=0;i<cant;i++)
		p[i]=x.p[i];
}

VectorDinamico::VectorDinamico(int x){
	cant=x;
	p=new int[x];
	for(int i=0;i<x;i++) 
		*(p+i)=0;
}

void VectorDinamico::Duplicar(){
	int *aux=new int[2*cant];
	for(int i=0;i<cant;i++) 
		*(aux+i)=*(p+i);
	for(int i=cant;i<cant*2;i++) 
		*(aux+i)=0;
	cant=cant*2;
	delete []p;
	p=aux;	
}



int main(int argc, char *argv[]) {
	VectorDinamico v(10);
	v.CargarElemento(0,61);
	v.CargarElemento(1,52);
	v.CargarElemento(2,43);
	v.CargarElemento(3,34);
	v.CargarElemento(4,5);

	VectorDinamico h(v);
	
	v.CargarElemento(2,9999);  //modifico diferentes elementos para demostrar que estan en distintas direcciones
	h.CargarElemento(6,5555);
	
	cout<<"vector v: \n"; 
		for(int i=0;i<v.VerCantidad();i++) 
		cout<<v.VerElemento(i)<<"   ";
	cout<<"\n\n";
	
	cout<<"vector h: \n"; 
	for(int i=0;i<h.VerCantidad();i++) 
		cout<<h.VerElemento(i)<<"   ";
	cout<<"\n\n";
	
	v.Duplicar();
	cout<<"vector v duplicado el tamaño: \n"; 
	for(int i=0;i<v.VerCantidad();i++) 
		cout<<v.VerElemento(i)<<"   ";
	cout<<"\n\n";
	
	
	
	
	return 0;
}

