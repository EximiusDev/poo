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
};

int Polinomio::Evalua(int _x){
	int s=0;
	for(int i=0;i<=grado;i++) { 
		s=s+coef[i]*pow(_x,i);
	}
	return s;
}

	
	
int main(int argc, char *argv[]) {
	int N,x;
	cout<<"Ingrese el grado del polinomio: ";
	cin>>N;
	Polinomio p(N);
	int c;
	for(int i=p.VerGrado();i>=0;i--) { 
		cout<<"Ingrese el coeficiente para el grado "<<i<<": ";
		cin>>c;
		p.CambiaCoef(i,c);
	}
	cout<<"\nPolinomio: ";
	for(int i = p.VerGrado();i>0;i--) { 
		cout<<p.VerTermino(i)<<" + ";
	}
	cout<<p.VerTermino(0)<<endl;
	cout<<"\nIngrese el valor de x para evaluar: ";
	cin>>x;
	cout<<"Resultado de P("<<x<<")= "<<p.Evalua(x)<<endl;
	
	
	
	
	return 0;
}

