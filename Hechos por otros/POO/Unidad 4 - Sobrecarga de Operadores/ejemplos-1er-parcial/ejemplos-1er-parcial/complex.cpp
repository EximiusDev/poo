// 2 (30pts) Modele la clase complex para representar numeros complejos. 
// Implemente todos los métodos que proponga incluyendo las sobrecargas de 
// los operadores < y << para relacionar los módulos de 2 complejos y para
// efectuar una salida a través del objeto cout respectivamente.
	
class Complex {
	float pr, pi;
public:
	Complex(float _pr=0, float _pi=0) {
		pr=_pr; pi=_pi;
	}
	void CargarParteReal(float x) { pr=x; }
	void CargarParteImag(float x) { pi=x; }
	float VerParteReal() { return pr; }
	float VerParteImag() { return pi; }
	float CalcularModulo() { return sqrt(pr*pr+pi*pi); }
	bool operator<(Complex c2) {
		return (this->CalcularModulo() < c2.CalcularModulo());
	}
};

ostream &operator<<(ostream &o, Complex c) {
	if (c.VerParteImag()<0)
		o<<c.VerParteReal()<<c.VerParteImag()<<"i";
	else
		o<<c.VerParteReal()<<"+"<<c.VerParteImag()<<"i";
	return o;
}
