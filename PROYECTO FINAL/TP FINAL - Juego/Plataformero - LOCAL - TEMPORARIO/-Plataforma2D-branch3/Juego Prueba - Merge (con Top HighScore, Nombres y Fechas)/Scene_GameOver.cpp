#include "Scene_GameOver.h"
#include "H/Scene_Menu.h"
#include "H/Scene_Play.h"
#include <iostream>
#include <fstream>
#include "Data_Struct.h"

using namespace std;

//Scene_GameOver::Scene_GameOver() {
Scene_GameOver::Scene_GameOver(int score) {
	m_score = score;
	
	time_t current_time; /// current_time es una clase de tipo time_t
	current_time = time(NULL); 
	strcpy(m_date, ctime(&current_time)); /// pone un \n al final
	
	txtr_button.resize(4);
	spr_button.resize(4);
	txtr_button[0].loadFromFile("./Textures/GameOver.png");
	spr_button[0].setTexture(txtr_button[0]);
	
	txtr_button[1].loadFromFile("./Textures/button_Play.png");
	spr_button[1].setTexture(txtr_button[1]);
	spr_button[1].setPosition(411,329);
	
	txtr_button[2].loadFromFile("./Textures/button_Exit.png");
	spr_button[2].setTexture(txtr_button[2]);
	spr_button[2].setPosition(364,429);
	
	txtr_button[3].loadFromFile("./Textures/button.png");
	spr_button[3].setTexture(txtr_button[3]);
	spr_button[3].setPosition(364,229);
	
	this->SaveAndLoad(m_score);
	
	//cout<<"Current score = "<<score<<endl;
	//cout<<"Current score = "<<m_score<<endl;
	int highScore = SaveAndLoad(m_score);
	//cout<<"HighScore = "<<highScore<<endl;
	
	m_font.loadFromFile("JollyLodger.ttf");
	//m_font.loadFromFile("RetroGaming.ttf");
	txt_score.setFont(m_font);
	//txt_highScore.setFont(m_font);
	
	txt_score.setString("Score: " + std::to_string(m_score) + "        HighScore: "+ std::to_string(highScore)); 
	//txt_score.setString("Score: " + std::to_string(m_score) + "   HighScore: "+ std::to_string(highScore)); //txt_score.setString("Score: " + std::to_string(m_score) + " \nHighScore: "+ std::to_string(highScore)); 
	txt_score.setFillColor({255,255,255});
	txt_score.setPosition(364 + 100, 229 + 8);
	//txt_score.setPosition(364 + 10, 229 + 12);
	txt_score.setCharacterSize(40); //24
	//txt_score.setCharacterSize(28); //24
}

void Scene_GameOver::Update (Game & playgame, RenderWindow & win){
	r1 = Arrow.getPosition(win);
	
	if (spr_button[1].getGlobalBounds().contains(r1.x,r1.y)){ 
		spr_button[1].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left)){
			
			//Data_Struct strc_add(playgame.Strc_aux.name_str,this->m_score);
			Data_Struct strc_add(playgame.Strc_aux.name_str,this->m_score, this->m_date); //sobrecarga de contructor
			playgame.AddScore(strc_add); 
			
			playgame.SetScene(new Scene_Play());
		} 
		
	}else{
		spr_button[1].setColor(Color(255,255,255));
	}
	if (spr_button[2].getGlobalBounds().contains(r1.x,r1.y)){ 
		spr_button[2].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left)){
			
			//char caux[25] = "test";
			//Data_Struct strc_add(playgame.Strc_aux.name_str,this->m_score); //no sirve para la fecha
			//Data_Struct strc_add(playgame.Strc_aux.name_str,this->m_score, ""); ///sobrecarga de contructor //no sirve para la fecha
			Data_Struct strc_add(playgame.Strc_aux.name_str,this->m_score, this->m_date); ///sobrecarga de contructor, m_date = current_date
			playgame.AddScore(strc_add); 
			
			playgame.SetScene(new Scene_Menu());
		}
		
	}else{
		spr_button[2].setColor(Color(255,255,255));
	}
	srand(time(0));
	//int score = rand()%100;
	
}

void Scene_GameOver::Draw (RenderWindow & win){
	win.draw(spr_button[0]);
	win.draw(spr_button[1]);
	win.draw(spr_button[2]);
	win.draw(spr_button[3]);
	win.draw(txt_score);
}
int Scene_GameOver::SaveAndLoad(int score){
	//int highscore;
	string folder_name ="SaveData.bin";
	
	ifstream in_archi(folder_name, ios::binary);
	
	if(!in_archi.is_open()){
		ofstream out_archi(folder_name, ios::binary);
		out_archi.write(reinterpret_cast<char*>(&score),sizeof(score));
		highscore = score;
		out_archi.close();
	} 
	else{
		in_archi.seekg(0);
		in_archi.read(reinterpret_cast<char*>(&highscore),sizeof(highscore));
		in_archi.close();	
		
		if(score > highscore){
			ofstream out_archi(folder_name, ios::binary);
			out_archi.seekp(0);
			out_archi.write(reinterpret_cast<char*>(&score),sizeof(score));
			highscore = score;
			out_archi.close();
		}
	}
	
	return highscore;
}
