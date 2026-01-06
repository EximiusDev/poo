#ifndef SCENE_GAMEOVER_H
#define SCENE_GAMEOVER_H
#include "H/Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
using namespace sf;
using namespace std;
class Scene_GameOver :public Scene {
public:
	Scene_GameOver();
	Scene_GameOver(int score);
	void Update (Game & playgame, RenderWindow & win) override;
	void Draw (RenderWindow & win) override;
	
	void InputEvents (Event & event) override {};
	int SaveAndLoad(int score);
private:
	vector<Texture>Tex;
	vector<Sprite>Spr;
	
	Mouse Arrow;
	Vector2i r1;
	int highscore;
	int m_score;
	
	Font m_font;
	Text txt_score;
	Text txt_highScore;
};

#endif

