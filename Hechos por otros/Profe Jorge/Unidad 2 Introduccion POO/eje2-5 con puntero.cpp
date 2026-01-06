#include <iostream>
using namespace std;
struct Alumno{
	string nombre;
	float nota;
};
class Curso{
private:
	string materia;
	int cant;
	Alumno *lista;
public:
	Curso(string _m):materia(_m),cant(0),lista(nullptr){}
	~Curso(){if (lista!=nullptr) delete[]lista;}
	void agregaAlumno(Alumno &x);
	float Promedio();
	Alumno MejorAlumno();
	Alumno VerAlumno(int x){return *(lista+x);}
	int VerCant(){return cant;}
};

void Curso::agregaAlumno(Alumno &x){
	Alumno *aux=new Alumno[cant+1];
	for (int i=0;i<cant;i++)
		*(aux+i)=*(lista+i);
	*(aux+cant)=x;
	if (lista!=nullptr) delete[]lista;   //porque no era el primero
	cant++;
	lista=aux;
}
float Curso::Promedio(){
	float s=0;
	for(int i=0;i<cant;i++)  
		s+= lista[i].nota;   //(lista+i)->nota//(*(lista+i)).nota;
	return s/cant;
}
	
Alumno Curso::MejorAlumno(){
	Alumno mejor;
	mejor.nota=0;
	for(int i=0;i<cant;i++) { 
		if(lista[i].nota > mejor.nota)
			mejor=*(lista+i);
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
	
	cout<<"\nVer Listado:\n";
	for(int i=0;i<c.VerCant();i++) { 
		aux=c.VerAlumno(i);
		cout<<aux.nombre<<":  "<<aux.nota<<endl;
	}
	cout<<"\nPromedio del curso: "<<c.Promedio()<<endl;
	aux=c.MejorAlumno();
	cout<<"Mejor alumno:   "<<aux.nombre<<":  "<<aux.nota<<endl;
	return 0;
}

