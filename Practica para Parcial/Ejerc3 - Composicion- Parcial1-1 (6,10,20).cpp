/*
Ejercicio 3
a) En la clase Alumno: ya están completos los datos o atributos; proponga un constructor para iniciar sus datos: nombre,
DNI y nota_final; un método para determinar la condición: 'R' o 'L' ('R' es Regular si nota_final>=4, 'L' es Libre si
nota_final<4) y otros métodos que considere necesarios o adecuados para consultar los datos de la clase.
b) Proponga una clase Materia, que reutilice la clase Alumno mediante la relación que considere más adecuada. La clase
Materia debe permitir definir el nombre de la materia, el nombre del profesor, y registrar varios alumnos. Proponga un
constructor, y métodos para obtener la cantidad de regulares y de libres; y otros métodos que crea necesarios.
Solo proponga las clases y codifique sus métodos (no hacer programa cliente).
class Alumno {
string nombre;
int DNI, nota_final;
. . .
public:
. . .
};
*/
#include <iostream>
#include <vector>
using namespace std;


class Alumno {
	string nombre;
	int DNI, nota_final;
public:
	Alumno(string nombre, int dni,int nota):nombre(nombre), DNI(dni), nota_final(nota){}
	string Condicion(){
		if(nota_final>=4){
			return "R";
		}
		return "L";
	}
	int VerNota(){return nota_final;}
	int VerDNI(){return DNI;}
	string VerNombre(){return nombre;}
};

class Materia{
	vector<Alumno> Alumnos;
	string profesor, m_materia;
public:
	Materia(string nombre_materia, string profesor):m_materia(nombre_materia), profesor(profesor){}
	void AgregarAlumno(Alumno Al){
		Alumnos.push_back(Al);
	}
};


int main() {
	
	
	
	return 0;
}

