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
	vector<vector<Texture>>Textu;
	vector<vector<Sprite>>Spri;
	
	int altura; /// minimo 200 /// la altura siempre tiene que tener minimo 2 ceros al final ej 100, 200, 500, 1000, 10000
	int ancho; /// minimo 120 (por la resolucion de pantalla)
	int nivelcero; /// nivel donde empiza el suelo
	int altura_total; /// altura + distancia de nivelcero
	
	int res_x, res_y;
	int tam_bloq;
	int pant_medio_x, pant_medio_y;
	
public:
	TextureBloq(vector<vector<TipoBloque>>M_Bloq, int altura_E, int ancho_E, int nivelcero_E, int resolucion_x,int resolucion_y, int x1, int y1);
	Sprite VerSpr(int a,int b, int y1, int x1);
	void PosSpr(int a,int b, int y1, int x1);
};

#endif

