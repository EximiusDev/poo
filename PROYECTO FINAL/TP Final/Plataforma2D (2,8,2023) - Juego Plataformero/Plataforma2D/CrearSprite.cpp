#include "CrearSprite.h"

CrearSprite::CrearSprite() {
	WalkRight.resize(21);
	JumpRight.resize(10);
	IdleRight.resize(21);
	
	WalkLeft.resize(21);
	JumpLeft.resize(10);
	IdleLeft.resize(21);
	
	xR=300;
	xL=xR+256;
	
for(int i=1;i<21;i++) { 
	WalkRight[i].createSpr("Walk"+to_string(i)+".png",0.5,0.5,xR,300);
	IdleRight[i].createSpr(to_string(i)+".png",0.5,0.5,xR,300);
	WalkLeft[i].createSpr("Walk"+to_string(i)+".png",-0.5,0.5,xL,300);
	IdleLeft[i].createSpr(to_string(i)+".png",-0.5,0.5,xL,300);
	}
for(int i=1;i<9;i++) {
	JumpRight[i].createSpr("J"+to_string(i)+".png",0.5,0.5,xR,300);
	JumpLeft[i].createSpr("J"+to_string(i)+".png",-0.5,0.5,xL,300);
}
}
		///El error puede estar aca o arriba no en otro lado 
Sprite CrearSprite::getSprW(int i,bool Flip){if(Flip){ WalkLeft[i].setScal(-0.5,0.5);WalkLeft[i].setPos(xL,y); return WalkLeft[i].getSpr();}else{WalkRight[i].setScal(0.5,0.5);WalkRight[i].setPos(xR,y); return WalkRight[i].getSpr();}}
Sprite CrearSprite::getSprJ(int i,bool Flip){if(Flip){JumpLeft[i].setScal(-0.5,0.5);JumpLeft[i].setPos(xL,y);return JumpLeft[i].getSpr();}else{JumpRight[i].setScal(0.5,0.5);JumpRight[i].setPos(xR,y);return JumpRight[i].getSpr();}}
Sprite CrearSprite::getSprI(int i,bool Flip){if(Flip){IdleLeft[i].setScal(-0.5,0.5);IdleLeft[i].setPos(xL,y);return IdleLeft[i].getSpr();}else{IdleRight[i].setScal(0.5,0.5);IdleRight[i].setPos(xR,y);return IdleRight[i].getSpr();}}

///Para evitar errores aseguro y lo pongo ahi


void CrearSprite::setPos(int x,int y){
	this ->y= y;
	xR=x;
	xL=xR+256;
	for(int i=1;i<21;i++) { 
		WalkRight[i].setPos(xR,y);
		IdleRight[i].setPos(xR,y);
		WalkLeft[i].setPos(xL,y);
		IdleLeft[i].setPos(xL,y);
		}
	for(int i=1;i<9;i++) {
		JumpRight[i].setPos(xR,y);
		JumpLeft[i].setPos(xL,y);
	}
}
int CrearSprite::getxR(){return xR;}
int CrearSprite::gety(){return y;}


