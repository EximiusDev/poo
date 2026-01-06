#include <iostream>
using namespace std;

class Racional {
	int num,den;
public:
	Racional(int n=0, int d=1) : num(n), den(d) { }
	int VerNum() const { return num; }
	int VerDen() const { return den; }
//	Racional operator+(Racional x);
	Racional & operator++(){       //preincremento
		num+=den;
		return *this;
	}
	Racional operator++(int x){       //posincremento
		Racional aux=*this;
		num+=den;
		return aux;
	}
	bool operator<(Racional x){
		return num/(1.0*den) <  x.VerNum()/(1.0*x.VerDen());
	}
	
	int operator[](int x) const {
		if(x==0) return num;
		else return den;
	}
	
	int & operator[](int x) {
		if(x==0) return num;
		else return den;
	}
	
	Racional & operator=(Racional x){num=x.num; den=x.den; return *this;}
	
	
	
} ;

/*
// como miembro de la clase
Racional Racional::operator+(Racional x){
  Racional s( num*x.VerDen()+x.VerNum()*den , den*x.VerDen() );
  return s;
}

Racional Racional::operator+(Racional x){     //directamente sin usar los metodos del argumento
Racional s( num*x.num+x.num*den , den*x.den );
return s;
}

*/


//como funcion global
Racional operator+(Racional x, Racional y){
	Racional s( x.VerNum()*y.VerDen()+y.VerNum()*x.VerDen() , x.VerDen()*y.VerDen() );
	return s;	
}

Racional operator*(Racional x, Racional y){
	Racional s( x.VerNum()*y.VerNum() , x.VerDen()*y.VerDen() );
	return s;	
}

bool operator>(Racional x,Racional y){
	return x.VerNum()/(1.0*x.VerDen()) >  y.VerNum()/(1.0*y.VerDen());
}

bool operator<=(Racional x,Racional y){
	return not(x>y);
	//return x.VerNum()/(1.0*x.VerDen()) <=  y.VerNum()/(1.0*y.VerDen());
}
bool operator==(Racional x,Racional y){
	return x.VerNum()/(1.0*x.VerDen()) ==  y.VerNum()/(1.0*y.VerDen());
}
bool operator!=(Racional x,Racional y){
	return not (x==y);    //  o   x.VerNum()/(1.0*x.VerDen()) !=  y.VerNum()/(1.0*y.VerDen());
}

ostream & operator <<(ostream &o, Racional x){
	o << x.VerNum()<<"/"<<x.VerDen();
	return o;
} 

istream & operator >>(istream &i, Racional &x){
	/*int  n,d;
	i>>n>>d;
	x.asigNum(n);          //faltaria codificar estos metodos de asignacion en la clase
	x.asigDen(d);*/
	
//	i>> x.num>>x.den;       //implica que friend istream & operator >>(istream &i, Racional x)   en la clase
	
	i >> x[0] >> x[1];       // con sobrecarga del []
	return i;
}

int main(int argc, char *argv[]) {
	Racional r(1,5),q(1,4),s,p;
	
	Racional k;
	cin>>k;
	
	cout<<"\nel racional leido es k: "<<k<<endl;

	if (r!=q) cout<<"\nr es distinto a  q\n";
	else
		cout<<"\nr es igual que q\n";
	
	p=r*q;
	s=r+q;  

	cout<<"r: "<<r<<endl;
	cout<<"q: "<<q<<endl;
	cout<<"s: "<<s<<endl;
	cout<<"p: "<<p<<endl;
	
	r=p++;

	cout<<"\nr: "<<r<<endl;
	cout<<"p: "<<p<<endl;
	
	cout<<"\ncon corchetes: p: "<<p[0]<<"/"<<p[1]<<endl;
	
	p[0]=4;
	p[1]=5;
	cout<<"\nmodificado a traves de corchetes: p: "<<p[0]<<"/"<<p[1]<<endl;
	
	cout<<q<<" "<<r<<" "<<s<<" "<<p<<endl;
	return 0;
}

