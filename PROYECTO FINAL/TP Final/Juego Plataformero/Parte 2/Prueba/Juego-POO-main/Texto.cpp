#include "Texto.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

Texto::Texto() {
	m_font.loadFromFile("asap.ttf");
	m_texto1.setFont(m_font);
	m_texto2.setFont(m_font);
	
	m_texto1.setString("Score :");
	m_texto1.setPosition(1000,40);
	m_texto1.setCharacterSize(50);
	//int aux = 100;
	//std::string Nom = std::to_string(aux);
	//string Nom1 = to_string(aux);
	//Nom2 = "<presione Enter para comenzar a jugar>";
	//m_texto2.setString(Nom1);
	m_texto1.setFillColor({200,200,200});
	m_texto2.setPosition(1160,50);
	m_texto2.setCharacterSize(40);
}

void Texto::Dibujar_Pant(RenderWindow & window) {
	//window.clear({0,0,0});
	window.draw(m_texto1);
	window.draw(m_texto2);
	//window.display();
}
Text Texto::Get_Texto(){
	return m_texto1;
}
void Texto::Set_oracion(string Nom1 ) {
	m_texto2.setString(Nom1);
}


/*

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>




///
private:
Font m_font;
Text m_texto1, m_texto2;
///
window.draw(m_texto1);
window.draw(m_texto2);
///
m_font.loadFromFile("asap.ttf");
m_texto1.setFont(m_font);
m_texto2.setFont(m_font);

m_texto1.setString("Super Pong!!!");
m_texto1.setPosition(180,150);
m_texto1.setCharacterSize(50);

m_texto2.setString("<presione Enter para comenzar a jugar>");
m_texto2.setFillColor({150,150,150});
m_texto2.setPosition(150,350);
m_texto2.setCharacterSize(20);
///
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

*/
