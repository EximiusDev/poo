#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window/Keyboard.hpp>
#include "Object.h"
#include <ctime>
#include "Platform.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
using namespace std;
using namespace sf;
class Player: public Object{
private:
	Clock jumping_time;
	
	string Name1;
	int number_Animation=1;
	bool walking_animation=false;
	bool jumping_Animation=false;
	bool on_Air_Jumping;
	bool on_Air_Falling;
	
	bool Idle=true;
	RectangleShape cell_0;
	
	FloatRect r1= spr.getGlobalBounds();
	//FloatRect m_bounds= spr.getGlobalBounds();
	//FloatRect other_bounds;
	//int p_score;
	float p_score=0;
	float score_pos=0;
	float score_spe=0;
	bool sumar_score;
	bool player_two = false;
public:
	Player();
	Player(bool player_2);
	void Update(bool collide_With_floor, bool collide_With_top,bool collide_With_wall_left,bool collide_With_wall_right,float velocity, int & life, Game& playgame);
	string Animation ();
	void Change_score(int score);
	int GetScore();
	
};	

#endif
