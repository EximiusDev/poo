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
#include <cmath>
using namespace std;

class Polinomio{
	int m_grad;
	float * coef;
public:
	Polinomio(int grad);
	Polinomio(const Polinomio &p2); /// Costructor por copia
	void Cambio_coef(int , float nuev_coef);
	void Mostrar_pol();
	/// float * Ver_Polinomio(); //// FALTAAA TERMINARRRRRRR
	////////////////////////////////////////////////////////////
	///fALTA SUMA DE POLINOMIOS
	//((((((((((((((((((((((((((((((()))))))))))))))))))))))))))))))
	float Evaluar_Pol(float);
	~Polinomio(); /// Destructor
};


int main() {
	
	Polinomio P1(3);
	cout<<endl;
	P1.Cambio_coef(3 , 2.5);
	P1.Cambio_coef(0 , 1000);
	cout<<endl;
	P1.Mostrar_pol();
	cout<<endl;
	float x = 2;
	cout<<"Evaluar pol en x = "<<x<<" es igual a = "<<P1.Evaluar_Pol(x);
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
float Polinomio::Evaluar_Pol(float x){
	float y = 0;
	for(int i=0;i<m_grad;i++) { 
		y = y + ( coef[i] )* (pow(x,i));
	}
	return y;
}


Polinomio::Polinomio(const Polinomio &p2){ /// Constructor de copia
	m_grad = p2.m_grad; /// el que llamo sin el nombre es el objeto nuevo, y el que va con nombre es el que paso para copiar
	coef = new float [m_grad]; /// creo memoria para el puntero (porque no esta inicializado, o sea el contructor no existe)
	for(int i=0;i<m_grad;i++) { 
		/// *(coef + i)= *(p2.coef + i); // igual al siguirnte:
		coef[i]=p2.coef[i];
	}
}
Polinomio::~Polinomio(){
	delete []coef;
}
