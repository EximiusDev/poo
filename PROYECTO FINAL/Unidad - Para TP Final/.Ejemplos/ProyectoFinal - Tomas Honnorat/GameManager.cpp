#include "GameManager.h"
#include <fstream>
using namespace std;

GameManager::GameManager(RenderWindow & window, Game & game) : kills(0), totalTime(0), deadTime(2), gameOver(false)
{
	p_window = &window;
	p_game = &game;
}

void GameManager::InputEvents (Event & event) 
{
	
}

void GameManager::Update (Game & game, float delta) 
{
	if (gameOver)
	{
		totalTime += delta;
		if(totalTime >= deadTime)
		{
			// Change scene
			p_game->SetScene(new GameOverScreen(*p_window, kills, *p_game));
			gameOver = false;
		}
	}
}

void GameManager::Draw (RenderWindow & window) 
{
	
}

void GameManager::GameOver()
{
	gameOver = true;
	
}

void GameManager::EnemyKilled()
{
	kills++;
}

int GameManager::GetKills()
{
	return kills;
}


