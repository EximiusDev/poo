#include <iostream>
#include <vector>
using namespace std;

struct Evaluacion{
	Evaluacion(string ttipo,int nnota):tipo(ttipo),nota(nnota){}
	string tipo;
	int nota;
};

class Asignatura{
private:
	string m_nombre;
	int m_nroc;
	vector<string> m_unidades;
public:
	Asignatura(string nombre,int nrocuat):m_nombre(nombre),m_nroc(nrocuat){}
	string VerNombre()const{return m_nombre;}
	int VerCuatrimestre()const{return m_nroc;}
	void CargarUnidades(string unidad){
		m_unidades.push_back(unidad);
	}
	virtual string CalcularCondicion(vector<Evaluacion> v);
};

class FuPro:public Asignatura{
private:
	
public:
	string CalcularCondicion(vector<Evaluacion> v)override{
		int aux;int aux2;
		for(size_t i=0;i<v.size();++i){
			if(v[i].tipo=="parcial1" or "parcial2"){
				aux=aux+v[i].nota;
				if(aux<aux2){aux2=aux;}
			}else{return "ERROR";}
		}
		if(aux/v.size()>70 and aux2>=60) {return "Promocionado";}
		else if(aux/v.size()>60){return "Regular";}
		else return "Libre";
	}
};

class CompGraf:public Asignatura{
private:
	
public:
	string CalcularCondicion(vector<Evaluacion> v)override{
		int aux;
		for(size_t i=0;i<v.size();++i){
			if(v[i].tipo== "tp1" or "tp2" or "tpFinal"){
				if(v[i].nota<60){
					return "Libre"; 
				}else {aux=aux+v[i].nota;}
			}else if(v[i].tipo=="parcial"){
				if(v[i].nota<60){
					return "Regular";
				}else if(v[i].nota>65){aux=aux+v[i].nota;}
			}
		}
		return "Promocionado";
	}
};

string testCalcularCondicion(Asignatura *a,vector<Evaluacion> v){
	return a->CalcularCondicion(v);
}

int main() {
	
	return 0;
}

