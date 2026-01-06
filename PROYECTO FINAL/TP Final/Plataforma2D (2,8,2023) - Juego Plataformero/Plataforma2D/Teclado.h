#ifndef TECLADO_H
#define TECLADO_H
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class Teclado {
private:
public:
	Teclado();
	int Tecla(Keyboard KeyB);
};

#endif

