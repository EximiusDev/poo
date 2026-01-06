#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>        
class VectorDinamico{
private:
	T *p;
	int cant;
	VectorDinamico(const VectorDinamico &v){};
	VectorDinamico &operator=(const VectorDinamico &v){};
public:
	template<typename TF>
	VectorDinamico(int x,TF pf);
	VectorDinamico(int x);
	~VectorDinamico(){cant=0;delete[]p;}
	T operator[](int x) const { return p[x];}
	T & operator[](int x) { return p[x];}
	int size(){return cant;}
};

template <typename T>
template<typename TF>
VectorDinamico<T>::VectorDinamico(int x,TF pf){
	cant=x;
	p=new T[cant];
	for(int i=0;i<cant;i++) { 
		p[i]=pf();
	}
}

template <typename T>
VectorDinamico<T>::VectorDinamico(int x){
	cant=x;
	p=new T[cant];
}

int entero(){
	return rand()%100;
}
	
float flotante(){
	return rand()%100+rand()%100/100.0;
}
		
string cadena(){
	string s(rand()%6+5,' ');
	 for(unsigned int i=0;i<s.size();i++) { 
	   s[i]=rand()%26+'a';
	}
	return s;
}
			
//funcion templatizada auxiliar para mostrar el vector
template <typename Q>
void Ver(VectorDinamico<Q> &x){
	for(int i=0;i<x.size();i++) { 
		cout<<x[i]<<"  ";
	}
	cout<<endl;
}


int main(int argc, char *argv[]) {
	VectorDinamico<float> a(4);
	a[0]=12.1;
	a[1]=23.2;
	a[2]=45.3;
	a[3]=67.4;
    Ver(a);	
	
	VectorDinamico<string> s(5);
	s[0]="casa";
	s[1]="vivienda";
	s[2]="hogar";
	s[3]="rancho";
	s[4]="carpa";
	Ver(s);	
	
	VectorDinamico<int> e(15);
	for(int i=0;i<15;i++) { e[i]=rand()%10;}
	Ver(e);

	VectorDinamico <float> q(10,flotante);
	VectorDinamico <string> w(5,cadena);
	VectorDinamico <int> t(20,entero);
	Ver(q);
	Ver(w);
	Ver(t);
		
	return 0;
}

