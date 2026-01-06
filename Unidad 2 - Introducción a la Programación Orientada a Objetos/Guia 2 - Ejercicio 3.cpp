/* Ejercicio 3
Diseñe una clase Polinomio que contenga:
a. un constructor que reciba el grado el polinomio e inicialice sus coeficientes
en 0.
b. un método que permita cambiar un coeficiente.
c. un método evaluar que permita evaluar el polinomio para un valor dado de la variable x.
d. el/los métodos que considere necesarios para poder mostrar un polinomio
desde un programa cliente.
e. una función que permita sumar dos polinomios retornando un tercer
polinomio con el resultado (ej. p_res=Sumar(p1,p2);). ¿Cómo variaría si en
lugar de ser una función libre fuera un método de la clase?
Verifique el funcionamiento de la función Sumar(...) mediante un programa cliente.*/

#include <iostream>
using namespace std;

class Polinomio{
	int m_grad;
	float * coef;
public:
	Polinomio(int grad);
	void Cambio_coef(int , float nuev_coef);
	void Mostrar_pol();
};


int main() {
	
	Polinomio P1(3);
	cout<<endl;
	P1.Cambio_coef(3 , 2.2);
	cout<<endl;
	P1.Mostrar_pol();
	return 0;
}

Polinomio::Polinomio(int grad){
	m_grad = grad + 1;
	coef = new float[m_grad];
	for(int i=0;i<m_grad;i++) { 
		*(coef + i) = 0;
		cout<<*(coef + i)<<" x^"<<i<<" + ";
	}
	
}
void Polinomio::Cambio_coef(int nuev_gr, float nuev_coef){
	*(coef + nuev_gr ) = nuev_coef;
	cout<<"Cambio: "<<*(coef + nuev_gr)<<" x^"<<nuev_gr<<endl;
}
void Polinomio::Mostrar_pol(){ 
	for(int i=0;i<m_grad;i++) { 
		cout<<*(coef + i)<<" x^"<<i<<" + ";
	}; 
}
