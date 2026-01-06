#include "Scene_Menu.h"

#include <iostream>
#include "Game.h"
//#include "Scene.h"
#include <SFML/Window/Keyboard.hpp>
//using namespace sf;
using namespace std;

Scene_Menu::Scene_Menu() {
	/// inicializo las cosas
	textu.loadFromFile("Menu_temporal.png");
	//textu.loadFromFile("Menu_temporal1.png");
	spr.setTexture(textu);
	spr.setPosition(175, 130);
	
	
	m_font.loadFromFile("asap.ttf");
	txt_titulo.setFont(m_font);
	txt_subtitulo.setFont(m_font);
	
	txt_titulo.setString("Plataformero 2D!!!");
	txt_titulo.setFillColor({0,0,0});
	txt_titulo.setPosition(180,150);
	txt_titulo.setCharacterSize(50);
	
	txt_subtitulo.setString("<presione Enter para comenzar a jugar> \n<presione Escape para comenzar a jugar>");
	txt_subtitulo.setFillColor({150,150,150});
	txt_subtitulo.setPosition(150,350);
	txt_subtitulo.setCharacterSize(20);
	
}

void Scene_Menu::Update (Game & playgame) {
	spr.move(0.005,0.01);
	
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	//spr.setColor({r,g,b});
	//spr.setColor(Color(r,g,b,100));
	//txt_titulo.setFillColor({r,g,b});
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)){ // Enter
		//playgame.SetScene(new Match());
		new_scene = true;
	}
	else if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		/// exit = true; /// No es la implementacion correcta
		playgame.Stop(); ///implementacion correcta
	}
}

void Scene_Menu::Draw (sf::RenderWindow & win) {
	
	//if (exit) win.close();
	
	win.clear(Color(255,255,255,255));
	win.draw(spr);
	
	//window.clear({0,0,0});
	win.draw(txt_titulo);
	win.draw(txt_subtitulo);
	
	if(new_scene) win.clear(Color(150,150,150,150)); /// TEMPORAL quitar despues
	
	// no va display
}


/*
Scene_Menu::~Scene_Menu() {

}*/
