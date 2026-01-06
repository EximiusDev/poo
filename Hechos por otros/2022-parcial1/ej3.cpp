#include <iostream>
#include <vector>
using namespace std;

class Bien {
public:
	Bien(float valor=0) : m_valor(valor) { }
	float VerValor() { return m_valor; }
	virtual float Amortizar() =0;
	virtual ~Bien() { }
private:
	float m_valor;
};

class Inmueble : public Bien {
public:
	Inmueble(float valor) : Bien(valor) { }
	float Amortizar() override { return 0; }
};

class Mueble : public Bien {
public:
	Mueble(float valor, int anio_compra) : Bien(valor), m_anio_compra(anio_compra) { }
	float Amortizar() override { return VerValor()*(2023-m_anio_compra)*0.05; }
private:
	int m_anio_compra;
};

class Rodado : public Bien {
public:
	Rodado(float valor, int km) : Bien(valor), m_km(km) { }
	float Amortizar() override { return VerValor()*m_km/10000.0; }
private:
	int m_km;
};

int main() {
	vector<Bien*> v;
	v.push_back(new Mueble(5e5,2018));
	v.push_back(new Rodado(10e6,5e4));
	v.push_back(new Inmueble(20e6));
	
	for (size_t i=0; i<v.size(); ++i) { 
		cout << v[i]->Amortizar() << endl;
	}
	
	for (size_t i=0; i<v.size(); ++i) { 
		delete v[i];
	}
	return 0;
}

