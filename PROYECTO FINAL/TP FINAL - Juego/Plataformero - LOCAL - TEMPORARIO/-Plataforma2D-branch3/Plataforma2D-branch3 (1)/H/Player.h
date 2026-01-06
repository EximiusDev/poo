#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window/Keyboard.hpp>
#include "Object.h"
#include <ctime>
using namespace std;
using namespace sf;
class Player: public Object{
private:
	Clock m_clock;
	string Name1;
	int NumAnim=1;
	bool Walking=false;
	bool jumping_Animation=false;
	bool on_Air_Jumping;
	bool on_Air_Falling;
	
public:
	Player();
	void Update(bool on_Air);
};	

#endif

