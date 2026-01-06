#include "../H/Scene_Menu.h"
#include <iostream>
#include "../H/Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "../H/Scene_Play.h"
#include "../Scene_HighScore.h"

using namespace sf;
using namespace std;

Scene_Menu::Scene_Menu() {
	/// inicializo las cosas
	//textu.loadFromFile("Menu_temporal.png");
	txtr_button.resize(4);
	spr_button.resize(4);
	txtr_button[0].loadFromFile("./Textures/Menu.png");
	spr_button[0].setTexture(txtr_button[0]);

	txtr_button[1].loadFromFile("./Textures/button_Play.png");
	spr_button[1].setTexture(txtr_button[1]);
	spr_button[1].setPosition(411,329);

	txtr_button[2].loadFromFile("./Textures/button_Score.png");
	spr_button[2].setTexture(txtr_button[2]);
	spr_button[2].setPosition(364,429);

	txtr_button[3].loadFromFile("./Textures/button_Exit.png");
	spr_button[3].setTexture(txtr_button[3]);
	//spr_button[3].setPosition(411,529); // 
	spr_button[3].setPosition(386,529);

	
	//Hay que poner el scale segun resolucion

}

void Scene_Menu::Update (Game & playgame, RenderWindow & win) {
	
	r1 = Arrow.getPosition(win);
	
	if (spr_button[1].getGlobalBounds().contains(r1.x,r1.y)){ 
		spr_button[1].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left)){
			playgame.SetScene(new Scene_Play());
		} 
		
	}else{
		spr_button[1].setColor(Color(255,255,255));
	}
	
	if (spr_button[2].getGlobalBounds().contains(r1.x,r1.y)){ 
		spr_button[2].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left)&&Cl.getElapsedTime().asMilliseconds() >= 100){
			playgame.SetScene(new Scene_HighScore());
			Cl.restart();
		} 
	}else{
		spr_button[2].setColor(Color(255,255,255));
	}
	//playgame.SetScene(new Match());
	///new_scene = true;
	if (spr_button[3].getGlobalBounds().contains(r1.x,r1.y)){ 
		spr_button[3].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left)){
			//playgame.Stop();
			exit(0);
		} 
		
	}else{
		spr_button[3].setColor(Color(255,255,255));
	}
	
}

void Scene_Menu::Draw (RenderWindow & win) {
	
	
	win.draw(spr_button[0]);
	win.draw(spr_button[1]);
	win.draw(spr_button[2]);
	win.draw(spr_button[3]);
	// no va display
}


