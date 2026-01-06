#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;
class GameOver {
private:
	Texture PerdisteT;
	Sprite PerdisteS;
	Texture ReiniciarT;
	Sprite ReiniciarS;
	Texture SalirT;
	Sprite SalirS;
public:
	GameOver();
	Sprite Perdiste();
	Sprite Reiniciar();
	Sprite Salir();
};

#endif

