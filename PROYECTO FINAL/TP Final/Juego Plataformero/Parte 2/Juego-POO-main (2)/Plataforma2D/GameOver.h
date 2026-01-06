#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;
class GameOver {
private:
	Texture T;
	Sprite S;
public:
	GameOver();
	Sprite Perdio();
};

#endif

