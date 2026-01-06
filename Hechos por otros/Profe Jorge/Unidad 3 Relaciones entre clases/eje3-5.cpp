#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
//**********************************************
class Monomio{    // coef.x^grado
	int grado;
	float coef;
public:
	Monomio(float co, int gr):grado(gr),coef(co){};
	void Asignar(float co, int gr){grado= gr; coef=co;}
	float VerCoef(){return coef;}
	int VerGrado(){return grado;}
	float Evaluar(float x){return coef*pow(x,grado);}
};

class Polinomio{
	vector<Monomio> p;
public:
	Polinomio(){}																//constructor para un crear polinomio sin parámetros					
	Polinomio(int g){															//sobrecarga del constructor creando un polinomio de grado n vacío
		for(int i=0;i<=g;i++) 
			p.push_back(Monomio(0,i));
	}
	void AgregarTermino(Monomio &m){ p.push_back(m);}                            //allternativa a)
	//void AgregarTermino(float co, int gr){p.push_back(Monomio(co,gr));}       //alternativa b)
	//void ApregarTermino(float co, int gr){Monomio m(co,gr); p.push_back(m);}   //alternativa c)
		
	void ModificarTermino(float co, int gr){p[gr].Asignar(co,gr);}
	float Evaluar(float vx){
		float vp= 0;
		for(unsigned int i=0;i< p.size(); i++)
			vp += p[i].Evaluar(vx);
		return vp;
	}
	float VerCoef(int gra){return p[gra].VerCoef();}
	float VerGrado(){return p.size()-1;}
};

int main(int argc, char *argv[]){
	int grado;
	float c,x;
	cout<<"Ingrese el grado del polinomio: "; cin>>grado;
	//Polinomio poli(grado);
	Polinomio poli;
	
	for (int k=0; k<=grado; k++){
		cout<<"ingrese coeficiente para el grado "<<k<<": ";
		cin>>c;
	    Monomio aux(c,k);
		poli.AgregarTermino(aux);         //si uso el constructor     Polinomio poli;  
		//  poli.AgregarTermino(c,k);    //si uso el constructor     Polinomio poli;  usando la alternativa b(o c)
		//  poli.ModificarTermino(c,k);   //si uso el constructor     Polinomio poli(grado);
		
	}
		
	cout<<"\nPolinomio: ";
	for (int k=poli.VerGrado();k>=0; k--){
		if(k!=poli.VerGrado())
		{	if(k==0)
			    cout<<" + "<<poli.VerCoef(k);
			else
				cout<<" + "<<poli.VerCoef(k)<<"x^"<<k;
		}
		else
			   cout<<poli.VerCoef(k)<<"x^"<<k;
	}
	cout<<endl;
	cout<<"Ingrese un valor para x: ";cin>>x;
	cout<<"El valor del polinomio en x= "<<x<<" es = "<<poli.Evaluar(x)<<endl;
	return 0;
}	
