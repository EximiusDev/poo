#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	short  x=99;
	short *p=&x;
	short &alias=x;
	cout<<"valor de x: "<<x<<endl;
	cout<<"direccion de p: "<<p<<"   tamaño de p: "<<sizeof(p)<<endl;
	cout<<"valor apuntado por p: "<<*p<<"  tamaño de lo apuntado por p"<<sizeof(*p)<<endl;
	cout<<"valor del alias: "<<alias<<"   direccion de alias:"<<&alias<<"      direccion de x:"<<&x<<endl;
	
	p=nullptr;
	cout<<"direccion de p: "<<p<<endl;
	
	return 0;
}

