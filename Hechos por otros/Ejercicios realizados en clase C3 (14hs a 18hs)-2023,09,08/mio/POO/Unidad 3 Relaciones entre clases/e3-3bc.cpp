#include <iostream>
#include <cmath>
using namespace std;
struct Punto{
	float x,y;
	Punto(float xx,float yy):x(xx),y(yy){}
};

bool casiIgual(float q, float w){
	return fabs(q-w)<0.000001;
}


class Recta{
public:
	virtual string ObtenerEcuacion()=0;
	virtual bool pertenece(Punto &P)=0;
	virtual ~Recta(){}
};



class RectaExplicita:public Recta{
	float m,b;
public:
	RectaExplicita(Punto &p, Punto &q);
	string ObtenerEcuacion();
	bool pertenece(Punto &P){return casiIgual(P.y , m*P.x+b);}
	float VerM(){return m;}
	float VerB(){return b;}
};

class RectaGeneral:public Recta{
	float a,b,c;
public:
	RectaGeneral(Punto &p, Punto &q);
	string ObtenerEcuacion();
	bool pertenece(Punto &P){return casiIgual(a*P.x+b*P.y+c, 0);}
	float VerA(){return a;}
	float VerB(){return b;}
	float VerC(){return c;}
};


RectaExplicita::RectaExplicita(Punto &p, Punto &q){
	m = (q.y-p.y)/(q.x-p.y);
	b = p.y - m * p.x;
}

string RectaExplicita::ObtenerEcuacion(){
	return "y= "+to_string(m)+".x + "+to_string(b); 
}

RectaGeneral::RectaGeneral(Punto &p, Punto &q){
	a = q.y-p.y;
	b = p.x-q.x;
	c = -a*p.x-b*p.y;
}

string RectaGeneral::ObtenerEcuacion(){
	return "y= "+to_string(a)+".x + "+to_string(b)+".y +"+to_string(c)+" = 0"; 
}


int main(int argc, char *argv[]) {
	Punto a(1,1),b(14,14);
	Punto c(3,2);
	
	Recta *pR; 
	
	pR=new RectaExplicita(a,b);
	cout<< pR -> ObtenerEcuacion()<<endl;
	if(pR->pertenece(c))
		cout<<"pertenece\n";
	else
		cout<<"no pertenece\n";
	delete pR;
	
	pR=new RectaGeneral(a,b);
	cout<< pR -> ObtenerEcuacion()<<endl;
	if(pR->pertenece(c))
		cout<<"pertenece\n";
	else
		cout<<"no pertenece";
	delete pR;
	
	
	
	return 0;
}

