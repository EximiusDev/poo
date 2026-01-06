#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "Pantalla.h"
#include "TexturePer.h"
#include <vector>
#include "GeneracionMundo.h"
#include <iostream>

#include "Personaje.h"
#include "Equipamiento.h"

using namespace std; /// son necesarios ambos namespace sino no funciona
using namespace sf;

int main(int argc, char *argv[]){

	//Pantalla A; /// define a A como objeto de tipo Pantalla
	
	int kit_rep = 10;
	int radar = 10;
	int andamios = 10;
	int motor = 10;
	int taladro  =  10;
	int tanque_combust = 10;
	int refuerzo_estruc = 10;
	int bombas = 10;
	
	int vida = 99;
	int combustible = 99;
	int dinero = 99;
	
	Equipamiento equipado(kit_rep, radar, andamios, motor, taladro, tanque_combust, refuerzo_estruc, bombas);
	
	Personaje Pj( vida, combustible, dinero, equipado);
	
	Equipamiento Eq();
	
	Eq = equipado;
	
	cout<<endl;
	cout<<equipado.Ver_motor();
	cout<<endl;
	
	Pj.Modificar_Equipamiento(Eq);
	cout<<endl;
	cout<<endl;
	cout<<Pj.Ver_dinero();
	cout<<endl;
	
	/*GeneracionMundo B;
	B.Modificardatos(50,50,20);
		vector<vector<TipoBloque>>B1= B.Ver_Matriz_Bloques();
	for(int i=0;i<100;i++) { 
		for(int j=0;j<100;j++) { 
			cout<<B1[i][j].Verpuntos();
		}
		
	}*/
	//A.Run("Excabadora-izq.png"); /// llamo a el obejto A con el metodo Run(para correr el juego) y le paso la imagen a cargar (la imagen del personaje)
	//A.Run("sfml.png");
	
	return 0;
}

