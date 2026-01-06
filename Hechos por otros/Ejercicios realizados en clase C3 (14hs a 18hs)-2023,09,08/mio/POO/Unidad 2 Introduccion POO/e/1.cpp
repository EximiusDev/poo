#include <iostream>

#include <cmath>
using namespace std;



class Cilindro{
private:	
	float m_r, m_h;
public:
	Cilindro():m_r(0),m_h(0){};
	Cilindro(float r,float h):m_r(r),m_h(h){ }
	void AsignarDatos(float r,float h){
		m_r=r;
	    m_h=h;
	}
    float ObtenerVolumen(){
		return 3.1415 *m_r * m_r * m_h;
	}	
};


int main(int argc, char *argv[]) {
	Cilindro c1,c2(5.3,10.2);
	float a,b;
	cin>>a>>b;
	c1.AsignarDatos(a,b);
	cout<<"\nCilindro c1: "<<c1.ObtenerVolumen();
	cout<<"\nCilindro c2: "<<c2.ObtenerVolumen();
	return 0;
}

