#include "Player.h"

Player::Player(RenderWindow & window, Game &game,GameManager &gameManager) : BulletPoll(10), walk_tex(6),reaload_tex(4), totalTime(0), switchTime(0.06), index(0),reloadIndex(0), totalTimeReload(0),
	totalTimeReloadAnim(0), switchTimeReloadAnim(0.04),vectorZero(0,0), Life(3), ammoAmount(8), reloadTime(0.7), reloading(false), damaged(false), totaldamagedTime(0),damagedTime(0.2), dead(false)
{
	p_window = &window;
	windowSize = p_window->getSize();
	
	speed = 200 * windowSize.x / 1280; // 1280 velocidad testeada en 1280
	
	player_tex.loadFromFile("Textures/Player.png");
	weapon_tex.loadFromFile("Textures/Weapon.png");
	hit_tex.loadFromFile("Textures/PlayerDamaged.png");
	
	player_spr.setTexture(player_tex);
	weapon_spr.setTexture(weapon_tex);
	hit_spr.setTexture(hit_tex);
	
	SetSpritesSize();
	
	PlayerScale = player_spr.getScale();
	weaponScale = weapon_spr.getScale();
	
	m_boundOffset = (p_window->getSize().x*20)/1280;
	
	UP = Keyboard::W;
	DOWN = Keyboard::S;
	LEFT = Keyboard::A;
	RIGHT = Keyboard::D;
	
	bullet_tex.loadFromFile("Textures/Bullet.png");
	for(Bullet &b : BulletPoll)
	{
		b.Startup(window, bullet_tex);
	}
	
	walk_tex[0].loadFromFile("Textures/Player1.png");
	walk_tex[1].loadFromFile("Textures/Player2.png");
	walk_tex[2].loadFromFile("Textures/Player3.png");
	walk_tex[3].loadFromFile("Textures/Player4.png");
	walk_tex[4].loadFromFile("Textures/Player5.png");
	walk_tex[5].loadFromFile("Textures/Player6.png");
	
	reaload_tex[0].loadFromFile("Textures/weapon1.png");
	reaload_tex[1].loadFromFile("Textures/weapon2.png");
	reaload_tex[2].loadFromFile("Textures/weapon3.png");
	reaload_tex[3].loadFromFile("Textures/weapon4.png");
	
	p_gameManager = &gameManager;
	
	// sound buffers
	shoot_buffer.loadFromFile("Sounds/shoot1.wav");
	hit_buffer.loadFromFile("Sounds/Hit.wav");
	noAmmo_buffer.loadFromFile("Sounds/GunBarrel1.wav");
	// set buffers
	shoot_sound.setBuffer(shoot_buffer);
	hit_sound.setBuffer(hit_buffer);
	noAmmo_sound.setBuffer(noAmmo_buffer);
	// set volume
	shoot_sound.setVolume(game.getVolume());
	hit_sound.setVolume(game.getVolume());
	noAmmo_sound.setVolume(game.getVolume());
}

void Player::InputEvents (Event & event) 
{
	/// calculates move direction 
	velocity = {0,0};
	if(Keyboard::isKeyPressed(LEFT)){
		// Look Left
		player_spr.setScale(PlayerScale.x  * -1.0f,PlayerScale.y);
		// left
		velocity.x = -1;
	}
	if(Keyboard::isKeyPressed(RIGHT)){
		// Look Right
		player_spr.setScale(PlayerScale.x, PlayerScale.y);
		// right
		velocity.x = 1;
	}
	if(Keyboard::isKeyPressed(DOWN)){
		// down
		velocity.y = 1;
	}
	if(Keyboard::isKeyPressed(UP)){
		// Up
		velocity.y = -1;
	}
	
	/// Mouse click
	if(event.type == Event::MouseButtonPressed)
	{
		if(Mouse::isButtonPressed(Mouse::Left))
			Shoot();
	}
}

