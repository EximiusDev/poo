#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Pizza {
	string m_tipo;
public:
	Pizza(string tipo) : m_tipo(tipo) { }
	string VerTipo() { return m_tipo; }
	float VerT() {
		if (m_tipo=="chocolate") return 1.8;
		if (m_tipo=="palmitos") return 1.45;
		return 1.0;
	}
	virtual float CalcCosto(float dolar) = 0;
	virtual ~Pizza() { }
};

class PizzaRectangular : public Pizza {
	float m_ancho, m_alto;
public:
	PizzaRectangular(string tipo, float ancho, float alto) 
		: Pizza(tipo), m_ancho(ancho), m_alto(alto) { }
	float CalcCosto(float dolar) override { return VerT()*dolar*m_ancho*m_alto/16;  }
};

class PizzaRedonda : public Pizza {
	float m_radio;
public:
	PizzaRedonda(string tipo, float radio) 
		: Pizza(tipo), m_radio(radio) { }
	float CalcCosto(float dolar) override {
		return VerT()*dolar*M_PI*m_radio*m_radio/20; 
	}
};

float CostoPedido(vector<Pizza*> &v, float dolar) {
	float total = 0;
	for(Pizza *p : v)
		total += p->CalcCosto(dolar);
	return total;
}

int main() {
	vector<Pizza*> v;
	v.push_back(new PizzaRectangular("chocolate",30,50));
	v.push_back(new PizzaRedonda("palmitos",25));
	v.push_back(new PizzaRedonda("muzzarela",25));
	
	cout << CostoPedido(v,700) << endl;
	
	for(Pizza *p : v)
		delete p;
	return 0;
}

