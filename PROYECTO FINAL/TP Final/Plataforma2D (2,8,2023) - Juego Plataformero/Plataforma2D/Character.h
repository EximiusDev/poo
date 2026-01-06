#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
using namespace std;
using namespace sf;
class Character {
private:
	Texture t;
	Sprite s;
	
public:
	Character();
	void createSpr(string Nom,float x1,float y1,int x,int y);
	void setPos(int x,int y);
	void setScal(float x,float y);
	Sprite getSpr();
};

#endif

