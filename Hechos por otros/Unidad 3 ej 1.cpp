#include <iostream>
using namespace std;
class Persona {
private:
	string m_apellido, m_nombre, m_Ecivil;
	float m_nacimiento;
	int m_dni;
public:
	Persona (float nacimiento, int dni, string apellido, string nombre, string Ecivil){
		m_nacimiento=nacimiento;
		m_dni=dni;
		m_apellido=apellido;
		m_nombre=nombre;
		m_Ecivil=Ecivil;
	}
	int Edad(float hoy){
		int Anio=(hoy/10000 - m_nacimiento/10000);
		return Anio;
	}
	string VerNombre(){
		return m_nombre;
	}
	string VerApellido(){
		return m_apellido;
	}
	int VerDni(){
		return m_dni;
	}
	string VerEcivil(){
		return m_Ecivil;
	}
	float VerNacimiento(){
		return m_nacimiento;
	}
};
class Alumno : public Persona{
	float m_promedio;
	int m_aprobadas;
public:
	Alumno (float promedio, int aprobadas, float nacimiento, int dni, string apellido, string nombre, string Ecivil):Persona (nacimiento, dni, apellido, nombre, Ecivil){
		m_aprobadas=aprobadas;
		m_promedio=promedio;
	}
	MeritoAcademico(){
		return m_promedio*m_aprobadas;
	}
};
class Docente : public Persona{
	float m_ingreso;
public: 
	Docente (float ingreso, float nacimiento, int dni, string apellido, string nombre, string Ecivil):Persona(nacimiento, dni, apellido, nombre, Ecivil){
		m_ingreso=ingreso;
	}
	int Antiguedad(float hoy){
		int Anti=(hoy/10000-m_ingreso/10000);
		return Anti;
	}
};
int main() {
	cout << "Ingrese los datos de un alumno. " << endl;
	cout << "Ingrese los datos en el siguiente orden: nombre, apellido, dni, fecha de nacimiento ej: añomesdia, estado civil, promedio y materias aprobadas"<< endl;
	float nacimiento, promedio, ingreso;
	int aprobadas, dni;
	string nombre, apellido, Ecivil;
	cin >> nombre >> apellido >> dni >> nacimiento >> Ecivil >> promedio >> aprobadas;
	Alumno A1(promedio, aprobadas, nacimiento, dni, apellido, nombre, Ecivil);
	cout << "Ingrese ls datos de un docente. " << endl;
	cout << "Ingrese los datos en el siguiente orden: nombre, apellido, dni, fecha de nacimiento ej: añomesdia, estado civil y fecha de ingreso"<< endl;
	cin >> nombre >> apellido >> dni >> nacimiento >> Ecivil >> ingreso;
	Docente D1(ingreso, nacimiento, dni, apellido, nombre, Ecivil);
	cout << "ingrese la fecha de hoy de la misma forma que las anteriores fechas"<< endl;
	float hoy; cin >> hoy;
	cout << "La edad del alumno " << A1.VerNombre() << " " << A1.VerApellido() << " es "<< A1.Edad(hoy);
	cout << endl << "Y su merito académico es: " << A1.MeritoAcademico() << endl;
	cout << "La antiguedad del docente " << D1.VerNombre() << " " << D1.VerApellido() << " es " << D1.Antiguedad(hoy);
	return 0;
}

