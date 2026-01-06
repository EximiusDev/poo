#ifndef PANTALLA_H
#define PANTALLA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Character.h"
using namespace sf;
class Pantalla {
private:
	RenderWindow wind;
public:
	Pantalla();
	void Start();

};

#endif

