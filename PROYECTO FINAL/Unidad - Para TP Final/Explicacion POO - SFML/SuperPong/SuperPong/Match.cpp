#include "Match.h"
#include "Game.h"
#include "Menu.h"

Match::Match() 
	: m_p1(true), m_p2(false)
{
	
}

void Match::Update (Game &game ) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		game.SetScene(new Menu());
	if (m_ball.CollideWith(m_p1) || 
		m_ball.CollideWith(m_p2) )
		m_ball.Bounce();
	m_ball.Update();
	m_p1.Update();
	m_p2.Update();
}

void Match::Draw (RenderWindow & window) {
	window.clear(Color(180,255,180,255));
	m_ball.Draw(window);
	m_p1.Draw(window);
	m_p2.Draw(window);
	window.display();
}

