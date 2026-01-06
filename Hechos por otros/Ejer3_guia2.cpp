#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Polinomio{
public:
	Polinomio(int g){
		m_g = g;
		coef.resize(g+1,0);
	}
	void CargarCoef(int g, float c){
		coef[g] = c;
	}
	int VerGrado(){
		return coef.size()-1;
	}
	float VerCoef(int g){
		return coef[g];
	}
	float Evaluar(float x){
		float EvPol = 0;
		for(size_t g = 0;g<coef.size();g++){
			EvPol += coef[g] * pow(x,g);
		}
		return EvPol;
	}
private:
	int m_g;
	float x;
	vector<float> coef;
};




int main() {
	int g;
	cin>>g;
	Polinomio P(g);
	
	P.CargarCoef(0,-6);
	P.CargarCoef(3,7);
	P.CargarCoef(1,1);
	cout<<"EL POLINOMIO ES DE GRADO "<<P.VerGrado()<<endl;
	cout<<"---------------------"<<endl;
	cout<<"POLINOMIO"<<endl;
	for(size_t g = 0;g<P.VerGrado();g++){
		cout<<P.VerCoef(g)<<"X^"<<g<<endl;
	}
	int x;
	cin>>x;
	float result;
	result = P.Evaluar(x);
	cout<<"Resultado de evaluar el polinomio: "<<result<<endl;
	
	
	
	return 0;
}
