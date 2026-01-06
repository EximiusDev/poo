#include "../H/Scene_Pause.h"
#include <SFML/Window/Keyboard.hpp>
#include "../H/Game.h"
#include "../H/Scene_Menu.h"

Scene_Pause::Scene_Pause() {
	///initialize text
	//m_font.loadFromFile("JollyLodger.ttf");
	m_font.loadFromFile("RetroGaming.ttf");
	txt_button_menu.setFont(m_font);
	txt_button_play.setFont(m_font);
	
	txt_button_menu.setString("<presione ESCAPE \n para salir al menu sin guardar>");
	txt_button_menu.setFillColor({0,0,0});
	txt_button_menu.setPosition(450 -10,350 +10);
	txt_button_menu.setCharacterSize(20);
	
	//txt_subtitulo.setString("<presione Enter para comenzar a jugar> \n<presione Escape para comenzar a jugar>");
	txt_button_play.setString("<presione ENTER \n                 para seguir jugando>");
	//txt_button_play.setFillColor({150,150,150});
	txt_button_play.setFillColor({0,0,0});
	txt_button_play.setPosition(450 -10,200 +10);
	txt_button_play.setCharacterSize(20);
	
	Tex.loadFromFile("./Textures/Bck_Pause.png");
	Spr.setTexture(Tex);
	Spr.setScale(0.15,0.15);
	Spr.setPosition(406.15,125.625);
}

void Scene_Pause::Update (Game & playgame,RenderWindow & win) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){ // Escape
		/// FALTA HACER DELETE DE Scene_Play
		playgame.Delete_aux_Scene();
		playgame.SetScene(new Scene_Menu());
	}
	/*
	m_score = m_player.GetScore();
	seconds_game = playgame.GetTime_Sec_Curr_mScn()/100;
	txt_score.setString("Score : " + std::to_string(m_score) + " \nTime: "+ std::to_string(seconds_game));
	*/
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)){
		playgame.Unpause_Scene(); /// sale de la pausa
	}
}

void Scene_Pause::Draw (sf::RenderWindow & win) {
	//win.draw(m_floor);
	//m_player.Draw(win);
	
	win.draw(Spr);
	win.draw(txt_button_menu);
	win.draw(txt_button_play);
}

void Scene_Pause::InputEvents (Event & event) {
	
}

