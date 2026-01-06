// Diseñe una clase para representar un polinomio e implemente una sobrecarga
// para el operador - para restar dos polinomios

#include <iostream>
using namespace std;

class Polinomio {
	int grado;
	float *coef;
public:
	Polinomio (int grado, float coef[]) {
		this->grado=grado;
		this->coef=new float[grado+1];
		for (int i=0;i<=grado;i++) {
			this->coef[i] = coef[i];
		}
	}
	Polinomio (int grado) {
		this->grado=grado;
		this->coef=new float[grado+1];
	}
	Polinomio(const Polinomio &p) {
		grado=p.grado;
		coef=new float[p.grado+1];
		for(int i=0;i<=p.grado;i++)
			coef[i]=p.coef[i];
	}
	void CargarCoef(int i, float c) {
		coef[i]=c;
	}
	
	int VerGrado() { return grado; }
	float VerCoef(int i) { 
		if (i>grado) return 0;
		return coef[i];
	}
	Polinomio operator-(Polinomio p2) {
		int M=p2.grado>this->grado ? p2.grado :  this->grado;
		Polinomio resultado( M );
		for (int i=0;i<=M;i++) {
			resultado.coef[i]=this->VerCoef(i)-p2.VerCoef(i);
		}
		return resultado;
	}
	~Polinomio() { delete [] coef; }
	
};

ostream &operator<<(ostream &o, Polinomio &p) {
	o<<p.VerCoef(0);
	for(int i=0;i<=p.VerGrado();i++) {
		o<<"+"<<p.VerCoef(i)<<"*x^"<<i;
	}
	return o;
}

int main() {
	
	float c[3]={3,5,7};
	Polinomio  p(2,c);
	
	Polinomio p2(3);
	p2.CargarCoef(0,1);
	p2.CargarCoef(1,-3);
	p2.CargarCoef(2,2);
	p2.CargarCoef(3,9);
	
	Polinomio p3 ( p2-p );
	
	cout<<"p: "<<p<<endl;
	cout<<"p2: "<<p2<<endl;
	cout<<"p3: "<<p3<<endl;
	

}
