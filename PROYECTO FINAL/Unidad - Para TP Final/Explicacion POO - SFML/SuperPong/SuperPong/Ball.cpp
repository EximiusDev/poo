#include "Ball.h"

Ball::Ball() : Object("ball.png") {
	m_sprite.setScale(0.5,0.5);
	m_sprite.setPosition(175, 130);
}

void Ball::Update ( ) {
	m_sprite.move(m_speed);
	auto p = m_sprite.getPosition();
	if (p.x<0 || p.x+25>640) 
		m_speed.x = -m_speed.x;
	if (p.y<0 || p.y+25>480) 
		m_speed.y = -m_speed.y;
}

void Ball::Bounce ( ) {
	m_speed.x = -m_speed.x;
}

