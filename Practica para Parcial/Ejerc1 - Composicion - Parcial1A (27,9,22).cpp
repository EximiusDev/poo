#include <iostream>
using namespace std;

class Estado{
	int m_nivel, m_vidas, m_cant_ptos;
public:
	Estado(int vidas):m_vidas(vidas),m_nivel(1),m_cant_ptos(0){}
	bool Vivo(){return m_vidas > 0;}
	void LevelUp(){++ m_nivel;}
	void Incremento(int puntos){m_cant_ptos+= puntos;}
	int VerPuntos(){return m_cant_ptos;}
	int VerNivel(){return m_nivel;}
	Estado operator<(Estado E2){
		if(this->m_nivel<E2.m_nivel) return *this;
		else if (this->m_nivel==E2.m_nivel){
			if(this->m_cant_ptos < E2.m_cant_ptos) return *this;
		}
		return E2;
	}
	Estado operator>(Estado E2){
		if(this->m_nivel>E2.m_nivel) return *this;
		else if (this->m_nivel==E2.m_nivel){
			if(this->m_cant_ptos > E2.m_cant_ptos) return *this;
		}
		return E2;
	}
};

class Personaje{
	string m_nombre;
	int m_x, m_y;
	Estado m_Estad;
public:
	Personaje(string nombre, int x, int y, int vidas):m_Estad(vidas){
		m_nombre= nombre; m_x=x; this->m_y=y;
	}
	Estado VerEstado(){return m_Estad;}
	void CambiarEstado(Estado E2){m_Estad = E2;}
};

int main() {
	Personaje P1("Mario", 50,0,3);
	Personaje P2("Sonic", 0,0,1);
	
	int niv1= rand()%10+1;	cout<<niv1<<endl;
	int niv2= rand()%10+1;	cout<<niv2<<endl;
	
	Estado Eaux1 = P1.VerEstado();
	for(int i=0;i<niv1;i++) { Eaux1.LevelUp(); }
	int ptos1 =  rand()%100;	cout<<ptos1<<endl;
	Eaux1.Incremento(ptos1);
	P1.CambiarEstado(Eaux1);
	cout<<P1.VerEstado().VerNivel()<<endl;
	cout<<P1.VerEstado().VerPuntos()<<endl;
	
	cout<<endl;
	
	Estado Emenor = P1.VerEstado() < P2.VerEstado(); /// la sobrecarga de operador devuelve un Estado
	cout<<Emenor.VerNivel()<<endl;
	
	Estado Emayor = P1.VerEstado() > P2.VerEstado(); /// la sobrecarga de operador devuelve un Estado
	cout<<Emayor.VerNivel()<<endl;
	
	///falta devolver todos los datos del Personaje que tiene Emayor de estado
	///pero la logica esta bien
	
	return 0;
}

