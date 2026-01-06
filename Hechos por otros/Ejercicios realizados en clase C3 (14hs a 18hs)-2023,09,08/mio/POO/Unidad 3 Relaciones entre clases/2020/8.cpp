#include <iostream>
using namespace std;

class Tanque{
protected:
	float peso,vol;
public:
	Tanque(){cout<<"crea tanque\n";}
	virtual void CalcularVolumen()=0;
	float VerPeso(){return peso;}
	float VerVolumen(){return vol;}
	virtual ~Tanque(){cout<<"destruyo tanque\n";}
};

class Cilindro:public Tanque{
	float altura,radio;
public:
	Cilindro(float alt,float rad, float pe):altura(alt),radio(rad){peso=pe;cout<<"crea cilindro\n";}
	void CalcularVolumen(){vol=3.14*radio*radio*altura;}
	~Cilindro(){cout<<"destruyo cilindro\n";}
	
};

class Esfera:public Tanque{
	float radio;
public:
	Esfera(float rad, float pe):radio(rad){peso=pe;cout<<"crea esfera\n";}
	void CalcularVolumen(){vol=(3/4.0)*3.14*radio*radio*radio;}
	~Esfera(){cout<<"destruyo esfera\n";}
	
};

int main(int argc, char *argv[]) {
	//nota: LOS MENSAJES EN DESTRUCTURORES Y CONSTRUCTORES SON SIMPLEMENTE PARA 
	// VER QUE Y EN QUE ORDEN SE CONSTRUYEN Y DESTRUYEN LOS OBJETOS
	Tanque *pt;
	pt=new Cilindro(10,1,100);
	pt->CalcularVolumen();
	cout<<"volumen:"<<pt->VerVolumen()<<endl;
	cout<<"peso:"<<pt->VerPeso()<<endl;
	delete pt;
	
	cout<<endl;
	pt=new Esfera(10,100);
	pt->CalcularVolumen();
	cout<<"volumen:"<<pt->VerVolumen()<<endl;
	cout<<"peso:"<<pt->VerPeso()<<endl;
	delete pt;

	return 0;
	
}

