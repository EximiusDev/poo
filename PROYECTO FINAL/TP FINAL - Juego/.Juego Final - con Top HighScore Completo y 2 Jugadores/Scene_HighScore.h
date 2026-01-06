#ifndef SCENE_HIGHSCORE_H
#define SCENE_HIGHSCORE_H
#include "H/Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene_HighScore.h"
#include "H/Game.h"
#include <SFML/Graphics/RenderWindow.hpp>



#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "string.h"
#include <cstring>
#include <sstream>
#include <ctime>
#include <time.h>

using namespace sf;
using namespace std;
class Scene_HighScore:public Scene {
public:
	Scene_HighScore();
	
	void Update (Game & playgame, RenderWindow & win) override;
	void Draw (RenderWindow & win) override;
	void InputEvents (Event & event) override {};
	~Scene_HighScore() override {};
	
	static bool reverse_sort(Data_Struct a1,Data_Struct a2);
private:
	Texture txtr_back;
	Sprite spr_back;
	
	Mouse Arrow;
	Vector2i r1;
	
	Font m_font;
	//Text txt_score;
	//Text txt_highScore;
	Text txt_title;
	Text txt_tittle_name;
	Text txt_tittle_score;
	Text txt_botones;
	
	vector<Text> txt_names; //_names;
	vector<Text> txt_date; //_names;
	vector<Text> txt_scores; //_scores;
	bool  init_highscores = false;
};

#endif