void Player::Update (Game & game, float delta) 
{
	if(!dead)
	{
		/// Move Sprite
		player_spr.move(speed * Normalize(velocity) * delta);
		
		
		/// bounds Limits
		Vector2u windowSize = p_window->getSize();
		// +x
		if(player_spr.getPosition().x >= (windowSize.x - player_spr.getGlobalBounds().width/2) - m_boundOffset){
			player_spr.setPosition((windowSize.x - player_spr.getGlobalBounds().width/2) - m_boundOffset, player_spr.getPosition().y);
		}
		// -x
		if(player_spr.getPosition().x <= (player_spr.getGlobalBounds().width/2) + m_boundOffset){
			player_spr.setPosition((player_spr.getGlobalBounds().width/2) + m_boundOffset, player_spr.getPosition().y);
		}
		// y
		if(player_spr.getPosition().y >= (windowSize.y - player_spr.getGlobalBounds().height/2) - m_boundOffset){
			player_spr.setPosition(player_spr.getPosition().x, (windowSize.y -player_spr.getGlobalBounds().height/2) - m_boundOffset);
		}
		// -y
		if(player_spr.getPosition().y <= (player_spr.getGlobalBounds().height/2) + m_boundOffset){
			player_spr.setPosition(player_spr.getPosition().x, (player_spr.getGlobalBounds().height/2) + m_boundOffset);
		} 
		
		/// Weapon Position and Rotation
		weapon_spr.setPosition(player_spr.getPosition());
		// mouse position
		Vector2i mousePos = Mouse::getPosition(*p_window);
		// vector dir (player - mouse pos)
		dir = {mousePos.x - player_spr.getPosition().x, mousePos.y - player_spr.getPosition().y};
		// angle in radians of vector v
		float angleDir = atan(dir.y/dir.x) * 180/3.1415;
		// check cuadrant of vector
		if((dir.x < 0 && dir.y >0) || (dir.x < 0 && dir.y < 0))
		{
			// new rotation and scale
			weapon_spr.setRotation(angleDir);
			weapon_spr.setScale(weaponScale.x , weaponScale.y);
		}
		else
		{
			// new rotation and scale
			weapon_spr.setRotation(180 + angleDir);
			weapon_spr.setScale(weaponScale.x , weaponScale.y* - 1.0f);
		}
		
		/// Bullets Update
		for(Bullet &b : BulletPoll)
		{
			b.Update(delta);
		}
		
		
		/// Update Walk Animation
		if(velocity != vectorZero)
		{
			totalTime += delta;
			if(totalTime >= switchTime)
			{
				totalTime = 0;
				
				player_spr.setTexture(walk_tex[index]);
				index++;
				
				if (index > 5)
					index = 0;
			}
		} else
		   player_spr.setTexture(player_tex);
		
		/// Reload Time
		if(reloading)
		{
			totalTimeReload += delta;
			if(totalTimeReload >= reloadTime)
			{
				totalTimeReload = 0;
				
				reloading = false;
				ammoAmount = 8;
				p_userInterface->updateAmmo(ammoAmount);
			}
		}
		
		if (reloading)
		{
			totalTimeReloadAnim += delta;
			if(totalTimeReloadAnim >= switchTimeReloadAnim)
			{
				totalTimeReloadAnim = 0;
				
				//anim
				weapon_spr.setTexture(reaload_tex[reloadIndex]);
				reloadIndex++;
				
				if (reloadIndex > 3)
					reloadIndex = 0;
			}
		} else
			weapon_spr.setTexture(weapon_tex);
	}
	
	// damaged time
	if(damaged)
	{
		totaldamagedTime += delta;
		if(totaldamagedTime >= damagedTime)
		{
			totaldamagedTime = 0;
			damaged = false;
		}
	}
	hit_spr.setPosition(player_spr.getPosition());
}

void Player::Draw (RenderWindow & window) 
{

	if(!dead)
	{
		window.draw(player_spr);
		window.draw(weapon_spr);
		/// Bullets Draw
		for(Bullet &b : BulletPoll)
		{
			b.Draw(window);
		}
	}
	
	if(damaged)
	{
		window.draw(hit_spr);
	}

}


void Player::SetSpritesSize()
{
	// get window resolution
	Vector2u windowSize = p_window->getSize();
	Vector2f defaultScale = {windowSize.x /426.0f , windowSize.y /240.0f}; // resolucion de referencia 1280*720
	
	// Set Scale
	player_spr.setScale(defaultScale);
	weapon_spr.setScale(defaultScale);
	hit_spr.setScale(defaultScale);
	
	// Set Origin in center
	player_spr.setOrigin(player_spr.getLocalBounds().width/2,player_spr.getLocalBounds().height/2);
	weapon_spr.setOrigin(weapon_spr.getLocalBounds().width, weapon_spr.getLocalBounds().height/2);
	hit_spr.setOrigin(hit_spr.getLocalBounds().width/2, hit_spr.getLocalBounds().height/2);
	
	// Set Position
	player_spr.setPosition(windowSize.x/2, windowSize.y/2);
	weapon_spr.setPosition(player_spr.getPosition());
	
}

void Player::Startup(UI& ui)
{
	p_userInterface = & ui;
}

void Player::Shoot()
{
	if(!dead)
	{
		if(!reloading) 
		{
			ammoAmount--;
			
			p_userInterface->updateAmmo(Clamp(ammoAmount, 0 , 8));
			shoot_sound.play();
			
			if(ammoAmount <= 0)
			{
				reloading = true;
			}
			
			Vector2f shootingPoint = player_spr.getPosition() + Normalize(dir) * (50.0f  * p_window->getSize().x )/1280.0f;
			
			for(int i = 0; i < BulletPoll.size(); i++)
			{
				if(!BulletPoll[i].IsActive())
				{
					BulletPoll[i].ShootBullet(shootingPoint, dir);
					return;
				}
			}
			//cout << "Se creara una bala nueva" << endl;
			Bullet b;
			b.Startup(*p_window, bullet_tex);
			BulletPoll.push_back(b);
			BulletPoll[BulletPoll.size()-1].ShootBullet(shootingPoint, dir);
			return;
		}
		
		noAmmo_sound.play();
	}
}


void Player::Damage()
{
	if (!dead)
	{
		// cout << "Recibi daño" << endl;
		damaged = true;
		hit_sound.play();
		Life--;
		Life = Clamp(Life, 0, 3);
		
		p_userInterface->updateHealth(Life);
		
		// DEAD
		if(Life <= 0)
		{
			//cout << "GameOver" << endl;
			dead = true;
			p_gameManager->GameOver();
			return;
		}
	}
}

Sprite& Player::GetPlayerSpr()
{
	return player_spr;
}

vector<Bullet>& Player::GetBulletPool()
{
	return BulletPoll;
}

int Player::GetLife()
{
	return Life;
}





























