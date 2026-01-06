#ifndef CREARFONDO_H
#define CREARFONDO_H
#include <vector>
#include "Background.h"
#include <SFML/Graphics/Sprite.hpp>
using namespace std;
using namespace sf;

class CrearFondo {
private:
	vector<Background> Backg;
public:
	CrearFondo();
	void setMov(int x);
	Sprite getSpr(int i);
};

#endif

