#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
struct Punto{
	float x,y;
};
class RectaExplicita{
private:
	float m, b;
public:
	RectaExplicita(Punto &p, Punto &q){ m=(q.y-p.y)/(q.x-p.x);  b= p.y-m*p.x;}
	string obtenerEcuacion();
	float ver_m() {return m;};
	float ver_b() {return b;};
};
string RectaExplicita::obtenerEcuacion(){
	stringstream sss;
	sss <<setprecision(2)<<fixed<<"y= "<<m<<"x +"<<b;
	return sss.str();

}


int main(int argc, char *argv[]) {
	
    Punto p1={2,5.5}, p2={6,9.145567};
		
	RectaExplicita r(p1,p2);
	cout<<r.obtenerEcuacion()<<endl;
	
	
	return 0;
}

