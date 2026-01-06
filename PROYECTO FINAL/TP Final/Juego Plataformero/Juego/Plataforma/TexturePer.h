#ifndef TEXTUREPER_H
#define TEXTUREPER_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;
class TexturePer {
private:
	Texture t;
	Sprite s;
public:
	TexturePer(string Nom);
	void Pos(int x,int y);
};

#endif

