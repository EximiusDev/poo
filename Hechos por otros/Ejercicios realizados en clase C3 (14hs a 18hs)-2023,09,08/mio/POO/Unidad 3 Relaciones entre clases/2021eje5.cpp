#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

class Monomio{
	int n;
	float  coe;         //  coe*X^n
public:
	Monomio(int gr, float co):n(gr),coe(co){}
	void Asignar(int gr, float co){n=gr;coe=co;}
	int VerGrado(){return n;}
	float VerCoef(){return coe;}
	float Evaluar(float x){return coe*pow(x,n);}
};

class Polinomio{
	vector<Monomio> v;
public:
	Polinomio(){}
	Polinomio(int x){
		for(int i=0;i<=x;i++) { 
			v.push_back(Monomio(i,0));
		}
	}
	void ModificarMonomio(int gr,float co){v[gr].Asignar(gr,co);}
	float Evaluar(float x){
		float resultado=0;
		for(unsigned int i=0;i<v.size();i++)  
			resultado = resultado + v[i].Evaluar(x);
		return resultado;
	}
	float  VerCoef(int x){return v[x].VerCoef();}
	int VerGrado(){return v.size()-1;}
	
	string VerPolinomio(){
		stringstream s;
		for (int k=VerGrado();k>0; k--)
			s<<VerCoef(k)<<".x^"<<k<< " + ";
		s<<VerCoef(0);
		return s.str();
	}
		
};



int main(int argc, char *argv[]) {
	Polinomio p(3);
	cout<<"\nPolinomio creado: ";
	/*for (int k=p.VerGrado();k>0; k--)
			cout<<p.VerCoef(k)<<".x^"<<k<< " + ";
	cout<<p.VerCoef(0)<<endl;
	*/
	cout<<p.VerPolinomio()<<endl;
	
	
	p.ModificarMonomio(0,5);	
	p.ModificarMonomio(1,3);	
	p.ModificarMonomio(2,4);	
	p.ModificarMonomio(3,2);	
	
	cout<<"\nPolinomio Cargado: ";
	/*for (int k=p.VerGrado();k>0; k--)
		cout<<p.VerCoef(k)<<".x^"<<k<< " + ";
	cout<<p.VerCoef(0)<<endl;
	*/
	cout<<p.VerPolinomio()<<endl;
	cout<<"Evaluado en 2: "<< p.Evaluar(2);
	
	
	return 0;
}

