#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "Pantalla.h"
#include "TexturePer.h"
#include <vector>
#include "GeneracionMundo.h"
#include <iostream>
using namespace std; /// son necesarios ambos namespace sino no funciona
using namespace sf;

int main(int argc, char *argv[]){
	
	///int resolucion_x = 640 , resolucion_y = 480;
	///int resolucion_x = 1280 , resolucion_y = 720; 
	///int resolucion_x = 1280 , resolucion_y = 768;
	int resolucion_x = 1366 , resolucion_y = 768;
	///int resolucion_x = 1920, resolucion_y = 1080;
	
	Pantalla Pant1(resolucion_x,resolucion_y); /// define a Pant1 como objeto de tipo Pantalla
	
	
	/*GeneracionMundo Mundo1;
	Mundo1.Modificardatos(50,50,20);
		vector<vector<TipoBloque>>B1 = Mundo1.Ver_Matriz_Bloques();
	for(int i=0;i<100;i++) { 
		for(int j=0;j<100;j++) { 
			cout<<B1[i][j].Verpuntos();
		}
		
	}*/
	
	///Pant1.Run("Excabadora-izq.png"); /// llamo a el obejto Pant1 con el metodo Run(para correr el juego) y le paso la imagen a cargar (la imagen del personaje)
	//Pant1.Run("El taladro.png"); /// llamo a el obejto Pant1 con el metodo Run(para correr el juego) y le paso la imagen a cargar (la imagen del personaje)
	Pant1.Run("Taladro_128x128.png"); /// llamo a el obejto Pant1 con el metodo Run(para correr el juego) y le paso la imagen a cargar (la imagen del personaje)
	//Pant1.Run("sfml.png");
	
	return 0;
}

