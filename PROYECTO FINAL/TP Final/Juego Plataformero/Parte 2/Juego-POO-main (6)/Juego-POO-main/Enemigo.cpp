#include "Enemigo.h"
//#include "Character.h"
#include "Bloques.h"

//Enemigo::Enemigo(string Nom,float x1,float y1,int x,int y) {
Enemigo::Enemigo(string Nom) {
	if(vivo == true){
		Spr_E.Start(Nom);
		//pos_x = x;
		//pos_y = y;
	}
}
Enemigo::Enemigo(){};

void  Enemigo::Crear_Spr(string Nom){
	if(vivo == true){
		Spr_E.Start(Nom);
		//pos_x = x;
		//pos_y = y;
	}
}

void  Enemigo::Set_Pos_Spr(int x,int y){
	if(vivo == true){
		Spr_E.setPos(x,y);
		pos_x = x;
		pos_y = y;
	}
}
void  Enemigo::Mod_Pos_Mundo(int x0,int y0){
	mundo_x = x0;
	mundo_y = y0;
}
void Enemigo::setScale(float x1,float y1){
	Spr_E.setScal(x1,y1);
}
Sprite Enemigo::get_Spr(){return Spr_E.getSpr();}
