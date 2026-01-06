#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

class Carrera{
protected:
	string m_evento, m_fecha;
	vector<string> m_participantes;
public:
	Carrera(string evento, string fecha): m_evento(evento), m_fecha(fecha){	};
	
	string verEvento() const {return m_evento;};
	string verFecha() const {return m_fecha;};
	void agregarParticipante(string nombre) {m_participantes.push_back(nombre);};
	string verParticipante(int index) const {return m_participantes[index];};
	
	virtual int CalcularPuntos(string nombre,int posicion, bool vuelta_rapida=false)=0;
	
	virtual ~Carrera(){};
};

class Formula1: public Carrera{
public:
	Formula1(string fecha): Carrera("Formula1", fecha){};

	int CalcularPuntos(string nombre,int posicion, bool vuelta_rapida=false){
		bool esta=false;
		for(string participante: m_participantes){
			if(participante==nombre) esta=true;
		}
		if(not esta) return -1;
		vector<int> puntos_por_posicion = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
		if(posicion>9) return 0;
		else{
			int puntos = puntos_por_posicion[posicion]; 
			if(vuelta_rapida) puntos++;
			return puntos;
		}
	}
};

class MotoGP: public Carrera{
public:
	MotoGP(string fecha): Carrera("MotoGP", fecha){};
	
	int CalcularPuntos(string nombre,int posicion, bool vuelta_rapida=false){
		bool esta=false;
		for(string &participante: m_participantes){
			if(participante==nombre) esta=true;
		}
		if(not esta) return -1;
		vector<int> puntos_por_posicion = {25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		if(posicion>14) return 0;
		else{
			int puntos = puntos_por_posicion[posicion]; 
			return puntos;
		}
	}	
};

string testCalcularPuntos(Carrera *c, vector<string> participantes){
	stringstream ss;
	for(size_t i=0; i<participantes.size();i++) {
		int puntos = c->CalcularPuntos(participantes[i],i);
		if(puntos==-1) 	ss<<participantes[i]<<" no se encuentra registrado/a entre los participantes"<<endl;
		else			ss<<"Participante: "<<participantes[i]<<" - Puntos: "<<puntos<<endl;
	}
	return ss.str();
}

int main() {
	
	Carrera *c;
	string fecha;
	cout<<"Ingrese fecha carrera: "; cin>>fecha;
	int opcion;
	cout<<"Elija un tipo de carrera (1- Formula1 o 2-MotoGP): ";cin>>opcion;
	if(opcion==1)	c= new Formula1(fecha);
	else 			c= new MotoGP(fecha);
	cout<<"Ingrese participantes de la carrera o - para finalizar la carga:"<<endl;
	string part;
	cin>>part;
	while(part!="-"){
		c->agregarParticipante(part);
		cin>>part;
	}
	
	cout<<"Ingresar la cantidad de participantes de los que desea conocer su puntaje: ";
	int cant_participantes; cin>>cant_participantes;
	cout<<"Ingresar competidores por orden de llegada para obtener sus puntos: "<<endl;
	vector<string> participantes;
	for(int i=0;i<cant_participantes;i++){
		string participante; cin>>participante;
		participantes.push_back(participante);
	}
	cout<< testCalcularPuntos(c, participantes);
	
	delete c;
	
	return 0;
}

