#include <iostream>
#include <vector>
using namespace std;

class Ejercicio {
	int puntaje;
	string enunciado;
	bool solo_libres;
public:
		Ejercicio(int p,string e,bool l):puntaje(p),enunciado(e),solo_libres(l){}	
		string VerEnunciado(){return enunciado;}
		int VerPuntajeMaximo(){return puntaje;}
};
class Examen{
  string nom;
  int fecha;
  vector<Ejercicio> lista;
  public:
	Examen(string n, int f):nom(n),fecha(f){}
	int verFecha(){return fecha;}
	string verNombre(){return nom;}
	void agregaEjer(Ejercicio e){
	    lista.push_back(e);	
	}
	Ejercicio VerEjercicio(int x){return lista[x];}

	int verCantEjer(){return lista.size();}
	float CalcularCalificacion(vector<int> c);
};

float Examen::CalcularCalificacion(vector<int> notas){
	int sp=0,st=0;
	for(int i=0;i<lista.size();i++) { 
		sp=sp+notas[i];
		st=st+lista[i].VerPuntajeMaximo();
	}
	return sp*100.0/st;
}



int main(int argc, char *argv[]) {
	
	return 0;
}

