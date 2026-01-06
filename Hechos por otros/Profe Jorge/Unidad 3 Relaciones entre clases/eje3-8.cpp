#include <iostream>
using namespace std;
class Tanque{
protected:
	float vol,peso;
public:
	virtual void CalcularVolumen()=0;
	float VerPeso(){return peso;}
	float VerVolumen(){return vol;}
	virtual ~Tanque(){}
};

class Cilindro:public Tanque{
	float radio, altura;
public:
	Cilindro(float r, float a,float p):radio(r),altura(a){peso=p;}
	void CalcularVolumen() override {vol=3.14*radio*radio*altura;}
};

class Esfera:public Tanque{
	float radio;
public:
	Esfera(float r, float p):radio(r){peso=p;}
	void CalcularVolumen() override {vol=(4/3.0)*3.14*radio*radio*radio;}
};

int main(int argc, char *argv[]) {
	Tanque *pT;
	
	pT=new Cilindro(2,10,56);
	pT->CalcularVolumen();
	cout<<"Tanque Cilindro:  \nVolumen: "<<pT->VerVolumen()
		<<"    pesa: "<<pT->VerPeso()<<endl;
	delete pT;
	
	pT=new Esfera(2,80);
	pT->CalcularVolumen();
	cout<<"\nTanque Esfera:  \nVolumen: "<<pT->VerVolumen()
		<<"    pesa: "<<pT->VerPeso()<<endl;
	delete pT;
	
	return 0;
}

