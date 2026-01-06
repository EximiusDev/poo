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

class RectaExplicita{
	float m, b;
	
public:
	RectaExplicita(Punto p1, Punto p2);
	float verM(){return m;}
	float verB(){return b;}
	string ObtenerEcuacion(){
		return "y= "+to_string(m)+" x + "+to_string(b);
	}
	///bool Pertenece(Punto p){return p.y == ((m * p.x) + b);} /// anda bien salvo por el redondeo de float (decimales redondeados distintos)
	bool Pertenece(Punto p){return esIgual(p.y,((m * p.x) + b));} /// anda con la funcion esIgual
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

RectaExplicita::RectaExplicita(Punto p1, Punto p2){
	m = ((p2.y -p1.y)*1.0)/(p2.x -p1.x);
	b = p1.y - m*p1.x;
}
