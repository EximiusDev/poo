
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

bool Object::Collide(Object & Obj){
	//FloatRect r1= this->spr.getGlobalBounds();
	//FloatRect r2= Obj.spr.getGlobalBounds();
	
	m_bounds = this->spr.getGlobalBounds(); 	// m_bounds : player
	other_bounds = Obj.spr.getGlobalBounds(); 	// other_bounds : bloq
	
	//m_bounds.left = m_bounds.left +100; /// cambia la posicion del objeto m_bounds (corre la hitbox 100 a la izquierda)
	
	return m_bounds.intersects(other_bounds);
}; 

///ELIMINAR NUMEROS MAGICOS
bool Object::CollideDown(Object & Obj){ /// colision con el piso
	//FloatRect r1= this->spr.getGlobalBounds();
	//FloatRect r2= Obj.spr.getGlobalBounds();
	m_bounds = this->spr.getGlobalBounds(); 	// m_bounds : player
	other_bounds = Obj.spr.getGlobalBounds(); 	// other_bounds : bloq
	if(m_bounds.intersects(other_bounds)&&m_bounds.top+m_bounds.height>other_bounds.top&&m_bounds.left<other_bounds.left+other_bounds.width&&m_bounds.left+m_bounds.width>other_bounds.left&&m_bounds.top+m_bounds.height<other_bounds.top+22){
		return true;
	}
		return false;
	
}; 
bool Object::CollideUp(Object & Obj){
	//FloatRect r1= this->spr.getGlobalBounds();
	//FloatRect r2= Obj.spr.getGlobalBounds();
	m_bounds = this->spr.getGlobalBounds(); 	// m_bounds : player
	other_bounds = Obj.spr.getGlobalBounds(); 	// other_bounds : bloq

	if(m_bounds.intersects(other_bounds)&&m_bounds.top<other_bounds.top+other_bounds.height&&m_bounds.top>other_bounds.top+other_bounds.height-20&&m_bounds.left<other_bounds.left+other_bounds.width&&m_bounds.left+m_bounds.width>other_bounds.left){
		return true;
	}
	return false;

}; 


bool Object::CollideWithWallright(Object & Obj){
	//FloatRect m_bounds= this->spr.getGlobalBounds(); //r1 : player
	//FloatRect other_bounds= Obj.spr.getGlobalBounds(); //r2 : bloq
	m_bounds = this->spr.getGlobalBounds(); 	// m_bounds : player
	other_bounds = Obj.spr.getGlobalBounds(); 	// other_bounds : bloq
	
	//if(m_bounds.intersects(other_bounds)&&m_bounds.top+m_bounds.height>other_bounds.top+50&&m_bounds.top<other_bounds.top+other_bounds.height-50&&m_bounds.left+m_bounds.width>other_bounds.left&&m_bounds.left+m_bounds.width<other_bounds.left+50){ //Si se intertan y el personaje esta mas abajo entonces devolver verdadero
	if(m_bounds.intersects(other_bounds)&&m_bounds.top+m_bounds.height>other_bounds.top+20&&m_bounds.top<other_bounds.top+other_bounds.height-20&&m_bounds.left+m_bounds.width>other_bounds.left&&m_bounds.left+m_bounds.width<other_bounds.left+20){ //Si se intertan y el personaje esta mas abajo entonces devolver verdadero
		return true;
	}
	return false;

}
bool Object::CollideWithWallleft(Object & Obj){
	//FloatRect r1= this->spr.getGlobalBounds();
	//FloatRect r2= Obj.spr.getGlobalBounds();
	m_bounds = this->spr.getGlobalBounds(); 	// m_bounds : player
	other_bounds = Obj.spr.getGlobalBounds(); 	// other_bounds : bloq
	
	//if(m_bounds.intersects(other_bounds)&&m_bounds.top+m_bounds.height>other_bounds.top+50&&m_bounds.top<other_bounds.top+other_bounds.height-50&&m_bounds.left<other_bounds.left+other_bounds.width&&m_bounds.left+50>other_bounds.left+other_bounds.width){ //Si se intertan y el personaje esta mas abajo entonces devolver verdadero
	if(m_bounds.intersects(other_bounds)&&m_bounds.top+m_bounds.height>other_bounds.top+20&&m_bounds.top<other_bounds.top+other_bounds.height-20&&m_bounds.left<other_bounds.left+other_bounds.width&&m_bounds.left+20>other_bounds.left+other_bounds.width){ //Si se intertan y el personaje esta mas abajo entonces devolver verdadero
		return true;
	}
	return false;
}



