#include <iostream>
using namespace std;
class Vector2D {
public:
	Vector2D() {}
	Vector2D(int x, int y, int z=0) : m_x(x), m_y(y), m_z(z) { 	}
	int VerX() { return m_x; }
	int VerY() { return m_y; }
	int VerZ() { return m_z; }
	
/*	Vector2D operator*(float c){//Producto por un real
		Vector2D aux(m_x*c, m_y*c);
		return aux;
	}
*/	
	int operator*(Vector2D &v1) {	//Producto escalar osea retorna un escalar al multiplicar dos vectores
		return (m_x*v1.VerX())+(m_y*v1.VerY()); //(x1*x2 + y1*y2)
	}
	
	Vector2D operator%(Vector2D &v1) {	//Producto vectorial
		 Vector2D aux(0,0,m_x*v1.VerY()-(m_y*v1.VerX())); // para la coordenada z (x1*y2 - y1*x2)
		 return aux;
	}
private:
	int m_x, m_y, m_z;
};


Vector2D operator*(Vector2D &v1, float c){ //Producto por un real
	Vector2D aux(v1.VerX()*c, v1.VerY()*c);
	return aux;
}

Vector2D operator*(float c, Vector2D &v1){ //Producto por un real para que sea conmutativo
	Vector2D aux(v1.VerX()*c, v1.VerY()*c);
	return aux;
}



//Vector2D operator*(Vector2D &v1, Vector2D &v2) {	//Producto vectorial osea retorna un vector al multiplicar dos vectores
//	return Vector2D((v2.VerY()-v1.VerY()),(v1.VerX()-v2.VerX())); //(y2-y1)x + (x1-x2)y
//}


ostream & operator<<(ostream &o, Vector2D &v1) {
	o << v1.VerX() << " i + " << v1.VerY() << " j + " << v1.VerZ()<<" k";
	return o;
}
int main() {
	/** Implemente una clase llamada Vector2D con dos números reales como atributos
	para representar un vector en el plano. Implemente operadores para los productos
	escalar y vectorial y el producto del vector por un real. Para elegir los operadores a
	sobrecargar en cada caso, analice la tabla de jerarquía de operadores y seleccione
	los operadores cuya jerarquía coincida con la que tienen dichos productos en el
	álgebra de vectores convencional.
	**/
	Vector2D v1(3, 4), v2(2, 1), v3,v4,v5;
	cout << "v1 es " << v1 << endl << "v2 es: " << v2 << endl;
	
	int escalar = v1*v2;
	cout << "El producto escalar entre v1 y v2 es: " << escalar << endl;
	
	v3 = v1 % v2;   //aca calculo el producto vectorial
	cout << "El producto vectorial entre v1 y v2 es: " << v3 << endl;
	
	v4 = v1 * 10;
	cout << "El producto de un vector por un real: " << v4 << endl;
	
	v5 = 10 * v2;
	cout << "El producto de un real por un vector: " << v5 << endl;
	
	return 0;
}

