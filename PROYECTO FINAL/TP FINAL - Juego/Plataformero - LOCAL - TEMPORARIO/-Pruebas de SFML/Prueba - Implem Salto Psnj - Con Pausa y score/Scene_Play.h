#ifndef SCENE_PLAY_H
#define SCENE_PLAY_H
#include "Scene.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include "Player.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
//using namespace sf;

class Scene_Play : public Scene {
public:
	Scene_Play();
	void Update (Game & playgame) override;
	void Draw (sf::RenderWindow & win) override;
	
	//void InputEvents (Event & event) override;
	void InputEvents (Event & event) override {};
private:
	RectangleShape m_floor;
	Player m_player;
	Font m_font;
	Text txt_mov_lat, txt_salto;
	Text txt_score;
	int m_score;
	long seconds_game;
	long seconds_pause;
	//bool paused;
};

#endif

