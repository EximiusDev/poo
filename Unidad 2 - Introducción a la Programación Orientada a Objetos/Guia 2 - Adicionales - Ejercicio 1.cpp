/* Ejercicios Adicionales
	Ejercicio 1
	Cree una clase Rectangulo que posea:
	a. Un constructor que permita crear el objeto a partir de la base y altura del
	rectángulo.
	b. Otro constructor que permita crear el objeto a partir de las coordenadas (x,
																				 y) de dos vértices opuestos.
	c. Métodos VerArea(...) y VerPerimetro(...) que calculen respectivamente el
	área y perímetro del rectángulo.
	d. Un método EsCuadrado(...) que permita conocer si el rectángulo es
	cuadrado.
	e. Cree un programa cliente donde utilice varias instancias de la clase
	Rectangulo. Cree los objetos dinámicamente y no olvide borrarlos al
	terminar de utilizarlos.
	*/


#include <iostream>
using namespace std;

class Rectangulo{
	int m_lado1, m_lado2;
	int m_x1, m_y1;
	int m_x2, m_y2;
	
public:	
	Rectangulo(int , int , int , int );
	Rectangulo(int lado1, int lado2){ m_lado1 = lado1; 		m_lado2 = lado2;	}
	int VerArea(){return m_lado1*m_lado2; }
	int VerPerimetro(){return m_lado1 *2 + m_lado2 *2; }
	bool EsCuadrado();
};

//////////////// MAIN

int main() {
	
	cout<<"Ingrese los lados del rectangulo: "<<endl;
	int lado1,lado2;
	cin>>lado1>>lado2;
	
	Rectangulo R(lado1, lado2);
	///Rectangulo R(10, 12);
	
	cout<<"Area = "<<R.VerArea()<<endl;
	cout<<"Perimetro = "<<R.VerPerimetro()<<endl;
	
	return 0;
}

//////////////// //////////////// //////////////// ///////////////

Rectangulo::Rectangulo(int x1, int y1, int x2, int y2){
	m_x1 = x1, m_y1 = y1;
	m_x2 = x2, m_y2 = y2;
}
bool Rectangulo::EsCuadrado(){
	return m_lado1 == m_lado2; /// Es lo mismo que :
	/* if(m_lado1 == m_lado2) return true;
	else false;
	*/
}
