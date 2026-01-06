#include <iostream>
#include <cmath>
using namespace std;

class Ecuacion {
	float m_a, m_b, m_c;
	float m_r1, m_r2;
	bool m_son_reales;
	void Calcular();
public:
	void CargarCoefs(int a, int b, int c);
	bool TieneRaicesReales(){return m_son_reales;}
	float VerRaiz1(){return m_r1;}
	float VerRaiz2(){return m_r2;}
	float VerParteReal(){return m_r1;}
	float VerParteImag(){return m_r2;}
};

int main() {
	
	float x, y, z;
	cin >> x >> y >> z;
	Ecuacion eq;
	eq.CargarCoefs(x,y,z);
	if (eq.TieneRaicesReales()) {
		cout << "r1=" << eq.VerRaiz1() << endl;
		cout << "r2=" << eq.VerRaiz2() << endl;
	} else {
		cout << "r1=" << eq.VerParteReal() << "+"
			<< eq.VerParteImag() << "i" << endl;
		cout << "r1=" << eq.VerParteReal() << "-"
			<< eq.VerParteImag() << "i" << endl;
	}
	
	return 0;
}

void Ecuacion::CargarCoefs(int a,int b,int c){
	m_a = a; m_b = b; m_c = c; Calcular();
}

void Ecuacion::Calcular() {
	float d = m_b*m_b-4*m_a*m_c;
	if (d>=0) {
		m_son_reales = true;
		m_r1 = (-m_b+sqrt(d))/(2*m_a);
		m_r2 = (-m_b-sqrt(d))/(2*m_a);
	} else {
		m_son_reales = false;
		m_r1 = -m_b/(2*m_a);
		m_r2 = sqrt(-d)/(2*m_a);
	}
}
