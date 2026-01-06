#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
//**********************************************
class Monomio{    // a.x^n
	int n;
	float a;
public:
	Monomio(int gr,float aa):n(gr),a(aa){};
	void asignar(int gr,float aa){n= gr;a=aa;}
	float ver_a(){return a;}
	int ver_n(){return n;}
	float evaluar(float x){return a*pow(x,n);}
};

class Polinomio{
	vector<Monomio> p;
public:
	Polinomio(){}
	Polinomio(int g){
		for(int i=0;i<=g;i++) 
			p.push_back(Monomio(i,0));
	}
	void agregarTermino(int nn,float aa){p.push_back(Monomio(nn,aa));}
	//void agregarTermino(float aa,int nn){Monomio m(aa,nn); p.push_back(m);}
	void agregarTermino(Monomio &m){p.push_back(m);}
	void modificarTermino(int nn,float aa){p[nn].asignar(nn,aa);}
	float evaluar(float vx){
	   float vp= 0;
	   for(unsigned int i=0;i< p.size(); i++)
			vp += p[i].evaluar(vx);
	   return vp;
	}
	float verCoef(int gra){return p[gra].ver_a();}
	float verGrado(){return p.size()-1;}
};

int main(int argc, char *argv[]){
	int grado;
	float c,x;
	cout<<"Ingrese el grado del polinomio: "; cin>>grado;
	Polinomio poli;
	//Polinomio poli(grado);
	
	for (int k=0; k<=grado; k++){
		cout<<"ingrese coeficiente para el grado "<<k<<": ";
		cin>>c;
		Monomio w(k,c);
		poli.agregarTermino(w);
	//	poli.agregarTermino(k,c);
	//	poli.modificarTermino(k,c);
	}
	
	
	cout<<"\nPolinomio: ";
	for (int k=poli.verGrado();k>=0; k--){
		if(k!=poli.verGrado())
			cout<<" + "<<poli.verCoef(k)<<"x^"<<k;
		else
			cout<<poli.verCoef(k)<<"x^"<<k;
	}
	cout<<endl;
	cout<<"Ingrese un valor para x: ";cin>>x;
	cout<<"El valor del polinomio en x= "<<x<<" es = "<<poli.evaluar(x)<<endl;
	return 0;
}	
