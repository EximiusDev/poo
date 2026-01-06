#include <iostream>
using namespace std;

class Racional{
	int num, den;
public:
	Racional(int n=0, int d=0):num(n),den(d){}
	///Racional(int n, int d){num = n ; den = d;} /// constructor funiona como el anterior
	int VerNum(){return num;}
	int VerDen(){return den;}
	void Asignar(int n, int d){num = n; den = d;}
	/*Racional operator+(Racional r){ /// funciona pero ya hay una sobrecarga de (+) como funcion
		int aux1, aux2;
		aux1 = num * r.den + r.num * den;
		aux2 = den * r.den;
		Racional Suma(aux1, aux2);
		return Suma;
	}*/
	bool operator<(Racional r){
		return (num* r.VerDen() < r.VerNum() * den); /// pregunto si es verdadera o falsa la expresion
	}
	bool operator> (Racional r){
		return ( !(*this < r) ); // si este objeto no es < a r es true
		// return (num* r.VerDen() < r.VerNum() * den); /// Sino hago esto
	}
	Racional & operator++(){ /// Preincremento
		num = num + den;
		return *this;
	}
	Racional operator++(int ){ /// Postincremento (necestia el int)
		Racional previo = *this;
		num = num + den; /// aumento el valor
		return previo; /// retorno el valor previo para mostrar ese valor, y no el actual
	}
	int operator[](int x){ /// Sirve para trabajar los metodos de la clase como las componentes de un vector
		if (x==0) return num; // es obligatoriamente miembro de la clase la sobrecarga de []
		else return den;
	}
	//int operator*(int x){
	Racional operator*(Racional r){
		Racional aux(r.num * num , r.num * num);
		//aux.num = r.num * num;
		//aux.den = r.num * num;
		return aux;
	}
};

ostream & operator<<(ostream & outp, Racional &x){ /// sobrecarga de << para cout de Racional
	outp << x.VerNum()<<"/"<<x.VerDen();
	return outp;
}
istream & operator>>(istream &ent, Racional &x){ /// sobrecarga de >> para cin de Racional
	int z,w;
	cout<<"numerador: ";
	ent>> z;
	cout<<"denominador: ";
	ent>> w;
	/// x.Asignar(z,w);
	return ent;
}

Racional operator+(Racional t, Racional r){
	Racional Suma(t.VerNum()* r.VerDen() + r.VerNum()* t.VerDen() , t.VerDen()* r.VerDen());
	return Suma;
}

int main() {
	
	Racional q(2,3), w(3,4) , h;
	Racional s = q+w; /// Aplicacion de sobrecarga de operadores (+) desde la clase racional
	//Racional S(q+w); // Igual que lo anterior
	
	cout<<"q: "<<q.VerNum()<<"/"<<q.VerDen()<<endl;
	
	cout<<"w: "<<w[0]<<"/"<<w[1]<<endl;
	
	cout<<"s(q+w): "<<s<<endl;
	
	cout<<"h: "<<h<<endl;
	
	h.Asignar(1,2);
	
	cout<<"nuevo valor de h: "<<h<<endl;
	
	
	
	if(q<w) cout<<"q es menor \n";
	else cout<<"w es menor \n";
	
	return 0;
}

