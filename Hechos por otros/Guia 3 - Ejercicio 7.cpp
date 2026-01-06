#include <iostream>
using namespace std;

class Tanque{
	float cilindro;
	double peso;
	int radio, altura;
public:
	Tanque(float _cilindro, double _peso) : cilindro(_cilindro), peso(_peso){};
	virtual volumen(int radio, int altura)=0;
	void GetPeso(){
		return peso;
	}
};
class Cilindro : public Tanque{
	double area;
public:
	volumen(int radio, int volumen){
		
	}
};
int main() {
	
	return 0;
}

