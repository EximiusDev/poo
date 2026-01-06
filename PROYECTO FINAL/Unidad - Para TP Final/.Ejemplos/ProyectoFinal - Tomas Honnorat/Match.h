#ifndef MATCH_H
#define MATCH_H
#include "Scene.h"
#include "Player.h"
#include "SpawnManager.h"
#include "UI.h"
#include "GameManager.h"

class Match : public Scene {
public:
	Match(RenderWindow & window, Game & game);
	~Match();
	void InputEvents (Event & event) override;
	void Update (Game & game, float delta) override;
	void Draw (RenderWindow & window) override;
	
	void SetSpritesSize();
private:
	RenderWindow * p_window;
	Player playerOne;
	
	Texture cursor_tex;
	Sprite cursor_spr;
	
	Texture ground_tex;
	Sprite ground_spr;
	
	SpawnManager spawnManager;
	UI userInterface;
	
	GameManager gameManager;
	
	SoundBuffer gameTheme_buffer;
	Sound gameTheme_sound;
};

#endif

