#ifndef Pantalla_h
#define Pantalla_h
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include "TexturePer.h"
using namespace std;
using namespace sf;
class Pantalla {
private:
	RenderWindow w; /// creo un objeto de tipo RenderWindow (de SFML Graphics) llamando W
public:
	Pantalla(); /// constructor de Pantalla
	void Run(string Nom); /// metodo de Pantalla Run
	
};

#endif

