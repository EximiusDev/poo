#include <iostream>
#include <sstream>

using namespace std;
struct Punto {
	float x,y;
	//Punto(int ax=0,int ay=0){x=ax;y=ay;}      //constructor
};

class RectaExplicita{
private:
	float m, b;
public:
	RectaExplicita(Punto &p, Punto &q){m=(q.y-p.y)/(q.x-p.x); b= p.y-m*p.x;}
	string obtenerEcuacion();
	float ver_m() {return m;};
	float ver_b() {return b;};
};

string RectaExplicita::obtenerEcuacion(){
	/*string s= " y= "+ to_string(m) + ".x + " + to_string(b);
	return s;
	*/
	/*stringstream: Los objetos de esta clase usan un buffer de cadena que
	contiene una secuencia de caracteres. Se puede acceder a esta secuencia
	de caracteres directamente como un objeto de cadena, utilizando miembro
	str.
	*/
	stringstream aux;
	aux << " y = " << m << "x + " << b;
	return aux.str();

}
int main(int argc, char *argv[]) {
	Punto punto1={0,2}, punto2={2,8};
	cout<<"P1("<< punto1.x <<","<< punto1.y <<")\n";
	cout<<"P2("<< punto2.x <<","<< punto2.y <<")\n";
	RectaExplicita R(punto1, punto2);
	string ecuacion = R.obtenerEcuacion();
	cout<<"Ecuacion explicita de la recta: "<<ecuacion<<endl;
	return 0;
}	
