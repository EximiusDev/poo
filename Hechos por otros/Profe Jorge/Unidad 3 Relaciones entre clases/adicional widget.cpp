#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


// declaracion adelantada, porque ventana necesita widget y widget necesita ventana
// una declaracion adelantada solo sirve para declarar un puntero o una referencia, 
// pero no usarla... en este caso eso alcanza para definir widget, y más abajo cuando
// se use el puntero, la clase ventana ya va a estar completamente definida
class Ventana; 

// esta función se supone que ya existe segun el enunciado
void escribirEnVentana(Ventana *v, string mensaje);

// esta es la clase que daba el enunciado como base para los widgets
class Widget {
public:
	Widget() : m_v(nullptr) {}
	void SetearVentana(Ventana *v) { m_v = v; }
	Ventana* ObtenerVentana() { return m_v; }
	virtual void Dibujar()= 0;
	virtual ~Widget() {}
protected:
	Ventana *m_v; // ventana que lo contiene public:
};

// a)
class Ventana {
public:
	Ventana(string titulo) : m_titulo(titulo) { }
	
	void Agregar(Widget *p) { m_widgets.push_back(p); p->SetearVentana(this); }
	void Dibujar() {
	// todos los couts son solo adornos
		//cout << "+---+" << setw(m_ancho-5) << setfill('-') << right << "+---+---+---+" << endl;
		//cout << "| = | " << setw(m_ancho-19) << setfill(' ') << left << m_titulo << "| _ | M | X |" << endl;
		//cout << "+---+" << setw(m_ancho-5) << setfill('-') << right << "+---+---+---+" << endl;
		//cout << '|' << setw(m_ancho-1) << setfill(' ') << right << '|' << endl;
		for (Widget *p : m_widgets) 
			p->Dibujar();
		//cout << '|' << setw(m_ancho-1) << setfill(' ') << right << '|' << endl;
		//cout << '+' << setw(m_ancho-1) << setfill('-') << right << '+' << endl;
	}
	int Ancho() { return m_ancho; }
	~Ventana() { for (Widget *p : m_widgets) delete p; }
	
private:
	int m_ancho = 60;
	string m_titulo;
	vector<Widget*> m_widgets;
};

// b)
class Mensaje : public Widget {
public:
	Mensaje(string texto) : m_texto(texto) { }
	void Dibujar() override { escribirEnVentana(m_v,m_texto); }
private:
	string m_texto;
};


// c)
int main() {
	Ventana v("Ejemplo");
	v.Agregar(new Mensaje("Quiero aprobar POO"));
	v.Dibujar();
}

// implementación que se supone que ya existe, solo para poder probarla y ver algo
void escribirEnVentana(Ventana *v, string mensaje) {
	cout << "| " << setw(v->Ancho()-4) << setfill(' ') << left << mensaje << " |" << endl;
}
