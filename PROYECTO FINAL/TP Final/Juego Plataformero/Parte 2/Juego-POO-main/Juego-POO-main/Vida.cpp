#include "Vida.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;
Vida::Vida() {}

bool Vida::pierdeVida(){ bool Perdio; cantVida--; if(cantVida<=0){Perdio=true;return Perdio;}else{Perdio = false; return Perdio;}}

void Vida::Reinicio(){cantVida =3;}

Sprite Vida::sgSpriteFull(int i){
	
	TF.loadFromFile("Heart1.png");
	SF.setTexture(TF);
	SF.setPosition(i*96,30);
	SF.setScale(2,2);
	
	return SF;
};
Sprite Vida::sgSpriteVoid(int i){
	
	TV.loadFromFile("HeartNo1.png");
	SV.setTexture(TV);
	SV.setPosition(i*96,30);
	SV.setScale(2,2);
	return SV;
};
int Vida::getVida(){return cantVida;}
