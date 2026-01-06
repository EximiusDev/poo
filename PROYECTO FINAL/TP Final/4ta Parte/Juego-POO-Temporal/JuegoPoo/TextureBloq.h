#ifndef TEXTUREBLOQ_H
#define TEXTUREBLOQ_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "TipoBloque.h"
using namespace std;
using namespace sf;

class TextureBloq {

private:
	Texture textu_bloq;
	Sprite Spri_bloq;
public:
	//TextureBloq(TipoBloque bloq_de_mat);
	//void Inicializar(vector<vector<TipoBloque>>B);
	void Inicializar(TipoBloque bloq_de_mat);
	Sprite GeneradorSpr(int a,int b);
	void PosSpr(int a,int b);
	void Mov(int a,int b,int c,int d);
};

#endif

