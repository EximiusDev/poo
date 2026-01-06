#ifndef CREARSPRITE_H
#define CREARSPRITE_H
#include "Character.h"

class CrearSprite {
private:
	vector<Character> WalkRight;
	vector<Character> JumpRight;
	vector<Character> JumpLeft;
	vector<Character> WalkLeft;
	vector<Character> IdleRight;
	vector<Character> IdleLeft; ///SON MUCHOS POR QUE CUALQUIER OTRA COSA RELENTIZA EL JUEGO
	int xL;
	int xR;
	int y;

public:
	CrearSprite();
	void Mod(int n,string Nom);
	Sprite getSprW(int i,bool Flip);
	Sprite getSprJ(int i,bool Flip);
	Sprite getSprI(int i,bool Flip);
	
	void setPos(int x,int y);
	int getxR();
	int gety();
};

#endif

