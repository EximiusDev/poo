#ifndef TEXTURE_PLATFORM_H
#define TEXTURE_PLATFORM_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
//#include "Estructuras"

#include <string>

using namespace std;
using namespace sf;

class Texture_Platform {
private:
	int pos_x;
	int pos_y;
	int tamanio_x;
	int tamanio_y;
	
	string nomBloq;
	
	//float deslizamiento;
	
	vector<vector<Texture>>mat_textu;
	vector<vector<Sprite>>mat_spri;
	
public:
	Texture_Platform(int posicion_x, int posicion_y, int largo, int alto, string nomBloque);
	Texture_Platform(int largo, int alto, string nomBloque);
	
	
	Sprite Texture_Platform::VerSpr(int a,int b, int x1, int y1);
	void Texture_Platform::PosSpr(int a,int b, int x1, int y1);
	
	int Texture_Platform::VerLargo();
	int Texture_Platform::VerAlto();
	
};

#endif

