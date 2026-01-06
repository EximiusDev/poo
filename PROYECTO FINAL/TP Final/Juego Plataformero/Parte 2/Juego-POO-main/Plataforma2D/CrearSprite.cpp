#include "CrearSprite.h"

CrearSprite::CrearSprite() {
	WalkRight.resize(21);
	WalkLeft.resize(21);
	Jump.resize(10);
	Idle.resize(21);
	xR=300;
	xL=xR+256;
for(int i=1;i<21;i++) { 
	WalkRight[i].createSpr("Walk"+to_string(i)+".png",0.5,0.5,xR,300);
	WalkLeft[i].createSpr("Walk"+to_string(i)+".png",-0.5,0.5,xL,300);
	
	Idle[i].createSpr(to_string(i)+".png",0.5,0.5,xR,300);}
for(int i=1;i<9;i++) {
	Jump[i].createSpr("J"+to_string(i)+".png",0.5,0.5,xR,300);
}
}
		
Sprite CrearSprite::getSprWL(int i){return WalkLeft[i].getSpr();}
Sprite CrearSprite::getSprWR(int i){return WalkRight[i].getSpr();}
Sprite CrearSprite::getSprJ(int i){return Jump[i].getSpr();}
Sprite CrearSprite::getSprI(int i){return Idle[i].getSpr();}

void CrearSprite::setPos(int x,int y){
	this ->y= y;
	xR=x;
	xL=xR+256;
	for(int i=1;i<21;i++) { 
		WalkRight[i].setPos(xR,y);
		WalkLeft[i].setPos(xL,y);
		
		Idle[i].setPos(xR,y);}
	for(int i=1;i<8;i++) {
		Jump[i].setPos(xR,y);
	}
}
int CrearSprite::getxR(){return xR;}
int CrearSprite::gety(){return y;}


