/// Un color se representa habitualmente mediante 3 números que indican qué intensidad
/// de luz roja, qué intensidad de luz verde, y qué intensidad de luz azul hay que mezclar
/// para formarlo. Considerando 0 como intensidad mínima y 1 como intensidad máxima, 
/// a) defina una clase para representar un color. b) Sobrecargue los operadores == y
/// != para permitir comparar dos colores. c) Sobrecargue el operador + para permitir
/// sumar dos colores (notar que cada intensidad debe ser como máximo 1; si se suma un
/// color con intensidad de rojo 0.5 y otro con 0.7, el resultante tendrá 1.0 y no 1.2),
/// y el operador - para restarlos (de forma similar a la suma, la intensidad nunca puede
/// ser menor a 0). d) Escriba un programa cliente que permita ingresar dos colores, y si
/// son diferentes muestre el color resta y el color suma; si son iguales un mensaje alusivo.
	
#include <iostream>
using namespace std;

// a) 
class Color {
public:
	Color(float ar, float ag, float ab) : r(ar), g(ag), b(ab) { }
	float VerR() { return r; }
	float VerG() { return g; }
	float VerB() { return b; }
	
	// b)
	bool operator==(Color c) {
		return this->r==c.r and this->g==c.g and this->b==c.b;
	}
	bool operator!=(Color c) {
		return !(*this==c); // reaprovecho el == que ya hice
	}
	
	// c)
	Color operator+(Color c) {
		float rn = this->r + c.r; if (rn>1) rn = 1;
		float gn = this->g + c.g; if (gn>1) gn = 1;
		float bn = this->b + c.b; if (bn>1) bn = 1;
		Color cn(rn,gn,bn);
		return cn;
	}
	Color operator-(Color c) {
		float rn = this->r - c.r; if (rn<0) rn = 0;
		float gn = this->g - c.g; if (gn<0) gn = 0;
		float bn = this->b - c.b; if (bn<0) bn = 0;
		Color cn(rn,gn,bn);
		return cn;
	}
	
	// extra.. no lo pide el enunciado
	float &operator[](int i) {
		if (i==0) return r;
		if (i==1) return g;
		return b;
	}
private:
	float r,g,b;
};

// ej de implementación alternativa del - fuera de la clase
//Color operator-(Color c1, Color c2) {
//	float rn = c1.VerR() - c2.VerR(); if (rn<0) rn = 0;
//	float gn = c1.VerG() - c2.VerG(); if (gn<0) gn = 0;
//	float bn = c1.VerB() - c2.VerB(); if (bn<0) bn = 0;
//	Color cn(rn,gn,bn);
//	return cn;
//}

// ej de implementación alternativa del == fuera de la clase
//bool operator==(Color c1, Color c2) {
//	return c1.VerR()==c2.VerR() and c1.g==c2.g and c1.b==c2.b;
//}

// extra.. no lo pide el enunciado
ostream &operator<<(ostream &o, Color c) {
	o << "("<<c[0]<<","<<c[1]<<","<<c[2]<<")";
	return o;
}

// d) 
int main() {
	float r1,g1,b1, r2,g2,b2;
	cin >> r1 >> g1 >> b1;
	cin >> r2 >> g2 >> b2;
	Color c1(r1,g1,b1), c2(r2,g2,b2);
	if (c1==c2) {
		cout << "Son iguales" << endl;
	} else {
		Color suma = c1+c2, resta = c1-c2;;
		cout << "Suma: " << suma << endl;
		cout << "Resta: " << resta << endl;
	}
	return 0;
}

