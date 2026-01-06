#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
class Polinomio{
private:
	int grado,coef[20];
public:
	Polinomio(int _g){
		grado=_g;
		for(int i=0;i<=grado;i++)
			coef[i]=0;
	}
	void CambiaCoef(int _g,int _v) {coef[_g]=_v;}
	int Evalua(int _x);
	string VerTermino(int _x){
		stringstream s;
		s<<coef[_x]<<".x^"<<_x;
		return s.str();
	}
	int VerGrado(){return grado;}
	int VerCoef(int _x){return coef[_x];}
	Polinomio Sumar(Polinomio &x2);
};

int Polinomio::Evalua(int _x){
	int s=0;
	for(int i=0;i<=grado;i++) { 
		s=s+coef[i]*pow(_x,i);
	}
	return s;
}

Polinomio Polinomio::Sumar(Polinomio &x2){
	int gra,a,b;
	/*if(grado>x2.VerGrado()) 
		gra=grado; 
	else
		gra=x2.VerGrado(); 
	*/
	gra=max(grado,x2.VerGrado());
		
	Polinomio aux(gra);
	for(int i=0;i<=gra;i++) { 
		a=coef[i];
		b=x2.VerCoef(i);
		if(i>grado) a=0;    //por si no son del mismo grado
		if(i>x2.VerGrado()) b=0;	//por si no son del mismo grado
		aux.CambiaCoef(i,a+b);
    }
	return aux;
} 

//funcion independiente
Polinomio Sumar(Polinomio &x1,Polinomio &x2){
	int gra,a,b;
	/*if(x1.VerGrado()>x2.VerGrado()) 
		gra=x1.VerGrado(); 
	else
		gra=x2.VerGrado(); 
	*/
	gra=max(x1.VerGrado(),x2.VerGrado());
	Polinomio aux(gra);
	for(int i=0;i<=gra;i++) { 
		a=x1.VerCoef(i);
		b=x2.VerCoef(i);
		if(i>x1.VerGrado()) a=0;    //por si no son del mismo grado
		if(i>x2.VerGrado()) b=0;	//por si no son del mismo grado
		aux.CambiaCoef(i,a+b);
	}
	return aux;
} 

	
	
int main(int argc, char *argv[]) {
	int N;
	cout<<"Ingrese el grado del polinomio 1: ";
	cin>>N;
	Polinomio p1(N);
	int c;
	for(int i=p1.VerGrado();i>=0;i--) { 
		cout<<"Ingrese el coeficiente para el grado "<<i<<": ";
		cin>>c;
		p1.CambiaCoef(i,c);
	}
	
	cout<<"\n\nIngrese el grado del polinomio 2: ";
	cin>>N;
	Polinomio p2(N);
	for(int i=p2.VerGrado();i>=0;i--) { 
		cout<<"Ingrese el coeficiente para el grado "<<i<<": ";
		cin>>c;
		p2.CambiaCoef(i,c);
	}
	
	cout<<"\nPolinomio1: ";
	for(int i = p1.VerGrado();i>0;i--)
		cout<<p1.VerTermino(i)<<" + ";
	cout<<p1.VerTermino(0)<<endl;
	
	cout<<"Polinomio2: ";
	for(int i = p2.VerGrado();i>0;i--) 
		cout<<p2.VerTermino(i)<<" + ";
	cout<<p2.VerTermino(0)<<endl;
	
	Polinomio su(19);
	
	su=Sumar(p1,p2);    //funcion independiente
	//su=p1.Sumar(p2);      //metodo de la clase
	
	
	cout<<"\nPolinomio Suma: ";
	for(int i = su.VerGrado();i>0;i--)  
		cout<<su.VerTermino(i)<<" + ";
	cout<<su.VerTermino(0)<<endl;
	
	
	
	return 0;
}

