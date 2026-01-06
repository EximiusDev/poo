#include "Enemy.h"
#include "SpawnManager.h"

Enemy::Enemy() : isActive(false), Life(3), moveDir(0,0), totalTime(0),totalTime2(0), animTime(0.1), deadTime(1),alpha(255), damaged(false), canMove(false)
{
	
}

void Enemy::InputEvents (Event & event) 
{
	
}

void Enemy::Update (Game & game, float delta) 
{
	if(isActive)
	{
		if(canMove)
		{
			/// player collision
			auto enemy = enemy_spr.getGlobalBounds();
			auto player = playerTarget->GetPlayerSpr().getGlobalBounds();
			
			if(enemy.intersects(player))
			{
				Damage(99);
				playerTarget->Damage();
			}
			
			/// Bullet collision
			for( Bullet& b : playerTarget->GetBulletPool())
			{
				if( b.IsActive())
				{
					auto bullet = b.GetSpriteBullet().getGlobalBounds();
					
					if(bullet.intersects(enemy))
					{
						b.DestroyBullet();
						Damage(1);
					}
				}
			}
			/// movement
			move(delta);
			
			/// Damaged animation
			if(damaged)
			{
				enemy_spr.setTexture(*p_enemyDamaged_tex);
				
				totalTime += delta;
				if(totalTime >= animTime)
				{
					totalTime = 0;
					enemy_spr.setTexture(*p_enemy_tex);
					damaged = false;
				}
			}
		}
		
		/// Dead animation
		if(!canMove)
		{
			enemy_spr.setTexture(*p_enemyDie_tex);
			
			totalTime2 += delta;
			
			alpha -= 250* delta ;
			auto a = Clamp(alpha, 0 , 255);
			
			Color color(255,255,255, a);
			enemy_spr.setColor(color); 
			
			if(totalTime2 >= deadTime)
			{
				totalTime2 = 0;
				isActive = false;
				
				alpha = 255;
				Color color(255,255,255,255);
				enemy_spr.setColor(color);
			}
		}
		
	}
}

void Enemy::Draw (RenderWindow & window) 
{
	if(isActive){
		window.draw(enemy_spr);
	}
}

void Enemy::SetSpritesSize()
{
	// get window resolution
	Vector2u windowSize = p_window->getSize();
	Vector2f defaultScale = {windowSize.x /426.0f , windowSize.y /240.0f};
	
	// Set Scale
	enemy_spr.setScale(defaultScale);
	
	// Set Origin in center
	enemy_spr.setOrigin(enemy_spr.getLocalBounds().width/2,enemy_spr.getLocalBounds().height/2);
}

bool Enemy::IsActive()
{
	return isActive;
}

void Enemy::Startup(Player &player, RenderWindow & window, Texture &enemy_tex, Texture &enemyDamaged_tex, Texture &enemyDie_tex, GameManager &gameManager, UI& ui, SpawnManager &spawnManager)
{
	playerTarget = &player;
	p_window = &window;
	p_enemy_tex = &enemy_tex;
	p_enemyDamaged_tex = &enemyDamaged_tex;
	p_enemyDie_tex = &enemyDie_tex;
	p_gameManager = &gameManager;
	p_ui = &ui;
	p_spawnManager = &spawnManager;
	
	windowSize = p_window->getSize();
	
	speed = 200 * windowSize.x / 1280; // 1280 velocidad testeada en 1280
	
	enemy_spr.setTexture(*p_enemy_tex);
	
	SetSpritesSize();
	
	enemyScale = enemy_spr.getScale();
}

void Enemy::ActivatedEnemy(Vector2f pos)
{
	// fix animation
	totalTime = 0;
	enemy_spr.setTexture(*p_enemy_tex);
	damaged = false;
	
	enemy_spr.setPosition(pos);
	isActive = true;
	canMove = true;
}

void Enemy::desactivedEnemy()
{
	canMove= false;
	p_gameManager->EnemyKilled();
	p_ui->updateKills(p_gameManager->GetKills());
	
}

void Enemy::Damage(int d)
{
	Life -=d ;
	damaged = true;
	
	p_spawnManager->playHitSound();
	
	if(Life <= 0)
	{
		Life = 3;
		desactivedEnemy();
	}

	// cout << "daño a enemigo, vida restante : " << Life << endl;
}

void Enemy::move(float delta)
{
	auto dir = playerTarget->GetPlayerSpr().getPosition() - enemy_spr.getPosition();
	
	// Flip sprite
	if((dir.x < 0 && dir.y >0) || (dir.x < 0 && dir.y < 0))
	{
		enemy_spr.setScale(enemyScale.x * - 1.0f, enemyScale.y);
	}
	else
	{
		enemy_spr.setScale(enemyScale.x , enemyScale.y);
	}
	
	float length = sqrt((dir.x * dir.x) + (dir.y * dir.y));
	// reduce speed of enemy with distance <= 200
	if(length <= (200 *  windowSize.x / 1280)){
		speed = 125 * windowSize.x / 1280;
	}
	else
	   speed = 200 * windowSize.x / 1280;
	
	moveDir = Normalize(dir);
	
	enemy_spr.move(moveDir * speed * delta);
}



