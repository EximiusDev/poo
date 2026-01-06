#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Scene.h"
#include "Game.h"
#include "GameOverScreen.h"


class GameManager : public Scene {
public:
	GameManager(RenderWindow & window, Game & game);
	void InputEvents (Event & event);
	void Update (Game & game, float delta);
	void Draw (RenderWindow & window);
	void GameOver();
	void EnemyKilled();
	int GetKills();
private:
	Game* p_game;
	
	int kills;
	
	float totalTime;
	float deadTime;
	bool gameOver;
};

#endif

