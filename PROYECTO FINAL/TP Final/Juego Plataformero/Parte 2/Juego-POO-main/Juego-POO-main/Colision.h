#ifndef COLISION_H
#define COLISION_H
#include <SFML/Graphics/Rect.hpp>
#include "CrearSprite.h"
using namespace sf;
class Colision {
private:
	Rect<int>HitBox;
	bool Coli =false;
public:
	Colision();
	bool Colisiona(CrearSprite Spr);
};

#endif

