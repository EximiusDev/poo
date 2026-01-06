#include <iostream>
using namespace std;

class Estado {
	int m_nivel, m_vidas, m_puntos;
public:
	Estado(int vidas) : m_nivel(1), m_vidas(vidas), m_puntos(0) { }
	bool EstaVivo() { return m_vidas>0; }
	void SubirNivel() { ++m_nivel; }
	void SubirPuntaje(int cuanto) { m_puntos += cuanto; }
	int VerPuntos() { return m_puntos; }
	int VerNivel() { return m_nivel; }
	int VerVidas() { return m_vidas; }
	void PerderVida() { --m_vidas; }
};

bool operator<(Estado e1, Estado e2) {
	if (e1.VerNivel()!=e2.VerNivel())
		return e1.VerNivel()<e2.VerNivel();
	return e1.VerPuntos()<e2.VerPuntos();
}

bool operator>(Estado e1, Estado e2) {
	return e2<e1;
}

class Personaje {
	string m_nombre;
	int m_x, m_y;
	Estado m_estado;
public:
	Personaje(string nombre, int vidas, int x, int y) 
		: m_nombre(nombre), m_x(x), m_y(y), m_estado(vidas) { }
	void Mover(int x, int y) { m_x = x; m_y = y; }
	int VerX() { return m_x; }
	int VerY() { return m_y; }
	string VerNombre() { return m_nombre; }
	Estado &VerEstado() { return m_estado; }
};

void mostrar(Personaje p2) {
	cout << "Nombre: " << p2.VerNombre() << endl;
	cout << "Pos: " << p2.VerX() << ", " << p2.VerY() << endl;
	cout << "Vidas: " << p2.VerEstado().VerVidas() << endl;
	cout << "Puntaje: " << p2.VerEstado().VerPuntos() << endl;
	cout << "Nivel: " << p2.VerEstado().VerNivel() << endl;
}

int main() {
	Personaje p1("player 1",3,10,10), p2("player 2",3,200,10);
	int n1 = rand()%10, n2 = rand()%10;
	for (int i=0; i<n1; ++i) p1.VerEstado().SubirNivel();
	p1.VerEstado().SubirPuntaje(rand()%10*1000);
	for (int i=0; i<n2; ++i) p2.VerEstado().SubirNivel();
	p2.VerEstado().SubirPuntaje(rand()%10*1000);
	
	if (p1.VerEstado()>p2.VerEstado()) mostrar(p1);
	else                               mostrar(p2);
	return 0;
}

