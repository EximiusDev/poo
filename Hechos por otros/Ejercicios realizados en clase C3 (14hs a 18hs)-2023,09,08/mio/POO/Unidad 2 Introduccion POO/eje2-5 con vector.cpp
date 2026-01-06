#include <iostream>
#include <vector>
using namespace std;
struct Alumno{
	string nombre;
	float nota;
};
class Curso{
private:
	string materia;
	vector<Alumno> v;
public:
	Curso(string _m):materia(_m){}
	void agregaAlumno(Alumno &x){v.push_back(x);}
	float Promedio();
	Alumno MejorAlumno();
	Alumno VerAlumno(int x){return v[x];}
	int VerCant(){return v.size();}
	string NombreCurso(){return materia;}
};

float Curso::Promedio(){
	float s=0;
	for(size_t i=0;i<v.size();i++)  
		s+= v[i].nota;   
	return s/v.size();
}
	
Alumno Curso::MejorAlumno(){
	Alumno mejor;
	mejor.nota=0;
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].nota > mejor.nota)
			mejor=v[i];
	}
	return mejor;
}

int main(int argc, char *argv[]) {
	Curso c("POO");
	Alumno aux;
	int n;
	cout<<"Ingrese cantidad de alumnos:"; cin>>n;
	for(int i=0;i<n;i++) { 
		cout<<"ingrese nombre: "; cin>>aux.nombre;
		cout<<"ingrese nota: "; cin>>aux.nota;
		c.agregaAlumno(aux);
	}
	
	cout<<"\nVer Listado: "<<c.NombreCurso()<<endl;;
	for(int i=0;i<c.VerCant();i++) { 
		aux=c.VerAlumno(i);
		cout<<aux.nombre<<":  "<<aux.nota<<endl;
	}
	cout<<"\nPromedio del curso: "<<c.Promedio()<<endl;
	aux=c.MejorAlumno();
	cout<<"Mejor alumno:   "<<aux.nombre<<":  "<<aux.nota<<endl;
	return 0;
}

