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
	Texture textur;
	Sprite spr;
	Player player;
	//Parallax background_Parallax;
	Platform plat;
	bool on_Air;
	
public:
		
	Game();
	void run();
	void update();
	void draw();
	void processEvent();
	

	

	
};

#endif

