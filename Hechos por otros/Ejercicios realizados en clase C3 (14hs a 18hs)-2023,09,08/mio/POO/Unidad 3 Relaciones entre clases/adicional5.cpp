#include <iostream>
#include <vector>
using namespace std;

class Cuerpo{
protected:
	float a,b,vol;
	string tipo;
public:
	Cuerpo(float xa,float xb):a(xa),b(xb){}
	virtual void  CalcularVolumen()=0;
	float VerVol(){return vol;}
	virtual ~Cuerpo(){}
};

class PrismaRect:public Cuerpo{
	float l2;
public:
	PrismaRect(float xa,float xb, float xc): Cuerpo(xa,xb),l2(xc){}
	void  CalcularVolumen(){vol=a*b*l2;}
};

class Cilindro:public Cuerpo{
public:
	Cilindro(float xa,float xb): Cuerpo(xa,xb){}
	void  CalcularVolumen(){vol=3.14*a*a*b;}
};


int main(int argc, char *argv[]) {
	vector <Cuerpo*> v;
	v.push_back(new PrismaRect(2,2,4));
	v.push_back(new Cilindro(10,4));
	v.push_back(new Cilindro(1,10));
	v.push_back(new PrismaRect(3,4,2));
	v.push_back(new PrismaRect(1,1,5));
	for(size_t i=0;i<v.size();i++) { 
		v[i]->CalcularVolumen();
		cout<<"volumen: "<< v[i]->VerVol() <<"\n";
	}
	
	for(Cuerpo *p: v)
		delete p;
		
	return 0;
}

