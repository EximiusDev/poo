#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

//funcion libre
bool esIgual(float d1, float d2, float epsilon = 0.00000000001)
{
	return fabs(d1 - d2) < epsilon;
}


class Punto {
private:
	float x,y;
public:
	Punto():x(0),y(0){};
	Punto(float xx, float yy):x(xx),y(yy){};
	void asignar_valor(float xx, float yy);
	float ver_x() {return x;};
	float ver_y() {return y;};
};

class Recta{
public:
	virtual string obtenerEcuacion()=0;//Metodo virtual puro
	virtual bool pertenece(Punto &P)=0;//Metodo virtual puro
	virtual ~Recta(){};
};

class RectaGeneral: public Recta{
private:
	float A,B,C;
public:
	RectaGeneral(Punto &P1, Punto &P2);
	string obtenerEcuacion();
	bool pertenece(Punto &P){return esIgual((A*P.ver_x()+ B*P.ver_y()+C), 0);}
	float ver_A() {return A;};
	float ver_B() {return B;};
	float ver_C() {return C;};
};

class RectaExplicita: public Recta
{private:
	float m, b;
public:
	RectaExplicita(Punto &P1, Punto &P2);
	string obtenerEcuacion();
	bool pertenece(Punto &P){return esIgual(P.ver_y(),(ver_m()*P.ver_x()+ver_b()));}
	float ver_m() {return m;};
	float ver_b() {return b;};
};

void Punto::asignar_valor(float xx, float yy){
	x= xx; y= yy;
}

RectaGeneral::RectaGeneral(Punto &P1, Punto &P2){
 /* A= -(y2-y1)
	B= (x2-x1)
	C= -(y1*(x2-x1) - x1*(y2-y1))*/
	A = -(P2.ver_y()-P1.ver_y());
	B = (P2.ver_x()-P1.ver_x());
	C = -((P1.ver_y()* (P2.ver_x()-P1.ver_x())) - P1.ver_x()*(P2.ver_y()-P1.ver_y()));
}

RectaExplicita::RectaExplicita(Punto &P1, Punto &P2){
	m = (P2.ver_y()-P1.ver_y())/(P2.ver_x()-P1.ver_x());
	b = P1.ver_y() - (m * P1.ver_x());
}

string RectaExplicita::obtenerEcuacion() {
	stringstream aux;
	aux.str("");
	aux << "Y = "<< m <<" . X + "<< b;
	return aux.str();
}
string RectaGeneral::obtenerEcuacion(){
	stringstream aux;
	aux.str("");
	aux << A <<" X + "<< B <<" Y + "<< C<<" = 0";
	return aux.str();
}


int main(int argc, char *argv[]) {
	float x1, x2, y1, y2;
	Recta *pR;
	cout << "DATOS DE LOS PUNTOS P1 Y P2."<<endl;
	cout << "Ingrese X1: "; cin>> x1;
	cout << "Ingrese Y1: "; cin>> y1;
	cout << endl;
	cout << "Ingrese X2: "; cin>> x2;
	cout << "Ingrese Y2: "; cin>> y2;
	cout << endl;
	Punto p1(x1,y1),p2(x2,y2);
	
	pR= new RectaExplicita(p1,p2);
	cout<<"Ecuacion recta general:   "<< pR->obtenerEcuacion() <<endl;
	delete pR;
	
	pR= new RectaGeneral(p1,p2);
	cout<<"Ecuacion recta general:   "<< pR->obtenerEcuacion() <<endl;
	delete pR;
	
	return 0;
}
