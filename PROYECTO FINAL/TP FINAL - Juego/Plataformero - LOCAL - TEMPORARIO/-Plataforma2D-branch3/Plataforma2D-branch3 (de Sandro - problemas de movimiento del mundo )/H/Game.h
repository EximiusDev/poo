#ifndef GAME_H
#define GAME_H
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "Player.h"
#include <vector>
#include "Background.h"
#include "Platform.h"
#include "Parallax.h"
using namespace std;
using namespace sf;

class Game {
private:
	RenderWindow win;
	
	/*
	Texture textur;
	Sprite spr;*/
	
	Player player;
	Parallax background_Parallax;
	Platform plat;
	
	bool on_Air;
	bool collide_With_wall_right;
	bool collide_With_wall_left;
	
	///Vector2f worldspeed = {-0.5,0};  agregar despues
	
	//const float GridSize = 80.f;
	
	Vector2i resolutionWin;
	
	public:
		
		Game(int resolution_x, int resolution_y);
		//Game(Vector2i resolutionWindows);
		Game();
		void run();
		void update();
		void draw();
		void processEvent();
		
		
};

#endif

