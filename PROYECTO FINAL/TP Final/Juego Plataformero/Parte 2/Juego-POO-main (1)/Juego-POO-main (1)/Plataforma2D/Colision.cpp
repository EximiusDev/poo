#include "Colision.h"
#include "CrearSprite.h"

Colision::Colision() {
	Rect<int>A(0,704,1920,96);
	HitBox =A;
}

bool Colision::Colisiona(CrearSprite Spr){
	
	
	if(HitBox.contains(Spr.getxR()+170,Spr.gety()+200)){
		Coli=true;
	}
	
	return Coli;
}
