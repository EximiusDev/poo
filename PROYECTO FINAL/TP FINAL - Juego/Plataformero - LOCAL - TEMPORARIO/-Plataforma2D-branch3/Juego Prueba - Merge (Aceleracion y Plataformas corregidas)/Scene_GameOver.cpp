#include "Scene_GameOver.h"
#include "H/Scene_Menu.h"
#include "H/Scene_Play.h"
#include <iostream>
#include <fstream>
using namespace std;

//Scene_GameOver::Scene_GameOver() {
Scene_GameOver::Scene_GameOver(int score) {
	m_score = score;
	Tex.resize(4);
	Spr.resize(4);
	Tex[0].loadFromFile("./Textures/GameOver.png");
	Spr[0].setTexture(Tex[0]);
	
	Tex[1].loadFromFile("./Textures/button_Play.png");
	Spr[1].setTexture(Tex[1]);
	Spr[1].setPosition(411,329);
	
	Tex[2].loadFromFile("./Textures/button_Exit.png");
	Spr[2].setTexture(Tex[2]);
	Spr[2].setPosition(364,429);
	
	Tex[3].loadFromFile("./Textures/button.png");
	Spr[3].setTexture(Tex[3]);
	Spr[3].setPosition(364,229);
	
	this->SaveAndLoad(m_score);
	
	//cout<<"Current score = "<<score<<endl;
	cout<<"Current score = "<<m_score<<endl;
	int highScore = SaveAndLoad(m_score);
	cout<<"HighScore = "<<highScore<<endl;
	
	m_font.loadFromFile("RetroGaming.ttf");
	txt_score.setFont(m_font);
	//txt_highScore.setFont(m_font);
	
	txt_score.setString("Score: " + std::to_string(m_score) + "   HighScore: "+ std::to_string(highScore)); 
	//txt_score.setString("Score: " + std::to_string(m_score) + " \nHighScore: "+ std::to_string(highScore)); 
	txt_score.setFillColor({255,255,255});
	txt_score.setPosition(364 + 10,229 + 12);
	txt_score.setCharacterSize(28); //24
}

void Scene_GameOver::Update (Game & playgame, RenderWindow & win){
	r1 = Arrow.getPosition(win);
	
	if (Spr[1].getGlobalBounds().contains(r1.x,r1.y)){ 
		Spr[1].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left)){
			playgame.SetScene(new Scene_Play());
		} 
		
	}else{
		Spr[1].setColor(Color(255,255,255));
	}
	if (Spr[2].getGlobalBounds().contains(r1.x,r1.y)){ 
		Spr[2].setColor(Color(200,200,200));
		if(Arrow.isButtonPressed(Arrow.Left)){
			playgame.SetScene(new Scene_Menu());
		} 
		
	}else{
		Spr[2].setColor(Color(255,255,255));
	}
	srand(time(0));
	//int score = rand()%100;
	
}

void Scene_GameOver::Draw (RenderWindow & win){
	win.draw(Spr[0]);
	win.draw(Spr[1]);
	win.draw(Spr[2]);
	win.draw(Spr[3]);
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
