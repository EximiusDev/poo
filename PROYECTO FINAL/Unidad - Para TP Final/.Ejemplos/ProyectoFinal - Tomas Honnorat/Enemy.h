#ifndef ENEMY_H
#define ENEMY_H
#include "Scene.h"
#include "Player.h"
#include "GameManager.h"
#include "UI.h"

class Enemy : public Scene {
public:
	Enemy();
	void Startup(Player &player, RenderWindow & window, Texture &enemy_tex,  Texture &enemyDamaged_tex, Texture &enemyDie_tex, GameManager &gameManager, UI& ui, class SpawnManager &spawnManager);
	void InputEvents (Event & event) override;
	void Update (Game & game, float delta) override;
	void Draw (RenderWindow & window) override;
	void SetSpritesSize();
	
	void ActivatedEnemy(Vector2f pos);
	void desactivedEnemy();
	
	void Damage(int d);
	
	bool IsActive();
private:
	
	int Life;
	bool isActive;
	bool canMove;
	float speed;
	Vector2f moveDir;
	void move(float delta);
	Vector2f enemyScale;
	
	Sprite enemy_spr;
	Texture *p_enemy_tex;
	Texture *p_enemyDamaged_tex;
	Texture *p_enemyDie_tex;
	
	float totalTime;
	float totalTime2;
	float animTime;
	float deadTime;
	float alpha;
	bool damaged;
	
	Player* playerTarget;
	GameManager* p_gameManager;
	UI* p_ui;
	SpawnManager* p_spawnManager;
};

#endif

