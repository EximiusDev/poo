#include "Menu.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
using namespace sf;

Menu::Menu() {
	m_font.loadFromFile("asap.ttf");
	m_t1.setFont(m_font);
	m_t2.setFont(m_font);
	
	m_t1.setString("Super Pong!!!");
	m_t1.setPosition(180,150);
	m_t1.setCharacterSize(50);
	
	m_t2.setString("<presione Enter para comenzar a jugar>");
	m_t2.setFillColor({150,150,150});
	m_t2.setPosition(150,350);
	m_t2.setCharacterSize(20);
}

void Menu::Update (Game &game) {
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	m_t1.setFillColor({r,g,b});
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)) // Enter
		game.SetScene(new Match());
}

void Menu::Draw (RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(m_t1);
	window.draw(m_t2);
	window.display();
}

