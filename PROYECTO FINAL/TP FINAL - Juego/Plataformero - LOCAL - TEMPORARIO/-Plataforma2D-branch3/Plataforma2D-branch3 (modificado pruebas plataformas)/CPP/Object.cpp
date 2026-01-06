
#include "../H/Object.h"
#include <iostream>
using namespace std;
Object::Object() {}
Object::Object(string name) {
	tex.loadFromFile(name);
	spr.setTexture(tex);
	
	
}
void Object::Draw (RenderWindow& win ) {
	win.draw(spr);
}
bool Object::Collide(Object & O){
	FloatRect r1= this->spr.getGlobalBounds();
	FloatRect r2= O.spr.getGlobalBounds();

	if(r2.top+r2.height > r1.top && r2.left + r2.width > r1.left && r2.left  < r1.left+r1.width &&r2.top+r2.height < r1.top + 20){ //Calcula la interseccion solo con la parte de arriba del bloque

		
		return true;
	}
	
			return false;
}; 


bool Object::CollideWithWallright(Object & O){
	FloatRect r1= this->spr.getGlobalBounds();
	FloatRect r2= O.spr.getGlobalBounds();
	if(r1.intersects(r2)&&r2.top+r2.height> r1.top+22){ //Si se intertan y el personaje esta mas abajo entonces devolver verdadero
		return true;
	}
	
	return false;
}
bool Object::CollideWithWallleft(Object & O){
	FloatRect r1= this->spr.getGlobalBounds();
	FloatRect r2= O.spr.getGlobalBounds();
	if(r1.intersects(r2)&&r2.top+r2.height > r1.top+22){ //Si se intertan y el personaje esta mas abajo entonces devolver verdadero
		return true;
	}
	return false;
}
