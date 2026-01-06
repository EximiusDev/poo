#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Character.h"

class Enemigo {
private:
	Character Spr_E;
	int pos_x;
	int pos_y;
	int mundo_x;
	int mundo_y;
	bool vivo = true;
public:
	Enemigo(string Nom,float x1,float y1,int x,int y);
	Enemigo();
	void  Set_Pos_Spr(int x,int y);
	void  Mod_Pos_Mundo(int x0,int y0);
	void  Crear_Spr(string Nom,float x1,float y1,int x,int y);
};











#endif

