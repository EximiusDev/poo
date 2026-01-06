#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
using namespace std;
using namespace sf;
class Background {
private:
	Texture tb;
	Sprite sb;
public:
	Background();
	void createBackg(string Nom);
	void setPos(int x,int y);
	void setScale(float x);
	Sprite getSpr();
	
};

#endif

