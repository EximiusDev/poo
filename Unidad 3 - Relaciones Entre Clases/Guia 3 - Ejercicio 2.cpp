#include <iostream>
#include <vector>
using namespace std;

//////////////////////////////////////////////////////}
/// Ejercicio 1
class Persona{
	string m_ape;
	string m_nom;
	int m_DNI;
	int m_nacim;
	string m_EstCivil;
public:
	///Persona();
	Persona(string ape, string nombre,int DNI, int nacim, string estCivil);
	int Edad(int fecha){ return fecha - m_nacim;  }
};
class Alumno: public Persona{
	float m_prom;
	int m_mat_aprob;
public:
	// Alumno():Persona(){ /* Procesos del constructor */ } //Otra forma de hacerlo
	Alumno(float , int , string , string ,int , int , string );
	//Alumno(float promedio, int materias_aprob, string ape, string nombre,int DNI, int nacim, string estCivil);
	/// No tengo que poner Alumno():Persona(); porque
	///porque es parte de la implementacionde la clase Alumno
	
	float MeritoAcademico();
	int VerMaterias(){return m_mat_aprob;} /// para Curso
	float VerProm(){return m_prom;} /// para Curso
	void CambiarProm(float Prome){m_prom = Prome;}
};
class Docente:public Persona{
	int m_fecha_ingreso;
public:
	Docente(int , string , string ,int , int , string );
	int Antiguedad(int fecha){ return fecha - m_fecha_ingreso; }
	//Docente():Persona(){}
};

Persona::Persona(string ape, string nombre,int DNI, int nacim, string estCivil){
	m_ape = ape;
	m_nom = nombre;
	m_DNI = DNI;
	m_nacim = nacim;
	m_EstCivil = estCivil;
}
Alumno::Alumno(float promedio, int materias_aprob, string ape, string nombre,int DNI, int nacim, string estCivil):Persona( ape, nombre, DNI,  nacim, estCivil){
	m_prom = promedio;
	m_mat_aprob = materias_aprob;
}
float Alumno::MeritoAcademico(){
	return m_prom * m_mat_aprob;
}
Docente::Docente(int feIng, string ape, string nombre,int DNI, int nacim, string estCivil):Persona( ape, nombre, DNI,  nacim, estCivil){
	m_fecha_ingreso = feIng;
}
///////////////////////////////////////////////////////////////////////////////////////////////

/* Ejercicio 2
Utilice las clases Alumno y Docente del ejercicio anterior para crear una clase
Curso que modele el cursado de una materia. Cada curso tiene un nombre, un
profesor a cargo y un número máximo de 50 alumnos. Implemente un método
AgregarAlumno(...) que permita agregar un alumno al curso y otro método
MejorPromedio(...) que devuelva el alumno con mejor promedio. Proponga los
constructores y métodos extra que considere necesarios.
*/

class Curso{
	string m_nombre;
	int max_alumnos = 50; 
	Alumno A1(), A2();
	Docente D1();
	vector<Alumno>Alumnos;
	/// o usar vector<Alumno>A; si es necesario
	///  vector<Docente>D;
public:
	///Curso():D1(),Alumnos(){}
	
	//Curso():D1(int feIng, string ape, string nombre,int DNI, int nacim, string estCivil),Alumnos();
	//Curso(""""):A1(""""),D1("""");
	/// Alumno AgregarAlumno(""""); 
	/// void AgregarAlumno(""""); ///con vector
	///MejorPromedio(...)
	void AgregarAlumno(Alumno Alum); /// agrega un Alumno al Curso
	Alumno MejorPromedio(); /// devuelve al Alumno con mejor promedio
	
};



int main() {
	
	string ape = " Perez";
	string nombre = " Juan";
	string estCivil = "Soltero";
	
	int DNI = 44444444;
	int nacim = 1999;
	
	float prom = 6.7;
	int mat_aprob = 4;
	
	int fecha_ingreso = 2021;
	
	cin>>ape>>nombre>>DNI>>nacim>>estCivil;/*
	cin>>ape>>nombre;
	cin>>DNI>>nacim;
	cin>>estCivil; */
	
	
	
	Alumno A1( prom, mat_aprob , ape, nombre, DNI,  nacim, estCivil);
	Alumno A2( 4.4, 8, "Turner", "Timmy", 48012345, 2013, "Soltero");
	Docente D1( fecha_ingreso, "House", "Gregory", 32001001, 1960 , "Soltero");
	cout<<endl;
	
	Curso C1;
	C1.AgregarAlumno(A1);
	C1.AgregarAlumno(A2);
	
	Alumno A0 = C1.MejorPromedio();
	//cout<<"Mejor promedio "<<C1.MejorPromedio().VerProm()<<endl;
	cout<<"Mejor promedio: "<<A0.VerProm()<<" de "<<A0.MeritoAcademico()<<endl;
	
	cout<<A1.Edad(2023)<<endl;
	cout<<A1.MeritoAcademico()<<endl;
	cout<<endl;
	cout<<A2.Edad(2023)<<endl;
	cout<<A2.MeritoAcademico()<<endl;
	cout<<endl;
	cout<<D1.Edad(2023)<<endl;
	cout<<D1.Antiguedad(2023)<<endl;
	
	return 0;
}

void Curso::AgregarAlumno(Alumno Alum){
	if (max_alumnos<=Alumnos.size()) cout<<"ERROR"<<endl;
	else Alumnos.push_back(Alum);
}
Alumno Curso::MejorPromedio(){
	Alumno Aux = Alumnos[0];
	for(int i=0;i<Alumnos.size();i++) { 
		if(Aux.MeritoAcademico()/(Aux.VerMaterias())<Alumnos[i].VerProm()){
			Aux.CambiarProm(Alumnos[i].VerProm());
		}
	}
	return Aux;
}
