#ifndef BLOQUES_H
#define BLOQUES_H
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>

using namespace std;
using namespace sf;
class Bloques {
private:
	Texture tb;
	Sprite s;
	int y;
	int x;
public:
	Bloques();
	void Start(string Nom);
	void setPos(int x,int y);
	Sprite getSpr();
	int getY();
	int getX();
};

#endif

