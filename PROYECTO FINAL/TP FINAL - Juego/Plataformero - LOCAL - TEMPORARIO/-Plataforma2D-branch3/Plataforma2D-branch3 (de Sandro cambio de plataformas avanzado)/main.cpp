#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "H/Game.h"


using namespace sf;

int main(int argc, char *argv[]){
	
	int resolution_x  = 1280; int resolution_y  = 720;
	//Vector2i resolutionWindows = {1280,720};
	
	
	//int tamanio_bloque = 24* scale
	int tamanio_bloque = resolution_y/10;
	
	Game G(resolution_x, resolution_y);
	//Game G(resolutionWindows);
	G.run();
	
	
	return 0;
}

