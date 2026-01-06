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
	Persona(int );
	int Edad(int fecha){ return fecha - m_nacim;  }
};

class Alumno: public Persona{
	float m_prom;
	int m_mat_aprob;
public:
	// Alumno():Persona(){ /* Procesos del constructor */ } //Otra forma de hacerlo
	Alumno(float ,int ,int); /// No tengo que poner Alumno():Persona(); porque
	///porque es parte de la implementacionde la clase Alumno
	
	float MeritoAcademico();
};

class Docente:public Persona{
	int m_fecha_ingreso;
public:
	Docente(int feIng, int dni);
	int Antiguedad(int fecha){ return fecha - m_fecha_ingreso; }
	//Docente():Persona(){}
};

int main() {
	
	float prom = 5.5;
	int mat_aprob = 2;
	int DNI = 44444444;
	Alumno a1( prom, mat_aprob , DNI);
	cout<<a1.Edad(12)<<endl;
	cout<<a1.MeritoAcademico()<<endl;
	
	return 0;
}
Persona::Persona(int DNI){
	//m_DNI = DNI;
	m_nacim = 0;
	
}
Alumno::Alumno(float promedio,int materias_aprob, int dni):Persona( dni){
	m_prom = promedio;
	m_mat_aprob = materias_aprob;
}
float Alumno::MeritoAcademico(){
	return m_prom * m_mat_aprob;
}
Docente::Docente(int feIng, int dni):Persona( dni){
	m_fecha_ingreso = feIng;
}
