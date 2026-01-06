#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace std;

class Jugador{
	string Nombre;
	int Jugada;
public:
	Jugador(string m_Nombre):Nombre(m_Nombre){}
	void SetJugada(int x){Jugada=x;}
	virtual int Jugar()=0;
	string Ver_Nombre(){return Nombre;}
	int Ver_Jugada(){return Jugada;}
};

class JugadorIA:public Jugador{
	//int Jugada=0;
public:
	JugadorIA(string nai="HALL 9000"):Jugador(nai){};
	virtual int Jugar(){
		int a;
		srand(time(0));
		a=rand ()%4;
		cout<<"La inteligencia artificial tiene  "<<a<<endl;
		SetJugada(a);
		return a;
	}
	//	int Ver_Jugada(){return Jugada;}
};
class JugadorHumano:public Jugador{
//	int Jugada;
public:
	JugadorHumano(string Nombre):Jugador(Nombre){};
	virtual int Jugar(){
		int a;
		cout<<"Ingrese la Jugada que desea Realizar "<<endl;
		cout<<"(1)"<<"Piedra "<<endl;
		cout<<"(2)"<<"Papel "<<endl;
		cout<<"(3)"<<"Tijera "<<endl;
		cin>>a;
		cout<<"El jugador tiene "<<a<<endl;
		SetJugada(a);
	 	return a;
	}
		
	//	int Ver_Jugada(){return Jugada;}
};
string Ganador(Jugador* a,Jugador* b){
	stringstream ss;
	ss.str(" ");
	if(	(a->Ver_Jugada()==1 && b->Ver_Jugada()==1) ||
		(a->Ver_Jugada()==2 && b->Ver_Jugada()==2) ||
		(a->Ver_Jugada()==3 && b->Ver_Jugada()==3) ){
		ss<<"Empate"<<endl;
	} else 
		if( (a->Ver_Jugada()==1 && b->Ver_Jugada()==3) ||
			(a->Ver_Jugada()==2 && b->Ver_Jugada()==1) ||
		    (a->Ver_Jugada()==3 && b->Ver_Jugada()==2) ){
			ss<<"Gano "<<a->Ver_Nombre();
		}else 
			ss<<"Gano "<<b->Ver_Nombre();
	return ss.str();
}
	int main() {
		Jugador **p;
		p=new Jugador* [2];    //creo 2 punteros de tipo jugador
		p[0]=new JugadorHumano("Lucio");  //creo una instancia de humano
		p[1]=new JugadorIA;               //creo una instacia de IA
		cout<<endl<<endl;
		for (int i=0;i<2;i++){
			cout<< p[i]->Ver_Nombre()<<endl;
			cout<< p[i]->Jugar()<<endl<<endl;
		}
		cout<<Ganador(p[0],p[1]);
		
		delete []p;
		return 0;
	}
	
