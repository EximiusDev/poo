#include <iostream>
using namespace std;



int main() {
	
	int a = 10;
	int *p;
	// p = new int;
	cin>>*p;
	cout<<*p+1<<endl;
	cout<<"Direccion de la variable A: "<<&a<<endl;
	cout<<"valor de variable A: "<<a<<endl;
	cout<<"\n\n";
	
	cout<<"Direccion del puntero(donde almaceno la otra direccion para la memoria dinamica): "<<&p<<endl;	cout<<"Direccion de variable a la que apunta el puntero: "<<p<<endl;
	cout<<"valor de variable a la que apunta el puntero: "<<*p<<endl;
	
	delete p;
	
	cout<<"\n Borro p: \n\n";
	cout<<"Direccion del puntero(donde almaceno la otra direccion para la memoria dinamica): "<<&p<<endl;
	cout<<"Direccion de variable a la que apunta el puntero: "<<p<<endl;
	cout<<"valor de variable a la que apunta el puntero: "<<*p<<endl;
	
	cout<<"\n Asigno A al puntero p: \n";
	p = &a;
	cout<<"Direccion del puntero(donde almaceno la otra direccion para la memoria dinamica): "<<&p<<endl;
	cout<<"Direccion de variable a la que apunta el puntero: "<<p<<endl;
	cout<<"valor de variable a la que apunta el puntero: "<<*p<<endl;
	
	///El puntero no se borra se borra la informacion a la que señala el puntero
	
	return 0;
}

