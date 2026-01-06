#ifndef SPAWNMANAGER_H
#define SPAWNMANAGER_H
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "UI.h"

class SpawnManager : public Scene {
public:
	SpawnManager();
	void Startup(Player &player, RenderWindow & window, GameManager &gameManager, UI& ui, Game &game);
	void InputEvents (Event & event);
	void Update (Game & game, float delta);
	void Draw (RenderWindow & window);
	
	void SpawnEnemy();
	
	int RandomRangeINT(int min, int maximo);
	
	void playHitSound();
private:
	float totalTime;
	float spawnRate;
	
	vector<Enemy> Enemies;
	Texture enemies_tex;
	Texture enemiesDamaged_tex;
	Texture enemiesDie_tex;
	
	Player * p_player;
	GameManager* p_gameManager;
	UI* p_ui;
	
	SoundBuffer damage_buffer;
	Sound damage_sound;
};

#endif

