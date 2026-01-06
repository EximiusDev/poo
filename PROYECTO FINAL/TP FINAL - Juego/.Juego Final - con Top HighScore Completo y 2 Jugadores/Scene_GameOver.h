#ifndef SCENE_GAMEOVER_H
#define SCENE_GAMEOVER_H
#include "H/Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

//#include <string>
//#include "string.h"
#include <cstring>
#include <sstream>
#include <ctime>
#include <time.h>

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
	~Scene_GameOver() override {};
private:
	vector<Texture>txtr_button;
	vector<Sprite>spr_button;
	
	Mouse Arrow;
	Vector2i r1;
	int highscore;
	int m_score;
	char m_date[25]; //string m_date;
	
	Font m_font;
	Text txt_score;
	Text txt_highScore;
};

#endif

