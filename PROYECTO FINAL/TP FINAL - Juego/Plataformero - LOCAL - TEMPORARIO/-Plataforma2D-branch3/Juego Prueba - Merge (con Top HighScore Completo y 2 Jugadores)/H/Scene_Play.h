#ifndef SCENE_PLAY_H
#define SCENE_PLAY_H
#include "Scene.h"
#include <SFML/Graphics/RectangleShape.hpp>
//#include "Player_.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
//using namespace sf;

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

class Scene_Play : public Scene {
public:
	Scene_Play(bool two_players);
	void Update (Game & playgame, RenderWindow & win) override;
	void Draw (sf::RenderWindow & win) override;
	
	//void InputEvents (Event & event) override;
	void InputEvents (Event & event) override {};
	~Scene_Play() override {};
private:
	//RectangleShape m_floor;
	//Player_ m_player;
	Font m_font;
	Text txt_mov_lat, txt_salto;
	Text txt_score;
	int m_score;
	long seconds_game;
	long seconds_pause;
	long seconds_played;
	//bool paused;
	
	/*
	Texture textur;
	Sprite spr;
	*/
	RenderWindow win;
	
	Player player_one;
	int life_one = 1;
	bool two_players = true;
	Player player_two; 
	int life_two = 1;
	Parallax background_Parallax;
	Platform plat;
	Object pinchos;
	bool collide_With_top_1;
	bool collide_With_floor_1;
	bool collide_With_wall_right_1;
	bool collide_With_wall_left_1;
	
	bool collide_With_top_2;
	bool collide_With_floor_2;
	bool collide_With_wall_right_2;
	bool collide_With_wall_left_2;
	Vector2f platformVelocity={2,2};
	
	
	float acel_velocity; // Clock acelerador;
	///Vector2f worldspeed = {-0.5,0};  agregar despues
	
	//const float GridSize = 80.f;
	
	Vector2i resolutionWin;
};

#endif

