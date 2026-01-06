#ifndef VIDA_H
#define VIDA_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;
class Vida {
private:
	int cantVida =3;
	Texture TF;
	Sprite SF;
	Texture TV;
	Sprite SV;
public:
	Vida();
	bool pierdeVida();
	void Reinicio();
	Sprite sgSpriteFull(int i);
	Sprite sgSpriteVoid(int i);
	
	int getVida();
};

#endif

