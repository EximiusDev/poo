/* Ejercicio 2
Proponga una clase EcuacionCuadratica para modelar ecuaciones cuadráticas de
la forma ax
2+bx+c=0. La clase debe incluir:
a. Un constructor que reciba los valores de los coeficientes a, b y c.
b. Un método TieneRaicesReales(...) que devuelva verdadero si las raíces de
la ecuación son reales.
c. Dos métodos VerRaiz1(...) y VerRaiz2(...) que permitan obtener las raíces
reales (en caso de que lo sean).
d. Dos métodos VerParteReal(...) y VerParteImag(...) que permitan obtener las
partes real e imaginaria de las raíces complejas (en caso de que lo sean).
e. Cree un programa cliente que utilice un objeto de la clase
EcuaciónCuadratica para determinar las raíces de una ecuación
cuadrática cuyos coeficientes sean ingresados por el usuario, y las muestre
en el formato que corresponda (según sean reales o complejas).*/
#include <iostream>
#include <cmath>
using namespace std;

class EcuacionCuadratica{
	float m_a, m_b, m_c;
	float m_r1, m_r2;
	float m_re, m_im;
	float Discrim;
public:
	//EcuacionCuadratica(float , float , float );
	EcuacionCuadratica(float = 0 , float = 0 , float = 0 );
	float VerRaiz1(){ return m_r1; }
	float VerRaiz2(){ return m_r2; }
	float VerParteReal(){ return m_re; }
	float VerParteImag(){ return m_im; }
	bool EsReal();
};

int main() {
	float a, b, c;
	cout<<"Ingrese los Coeficientes (a,b,c): "<<endl;
	a=b=c = 1;
	cin>>a>>b>>c;
	
	EcuacionCuadratica Ec1;
	EcuacionCuadratica Ec2( a, b, c);
	
	if(Ec2.EsReal()) cout<<"Las raices (reales) son: "<<Ec2.VerRaiz1()<<" y "<<Ec2.VerRaiz2()<<endl;
	else{
		cout<<"Las raices (complejas) son: "<<Ec2.VerParteReal()<<" + "<<Ec2.VerParteImag();
		cout<<" y "<<Ec2.VerParteReal()<<" - "<<Ec2.VerParteImag()<<endl;
	}
	
	return 0;
}

EcuacionCuadratica::EcuacionCuadratica(float a, float b, float c){
	m_a = a;
	m_b = b;
	m_c = c;
	Discrim = m_b*m_b -(4 * m_a * m_c);
	m_r1 = (-m_b - sqrt(Discrim))/2.0*m_a;
	m_r2 = (-m_b + sqrt(Discrim))/2.0*m_a;
	m_re = (-m_b )/2.0*m_a;
	m_im = ( sqrt(-Discrim))/2.0*m_a;
	//cout<<Discrim<<endl<<endl;
}
bool EcuacionCuadratica::EsReal(){
	if (Discrim < 0) return false;
	else return true;
}
