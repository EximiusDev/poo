#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Alumno{
	string m_nombre, m_dni;
	float m_nota1, m_nota2, m_nota3, m_promedio;
	char m_condicion;
public:
	Alumno(string nombre, string dni, float nota1, float nota2, float nota3):
		m_nombre(nombre), m_dni(dni), m_nota1(nota1), m_nota2(nota2), m_nota3(nota3){};
	tuple<float,char> calcularCondicion() {
		m_promedio= (m_nota1+m_nota2+m_nota3)/3.0;
		if(m_promedio>=60) m_condicion='P';
		else if(m_promedio<40) m_condicion='L';
		else m_condicion='R';
		return make_tuple(m_promedio, m_condicion);
	}
	tuple<string,string> ver_datos_alumno() const {
		return make_tuple(m_nombre, m_dni);
	}
};

class Materia{
	string m_nombre, m_profesor;
	vector<Alumno> m_alumnos;
public:
	Materia(string materia, string profesor, vector<Alumno> alumnos): 
		m_nombre(materia), m_profesor(profesor), m_alumnos(alumnos){};
	int cantidad_condicion(char condicion){
		int cont=0;
		for(Alumno &a: m_alumnos){
			float prom; char cond;
			tie(prom, cond)=a.calcularCondicion();
			if (cond==condicion) cont++;
		}
		return cont;
	};
	tuple<float,char> buscarCondicion(string dni){
		for (Alumno &a: m_alumnos){
			string nombre, a_dni;
			tie(nombre,a_dni)=a.ver_datos_alumno();
			if(a_dni==dni) return a.calcularCondicion();
		}
		return make_tuple(0,0);
	};
	tuple<int,int,int> cantidades(){
		int cant_promocionados, cant_regulares, cant_libres;
		cant_promocionados=cantidad_condicion('P');
		cant_regulares= cantidad_condicion('R');
		cant_libres = cantidad_condicion('L');
		return make_tuple(cant_promocionados, cant_regulares, cant_libres);
	}
	string buscarNombre(string dni){
		for (Alumno &a: m_alumnos){
			string nombre, a_dni;
			tie(nombre,a_dni)=a.ver_datos_alumno();
			if(a_dni==dni) return nombre;
		}
		return "no existe un alumno con ese dni";
	};
};

int main() {
	string profesor, nombre_materia;
	cout<<"Nombre profesor: ";cin>>profesor;
	cout<<"Nombre materia: ", cin>>nombre_materia;
	int cant;vector<Alumno> alumnos;
	cout<<"Cantidad de alumnos: "; cin>>cant;
	cout<<"Datos alumnos: "<<endl;
	for(int i=0;i<cant;++i){
		string nombre, dni;
		float nota1,nota2,nota3;
		cout<<"ALUMNO "<<i<<endl;
		cout<<"- nombre: ";cin>>nombre;
		cout<<"- dni: ";cin>>dni;
		cout<<"- nota1: ";cin>>nota1;
		cout<<"- nota2: ";cin>>nota2;
		cout<<"- nota3: ";cin>>nota3;
		Alumno a(nombre,dni, nota1, nota2,nota3);
		float prom;char cond;
		tie(prom, cond)= a.calcularCondicion();
		cout<<"(promedio: "<<prom<<" - condicion: "<<cond<<")"<<endl;
		alumnos.push_back(a);
	}
	
	Materia m(nombre_materia, profesor, alumnos);
	int cant_promocionados, cant_regulares, cant_libres;
	tie(cant_promocionados, cant_regulares, cant_libres)=m.cantidades();
	cout<<"Cantidad promocionados: "<<cant_promocionados<<endl;
	cout<<"Cantidad regulares: "<<cant_regulares<<endl;
	cout<<"Cantidad libres: "<<cant_libres<<endl;
	
	string dni;
	cout<<endl<<"Ingrese un dni para ver datos de ese alumno: ";cin>>dni;
	string nombre=m.buscarNombre(dni);
	float promedio; char condicion;
	tie(promedio, condicion) = m.buscarCondicion(dni);
	cout<<"Nombre: "<<nombre<<" - "<<"Promedio: "<<promedio<<" - "<<"Condicion: "<<condicion<<endl;
	
	
	return 0;
}

