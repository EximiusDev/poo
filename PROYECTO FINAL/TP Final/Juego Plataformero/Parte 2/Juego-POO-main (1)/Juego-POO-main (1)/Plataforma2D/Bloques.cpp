#include "Bloques.h"
#include <SFML/Graphics/Texture.hpp>
#include <string>
using namespace std;
using namespace sf;
Bloques::Bloques() {}
void Bloques::setPos(int x,int y){
	s.setPosition(x,y);
}
void Bloques::Start(string Nom){
	tb.loadFromFile(Nom);
	s.setTexture(tb);
	s.setScale(4,4);
}
Sprite Bloques::getSpr(){return s;}

