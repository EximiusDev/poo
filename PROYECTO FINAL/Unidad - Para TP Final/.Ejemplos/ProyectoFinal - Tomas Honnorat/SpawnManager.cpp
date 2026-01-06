#include "SpawnManager.h"

SpawnManager::SpawnManager() : Enemies(20), totalTime(0), spawnRate(1.5)
{
	enemies_tex.loadFromFile("Textures/Enemy.png");
	enemiesDamaged_tex.loadFromFile("Textures/EnemyDamaged.png");
	enemiesDie_tex.loadFromFile("Textures/Stone.png");
}

void SpawnManager::InputEvents (Event & event) 
{
	
}

void SpawnManager::Update (Game & game, float delta) 
{
	for(Enemy &e : Enemies)
	{
		e.Update(game, delta);
	}
	
	totalTime += delta;
	if(totalTime >= spawnRate)
	{
		totalTime = 0;
		SpawnEnemy();
		
		spawnRate -= 0.005; // AJUSTAR DIFICULTAD
		spawnRate = Clamp(spawnRate, 0.6 , 1.6);
	}
	// cout << spawnRate << endl;
}

void SpawnManager::Draw (RenderWindow & window) 
{
	for(Enemy &e : Enemies)
	{
		e.Draw(window);
	}
}

void SpawnManager::Startup(Player &player, RenderWindow & window, GameManager &gameManager, UI& ui, Game &game)
{
	p_player = &player;
	p_window = &window;
	p_gameManager = &gameManager;
	p_ui = &ui;
	
	windowSize = p_window->getSize();
	
	for(Enemy &e : Enemies)
	{
		e.Startup(player, window, enemies_tex,enemiesDamaged_tex, enemiesDie_tex, gameManager, ui, *this);
	}
	
	damage_buffer.loadFromFile("Sounds/hurt2.wav");
	damage_sound.setBuffer(damage_buffer);
	damage_sound.setVolume(game.getVolume());
}

void SpawnManager::SpawnEnemy()
{
	// Random position in radius of 740 with center in center of the screen
	float offset = 740 * windowSize.x/1280;
	
	float xpos = RandomRangeINT(0, windowSize.x);
	float ypos = RandomRangeINT(0, windowSize.y);
	
	Vector2f center(windowSize.x/2, windowSize.y/2);
	
	Vector2f spawnPos(center.x - xpos,center.y - ypos); 
	
	Vector2f pos = center + Normalize(spawnPos) * offset;
	
	//cout << pos.x << " " << pos.y << endl;
	
	for(int i = 0; i < Enemies.size(); i++)
	{
		if(!Enemies[i].IsActive())
		{
			Enemies[i].ActivatedEnemy(pos);
			return;
		}
	}
	//cout << "Se creara un enemigo nuevo" << endl;
	Enemy e;
	e.Startup(*p_player ,*p_window, enemies_tex, enemiesDamaged_tex, enemiesDie_tex, *p_gameManager, *p_ui, *this);
	Enemies.push_back(e);
	Enemies[Enemies.size()-1].ActivatedEnemy(pos);
	return;
}

int SpawnManager::RandomRangeINT(int min, int max)
{
	int i = min + (rand()%(max + 1 - min));
	return  i;
}

void SpawnManager::playHitSound()
{
	damage_sound.play();
}
