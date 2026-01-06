#include <iostream>
using namespace std;

class Racional{
	int num,den;
public:
	Racional():num(0),den(1){}
	Racional(int n,int d):num(n),den(d){}
	int VerNum(){return num;}
	int VerDen(){return den;}
	void AsignarNum(int x){num=x;}
	void AsignarDen(int x){den=x;}
	//Racional operator+ (Racional &y);     //si quiesiera que sea miembro de la clase
	Racional operator* (Racional &y);
	Racional & operator++();   //preincremento
	Racional operator++(int);   //posincremento
/*	Racional & operator=(Racional &x){
		num=x.num;
		den=x.den;
		return *this;
	}*/
	bool operator<(Racional &x){
		return num * x.VerDen() < x.VerNum() * den  ;
	}
	
	bool operator>=(Racional &x){
		return !(*this < x)  ;
	}
		
	int & operator[](int x){
		if(x==1) return num;
		else return den;
	}
	
//		friend istream & operator>>(istream &i, Racional &x);
		
	
};

Racional Racional::operator++(int){
   Racional aux=*this;
   num=num+den;
   return aux;
}

Racional & Racional::operator++(){
	num=num+den;
	return *this;
}

/*Racional Racional::operator+ (Racional &y){
	int n= num*y.den + y.num *den;
	int d= den*y.den;
	return Racional(n,d);
}
*/

Racional Racional::operator* (Racional &y){
    return Racional(num * y.num, den * y.den);
}


// funciones globales de sobrecarga

Racional operator + (Racional &x, Racional &y){
	int n= x.VerNum()*y.VerDen() + y.VerNum()*x.VerDen();
	int d= x.VerDen()*y.VerDen();
	return Racional (n,d);
}

bool operator==(Racional &x, Racional &y){         
//  cout<<x.VerNum()*y.VerDen()<<endl;
//  cout<<y.VerNum()*x.VerDen()<<endl;
	//a/b  == c/d   ->  a*d == c*b
	return x.VerNum()/y.VerDen() == y.VerNum()/x.VerDen() ;
}

bool operator!=(Racional &x, Racional &y){
	return !(x==y) ;
}

ostream & operator<<(ostream &o, Racional &x){
	o << x.VerNum() <<"/"<<x.VerDen();
	return o;
}

istream & operator>>(istream &i, Racional &x){
	//int n,m;
	//i>>n>>m;
	i >> x[1] >> x[2];
//	i>>x.num>>x.den;      //si uso friend
	/*x[1]=n;
	x[2]=m;
	*/
	//x.AsignarNum(n);
	//x.AsignarDen(m);
	return i;
}



int main(int argc, char *argv[]) {
	Racional t(5,6),q(1,2),w(3,4),r,h;
	
	r=t;
	h=t*q;
	if (t==r) cout<<"son iguales\n";
	else cout<<"son distintos\n";
	if (t!=w) cout<<"son distintos\n";
	else cout<<"no son distintos\n";
	if (q<w) cout<<"q es menor a w\n";
	   else cout<<"q no es menor a w\n";
	if (t>=w) cout<<"t es mayor o igual a w\n";
	  else cout<<"t es mayor o igual a w\n";
	
	cout<<t.VerNum()<<"/"<<t.VerDen()<<endl;
	cout<<q.VerNum()<<"/"<<q.VerDen()<<endl;
	cout<<w.VerNum()<<"/"<<w.VerDen()<<endl;
	cout<<r.VerNum()<<"/"<<r.VerDen()<<endl;
	cout<<h.VerNum()<<"/"<<h.VerDen()<<endl;
	
	cout<<h[1]<<"/"<<h[2]<<endl;

	/*int n,m;
	cin>>n>>m;
	Racional aux(n,m);
	*/
	Racional aux;
	cin>>aux;      //usando la sobrecarga de >>
	
	
	cout<<"salida sobrecargada: "<< aux <<endl;
	
	cout<<t<<endl<<q<<endl<<w<<endl<<r<<endl<<h<<endl;
	return 0;
}


