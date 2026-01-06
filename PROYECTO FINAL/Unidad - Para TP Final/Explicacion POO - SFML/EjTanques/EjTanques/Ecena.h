#ifndef ECENA_H
#define ECENA_H
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Juego;

class Escena {
public:
	virtual void actualizar(Juego &j) = 0;
	virtual void dibujar(RenderWindow &) = 0;
};

#endif
