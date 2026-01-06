#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "Utilities.h"

using namespace std;
using namespace sf;

class Scene {
public:
	Scene();
	virtual void InputEvents(Event &event) = 0;
	virtual void Update(class Game &game, float delta) = 0;
	virtual void Draw(RenderWindow &window) = 0;
	virtual ~Scene();
protected:
	RenderWindow * p_window;
	Vector2u windowSize;
};
#endif
