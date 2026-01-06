#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window/Keyboard.hpp>
#include "Object.h"
#include <ctime>
#include "Platform.h"
using namespace std;
using namespace sf;
class Player: public Object{
private:
	Clock jump_clock;
	string Name1;
	int number_Animation=1;
	bool walking_animation=false;
	bool jumping_Animation=false;
	bool on_Air_Jumping;
	bool on_Air_Falling;

	bool Idle=true;


	FloatRect r1= spr.getGlobalBounds();
	
public:
	Player();
	void Update(bool on_Air, bool collide_With_wall_left,bool collide_With_wall_right);
	string Animation ();
Vector2f getVelocity();

	
};	

#endif

