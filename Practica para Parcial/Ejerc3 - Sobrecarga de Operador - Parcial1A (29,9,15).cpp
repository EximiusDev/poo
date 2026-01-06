/////////// Sin terminar
#include <iostream>
using namespace std;

class Fecha{
	int dia, mes, anio;
public:
	Fecha(int dia, int mes, int anio):dia(dia), mes(mes), anio(anio){}
	int VerDia(){return dia;}
	int VerMes(){return mes;}
	int VerAnio(){return anio;}
	bool operator<=(Fecha F2){
		return (this->dia <= F2.dia);
	}
	int operator[](int n){
		if(n==1) return dia;
		else if(n==2)return mes;
		else if(n==3)return anio;
		return -999;
	}
	/*
	ostream & operator<<(ostream & outp){
		outp<<dia;
		return outp;
	}*/
};
ostream & operator<<(ostream & outp, Fecha F){
	outp<<"Dia "<<F.VerDia()<<" Mes "<<F[2]<<" Anio "<<F[3];
	return outp;
}

int main() {
	
	Fecha F1(3,12,1999);
	Fecha F2(10,3,2002);
	
	if(F1 <= F2) cout<<"f1"<<endl;
	else cout<<"f2"<<endl;
	cout<<F1<<endl;
	cout<<F2<<endl;
	
	cout<<endl;
	
	cout<<F1[2]<<endl;
	cout<<F1.VerAnio()<<endl;
	
	return 0;
}

