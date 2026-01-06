#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window/Keyboard.hpp>
#include "Object.h"
using namespace sf;
class Player: public Object{
private:
	float x_position=400;
	float y_position=500;
	bool Jumping;
	int Jumping_Time=40;
public:
	Player();
	void Update();
};	

#endif

