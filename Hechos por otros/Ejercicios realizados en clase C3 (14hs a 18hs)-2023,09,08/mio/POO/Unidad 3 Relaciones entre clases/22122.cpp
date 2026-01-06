#include <iostream>
#include <vector>
using namespace std;
class Persona{
protected:
	string nya;
	int dni;
	int dn,mn,an;
	char ec;
public:
	Persona(){}
	Persona(string n,int d,int di,int me,int a,char e){
	   nya=n; dni=d; dn=di; mn=me; an=a; ec=e;	
	}
	string VerNombre(){return nya;}
    int edad (int da,int ma,int aa){
		int fa=aa*10000+ma*100+da;
		int fn=an*10000+mn*100+dn;
		return (fa-fn)/10000;
	}
};
class Alumno:public Persona{
	int cma;
	float pro;
public:
	Alumno(string n,int d,int di,int me,int a,char e,int cm, float p):
		Persona(n, d, di, me, a, e){
		cma=cm; pro=p;
	}
	float Merito(){ return cma*pro;}
};
class Docente:public Persona{
	int di,mi,ai;
public:
	//Docente(){}
	Docente(string n,int d,int di,int me,int a,char e,int d1, int m1, int a1):
		Persona(n, d, di, me, a, e){
		di=d1; mi=m1; ai=a1;
	}
	int antiguedad(int da,int ma,int aa){
		int fa=aa*10000+ma*100+da;
		int fi=ai*10000+mi*100+di;
		return (fa-fi)/10000;
	}
};
class Curso{
	string materia;
	Docente doc;
	vector<Alumno>alumnos;
public:
	Curso(string mat, Docente d):doc(d){
		materia=mat;
	}
	void AgregarAlumno(Alumno &a){
		alumnos.push_back(a);
	}
	int VerCant(){return alumnos.size();}
	string VerMat(){return materia;}
	string VerDocente(){return doc.VerNombre();}
	Alumno VerAlumno(int x){return alumnos[x];}
};

int main(int argc, char *argv[]) {
	Docente d("Juan Perez",20000000,10,2,1980,'c',2,5,2001);
	Curso c("POO",d);

	Alumno a("Estela",11111,3,4,2000,'s',10,5.6);
	c.AgregarAlumno(a);
	Alumno b("luis",11111,3,4,2010,'s',120,5.6);
	c.AgregarAlumno(b);
	Alumno c1("Juan",11111,3,4,2000,'s',14,45.6);
	c.AgregarAlumno(c1);
	Alumno d1("Carlos",11111,3,4,1988,'s',110,4.6);
	c.AgregarAlumno(d1);
	Alumno e("Julio",11111,3,4,2000,'s',10,5.6);
	c.AgregarAlumno(e);
	
	
	cout<<c.VerMat()<< "     "<<c.VerDocente()<<endl;
	for(int i=0;i<c.VerCant();i++) { 
		cout<<c.VerAlumno(i).VerNombre()<<"   "<<c.VerAlumno(i).edad(9,9,2022)<<endl;
	}
	return 0;
}

