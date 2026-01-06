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

	///12,12
Vector2f scaleG={5,5};
//Vector2f scaleG={0,0};
Vector2f resolutionG={1280,720};

///Vector2f speedG = {1,0}; //Velocidad general
Vector2f speedG = {0,0}; //Velocidad general
Vector2f positionG = {0,0}; 
Vector2f acelG = {0,0};


Texture tex;
Sprite spr;

/// bool Iniciado = false;

public:
	Object();
	Object(string name);
	Object(Texture & textu);
	void Draw (RenderWindow& win);
	bool Collide(Object & Obj);
	
	bool CollideUp(Object & Obj);
	bool CollideWithWallleft(Object & Obj);
	bool CollideWithWallright(Object & Obj);
	//virtual bool CollideUp(Object & Obj)=0;  /// cada objeto lo hace de manera diferente
	//virtual bool CollideWithWallleft(Object & Obj)=0;
	//virtual bool CollideWithWallright(Object & Obj)=0;
};

#endif

