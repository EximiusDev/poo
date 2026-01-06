#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H
#include "Scene.h"
#include "Button.h"
#include "Game.h"

class GameOverScreen : public Scene {
public:
	GameOverScreen(RenderWindow & window, int currentScore, Game& game);
	void InputEvents (Event & event);
	void Update (Game & game, float delta);
	void Draw (RenderWindow & window);
	void SetSpriteSize(int currentScore, int highscore);
	int SaveAndLoad(int score);
private:
	Game* p_game;
	
	Texture background_tex;
	Sprite background_spr;
	
	Texture midleground_tex;
	Sprite midleground_spr;
	
	Font mainFont;
	
	Text currentScore_text;
	Text highScore_text;
	
	Button menu_button;
	Button exit_button;
	
	SoundBuffer succes_buffer;
	Sound succes_sound;
	
	SoundBuffer interact_buffer;
};

#endif

