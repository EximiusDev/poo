#include <iostream>
using namespace std;

class MiClase{
private:
 	static int c;
public:
	MiClase(){c++; cout<<"se creó un objeto\n";}
	~MiClase(){c--; cout<<"se destruyó un objeto\n";}
	static int Cantidad(){return c;}
};

//inicializo el miembro static de la clase MiClase
int MiClase::c=0;  // no funciona si no se lo inicializa

int main(int argc, char *argv[]) {
	MiClase *p;
	p=new MiClase[10];
	cout<<"\ncantidad de objetos creados: "<<MiClase::Cantidad()<<endl<<endl;
	MiClase a,b,c;
	cout<<"\ncantidad de objetos creados: "<<MiClase::Cantidad()<<endl<<endl;
	delete []p;
	cout<<"\ncantidad de objetos creados: "<<MiClase::Cantidad()<<endl<<endl;
	return 0;
}

