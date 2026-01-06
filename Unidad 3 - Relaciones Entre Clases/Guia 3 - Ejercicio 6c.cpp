#include <iostream>
#include <cmath>
using namespace std;

bool esIgual(float a, float b){
	return fabs(a-b) <= 0.001; /// fabs es el valor absoluto de entero}
	/// la funcion es para tenr cierta tolerancia ante el redondeo de los flotantes
}

struct Punto{
	int x,y;
	Punto(int a,int b){x=a; y=b;} /// Un struct puede tener constructor
	Punto(){} /// Un struct puede tener constructor
};
class Recta{
public:
	virtual string ObtenerEcuacion()=0;  /// Si no los igualoa 0 no anda
	virtual bool Pertenece(Punto p)=0;
};
class RectaExplicita: public Recta{
	float m, b;
public:
	RectaExplicita(Punto p1, Punto p2):Recta(){
		m = ((p2.y -p1.y)*1.0)/(p2.x -p1.x);
		b = p1.y - m*p1.x;
	}
	float verM(){return m;}
	float verB(){return b;}
	string ObtenerEcuacion() override { /// el override no es obligatorio pero es una buena practica de programacion evita confusiones al usar un metodo virtual puro
		return "y= "+to_string(m)+" x + "+to_string(b);
	}
	///bool Pertenece(Punto p){return p.y == ((m * p.x) + b);} /// anda bien salvo por el redondeo de float (decimales redondeados distintos)
	bool Pertenece(Punto p) override {return esIgual(p.y,((m * p.x) + b));} /// anda bien salvo por el redondeo de float (decimales redondeados distintos)
};

class RectaGeneral:public Recta{
	float a, b, c;
public:
	RectaGeneral(Punto p, Punto q);
	float verA(){return a;}
	float verB(){return b;}
	float verC(){return c;}
	string ObtenerEcuacion() /* override*/ {  /// el override no es obligatorio pero es una buena practica de programacion evita confusiones al usar un metodo virtual puro
		return to_string(a)+"x + "+to_string(b)+"y + "+to_string(c)+" = 0";
	}
		///bool Pertenece(Punto p){return (a*p.x+b*p.y+c == 0.0 );} /// anda bien salvo por el redondeo de float (decimales redondeados distintos)
		bool pertenece(Punto p) /* override */{return esIgual(a*p.x+b*p.y+c , 0.0);} /// anda con la funcion esIgual
};

int main() {
	Punto P1(2,2);
	Punto P2;
	P2.x = 5;
	P2.y = 5;
	
	RectaExplicita R1(P1,P2);
	RectaExplicita R2(Punto(1,1),{3,2});
	
	cout<<"R1: "<< R1.ObtenerEcuacion()<<endl;
	cout<<"R2: "<<R2.ObtenerEcuacion()<<endl;
	
	if (R1.Pertenece({5,6}))
		cout<<"Si pertenece a la recta r1"<<endl;
	else
		cout<<"NO pertenece a la recta r1"<<endl;
	
	
	return 0;
}

RectaGeneral::RectaGeneral(Punto p, Punto q){
	a= q.y-p.y;  b= p.x-q.x;   c= -a*p.x-b*p.y;
}
