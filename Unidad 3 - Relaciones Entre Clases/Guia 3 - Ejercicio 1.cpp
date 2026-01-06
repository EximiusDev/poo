/* Ejercicio 1
Diseñe una clase Persona que contenga los siguientes atributos: apellido y
nombre, DNI, fecha de nacimiento y estado civil. La clase debe poseer, además, un
método Edad(...) que calcule la edad actual de la persona en base a la fecha de
nacimiento y la fecha actual (que recibe como argumento).
Implemente una clase Alumno para contener la siguiente información de un
alumno: apellido y nombre, DNI, año de nacimiento, estado civil, promedio y
cantidad de materias aprobadas. La clase debe poseer, además, un método
MeritoAcademico() que devuelve el mérito académico del alumno (éste se calcula
como el producto entre el promedio y la cantidad de materias aprobadas).
Cree, también, una clase Docente para modelar un docente a partir de la siguiente
información: apellido y nombre, DNI, año de nacimiento, estado civil y fecha de
ingreso. La clase debe poseer, además, un método Antiguedad() que calcule la
antigüedad del docente en base a su fecha de ingreso y la fecha actual.
Proponga una jerarquía de clases adecuada para evitar repetir atributos.
Implemente constructores y métodos extra que considere adecuados. Codifique un
programa cliente que cree instancias de Alumno y Docente y utilice sus funciones.
Responda:
? ¿Puede crearse un objeto de tipo persona? ¿Para qué sirve esto?
? ¿Existe alguna clase abstracta en la jerarquía?*/

#include <iostream>
using namespace std;

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
};

class Docente:public Persona{
	int m_fecha_ingreso;
public:
	Docente(int , string , string ,int , int , string );
	int Antiguedad(int fecha){ return fecha - m_fecha_ingreso; }
	//Docente():Persona(){}
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
