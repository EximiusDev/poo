#include "../H/Scene_Menu.h"
#include "../H/Scene_Menu.h"
#include "../H/Scene_Menu.h"
#include <iostream>
#include "../H/Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "../H/Scene_Play.h"
#include "../Scene_HighScore.h"
#include <string.h>
#include <cstring>

using namespace sf;
using namespace std;

Scene_Menu::Scene_Menu() : m_text_inputBox(m_font,30,sf::Color::Black) {
	m_font.loadFromFile("JollyLodger.ttf");
	// texto que ingresa el usuario
	//InputText m_text_inputBox(m_font,30,sf::Color::Black);
	m_text_inputBox.setPosition(386 + 30 +70,529 + 10);// (120,50);
	m_text_inputBox.setMaxChars(25); // no mas de 10 caracteres
	m_text_inputBox.setSingleWord(true); // no permitir
	
	/// inicializo las cosas
	//textu.loadFromFile("Menu_temporal.png");
	txtr_button.resize(6);
	spr_button.resize(6);
	txtr_button[0].loadFromFile("./Textures/Menu.png");
	spr_button[0].setTexture(txtr_button[0]);

	txtr_button[1].loadFromFile("./Textures/button_Play.png");
	spr_button[1].setTexture(txtr_button[1]);
	spr_button[1].setPosition(411,329);

	txtr_button[2].loadFromFile("./Textures/button_Score.png");
	spr_button[2].setTexture(txtr_button[2]);
	spr_button[2].setPosition(364,429);

	txtr_button[3].loadFromFile("./Textures/button.png");
	spr_button[3].setTexture(txtr_button[3]);
	//spr_button[3].setPosition(411,529); // 
	spr_button[3].setPosition(386,529);
	
	txtr_button[4].loadFromFile("./Textures/button_Exit.png");
	spr_button[4].setTexture(txtr_button[4]);
	spr_button[4].setPosition(364,629);
	
	txtr_button[5].loadFromFile("./Textures/button.png");
	spr_button[5].setTexture(txtr_button[5]);
	spr_button[5].setPosition(100,629);
	spr_button[5].setScale(.3,1);
	//Hay que poner el scale segun resolucion
	
	txt_who_plays.setFont(m_font);
	txt_username.setFont(m_font);
	
	//txt_score.setString("Score: " + "        HighScore: "+ std::to_string(highScore)); 
	txt_who_plays.setString("Un Jugador"); 
	txt_who_plays.setPosition(100 + 20,629 +10); 
	txt_username.setString("Nombre:"); 
	txt_username.setPosition(386 + 20,529 + 10);
}

void Scene_Menu::Update (Game & playgame, RenderWindow & win) {
	m_playgame = & playgame;
	
	r1 = Arrow.getPosition(win);
	
	if (spr_button[1].getGlobalBounds().contains(r1.x,r1.y)){ 
		spr_button[1].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left)){
			playgame.SetScene(new Scene_Play(this->two_players));
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
	
	if (spr_button[4].getGlobalBounds().contains(r1.x,r1.y)){ 
		spr_button[4].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left)){
			//playgame.Stop();
			exit(0);
		} 
		
	}else{
		spr_button[4].setColor(Color(255,255,255));
	}
	
	if (spr_button[5].getGlobalBounds().contains(r1.x,r1.y)){ 
		spr_button[5].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left) && Cl.getElapsedTime().asMilliseconds() >= 200){
			if(two_players){
				two_players = false;
				txt_who_plays.setString("Un Jugador");
			}
			else {
				two_players = true;
				txt_who_plays.setString("Dos Jugadores");
			}
			playgame.Change_players(two_players);
			Cl.restart();
		}
		
	}else{
		spr_button[5].setColor(Color(255,255,255));
	}
	
	m_text_inputBox.update();
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		if(playgame.GetTime_Sec_Curr_Scn()>0.5){ /// en segundos
			playgame.Stop();
		}
	}
}

void Scene_Menu::Draw (RenderWindow & win) {
	
	for(unsigned int i=0;i<spr_button.size();i++) { 
		win.draw(spr_button[i]);
	}
	win.draw(txt_who_plays);
	win.draw(txt_username);
	/*
	win.draw(spr_button[0]);
	win.draw(spr_button[1]);
	win.draw(spr_button[2]);
	win.draw(spr_button[3]);
	win.draw(spr_button[4]);
	win.draw(spr_button[5]);
	*/
	
	win.draw(m_text_inputBox);
	// no va display
}

void Scene_Menu::InputEvents (Event & event){
	this->m_text_inputBox.processEvent(event);
	this->m_ev = event;
}

Scene_Menu::~Scene_Menu(){
	//cout<<"Se hace delete a la escena de menu"<<endl;
	std::string str_aux = m_text_inputBox.getValue();
	if ( (str_aux != "") ){
		strcpy(m_playgame->Strc_aux.name_str ,str_aux.c_str());
	}/*
	if(str_aux == ""){
		//string asd = str_aux;
	}
	else strcpy(m_playgame->Strc_aux.name_str ,str_aux.c_str());
	*/
}
