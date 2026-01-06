#include <iostream>
using namespace std;
class Tanque{
	float peso;
public:
	Tanque (int p):peso(p){};
	virtual float CalcularVolumen()=0;
	float VerPeso(){return peso;}
	virtual ~Tanque(){}
};

class Cilindro:public Tanque{
	float radio, altura;
public:
	Cilindro(float r, float a,float p):Tanque(p), radio(r),altura(a){}
	float CalcularVolumen() {return 3.14*radio*radio*altura;}
	virtual ~Cilindro(){}
};

class Esfera:public Tanque{
	float radio;
public:
	Esfera(float r, float p):Tanque(p), radio(r){}
	float CalcularVolumen() {return (4/3.0)*3.14*radio*radio*radio;}
	virtual ~Esfera(){}
};

int main(int argc, char *argv[]) {
	Tanque *pT;
	
	pT=new Cilindro(2,10,56);
	cout<<"Tanque Cilindro:  \nVolumen: "<<pT->CalcularVolumen()
		<<"    pesa: "<<pT->VerPeso()<<endl;
	delete pT;
	
	pT=new Esfera(2,80);
	cout<<"\nTanque Esfera:  \nVolumen: "<<pT->CalcularVolumen()
		<<"    pesa: "<<pT->VerPeso()<<endl;
	delete pT;
	
	return 0;
}

