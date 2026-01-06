#include "Scene_GameOver.h"
#include "H/Scene_Menu.h"
#include "H/Scene_Play.h"
#include <iostream>
#include <fstream>
using namespace std;

Scene_GameOver::Scene_GameOver() {
	Tex.resize(3);
	Spr.resize(3);
	Tex[0].loadFromFile("./Textures/GameOver.png");
	Spr[0].setTexture(Tex[0]);
	
	Tex[1].loadFromFile("./Textures/button_Play.png");
	Spr[1].setTexture(Tex[1]);
	Spr[1].setPosition(411,329);
	
	Tex[2].loadFromFile("./Textures/button_Exit.png");
	Spr[2].setTexture(Tex[2]);
	Spr[2].setPosition(364,429);
	
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
	int score = rand()%100;
	
	cout<<"Current score = "<<score<<endl;
	int highScore = SaveAndLoad(score);
	cout<<"HighScore = "<<highScore<<endl;
}

void Scene_GameOver::Draw (RenderWindow & win){
	win.draw(Spr[0]);
	win.draw(Spr[1]);
	win.draw(Spr[2]);
}
int Scene_GameOver::SaveAndLoad(int score){
	int highscore;
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
