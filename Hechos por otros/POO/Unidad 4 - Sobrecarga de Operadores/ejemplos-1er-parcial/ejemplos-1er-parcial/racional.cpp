// Ej 3 (30pts) Modele la clase racional para representar un número racional 
// con métodos para construir un objeto de este tipo y para mostrar su numerador 
// y denominador.
// Luego reutilice esta clase para diseñar la clase racional_puro. Un número 
// racional puro es aque donde el numerador es menor al denominador. Si el
// numerador fuear mayor o igual se separa una parte entera del racional. 
// Ejemplo: 7/2 no es puro, y equivale a 3+1/2.
	
class Racional {
protected:
	int num,den;
public:
	Racional(int n=0, int d=1) { num=n; den=d; }
	int VerNum() { return num; }
	int VerDen() { return den; }
	void Cargar(int n, int d) { num=n; den=d; }
	float CalcularReal() { return float(num)/den; }
};

class RacionalPuro : public Racional {
	int e;
public:
	RacionalPuro() { e=0; }
	RacionalPuro(int _e, int _n, int _d) :Racional(_n%_d,_d) { 
		e=_e + _n/_d;
	}
	void Cargar(int _e, int _n, int _d) {
		Racional::Cargar(_n%_d,_d);
		e=_e + _n/_d;
	}
	int VerParteEntera() { return e; }
};

// ojo, con esta clase se puede usar los Cargar heredados para cargar un
// racional no puro.. ¿como mejorarian eso?
	
