#ifndef BULLET_H
#define BULLET_H

#include "Utilities.h"

class Bullet
{
public:
	Bullet();
	
	void Startup(RenderWindow & window, Texture &bullet_tex);
	void Update (float delta);
	void Draw (RenderWindow & window);
	
	void SetSpritesSize();
	
	void ShootBullet(Vector2f pos, Vector2f lookDir);
	void DestroyBullet();
	
	Sprite& GetSpriteBullet();
	
	bool IsActive();
private:
	RenderWindow * p_window;
	bool isActive;
	float speed;
	
	Vector2f moveDir;
	
	//Texture bullet_tex;
	Sprite bullet_spr;
};

#endif

