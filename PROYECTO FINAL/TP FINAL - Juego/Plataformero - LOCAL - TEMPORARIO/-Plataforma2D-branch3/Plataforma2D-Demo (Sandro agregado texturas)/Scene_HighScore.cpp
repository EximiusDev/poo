#include "Scene_HighScore.h"
#include <SFML/Window/Keyboard.hpp>
#include "Scene_GameOver.h"
#include "H/Scene_Menu.h"

Scene_HighScore::Scene_HighScore(){
	Tex.loadFromFile("./Textures/HighScoreBck.png");
	Spr.setTexture(Tex);
	Spr.setScale(0.2352,0.25352);
	
	
}
void Scene_HighScore::Update (Game & playgame, RenderWindow & win){
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		playgame.SetScene(new Scene_Menu());
	}
}
void Scene_HighScore::Draw (RenderWindow & win){
	win.draw(Spr);
}

