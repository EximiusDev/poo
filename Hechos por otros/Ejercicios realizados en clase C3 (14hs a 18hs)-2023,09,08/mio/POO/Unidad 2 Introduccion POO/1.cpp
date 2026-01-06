#include <iostream>
using namespace std;

class Cilindro{
	float m_r, m_a;
public:
	Cilindro(float ar, float aa):m_r(ar), m_a(aa) {}
	Cilindro(){}
//	1 : sobrecarga de constructor sin parametros (junto con lo de arriba)
		
//	Cilindro(float ar=0, float aa=0):m_r(ar), m_a(aa) {}
//	2 : pasaje de parametros por defecto (sustituye las 2 lineas anteriores)
    //problema si hay 1 parametro
	
	void AsignarDatos(float ar, float aa){
		m_r=ar; 
		m_a=aa;
	}
	float ObtenerVolumen();
};

float Cilindro::ObtenerVolumen(){
	return 3.14 * m_r * m_r * m_a;
}	
	

int main(int argc, char *argv[]) {
	Cilindro c1,c2;
	float r,h;
	cout<<"ingrese radio y altura:";
	cin>>r>>h;
	c1.AsignarDatos(r,h);

	cout<<"volumen c1: "<<c1.ObtenerVolumen()<<endl;
	cout<<"volumen c2: "<<c2.ObtenerVolumen()<<endl;
	return 0;
}

