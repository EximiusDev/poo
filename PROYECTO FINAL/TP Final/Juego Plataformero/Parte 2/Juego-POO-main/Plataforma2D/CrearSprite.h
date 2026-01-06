#ifndef CREARSPRITE_H
#define CREARSPRITE_H
#include "Character.h"

class CrearSprite {
private:
	vector<Character> WalkRight;
	vector<Character> Jump;
	vector<Character> WalkLeft;
	vector<Character> Idle;
	int xL;
	int xR;
	int y;

public:
	CrearSprite();
	void Mod(int n,string Nom);
	Sprite getSprWL(int i);
	Sprite getSprWR(int i);
	Sprite getSprJ(int i);
	Sprite getSprI(int i);
	void setPos(int x,int y);
	int getxR();
	int gety();
};

#endif

