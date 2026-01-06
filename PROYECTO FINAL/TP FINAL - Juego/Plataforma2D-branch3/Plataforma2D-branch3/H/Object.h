#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Object.h"
#include <string.h>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;
class Object {
protected:
Vector2f speedPJ = {0,10}; //Velocidad del personaje Saltando (PlayerJumping)
Vector2f speedPW = {10,0}; //Velocidad del personaje caminando (Player-Walking)
Vector2f speedB = {10,0}; //Velocidad del fondo
Vector2f speedT = {10,0}; //Velocidad del terreno
  Texture tex;
  Sprite spr;
public:
	Object(string name);
	void Draw (RenderWindow& win);
	bool Collide(Object &);

};

#endif

