#include <iostream>
#include <sstream>
using namespace std;
class Racional{
int num,den;
public:
	Racional(){}
	Racional(int n,int d):num(n),den(d){}
	int VerNum(){return num;}
	int VerDen(){return den;}
	void AsignarDen(int x){den=x;}
	void AsignarNum(int x){num=x;}
	//Racional operator+(Racional &x);
	string Ver(){stringstream ss; ss<<num<<"/"<<den;return ss.str();}
	Racional & operator++();
	Racional operator++(int);
	int operator[](int i)const;   //para leer
	int & operator[](int i);   //para asignar
	
	
};


int Racional::operator[](int i)const {
	if (i==1) return num;
	return den;
}

int & Racional::operator[](int i){
	if (i==1) return num;
	return den;
}


Racional & Racional::operator++(){ //preincremento
	num=num+den;
	return *this;
}

Racional Racional::operator++(int){ //posincremento
	Racional aux=*this;
	num=num+den;
	return aux;
}


istream &operator>>(istream &i, Racional &x){
	int a,b;
	i >>a>>b;
	x.AsignarNum(a);
	x.AsignarDen(b);
	return i;
}

ostream & operator<<(ostream &o, Racional &x){
	o<<x.VerNum()<<"/"<<x.VerDen();
	return o;
}

	
/*Racional Racional::operator+(Racional &x){
	Racional aux(num*x.VerDen()+x.VerNum()*den, den*x.VerDen());
	return aux;
}
*/

Racional operator+(Racional &y, Racional &x){
	int n = y.VerNum()*x.VerDen()+x.VerNum()*y.VerDen();
	int d = y.VerDen()*x.VerDen();
	return Racional(n,d);
	//Racional aux(y.VerNum()*x.VerDen()+x.VerNum()*y.VerDen(), y.VerDen()*x.VerDen());
	//return aux;
}

Racional operator*(Racional &y, Racional &x){
	Racional aux(y.VerNum() * x.VerNum(), y.VerDen() * x.VerDen());
	return aux;
}


bool operator==(Racional &y, Racional &x){
	return y.VerNum()*x.VerDen() == x.VerNum()*y.VerDen();
}
bool operator<(Racional &y, Racional &x){
	return y.VerNum()*x.VerDen() < x.VerNum()*y.VerDen();
}

bool operator>=(Racional &y, Racional &x){
	return !(y<x);
}

bool operator!=(Racional &y, Racional &x){
	return !(y==x);
}

bool operator>(Racional &y, Racional &x){
	return y.VerNum()*x.VerDen() > x.VerNum()*y.VerDen();
}

bool operator<=(Racional &y, Racional &x){
	return !(y>x);
}


int main(int argc, char *argv[]) {
	Racional q(5,3),w(1,2),r;
	r=q+w;
	//cout<<"ingrese racional: ";
	//cin>>r;
	cout<< "q: "<< q <<endl;;
	cout<< "w: "<< w <<endl;
	if (q==w) cout<<"q es igual a w\n";
	if (q<=w) cout<<"q es menor o igual que w\n";
	if (q>=w) cout<<"q es mayor o igual que w\n";
	if (q!=w) cout<<"q es distinto que w\n";
	if (q<w) cout<<"q es menor que w\n";
	if (q>w) cout<<"q es mayor que w\n";
	
	cout<<"r: "<< r<<endl;
	cout<<"numerador de r: "<<r[1]<<endl;
	r[1]=2;
	cout<<"r: "<< r <<endl;
	
	
	return 0;
}

