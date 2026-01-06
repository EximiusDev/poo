#include "TexturePer.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
TexturePer::TexturePer(string Nom) { /// atributos de la clase TexturePer (le paso la variable Nom en el encabezado)
	tex.loadFromFile(Nom); /// cargo la imagen .png como una textura (lo cargo en la clase Texture de SFML)
	spr.setTexture(tex); /// cargo el objeto t (tipo Texture) en el Sprite (DE SFML) s
}
void TexturePer::Pos(float x1,float y1){ /// paso las variables de x1, y1 de posicion (para el metodo Pos de la clase TexturePer)
	spr.setPosition(x1,y1); /// le doy una posicion al sprite, uso el metodo setPosition de la clase sprite
	this ->x = x1; /// modifico los valores de x con los de x1
	this ->y = y1;
}
void TexturePer::Tam(float tam1,float tam2){ /// uso el metodo Tam de TexturePer para dar una escala a el sprite (en x, y)
	spr.setScale(tam1,tam2);
}
Sprite TexturePer::Vs(){return spr;} /// Vs devuelve el sprite s usado
float TexturePer::verx(){return x;} /// verx devuelve la pasicion en x
float TexturePer::very(){return y;}
