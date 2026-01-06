#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "Pantalla.h"
#include "TexturePer.h"

#include <vector>
using namespace std; /// son necesarios ambos namespace sino no funciona
using namespace sf;

int main(int argc, char *argv[]){
	//int resolucion_x = 1280 , resolucion_y = 720; 
	///int resolucion_x = 1366 , resolucion_y = 768;
	int resolucion_x = 1920, resolucion_y = 1080;
	
	Pantalla A(resolucion_x,resolucion_y); /// define a A como objeto de tipo Pantalla
	
	
	A.Run("Excabadora-izq.png"); /// llamo a el obejto A con el metodo Run(para correr el juego) y le paso la imagen a cargar (la imagen del personaje)
	//A.Run("sfml.png");
	
	return 0;
}

