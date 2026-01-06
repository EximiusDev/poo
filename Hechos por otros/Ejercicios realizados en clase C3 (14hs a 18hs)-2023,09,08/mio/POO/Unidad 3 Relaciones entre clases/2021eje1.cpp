#include <iostream>
#include <vector>
using namespace std;

class Persona{
	string nya;
	int dni, fn;    	//aaaammdd
	char ec;			//s c v d
public:
	Persona(string x, int y, int z, char w){
		nya=x; dni=y; fn=z; ec=w;
	}
	/*void cargaDatos(string x, int y, int z, char w){
		nya=x; dni=y; fn=z; ec=w;
	}*/
	string VerNyA(){return nya;}
	int VerDni(){return dni;}
	int VerFn(){return fn;}
	char VerEc(){return ec;}
	~Persona(){}
};

class Alumno:public Persona{
	float prom;
	int matApr;
public:
	//Alumno():Persona("",0,0,' '),prom(0),matApr(0){}
	Alumno(string xnya, int xdni, int xfn, char xec, float xpro, int xma):
		  Persona(xnya,xdni,xfn,xec),prom(xpro),matApr(xma){}
	Alumno(Persona &xp, float xpro, int xma):Persona(xp),prom(xpro),matApr(xma){}
	float VerProm(){return prom;}
	int VerMA(){return matApr;}
	float MeritoAcademico(){return prom*matApr;}
	~Alumno(){}
};

class Docente:public Persona{
	int fIng;
public:
	Docente(string xnya, int xdni, int xfn, char xec, int xfing):
		Persona(xnya,xdni,xfn,xec),fIng(xfing){}
	Docente(Persona &xp, int xfing):Persona(xp),fIng(xfing){}
	
	int VerFI(){return fIng;}
	float Antiguedad(int xfechaactual){return (xfechaactual-fIng)/10000;}   
	~Docente(){}
};

int main(int argc, char *argv[]) {
	Docente doc("juan",123123,20110304,'s',20111103);
	vector <Alumno>a;
	string n;
	int d,f,cm,c;
	float pr;
	char eci;
	cout<<"ingrese cantidad de alumnos a cargar:";
	cin>>c;
	for(int i=0;i<c;i++) {
		cout<<"ingrese nombre, dni, fecha nac, eciv, prom, mat apro:";
		cin>>n>>d>>f>>eci>>pr>>cm;
		a.push_back(Alumno(n,d,f,eci,pr,cm));
	}
	cout<<"Docente y antigüedad:"<<doc.VerNyA()<<"     "<<doc.Antiguedad(20210910)<<" años\n";
	cout<<"listado\n";
	for(int i=0;i<a.size();i++) { 
		cout<<a[i].VerNyA()<<"     merito  "<<a[i].MeritoAcademico()<<endl;
	}
	
	return 0;
}

