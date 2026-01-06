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
    Alumno():Persona("",0,0,' '),prom(0),matApr(0){}
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
	Docente():Persona("",0,0,' '),fIng(0){}
	Docente(string xnya, int xdni, int xfn, char xec, int xfing):
		Persona(xnya,xdni,xfn,xec),fIng(xfing){}
	Docente(Persona &xp, int xfing):Persona(xp),fIng(xfing){}
	
	int VerFI(){return fIng;}
	float Antiguedad(int xfechaactual){return (xfechaactual-fIng)/10000;}   
	~Docente(){}
};

class Curso{
	Docente docente;
	vector <Alumno> alumnos;
	string materia;
public:
	Curso(string xmat,Docente xd):materia(xmat),docente(xd){}
	void AgregarAlumno(Alumno xa){
		alumnos.push_back(xa);
	}
	Alumno MejorPromedio(){
		int pm,mejor=0;
		for(int i=0;i<alumnos.size();i++) { 
			if(alumnos[i].VerProm() > mejor){
				mejor=alumnos[i].VerProm();
				pm=i;
			}
		}
		return alumnos[pm];
	}
	string VerMateria(){return materia;}
	Alumno VerAlumno(int xi){return alumnos[xi];}
	Docente VerDocente(){return docente;}
	int CantAlum(){return alumnos.size();}
	
};

int main(int argc, char *argv[]) {
	Docente doc("juan",123123,20110304,'s',20111103);
	Curso C("POO 2021",doc);
	string n;
	int c;
	float pr;
	cout<<"ingrese cantidad de alumnos a cargar:";
	cin>>c;
	for(int i=0;i<c;i++) {
		cout<<"ingrese nombre, prom:";
		cin>>n>>pr;
		Alumno a(n,0,0,' ',pr,0);
		C.AgregarAlumno(a);
	}
	Docente d;
	d=C.VerDocente();
	cout<<"Docente "<<d.VerNyA()<<"     "<<C.VerMateria()<<"\n";
	cout<<"listado\n";
	for(int i=0;i<C.CantAlum();i++) { 
//		cout<<C.VerAlumno(i).VerNyA()<<" promedio  :"<<C.VerAlumno(i).VerProm()<<endl;
       Alumno aux= C.VerAlumno(i);
	   cout<<aux.VerNyA()<<" promedio  :"<<aux.VerProm()<<endl;
	}
	
	Alumno mejor= C.MejorPromedio();
	cout<<"\nmejor alumno: "<<mejor.VerNyA();
	
	return 0;
}

