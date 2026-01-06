#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

//	Se dispone de un archivo de textos EQUIPO.TXT donde cada línea contiene el
//	DNI, apellido y nombre correspondiente a un grupo de trabajo. Por persona hay un solo nombre y
//	apellido y están separados por un espacio en blanco. Escriba una clase que posea entre sus métodos: a)
//	la función GeneraEmail( ), encargada de formar la dirección de correo electrónico de cada empleado
//	del archivo, colocando la inicial del primer nombre y el apellido, seguido de @gmail.com y otra
//	funcion CreaBinario( ) que genere un archivo binario que contenga los datos referentes al nombre,
//	apellido, dni y email de cada persona. Programa los métodos adicionales que considere necesarios.

struct Equipo {
	int dni; string nombre, apellido,mail;
};

struct Equipoarchi {
	int dni; 
	char nombre[20], apellido[20];
	char mail[30];
};


class uno {
public:
	uno(string nombre_archivo) : archi(nombre_archivo) {
		Equipo p;
		while(archi>>p.dni>>p.nombre>>p.apellido)
			Empleados.push_back(p);
	};
	
	void GenerarEmail() {
	 	for(size_t i=0;i<Empleados.size();i++){
			Empleados[i].mail = Empleados[i].nombre[0]+ Empleados[i].apellido + "@gmail.com";
		}
	}
	
	bool CrearBinario() {
		ofstream f("EquipoBinario.dat",ios::binary|ios::trunc|ios::in);
		Equipoarchi a;
		for(size_t i=0;i<Empleados.size();i++){
			strcpy(a.apellido,Empleados[i].nombre.c_str());
			strcpy(a.nombre,Empleados[i].apellido.c_str());
			strcpy(a.mail,Empleados[i].mail.c_str());
			a.dni=Empleados[i].dni;
			
			cout<<a.mail<<"  "<<a.nombre<<endl;
			f.write(reinterpret_cast <char*> (&a), sizeof(a));
		}
		f.close();
		return true;
	}
	
private:
		fstream archi;
		vector<Equipo>Empleados;
};

int main() {
	
	uno A("EQUIPO.txt");
	A.GenerarEmail();
	A.CrearBinario();
	
	return 0;
} 
