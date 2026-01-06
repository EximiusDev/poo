#include "Character.h"
#include <SFML/Graphics/Sprite.hpp>
#include <string>
using namespace std;

Character::Character() {}
void   Character::setPos(int x,int y){
	s.setPosition(x,y);
}

void Character::setScal(float x,float y){
	s.setScale(x,y);
};
void Character::createSpr(string Nom,float x1,float y1,int x,int y){
t.loadFromFile(Nom);
s.setTexture(t);
s.setScale(x1,y1);
s.setPosition(x,y);}
Sprite Character::getSpr(){return s;}

