#ifndef PLAYER_H
#define PLAYER_H

#include "Scene.h"
#include "Bullet.h"
#include "UI.h"
#include "GameManager.h"
#include "Game.h"

class Player : public Scene {
public:
	Player(RenderWindow & window,Game &game, GameManager &gameManager);
	void InputEvents (Event & event) override;
	void Update (Game & game, float delta) override;
	void Draw (RenderWindow & window) override;
	void SetSpritesSize();
	void Startup(UI& ui);
	
	Sprite& GetPlayerSpr();
	vector<Bullet>& GetBulletPool();
	
	void Damage();
	int GetLife();
private:
	Texture player_tex;
	Sprite player_spr;
	Vector2f PlayerScale;
	// Weapon
	Texture weapon_tex;
	Sprite weapon_spr;
	Vector2f weaponScale;
	// ammo
	int ammoAmount;
	float totalTimeReload;
	float reloadTime;
	bool reloading;
	// reloading animation
	vector<Texture> reaload_tex;
	int reloadIndex;
	float totalTimeReloadAnim;
	float switchTimeReloadAnim;
	
	vector<Texture> walk_tex;
	int index;
	float totalTime;
	float switchTime;
	Vector2f vectorZero;
	
	Vector2f dir;
	float angleDir;
	
	RenderWindow * p_window;
	float m_boundOffset;
	
	Vector2f velocity;
	float speed;
	// keys
	Keyboard::Key UP;
	Keyboard::Key DOWN;
	Keyboard::Key LEFT;
	Keyboard::Key RIGHT;
	
	vector<Bullet> BulletPoll;
	Texture bullet_tex;
	void Shoot();
	
	int Life;
	
	UI* p_userInterface;
	GameManager* p_gameManager;
	// Sound
	SoundBuffer shoot_buffer;
	Sound shoot_sound;
	
	SoundBuffer noAmmo_buffer;
	Sound noAmmo_sound;
	
	SoundBuffer hit_buffer;
	Sound hit_sound;
	
	Texture hit_tex;
	Sprite hit_spr;
	
	float totaldamagedTime;
	float damagedTime;
	
	bool damaged;
	
	bool dead;
};

#endif

