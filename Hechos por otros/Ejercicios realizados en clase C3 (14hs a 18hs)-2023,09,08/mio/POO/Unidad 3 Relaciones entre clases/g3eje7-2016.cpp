#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
//Interfase de Personaje
class Personaje{
protected:
	int vida, mana;//Atributos de energia del Personaje
	int danioVida, danioMana;//Atributos de daño del Personaje
	string clase;//Tipo de personaje Caballero, arquero o mago
	void atacado(int, int);//Metodo que decrementa la energia
public:
	void asignarTipo(string c,int dv, int dm);//Constructor
	void atacar(Personaje &enemigo);//Metodo para restar eergia al enemigo
	int estaVivo();//Devuelve la cantidad de vida
	string tipo();//Devuelve el tipo de Personaje
	int ver_mana();//Devuelve cantidad de Mana
	
};
///*** Interfase de la case Juego ********************************
class Juego{
private:
	Personaje J[30];//Contiene a todos los jugadores
public:
	Juego(int);//Constructor con el parametro de la cantidad de jugadores
	void jugada(int x, int y);//el jugador x ataca al jugador y
	Personaje *estado(int x);//Retorna un puntero al personaje x
	void mostrar(int caJ);//Muestra a todos los jugadores y su energia
};
///--Implementacion de Personaje------------------------------------
void Personaje::asignarTipo(string c,int dv, int dm){
	clase=c;
	vida= mana= 10;
	danioVida= dv;
	danioMana= dm;
}
void Personaje::atacar(Personaje &enemigo){
	enemigo.atacado(this->danioVida, this->danioMana);
}
void Personaje::atacado(int dv, int dm){
	vida -= dv;
	mana -= dm;
}
int Personaje::estaVivo(){
	return vida;	
}
string Personaje::tipo(){
	return clase;
}
int Personaje::ver_mana(){
	return mana;
}

///---- Implementacion de Juego ------------------------------
Juego::Juego(int caJ){//constructor, inicializa el arreglo de jugadores
	for(int x=0; x< caJ; x++){
		switch (x%3){
		case 0: {J[x].asignarTipo("Caballero",6,0);
		break;};
		case 1: {J[x].asignarTipo("Arquero",2,4);
		break;};
		case 2: {J[x].asignarTipo("Mago",3,3);
		break;};			
		}
		//cout<<x<<") "<<J[x].tipo()<<" : Vida= "<<J[x].estaVivo()<<" : Mana= "<<J[x].ver_mana()<<endl;
	}
}
Personaje *Juego::estado(int x){
	return &J[x];
}
void Juego::jugada(int x, int y){
	J[x].atacar(J[y]);
}

void Juego::mostrar(int caJ){
	//Muestro los jugadores
	for(int m=0; m<caJ; m++){
		cout<<m<<") "<<"Jugador: "<<J[m].tipo()<<" Vida: "<<J[m].estaVivo()<<endl;
	}
}

int main(int argc, char *argv[]) {
	int caJ=5;//Cantidad de Jugadores
	do{
		cout<<"Ingrese la cantidad de Jugadores (<30): ";cin>>caJ;
	}while(caJ>30);
	Personaje *Jugador1, *Jugador2;//Punteros a jugadores
	Juego Game(caJ);//Inicializo el objeto Game
	Game.mostrar(caJ);//muestro el objeto Game
	//******************************************************/*/*/
	bool final= false;
	int pos, enemig, contVivos, ganador; 
	while(!final){
		do{//Selecciono aleatoriamente el atacante
			pos= rand()%caJ;
			Jugador1= Game.estado(pos);
		}while(Jugador1->estaVivo()== 0);//Si esta muerto elige otro vivo
		do{//genero enemigo al azar distinto de posicion del atacante
			enemig= rand()%caJ;
		}while(pos==enemig);
		cout<<pos<<" - "<<enemig<<endl;
		Jugador2= Game.estado(enemig);
		cout<<pos<<") Jugador: "<<Jugador1->tipo()<<" Vida: "<<Jugador1->estaVivo()<<"   ";
		cout<<enemig<<") Enemigo: "<<Jugador2->tipo()<<" Vida: "<<Jugador2->estaVivo()<<endl;
		if ((Jugador1->estaVivo()) != 0){
			Jugador1->atacar(*Jugador2);
			cout<<"ATAQUE!!! "<<enemig<<") Enemigo: "<<Jugador2->tipo()<<" Vida: "<<Jugador2->estaVivo()<<endl;
			contVivos=0;
			for (int k=0; k< caJ; k++){
				Jugador2=Game.estado(k);
				if ((Jugador2->estaVivo())>0){
					contVivos++;
					ganador= k;
				}
			}
			cout<<"Estan vivos: "<<contVivos<<endl;
			if (contVivos == 1)
				final= true;
		}
		else
			pos++;
		
	}//Si sale es porque queda un solo jugador vivo
	Jugador2=Game.estado(ganador);
	cout<<"GANADOR "<<ganador<<") "<<Jugador2->tipo()<<": vida= "<<Jugador2->estaVivo()<<endl;
	return 0;
}

