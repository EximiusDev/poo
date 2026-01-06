#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Alumno{
	string nombre;
	int n1,n2;
};

vector<Alumno> CargarDatosArchivo(){
	vector<Alumno> aux;
	ifstream archi("lista.txt");
	Alumno a;
	while(getline(archi,a.nombre)){
		archi>> a.n1 >> a.n2; 
  		aux.push_back(a);
		archi.ignore();
	}
	archi.close();
	return aux;	
}

int buscarAlumno(const vector<Alumno> &x, string nombuscado){
	for(size_t i=0;i<x.size();i++) { 
		if (x[i].nombre== nombuscado)
			return i;
	}
	return -1;
}	
	
void ActualizarArchivo(const vector<Alumno> &x){
	ofstream archi("lista.txt",ios::trunc);
	for(size_t i=0;i<x.size();i++) { 
		archi<<x[i].nombre<<endl;
		archi<<x[i].n1<<"  "<<x[i].n2<<endl;
	}
	archi.close();
}
	
	
bool modificarNotaAlumno(string nom, int nn1, int nn2){
	vector<Alumno> alumnos =  CargarDatosArchivo();
	int posicion = buscarAlumno(alumnos,nom);
	if (posicion == -1) return false;
	alumnos[posicion].n1=nn1;
	alumnos[posicion].n2=nn2;
	ActualizarArchivo(alumnos);	
	return true;
}

void CrearArchivoPromedios(){
	ofstream archi("Promedios.txt",ios::trunc);
	vector<Alumno> alumnos =  CargarDatosArchivo();
	for(size_t i=0;i<alumnos.size();i++) { 
		float prom=(alumnos[i].n1+alumnos[i].n2)/2.0;
		archi<<setw(15)<<left<<alumnos[i].nombre<< setw(6)<<setprecision(2)<<fixed<<prom;
		if (prom>=70) 
			archi<<setw(15)<<right<<"promocionado\n";
		else if (prom>=40)
			     archi<<setw(15)<<right<<"regular\n";
		     else
				 archi<<setw(15)<<right<<"libre\n";
	}
	archi.close();
	
}
	
	
	
	
	
int main(int argc, char *argv[]) {
	if (modificarNotaAlumno("juan", 39, 89))
		cout<<"se actualizaron las notas\n";
	else
		cout<<"no se modificaron las notas\n";
	
	CrearArchivoPromedios();
	return 0;
}

