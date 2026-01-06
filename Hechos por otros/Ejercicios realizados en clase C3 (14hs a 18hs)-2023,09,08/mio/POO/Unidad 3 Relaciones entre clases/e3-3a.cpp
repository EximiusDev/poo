#include <iostream>
using namespace std;
struct Punto{
	float x,y;
	Punto(float xx,float yy):x(xx),y(yy){}
};

class RectaExplicita{
	float m,b;
public:
	RectaExplicita(Punto &p, Punto &q);
	string ObtenerEcuacion();
	float VerM(){return m;}
	float VerB(){return b;}
};

class RectaGeneral{
	float a,b,c;
public:
	RectaGeneral(Punto &p, Punto &q);
	string ObtenerEcuacion();
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
	Punto a(1.4,1),b(4.1,3);
	RectaExplicita r(a,b);
	cout<<r.ObtenerEcuacion();
	RectaGeneral w(a,b);
	cout<<endl<<endl;
	
	cout<<w.ObtenerEcuacion();
	
	
	return 0;
}

