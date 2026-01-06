#include <iostream>
#include <sstream>

using namespace std;
class Punto {
private:
	float x,y;
public:
	Punto(float xx, float yy):x(xx),y(yy){};
	void asignar_valor(float xx, float yy);
	float ver_x() {return x;};
	float ver_y() {return y;};
};
class RectaExplicita{
private:
	Punto P1, P2;
	float m, b;
public:
	RectaExplicita(Punto &p1, Punto &p2):P1(p1),P2(p2){};
	string obtenerEcuacion();
	float ver_m() {return m;};
	float ver_b() {return b;};
};

void Punto::asignar_valor(float xx, float yy){
	x= xx; y= yy;
}
string RectaExplicita::obtenerEcuacion(){
	m = (P2.ver_y()-P1.ver_y())/(P2.ver_x()-P1.ver_x());
	b = P1.ver_y() - (m * P1.ver_x());
	/*stringstream: Los objetos de esta clase usan un buffer de cadena que
	contiene una secuencia de caracteres. Se puede acceder a esta secuencia
	de caracteres directamente como un objeto de cadena, utilizando miembro
	str.
	*/
	stringstream aux;
	aux.str("");
	aux << " Y = ";
	aux << ver_m();
	aux << " . X + ";
	aux << ver_b();
	return aux.str();
}
int main(int argc, char *argv[]) {
	Punto punto1(1,1), punto2(2,3);
	//punto1.asignar_valor(1,1);
	//punto2.asignar_valor(4,4);
	cout<<"P1.x= "<<punto1.ver_x()<<" , P1.y= "<<punto1.ver_y()<<endl;
	cout<<"P2.x= "<<punto2.ver_x()<<" , P2.y= "<<punto2.ver_y()<<endl;
	RectaExplicita R(punto1, punto2);
	string ecuacion = R.obtenerEcuacion();
	cout<<ecuacion<<endl;
	return 0;
}	
