#include <iostream>
using namespace std;

class Fraccion{
private:
	int num, den;
public:
	Fraccion(int n, int d):num(n),den(d){}
	int ver_numerador(){return num;};
	int ver_denominador(){return den;};
	double convertirADoble(){return (double)num/(double)den;}
};

class NumeroMixto{
	int ent;
	Fraccion impropia;
public:
	NumeroMixto(int e, int n, int d):impropia(n,d){ent=e;}
	int ver_entero(){return ent;}
	int ver_numerador_imp(){return impropia.ver_numerador();}
	int ver_denominador_imp(){return impropia.ver_denominador();}
	double convertirADoble(){return (ent+impropia.convertirADoble());}
};

int main(int argc, char *argv[]) {
	NumeroMixto Num(2,1,4);
	Num.convertirADoble();
	cout<<Num.ver_entero()<<" y "<<Num.ver_numerador_imp()<<"/"<<Num.ver_denominador_imp()<<endl;
	cout<<"Decimal: "<<Num.convertirADoble()<<endl;
	return 0;
}
