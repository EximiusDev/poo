#include <iostream>
#include <sstream>

#include <cmath>
using namespace std;
struct Punto {
	float x,y;
	//Punto(int ax=0,int ay=0){x=ax;y=ay;}      //constructor
};

//funcion libre
bool esIgual(float d1, float d2, float epsilon = 0.000001)
{	return fabs(d1 - d2) < epsilon;  }


class Recta{
public:
	virtual string obtenerEcuacion()=0;//Metodo virtual puro
	virtual bool pertenece(Punto &P)=0;//Metodo virtual puro
	virtual ~Recta(){};
};

class RectaExplicita: public Recta{
private:
	float m, b;
public:
	RectaExplicita(Punto &p, Punto &q){
		m=(q.y-p.y)/(q.x-p.x);
		b= p.y - m * p.x;
	}
	bool pertenece(Punto &P){return esIgual(P.y ,  m * P.x + b);}
	string obtenerEcuacion();
	float ver_m() {return m;};
	float ver_b() {return b;};
};

class RectaGeneral: public Recta{
private:
	float a,b,c;
public:
	RectaGeneral(Punto &p, Punto &q){
		a=q.y-p.y;
		b=p.x-q.x;
		c= - a*p.x - b*p.y;
	}
	string obtenerEcuacion();
	bool pertenece(Punto &P){return esIgual((a*P.x + b*P.y + c), 0);}
	float ver_A() {return a;};
	float ver_B() {return b;};
	float ver_C() {return c;};
};

string RectaGeneral::obtenerEcuacion(){
	stringstream aux;
	aux << a << "x + " << b << "y + "<< c <<" = 0";
	return aux.str();
	
}	

string RectaExplicita::obtenerEcuacion(){
/*	stringstream aux;
	aux << " y = " << m << "x + " << b;
	return aux.str();
*/
return "y = " + to_string(m) + "*x + " + to_string(b);
}

int main(int argc, char *argv[]) {
	Punto punto1={0,2}, punto2={2,8}, w={0.9,4.7};
	string ecuacion;
	
	cout<<"P1("<< punto1.x <<","<< punto1.y <<")\n";
	cout<<"P2("<< punto2.x <<","<< punto2.y <<")\n";
	Recta *pR;
	pR=new RectaExplicita(punto1, punto2);
	ecuacion = pR->obtenerEcuacion();
	cout<<"Ecuacion explicita de la recta: "<<ecuacion<<endl;
	if( pR->pertenece(w)) cout<<"pertenece\n";
		else cout<<"no pertenece\n";
		
	delete pR;
	pR=new RectaGeneral(punto1, punto2);
	ecuacion = pR->obtenerEcuacion();
	cout<<"Ecuacion general de la recta: "<<ecuacion<<endl;
	if( pR->pertenece(w)) cout<<"pertenece\n";
	else cout<<"no pertenece\n";
	delete pR;
	

	return 0;
}	
