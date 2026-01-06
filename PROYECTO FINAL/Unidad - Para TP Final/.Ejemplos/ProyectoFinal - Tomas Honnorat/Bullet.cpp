#include "Bullet.h"

Bullet::Bullet() : isActive(false), moveDir(0,0)
{
	
}

void Bullet::Update (float delta) 
{
	if(isActive)
	{
		float m_boundOffset = (p_window->getSize().x*20)/1280;
		
		bullet_spr.move(moveDir * delta * speed);
		
		/// bounds Limits
		Vector2u windowSize = p_window->getSize();
		// +x
		if(bullet_spr.getPosition().x >= (windowSize.x - bullet_spr.getGlobalBounds().width/2) - m_boundOffset){
			isActive = false;
		}
		// -x
		if(bullet_spr.getPosition().x <= (bullet_spr.getGlobalBounds().width/2) + m_boundOffset){
			isActive = false;
		}
		// y
		if(bullet_spr.getPosition().y >= (windowSize.y - bullet_spr.getGlobalBounds().height/2) - m_boundOffset){
			isActive = false;
		}
		// -y
		if(bullet_spr.getPosition().y <= (bullet_spr.getGlobalBounds().height/2) + m_boundOffset){
			isActive = false;
		} 
		
	}
}

void Bullet::Draw (RenderWindow & window) 
{
	if(isActive)
	{
		window.draw(bullet_spr);
	}
}

void Bullet::Startup(RenderWindow & window, Texture& bullet_tex)
{
	p_window = &window;
	bullet_spr.setTexture(bullet_tex);
	auto windowSize = p_window->getSize();
	
	speed = 900 * windowSize.x / 1280; // 1280 velocidad testeada en 1280
	
	SetSpritesSize();
}

bool Bullet::IsActive()
{
	return isActive;
}

void Bullet::SetSpritesSize()
{
	// get window resolution
	Vector2u windowSize = p_window->getSize();
	Vector2f defaultScale = {windowSize.x /426.0f , windowSize.y /240.0f};
	
	// Set Scale
	bullet_spr.setScale(defaultScale);
	
	// Set Origin in center
	bullet_spr.setOrigin(bullet_spr.getLocalBounds().width/2,bullet_spr.getLocalBounds().height/2);
}

void Bullet::ShootBullet(Vector2f pos, Vector2f lookDir)
{
	bullet_spr.setPosition(pos);
	moveDir = Normalize(lookDir);
	isActive = true;
}
void Bullet::DestroyBullet()
{
	isActive = false;
}

Sprite& Bullet::GetSpriteBullet()
{
	return bullet_spr;
}

