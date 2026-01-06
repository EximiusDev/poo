/* Ejercicio 3
Implemente una clase Monomio para representar un monomio de la forma a*x
n a
partir de un coeficiente y un exponente, con un método Evaluar(...) que reciba un
real y retorne el valor del monomio evaluado con ese real, y los demás métodos
que considere necesarios. Implemente, luego, una clase Polinomio que reutilice la
clase Monomio para modelar un polinomio, y añada un método Evaluar(...) para
evaluar un polinomio en un valor x real dado. ¿Qué relación debe haber entre las
clases Monomio y Polinomio?
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Monomio{
	float m_coef;
	int m_expon;
public:
	Monomio(float coef=0, int expon=0){m_coef=coef; m_expon=expon;}
	float Evaluar(float x); //que reciba un real y retorne el valor del monomio evaluado con ese real
	void CabiarExp(int expon){m_expon=expon;}
	void CabiarCoef(int coef){m_coef=coef;}
	int VerExp(){return m_expon;}
};



class Polinomio{
	vector<Monomio>Monomios;
public:
	Polinomio(int cant=0):Monomios(){
		Monomios.resize(cant + 1);
		for(unsigned int i=0;i<Monomios.size();i++) { 
			Monomios[i].CabiarCoef(0); 
			Monomios[i].CabiarExp(i); 
		}
	}
	//Polinomio():Monomios(float coef=0, int expon=0){}
	//Polinomio():Monomios(float coef, int expon){}
	//Polinomio(""""):Monomios("""");
	//Polinomio(){}
	float Evaluar(float x); /// 
	int VerGrado(){return Monomios.size();}
	Monomio VerMonomio(int i){return Monomios[i];}
	void CambiarMonomio(Monomio M);
	void CambiarMonomio(int );
	
};

int main() {
	
	Monomio M1;
	Monomio M2(2.5,2);
	
	cout<<M1.Evaluar(10)<<endl;
	cout<<M2.Evaluar(10)<<endl;
	cout<<endl;
	
	Polinomio P1;
	Polinomio P2(5);
	
	cout<<"P1: ";
	for(int i=0;i<P1.VerGrado();i++) { 
		Monomio aux = P1.VerMonomio(i);
		cout<<" + "<<aux.Evaluar(1)<<"x^"<<i;
	}
	cout<<endl;
	cout<<"P2: ";
	for(int i=0;i<P2.VerGrado();i++) { 
		Monomio aux = P2.VerMonomio(i);
		cout<<" + "<<aux.Evaluar(1)<<"x^"<<i;
	}
	cout<<endl;
	
	P1.CambiarMonomio(M2);
	P1.CambiarMonomio(3);
	cout<<"P1: ";
	for(int i=0;i<P1.VerGrado();i++) { 
		Monomio aux = P1.VerMonomio(i);
		cout<<" + "<<aux.Evaluar(1)<<"x^"<<i;
	}
	cout<<endl;
	return 0;
}

float Monomio:: Evaluar(float x){
	return 1.0*m_coef*(pow(x,m_expon));
}
void Polinomio::CambiarMonomio(Monomio M){
	 int n = Monomios.size();
	Monomios.resize(M.VerExp()+1);
	if(M.VerExp()>n){
		for(int i=n;i<M.VerExp();i++) { 
			Monomios[i].CabiarCoef(0); 
			Monomios[i].CabiarExp(i);
		}
	} 
	Monomios[M.VerExp()] = M;
}
void Polinomio::CambiarMonomio(int tam){
	 int n = Monomios.size();
	Monomios.resize(tam+1);
	if(tam>n){
		for(int i=n;i<tam;i++) { 
			Monomios[i].CabiarCoef(0); 
			Monomios[i].CabiarExp(i);
		}
	}
}
