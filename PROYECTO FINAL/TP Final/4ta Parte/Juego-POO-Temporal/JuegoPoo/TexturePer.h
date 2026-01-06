#ifndef TexturePer_h
#define TexturePer_h
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>

using namespace std;  /// son necesarios ambos namespace sino no funciona
using namespace sf;

class TexturePer { /// defino la clase TexturePer con sus atributos y metodos
private:
	Texture t; /// la clase Texture (pertene SFML/Graphics)
	Sprite s; /// la clase Sprite (pertene SFML/Graphics)
	float x,y;
public:
	TexturePer(string Nom); ///constructor de TexturePer le paso la imagen del personaje
	void Pos(float x1,float y1);
	float verx();
	float very();
	Sprite Vs();
	void Tam(float tam1,float tam2);
};

#endif

