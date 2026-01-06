#include "Background.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
using namespace std;
using namespace sf;
Background::Background() {
	
}
void Background::createBackg(string Nom){
	tb.loadFromFile(Nom);
	sb.setTexture(tb);
	sb.setPosition(0,0);
	sb.setScale(6.75,6.75);
}
Sprite Background::getSpr(){return sb;}
void Background::setPos(int x,int y){
	sb.setPosition(x,y);
}
void Background::setSca(float x,float y){
	sb.setScale(x,y);
}
