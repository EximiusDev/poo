#include "Scene_HighScore.h"
#include <SFML/Window/Keyboard.hpp>
#include "Scene_GameOver.h"
#include "H/Scene_Menu.h"

Scene_HighScore::Scene_HighScore(){
	txtr_back.loadFromFile("./Textures/HighScoreBck.png");
	spr_back.setTexture(txtr_back);
	spr_back.setScale(0.2352,0.25352); // spr_back.setScale(0.24,0.24);
	/*
	Tex[3].loadFromFile("./Textures/button.png");
	Spr[3].setTexture(Tex[3]);
	Spr[3].setPosition(364,229);
	*/
	m_font.loadFromFile("JollyLodger.ttf");
	//m_font.loadFromFile("RetroGaming.ttf");
	txt_title.setFont(m_font);
	txt_aux.setFont(m_font);
	txt_aux2.setFont(m_font);
	txt_botones.setFont(m_font);
	
	txt_title.setString("Top 10 HighScore:");
	txt_title.setPosition(500 + 20,100 + 20);
	txt_title.setCharacterSize(50);
	
	txt_aux.setString("Nombre: " + std::to_string(000));
	txt_aux.setPosition(450 + 20,200 - 10);
	txt_aux.setCharacterSize(32);
	txt_aux2.setString("Score: " + std::to_string(00000));
	txt_aux2.setPosition(700 + 20,200 -10);
	txt_aux2.setCharacterSize(32);
	
	txt_botones.setString("<presione ESCAPE para salir al menu> \n");
	
	
	//txt_button_play.setString("<presione Enter para comenzar a jugar>");
	//txt_score.setString("Score: " + std::to_string(m_score) + "   HighScore: "+ std::to_string(highScore));
	/*
	txt_button_menu.setString("<presione Escape para salir al menur>");
	txt_button_menu.setFillColor({0,0,0});
	txt_button_menu.setPosition(50,200);
	txt_button_menu.setCharacterSize(20);
	*/
	txt_names.resize(10);
	txt_scores.resize(10);
	for (int i = 0; i < 10; i++){
		txt_names[i].setFont(m_font);
		txt_scores[i].setFont(m_font);
		
		txt_names[i].setString(to_string(i+1)+") ___");
		txt_scores[i].setString("0");
		txt_names[i].setCharacterSize(24);
		txt_scores[i].setCharacterSize(24);
		txt_names[i].setPosition(450 + 35, 250 - 20 + 38*(i)); //450 + 20,250 // .setPosition(60,pos+40*(i+1));
		txt_scores[i].setPosition(700 + 35, 250 - 20 + 38*(i)); //450 + 20,250 // .setPosition(60,pos+40*(i+1));
	}
}
void Scene_HighScore::Update (Game & playgame, RenderWindow & win){
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		playgame.SetScene(new Scene_Menu());
	}
	/*
	int pos = 400;
	vector<hsStruct> highscore = g.getHighscore();
	sort(highscore.begin(),highscore.end(),reverse_sort);
	
	for (size_t i = 0; i < highscore.size() ; i++)
	{
		txt_names[i].setString(highscore[i]._name);
		txt_scores[i].setString(to_string(highscore[i]._points));
		txt_names[i].setScale(1,1);
		txt_names[i].setPosition(Vector2f(60,pos+40*(i+1)));
		txt_scores[i].setScale(1,1);
		txt_scores[i].setPosition(Vector2f(640-(txt_scores[i].getGlobalBounds().width+20),pos+40*(i+1)));
	}*/
}
void Scene_HighScore::Draw (RenderWindow & win){
	win.draw(spr_back);
	
	win.draw(txt_title);
	win.draw(txt_aux);
	win.draw(txt_aux2);
	win.draw(txt_botones);
	
	for (size_t i = 0; i < txt_names.size(); i++){
		win.draw(txt_names[i]);
		win.draw(txt_scores[i]);
	}
}

