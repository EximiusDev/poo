#include <iostream>
#include <cmath>
using namespace std;

class EcuacionCuadratica{
  private:
	int m_a,m_b,m_c;
	float m_r1,m_r2;
	bool m_tipo;
	void ObtenerRaices();
public:
	EcuacionCuadratica(int aa,int bb,int cc):m_a(aa),m_b(bb),m_c(cc){
		ObtenerRaices(); 
		m_tipo = m_b * m_b - 4 * m_a * m_c >= 0;
	}
	bool TieneRaicesReales(){return m_tipo;}
	float VerRaiz1(){return m_r1;}
	float VerRaiz2(){return m_r2;}
	float VerParteReal(){return m_r1;}
	float VerParteImag(){return m_r2;}
};

void EcuacionCuadratica::ObtenerRaices(){
	float d = m_b * m_b - 4 * m_a * m_c;
	if(d>=0){
		m_r1=(-m_b+sqrt(d))/(2.0*m_a);
		m_r2=(-m_b-sqrt(d))/(2.0*m_a);
	} else {
		m_r1=-m_b/(2.0*m_a);
		m_r2=sqrt(-d)/(2.0*m_a);
	}
}

int main(int argc, char *argv[]) {
	int a,b,c;
	cout<<"Ingrese los coeficientes a,b,c: ";
	cin>>a>>b>>c;
	EcuacionCuadratica e(a,b,c);
	if (e.TieneRaicesReales()){
		cout<<"\nraices reales:\n";
		cout<<"R1: "<<e.VerRaiz1()<<endl;
		cout<<"R2: "<<e.VerRaiz2()<<endl;
	} else {
		cout<<"\nraices complejas:\n";
		cout<<"R1: "<<e.VerParteReal()<<" + "<<e.VerParteImag()<<endl;
		cout<<"R2: "<<e.VerParteReal()<<" - "<<e.VerParteImag()<<endl;
	}
	
	
	
	return 0;
}

