#include <iostream>
using namespace std;

class Cilindro{
private:
	float alt,rad;
public:
	void AsignarDatos(float _a, float _r){
		alt=_a;
		rad=_r;
	}
	float ObtenerVolumen();
};

float Cilindro::ObtenerVolumen(){
	return 3.1415*rad*rad*alt;
}

int main(int argc, char *argv[]) {
    Cilindro c1,c2;
	float r,h;
	cout<<"Ingrese al radio y la altura del cilindro c1: ";
	cin>>r>>h;
	c1.AsignarDatos(r,h);
	c2.AsignarDatos(5.3,10.2);
	cout<<"\nVolumen del cilindro c1: "<<c1.ObtenerVolumen();
	cout<<"\nVolumen del cilindro c2: "<<c2.ObtenerVolumen();
	return 0;
}

