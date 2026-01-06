
#include "../H/Object.h"
Object::Object() {}
Object::Object(string name) {
	tex.loadFromFile(name);
	spr.setTexture(tex);
	
}
void Object::Draw (RenderWindow& win ) {
	win.draw(spr);
}
bool Object::Collide(Object & Obj){
	FloatRect r1= this->spr.getGlobalBounds();
	FloatRect r2= Obj.spr.getGlobalBounds();
	//r1.left = r1.left +100; /// cambia la posicion del objeto r1 (corre la hitbox 100 a la izquierda)
	
	return r1.intersects(r2);
}; 

bool Object::CollideUp(Object & Obj){
	FloatRect r1= this->spr.getGlobalBounds();
	FloatRect r2= Obj.spr.getGlobalBounds();
	
	if((r2.top+r2.height > r1.top) && (r2.left + r2.width > r1.left && r2.left  < r1.left+r1.width )){ //Calcula la interseccion solo con la parte de arriba del bloque
		return true;
	}
	else return false;
};
bool Object::CollideWithWallright(Object & Obj){
	FloatRect r1= this->spr.getGlobalBounds();
	FloatRect r2= Obj.spr.getGlobalBounds();
	/*
	if((r2.top+r2.height > r1.top) && (r2.left + r2.width > r1.left && r2.left  < r1.left+r1.width )){
		bool aux1;
	}
	else{
		
	}*/
	///if((r1.left+r1.width > r2.left + 10)&& (r2.left + r2.width > r1.left + r1.width && r2.left  < r1.left+r1.width )&& (r2.top + r2.height > r1.top -10  && r2.top + 10  < r1.top + r1.height )){ 
	if((r1.left+r1.width + 10 > r2.left)&& (r2.left  > r1.left + r1.width - 20) && (r2.top < r1.top + r1.height -20) && (r2.top + r2.height > r1.top + r1.height -20)) {// && (r2.top + 10  < r1.top + r1.height )){ 
		/*return true;
	}
	else return false;
	*/
	//if((r2.left+r2.width > r1.left + r1.width) && (r2.top + r2.height > r1.top +10  && r2.top + 10  < r1.top + r1.height )){ //&& (r2.left + r2.width > r1.left && r2.left  < r1.left+r1.width )){ 
	//if((r2.left+r2.width > r1.left + r1.width) && (r2.top + r2.height > r1.top +10  && r2.top + 10  < r1.top + r1.height )){ //&& (r2.left + r2.width > r1.left && r2.left  < r1.left+r1.width )){ 
	//if((r1.left+r1.width > r2.left) && (r2.top + r2.height > r1.top +10  && r2.top + 10  < r1.top + r1.height )){ //&& (r2.left + r2.width > r1.left && r2.left  < r1.left+r1.width )){ 
		return true;
	}
	else return false;
}; 
