/// Parcial 1 2020 - Ej 3

#include <iostream>
using namespace std;

class Triangulo {
public:
	Triangulo(float b, float h) : base(b), altura(h) { }
	float VerBase() const { return base; }
	float VerAltura() const { return altura; }
	float VerArea() const { return base*altura/2; }
private:
	float base, altura;
};

class Rectangulo {
public:
	Rectangulo(float b, float h) : base(b), altura(h) { }
	float VerBase() const { return base; }
	float VerAltura() const { return altura; }
	float VerArea() const { return base*altura; }
private:
	float base, altura;
};

class TrapecioRect {
public:
	TrapecioRect(float b, float a, float h) : t(a,h), r(b,h) { }
	float VerArea() const { return t.VerArea()+r.VerArea(); }
	float VerBaseMenor() const { return r.VerBase(); }
	float VerBaseMayor() const { return r.VerBase()+t.VerBase(); }
	float VerAltura() const { return r.VerAltura(); }
private:
	Triangulo t;
	Rectangulo r;
};

int main() {
	float a,b,h;
	cin >> a >> b >> h;
	TrapecioRect tr(b,a,h);
	cout << tr.VerArea();
	return 0;
}

