#include <iostream>
using namespace std;

class clase{
public:
	clase(){cout<<"crea objeto\n";}
	~clase(){cout<<"destruye objeto\n";}
};


int main(int argc, char *argv[]) {
	clase *p;         // declaro un puntero de tipo clase
	p=new clase[10];  //creo 10 objetos dinamicamente
	delete []p;       //destruyo los 10 objetos
	clase a;          //creo un objeto estatico
	return 0;
}

