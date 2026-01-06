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
	int res_x, res_y;
public:
	Pantalla(int resulucion_x,int resulucion_y); /// constructor de Pantalla
	void Run(string Nom); /// metodo de Pantalla Run
	
};

#endif

