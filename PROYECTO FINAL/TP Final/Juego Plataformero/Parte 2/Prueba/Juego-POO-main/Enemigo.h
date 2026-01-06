#ifndef ENEMIGO_H
#define ENEMIGO_H
//#include "Character.h"
#include "Bloques.h"
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>

class Enemigo {
private:
	//Character Spr_E;
	Bloques Spr_E;
	int pos_x;
	int pos_y;
	int mundo_x;
	int mundo_y;
	bool vivo = true;
public:
	Enemigo(string Nom);
	Enemigo();
	void  Set_Pos_Spr(int x,int y);
	void  Mod_Pos_Mundo(int x0,int y0);
	void  Crear_Spr(string Nom);
	void setScale(float x1,float y1);
	Sprite get_Spr();
};











#endif

