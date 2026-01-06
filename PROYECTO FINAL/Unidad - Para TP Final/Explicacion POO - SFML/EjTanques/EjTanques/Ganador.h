#ifndef GANADOR_H
#define GANADOR_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Escena.h"
using namespace sf;

class Ganador : public Escena {
public:
	Ganador(bool player_one);
	void actualizar(Juego &j) override;
	void dibujar(RenderWindow &w) override;
private:
	Font m_font;
	Text m_text;
};

#endif

