
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
bool Object::CollideUp(Object & O){
	FloatRect r1= this->spr.getGlobalBounds();
	FloatRect r2= O.spr.getGlobalBounds();

	if(r2.top+r2.height > r1.top && r2.left + r2.width > r1.left && r2.left  < r1.left+r1.width &&r2.top+r2.height < r1.top + 20){ //Calcula la interseccion solo con la parte de arriba del bloque

		
		return true;
	}
	
			return false;
}; 


bool Object::CollideWithWallright(Object & O){
	FloatRect r1= this->spr.getGlobalBounds(); //r1 : bloq
	FloatRect r2= O.spr.getGlobalBounds(); //r2 : player
	if(r1.intersects(r2)&&r1.top+r1.height> r2.top+22){ //Si se intertan y el personaje esta mas abajo entonces devolver verdadero
	//by Fran: //if(r1.intersects(r2)&&r1.left+r1.width> r2.left){ //Si se intertan y el personaje esta mas abajo entonces devolver verdadero
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


bool Object::Collide(Object & O){
	FloatRect r1= this->spr.getGlobalBounds();
	FloatRect r2= O.spr.getGlobalBounds();
	//r1.left = r1.left +100; /// cambia la posicion del objeto r1 (corre la hitbox 100 a la izquierda)
	
	return r1.intersects(r2);
}; 
