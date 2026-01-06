#include <iostream>
#include <vector>
using namespace std;
class Persona{
protected:
	string nya;
	int dni,dnac,mnac,anac;
	char ecivil;
public:
	Persona(){}
	Persona(string nap,int doc, int dn, int mn, int an, char ec){
		nya=nap; dni=doc; dnac=dn; mnac=mn; anac=an; ecivil=ec;
	}
	int Edad(int da, int ma, int aa){
		int fn=anac*10000+mnac*100+dnac;
		int fa=aa*10000+ma*100+da;
		return (fa-fn)/10000;
	}
	string VerNombre(){return nya;}
};
class Alumno: public Persona{
	float promedio;
	int cmat;
public:
	Alumno(string nap,int doc, int dn, int mn, int an, char ec,float p,int c):
		Persona(nap,doc,dn,mn,an,ec){
		promedio=p; cmat=c;
	}
	void ModificarAlumno(string nap,int doc, int dn, int mn, int an, char ec,float p,int c){
		nya=nap; dni=doc; dnac=dn; mnac=mn; anac=an; ecivil=ec; promedio=p; cmat=c;
	}
	float MeritoAcademico(){return promedio*cmat;}	
	float VerPromedio(){return promedio;}
};
class Docente: public Persona{
	int ding,ming,aing;
public:
//	Docente(){}
	Docente(string nap,int doc, int dn, int mn, int an, char ec,int di,int mi,int ai):
		Persona(nap,doc,dn,mn,an,ec){
		ding=di; ming=mi; aing=ai;
	}
	int Antiguedad(int da, int ma, int aa){
		int fi=aing*10000+ming*100+ding;
		int fa=aa*10000+ma*100+da;
		return (fa-fi)/10000;
	}
};
class Curso{
	string materia;
	Docente docente;
	vector<Alumno> alumnos;
public:
	Curso(string mat, const Docente &doc):docente(doc){
		materia=mat;
	}
	void AgregarAlumno(Alumno a){alumnos.push_back(a);}
	string VerNombreDocente(){return docente.VerNombre();}
	Alumno VerAlumno(int x){return alumnos[x];}
	int VerCantidadAlumnos(){return alumnos.size();}
	Alumno MejorPromedio(){
		float m=0;int pm=0;
		for(int i=0;i<alumnos.size();i++) { 
			if ( m < alumnos[i].VerPromedio() ){
				pm=i; m=alumnos[i].VerPromedio();
			}
		}
		return alumnos[pm];
	}
	
};



int main(int argc, char *argv[]) {
/*	Persona p("Lopez Horacio",42333625,12,3,2020,'s');
	Alumno a("Juan Perez",42333625,12,3,2000,'s',7.8,10);
	cout<<a.VerNombre()<<"    "<<a.Edad(9,9,2022)<<"   "<<a.MeritoAcademico()<<endl;
	cout<<p.VerNombre()<<"    "<<p.Edad(9,9,2022)<<"   "<<endl;
	
	a.ModificarAlumno("Ana Laura",42344445,22,12,2010,'s',8.8,10);
	cout<<a.VerNombre()<<"    "<<a.Edad(9,9,2022)<<"   "<<a.MeritoAcademico()<<endl;
	*/
	
	Docente D("Jorge",42333625,12,3,2000,'s',1,3,2000);
	Curso C("POO",D);
	Alumno a("Juan Perez",42333625,12,3,2000,'s',7.8,10);
	C.AgregarAlumno(a);
	a.ModificarAlumno("Ana Laura",42344445,2,12,2010,'s',3.8,9);
	C.AgregarAlumno(a);
	a.ModificarAlumno("Luis Lopez",42554445,22,5,2009,'s',3.8,5);
	C.AgregarAlumno(a);
	a.ModificarAlumno("Claudia Gomez",4435545,22,4,2000,'s',8.8,5);
	C.AgregarAlumno(a);
	a.ModificarAlumno("Miguel Lot",42555445,22,11,2011,'s',4.8,5);
	C.AgregarAlumno(a);
	
	
	cout<<C.VerNombreDocente()<<endl;
	for(int i=0;i<C.VerCantidadAlumnos();i++) { 
		cout<<C.VerAlumno(i).VerNombre()<<"   "<<C.VerAlumno(i).VerPromedio()<<"   ";
		cout<<C.VerAlumno(i).MeritoAcademico()<<endl;
	}
	cout<<endl<<"el mejor es: "<<C.MejorPromedio().VerNombre();
	
	
		 
		 
	
	return 0;
}

