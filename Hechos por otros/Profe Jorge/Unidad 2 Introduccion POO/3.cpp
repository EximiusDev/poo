#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Polinomio{
private:
	float coef[20]; 
	int grado;
public:
	Polinomio(int x);
	void Asignar(int i,float c){coef[i]=c;}
	float VerCoef(int x){return coef[x];}
	int VerGrado(){return grado;}
	float Evaluar(int x);
	Polinomio Sumar(Polinomio &po); 
};
//constructor
Polinomio::Polinomio(int x=0){
	grado=x;
	for(int i=0;i<20;i++) 
		coef[i]=0;
} 

float Polinomio::Evaluar(int x){
	float s=0;
	for(int i=0;i<=grado;i++) { 
		s+= coef[i]*pow(x,i);
	}
	return s;
}

Polinomio Polinomio::Sumar(Polinomio &po){
	int g;
	if ( grado > po.VerGrado())
		g=grado;
	else
		g=po.VerGrado();
	Polinomio s(g);
	for(int i=0;i<=g;i++) {
		s.Asignar(i,coef[i]+po.VerCoef(i));
	}
	return s;
}
	


Polinomio Sumar(Polinomio &p1, Polinomio &p2){
	int g;
	if (p1.VerGrado()>p2.VerGrado())
		   g=p1.VerGrado();
	    else
		   g=p2.VerGrado();
	Polinomio s(g);
	//Polinomio s(max(p1.VerGrado(),p2.VerGrado());
	for(int i=0;i<=g;i++) {
		s.Asignar(i,p1.VerCoef(i)+p2.VerCoef(i));
	}
	return s;
}


int main(int argc, char *argv[]) {
	Polinomio p(4),q(2),suma; 
	p.Asignar(4,3);
	p.Asignar(3,2);
	p.Asignar(2,3);     
	p.Asignar(1,5);
	p.Asignar(0,2);    	
	q.Asignar(2,4);
	q.Asignar(1,8);
	q.Asignar(0,3);
	
	cout<<"\np= ";
	for(int i=0;i<=p.VerGrado();i++) { 
	   if(i!=0) cout<<" + ";
	   cout<< p.VerCoef(i) <<"*x^"<<i;
	}
	
	cout<<"\nq= ";
	for(int i=0;i<=q.VerGrado();i++) { 
		if(i!=0) cout<<" + ";
		cout<< q.VerCoef(i) <<"*x^"<<i;
	}
	cout<<"\nEvaluo p(x=2): "<<p.Evaluar(2);
	cout<<"\nEvaluo q(x=3): "<<q.Evaluar(3);
	
	//suma=p.Sumar(q);   // llamada a metodo de clase
	suma=Sumar(p,q);     //llamada a funcion libre
	
	cout<<"\nsuma= ";
	for(int i=0;i<=suma.VerGrado();i++) { 
		if(i!=0) cout<<" + ";
		cout<< suma.VerCoef(i) <<"*x^"<<i;
	}
	
	
	return 0;
}

