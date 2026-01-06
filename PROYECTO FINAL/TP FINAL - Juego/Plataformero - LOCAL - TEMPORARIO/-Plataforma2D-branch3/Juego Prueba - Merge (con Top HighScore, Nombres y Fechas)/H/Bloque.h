#ifndef BLOQUE_H
#define BLOQUE_H
#include "Object.h"

#include <SFML/Graphics/Texture.hpp>

class Bloque:public Object{
private:
	const int cant_pixeles = 24;
	int tamanio_pixeles = resolutionG.x/16;
	bool reset_block;
public:
	Bloque();
	void Update(float vel);
	void Update(float vel, float delta);
	void Init(string name,int i,int j = 7);
	void Init(Texture & textu,int i,int j = 7);
	
	void Draw (RenderWindow& win , bool is_active = false);
	bool is_block_active();//{return reset_block;}
	void block_out_window(bool state);//{reset_block = out_window;}
};

#endif

