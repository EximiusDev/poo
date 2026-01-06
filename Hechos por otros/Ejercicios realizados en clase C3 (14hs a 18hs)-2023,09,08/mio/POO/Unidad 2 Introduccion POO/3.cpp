#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

class Polinomio{
private:
	int grado, coef[20];
public:
	Polinomio(int x){
		grado=x;
		for(int i=0;i<=grado;i++)
			coef[i]=0;
	}
	void CambiaCoef(int x, int y){ coef[x]=y;}
	int VerGrado(){return grado;}
	int VerCoef(int x){return coef[x];}
	int Evaluar(int x);
	Polinomio Sumar(Polinomio &x2);
	
	string VerTermino(int x){
		stringstream s;
		s<<coef[x]<<".x^"<<x;
		return s.str();
	}
		
	string VerPolinomio(){
	    stringstream s;
		for(int i=grado;i>0;i--) 
			s<<VerTermino(i)<<" + ";
		s<<VerTermino(0);
		return s.str();
	}	
		
		
		
};



int Polinomio::Evaluar(int x){
	int s=0;
	for(int i=0;i<=grado;i++) 
		s = s + coef[i]*pow(x,i);
	return s;
}

Polinomio Polinomio::Sumar(Polinomio &x2){ //metodo de la clase|
	int gra, a, b; 
	gra=max(grado,x2.VerGrado());
	Polinomio aux(gra);
	for(int i=0;i<=gra;i++) { 
		a=coef[i];
		b=x2.VerCoef(i);
		if(i>grado) a=0;
		if(i>x2.VerGrado()) b=0;
		aux.CambiaCoef(i,a+b);
	}
	return aux;
}


Polinomio Sumar(Polinomio &x1, Polinomio &x2){  //funcion libre
	int gra, a, b; 
	gra=max(x1.VerGrado(),x2.VerGrado());
	/*if(x1.VerGrado()>x2.VerGrado())        //es lo mismo que la linea anterior
		gra=x1.VerGrado(); 
	else
		gra=x2.VerGrado(); 
	*/
	Polinomio aux(gra);
	for(int i=0;i<=gra;i++) { 
		a=x1.VerCoef(i);
		b=x2.VerCoef(i);
		if(i>x1.VerGrado()) a=0;
		if(i>x2.VerGrado()) b=0;
		aux.CambiaCoef(i,a+b);
	}
	return aux;
}




int main(int argc, char *argv[]) {
	int n,n1;
	cout<<"ingrese grado del polinomio 1:";
	cin>>n;
	cout<<"ingrese grado del polinomio 2:";
	cin>>n1;
	
	Polinomio P(n),Q(n1);
	int c;
	for(int i=0;i<=P.VerGrado();i++) {
		cout<<"P coef grado "<< i<<":  ";
		cin>>c;
		P.CambiaCoef(i,c);
	}
	for(int i=0;i<=Q.VerGrado();i++) {
		cout<<"Q coef grado "<< i<<":  ";
		cin>>c;
		Q.CambiaCoef(i,c);
	}
	
	/*cout<<"P=";
	for(int i=P.VerGrado();i>=0;i--) { 
		cout<<P.VerCoef(i)<<"x^"<<i<<" + "; 
	}*/
	cout<<"P= "<<P.VerPolinomio();//reemplaza a lo de abajo
	/*cout<<"P= ";
	for(int i=P.VerGrado();i>0;i--) 
		cout<<P.VerTermino(i)<<" + ";
	cout<<P.VerTermino(0);
	*/
	cout<<endl<<endl;
	
	cout<<"Q= "<<Q.VerPolinomio();//reemplaza a lo de abajo
	/*cout<<"Q=";
	for(int i=Q.VerGrado();i>0;i--) 
		cout<<Q.VerTermino(i)<<" + ";
	cout<<Q.VerTermino(0);
	*/
	
	cout<<"\n\n P(2)= "<<P.Evaluar(2);
	
	Polinomio p_res(19);
	
	//p_res=Sumar(P,Q);
	
	p_res=P.Sumar(Q);
	
	
	cout<<endl<<endl;
	
	
	cout<<"p_res= "<<p_res.VerPolinomio();  //reemplaza a lo de abajo
	
	/*cout<<"p_res=";
	for(int i=p_res.VerGrado();i>0;i--) 
		cout<<p_res.VerTermino(i)<<" + ";
	cout<<p_res.VerTermino(0);
	*/
	
	return 0;
}

