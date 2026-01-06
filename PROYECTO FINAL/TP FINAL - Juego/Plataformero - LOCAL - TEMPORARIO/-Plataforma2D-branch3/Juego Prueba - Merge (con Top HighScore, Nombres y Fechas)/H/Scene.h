#ifndef SCENE_H
#define SCENE_H
//#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
using namespace sf;
using namespace std;
class Game;

class Scene {
public:
	Scene();
	virtual void Update(Game &playgame,RenderWindow & win) = 0;
	virtual void Draw(sf::RenderWindow & win) = 0;
	
	virtual void InputEvents(Event &event) = 0;
	virtual ~Scene(){};
	
	void Pause_Scn(){paused = true;}
	void Unpause_Scn(){paused = false;}
	bool GetPause(){return paused;}
private:
	bool paused;
protected:
	Event m_ev;
};

#endif

