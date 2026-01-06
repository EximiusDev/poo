#ifndef SCENE_H
#define SCENE_H
//#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
using namespace std;
class Game;

class Scene {
public:
	Scene();
	virtual void Update(Game &playgame) = 0;
	virtual void Draw(sf::RenderWindow & win) = 0;
	
private:
};

#endif

