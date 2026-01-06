#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
struct Punto{
	float x,y;
};

class Recta{
public:
	virtual string obtenerEcuacion()=0;
	virtual bool pertenece(Punto &w)=0;
	virtual ~Recta(){}
};
   
bool esIgual(float d1, float d2, float epsilon = 0.00001)
{	return fabs(d1 - d2) < epsilon;  }



class RectaExplicita:public Recta{    // y= mx+b;
private:
	float m, b;
public:
	RectaExplicita(Punto &p, Punto &q){ m=(q.y-p.y)/(q.x-p.x);  b= p.y-m*p.x;}
	string obtenerEcuacion();
	bool pertenece(Punto &w)override{  //return esIgual(w.y ,w.x * m + b);  
        if (esIgual(w.y , w.x * m + b) ) return true;
		else return false;
	}
	float ver_m() {return m;};
	float ver_b() {return b;};
};

class RectaGeneral:public Recta{     // ax+by+c=0
private:
	float a,b,c;
public:
	RectaGeneral(Punto &p, Punto &q){ 
		a=q.y-p.y;
		b=p.x-q.x;
		c= - a*p.x - b*p.y;
	}
	string obtenerEcuacion();
	bool pertenece(Punto &w)override{  
		return esIgual(a*w.x + b*w.y + c , 0);  
	}
	float ver_A() {return a;};
	float ver_B() {return b;};
	float ver_C() {return c;};
};

string RectaGeneral::obtenerEcuacion(){
	stringstream sss;
	sss <<a<<"x + "<< b <<"y + "<<c<<" = 0";
	return sss.str();
}

string RectaExplicita::obtenerEcuacion(){
	stringstream sss;
	sss <<setprecision(2)<<fixed<<"y= "<<m<<"x +"<<b;
	return sss.str();
}


int main(int argc, char *argv[]) {
	Punto q={0,1};
	Punto p1={1,2}, p2={3,4};
	
	Recta *pR;
	
	pR=new RectaGeneral(p1,p2);
	cout<< pR-> obtenerEcuacion()<<endl;
	if ( pR-> pertenece(q) ) cout << "pertenece\n";
		else cout<<"no pertenece\n";
	delete pR;
	
	pR=new RectaExplicita(p1,p2);
	cout<< pR-> obtenerEcuacion()<<endl;
	if ( pR-> pertenece(q) ) cout << "pertenece\n";
	else cout<<"no pertenece\n";
	delete pR;
	
	
	return 0;
}

