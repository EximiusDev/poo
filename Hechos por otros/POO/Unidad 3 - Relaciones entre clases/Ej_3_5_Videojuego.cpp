#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


/*
 * Clase base: Personaje
 */ 
class Personaje{
	protected:
	// atributos de los personajes
	float vida, mana;
	public:
	// constructor: inicializa la vida
	// y mana de un personaje cualquiera
	Personaje(){vida=15; mana=15;};
	
	// permite saber si el personaje sigue vivo
	bool EstaVivo(){return vida>=0;};
	
	// recibe un golpe y quita vida y mana al personaje
	void RecibirGolpe(int v, int m){
		vida-=v;
		mana-=m;
	}
	
	// funciones utiles para saber cuanta enerǵia
	// y mana le queda al personaje
	float VerVida(){return vida;};
	float VerMana(){return mana;};
	
	// funciones virtuales puras, ya que hacen algo distinto
	// segun el tipo de personaje que se trate, no tiene sentido
	// implementarlas en esta clase dado que segun el enunciado
	// no sabemos como ataca un personaje generico. Ademas,
	// al ser virtuales puros convierten la clase Personaje en
	// abstracta, no permitiendo al usuario crear instancias de la
	// clase personaje
	virtual void Atacar(Personaje &p)=0;
	virtual string VerTipo()=0;	// devuelve una cadena con el tipo de personaje
};


/*
 * Clase Arquero
 */
class Arquero: public Personaje{	
	public:
	void Atacar(Personaje &p){
		p.RecibirGolpe(2, 4);
	};
	string VerTipo(){return "Arquero";};
};


/*
 * Clase Mago
 */
class Mago: public Personaje{	
	public:
	void Atacar(Personaje &p){
		p.RecibirGolpe(3, 3);
	};
	string VerTipo(){return "Mago";};
};


/*
 * Clase Caballero
 */
class Caballero: public Personaje{	
	public:
	void Atacar(Personaje &p){
		p.RecibirGolpe(6, 0);
	};
	string VerTipo(){return "Caballero";};
};


/*
 * Clase Juego: se encarga de crear los personajes
 * y realizar la simulacion
 */
class Juego{
	private:
	// arreglo con los personajes del juego
	static unsigned const nPersonajes=15;
	Personaje *personajes[nPersonajes];
	
	public:
	// inicializa el arreglo de personajes
	void InicializarPersonajes(){
		for(unsigned i=0; i<nPersonajes; i++){
			switch(rand()%3){
				case 0:
					personajes[i]=new Mago;
				break;
				
				case 1:
					personajes[i]=new Arquero;
				break;
			
				case 2:
					personajes[i]=new Caballero;
				break;
			}
		}
	}
		
	
	// corre el juego: hace que cada personaje ataque a otro
	// hasta que solo quede uno vivo
	void Correr(){
		// cuenta los personajes vivos
		unsigned nPersonajesVivos=nPersonajes;
		
		// el numero de jugadas realizadas
		unsigned nJugadas=1;
		
		// el bucle principal del juego, hace que cada personaje
		// ataque y muestra el estado de cada uno
		while(nPersonajesVivos>1){
			cout<<"Jugada N: "<<nJugadas<<endl<<endl;
			// hace que cada personaje ataque
			for(unsigned i=0; i<nPersonajes; i++){
				// solo ataca si el personaje todavia esta vivo
				if(personajes[i]->EstaVivo()){
					// elige otro personaje para atacar
					int cualAtacar=rand()%nPersonajes;
					// se asegura de atacar de que el personaje a atacar
					// este vivo y de no atacarse el solo
					while(!personajes[cualAtacar]->EstaVivo() || cualAtacar==i) cualAtacar=rand()%nPersonajes;
					personajes[i]->Atacar(*(personajes[cualAtacar]));
				}
				
			}
			
			// imprimimos el estado de cada personaje
			for(unsigned k=0; k<nPersonajes; k++){
				cout<<"Personaje: "<<left<<setw(2)<<k<<" -> "<<left<<setw(15)<<personajes[k]->VerTipo()<<"-> ";
				if(personajes[k]->EstaVivo()){
					cout<<"vida: "<<setw(10)<<personajes[k]->VerVida();
					cout<<"mana: "<<setw(10)<<personajes[k]->VerMana()<<endl;
				}else{
					cout<<"MUERTO"<<endl;
				}
			}
			
			// contamos los que quedan vivos para saber cuando detenernos
			nPersonajesVivos=0;
			for(unsigned i=0; i<nPersonajes; i++){
				if(personajes[i]->EstaVivo()) nPersonajesVivos++;
			}
			
			// incrementa el numero de jugada
			nJugadas++;
			
			cout<<endl<<endl<<"Presione una tecla para continuar..."<<endl<<endl;
			cin.get();
		}
		
		// buscamos el que quedo vivo para mostrar
		int cualQuedoVivo=0;
		while(!personajes[cualQuedoVivo]->EstaVivo()) cualQuedoVivo++;
		
		cout<<"GANADOR!!!: Personaje "<<cualQuedoVivo<<": "<<personajes[cualQuedoVivo]->VerTipo();
		cout<<" -> vida: "<<personajes[cualQuedoVivo]->VerVida();
		cout<<"    mana: "<<personajes[cualQuedoVivo]->VerMana()<<endl;
		
		
	}
	
};

int main(int argc, char *argv[]) {
	Juego j;
	
	j.InicializarPersonajes();
	j.Correr();
	
	return 0;
}

