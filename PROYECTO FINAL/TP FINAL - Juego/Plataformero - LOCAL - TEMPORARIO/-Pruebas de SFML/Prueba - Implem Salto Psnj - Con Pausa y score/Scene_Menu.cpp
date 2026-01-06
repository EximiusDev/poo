#include "Scene_Menu.h"

#include <iostream>
#include "Game.h"
//#include "Scene.h"
#include <SFML/Window/Keyboard.hpp>
#include "Scene_Play.h"

//using namespace sf;
using namespace std;

Scene_Menu::Scene_Menu() {
	/// inicializo las cosas
	//textu.loadFromFile("Menu_temporal.png");
	textu.loadFromFile("Menu_temporal2.png");
	spr.setTexture(textu);
	//spr.setPosition(175, 130);
	spr.setScale(2, 2);
}

void Scene_Menu::Update (Game & playgame) {
	spr.move(0.005,0.01);
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)){ // Enter
		playgame.SetScene(new Scene_Play()); //playgame.SetScene(new Match());
		///new_scene = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){ // Escape
		
		///Agregar clock clk (dar un tiempo para salir)
		if(playgame.GetTime_Sec_Curr_Scn()>0.5){ /// en segundos
			playgame.Stop();
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){ // 
		spr.setColor(Color(111,111,111,255));
	}
}

void Scene_Menu::Draw (sf::RenderWindow & win) {
	
	win.clear(Color(255,255,255,255));
	win.draw(spr);
	// no va display
}


/*
Scene_Menu::~Scene_Menu() {

}*/





/*
Texture t;
Sprite s;

t.loadFromFile("sfml.png");
s.setTexture(t);
s.setPosition(175, 130);
*/
/*
while(win.isOpen()) {

// procesar eventos
Event evt;
while(win.pollEvent(evt)) {
if(evt.type == Event::Closed)
win.close();	
}

// actualizar
s.move(0.005,0.01);

// redibujar todo
win.clear(Color(255,255,255,255));
win.draw(s);
win.display();
*/
