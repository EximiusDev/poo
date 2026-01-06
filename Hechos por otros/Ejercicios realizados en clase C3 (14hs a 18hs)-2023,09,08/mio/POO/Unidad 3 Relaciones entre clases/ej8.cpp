#include <iostream>
#include <vector>
using namespace std;

class Tanque{
protected:
	float peso, vol;
public:
	virtual void CalcularVolumen()=0;
	float VerVolumen(){return vol;}
	float VerPeso(){return peso;}
	virtual ~Tanque(){}
	
};

class Cilindro:public Tanque{
	float radio,altura;
public:
	Cilindro(float r, float h, float pe){
		radio=r; altura=h; peso=pe;
	}
	void CalcularVolumen(){vol=radio*radio*3.14*altura;}
};


class Esfera:public Tanque{
	float radio;
public:
	Esfera(float r, float pe){
		radio=r; peso=pe;
	}
	void CalcularVolumen(){vol=4.0/3.0*3.14*radio*radio*radio;}
};

int main(int argc, char *argv[]) {
    Tanque *p;
	p=new Cilindro(2,10,56);
	p->CalcularVolumen();
	
	cout<<"Tanque Cilindro:  \nVolumen: "<<p->VerVolumen()
		<<"    pesa: "<<p->VerPeso()<<endl;
	delete p;
	
	p=new Esfera(2,80);
	p->CalcularVolumen();
	cout<<"\nTanque Esfera:  \nVolumen: "<<p->VerVolumen()
		<<"    pesa: "<<p->VerPeso()<<endl;
	delete p;
	
	
	//
	//tambien podriamos tener un vector de tanques de tipo cilindro y tipo esfera y  luego recorrerlo y obtener sus volumenes
	/*
	vector<Tanque *>p;
	p.push_back(new Cilindro(1,2,2000));
	p.push_back(new Cilindro(54,2,2000));
	p.push_back(new Cilindro(5,32,2000));
	p.push_back(new Cilindro(12,32,2000));
	p.push_back(new Esfera(21,2000));
	p.push_back(new Cilindro(21,542,2000));
	p.push_back(new Esfera(22,2000));
	p.push_back(new Cilindro(21,542,2000));
	p.push_back(new Esfera(242,2000));
	p.push_back(new Cilindro(21,542,2000));
	
	for(size_t i=0;i<p.size();i++) { 
		p[i]->CalcularVolumen();
		cout<< p[i]->VerVolumen()<<endl;
	}
	
	for(size_t i=0;i<p.size();i++) 
		delete p[i];
		
	*/
	return 0;
}

