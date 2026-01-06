#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "string.h"
#include <cstring>
#include <sstream>
#include <ctime>
using namespace std;
//using namespace sf;



struct hsStruct{
public:
	hsStruct(){
		
	}
	
	hsStruct(char name[20], int points){
		for (int i = 0; i < 20; i++)
		{
			_name[i]=name[i];
		}
		
		this->_points = points;
	}
		bool operator<(hsStruct aux){
			if (this->_points<aux._points)
			{
				return true;
			}
			return false;
		}
		bool operator>(hsStruct aux){
			if (this->_points>aux._points)
			{
				return true;
			}
			return false;
		}
		char _name[20];
		int _points;
};

class Game {
public:
	//Functions
	Game();
	// Para el sistema de puntajes
	void InitHighScore();//passes the data from the Tanto file to a vector of scores
	void AddScore(hsStruct score);//if the score is higher than the last score saved, it add the score to the scores vector
	std::vector<hsStruct> getHighscore();
	void saveScores();
	~Game();
	
	//Variables
	hsStruct aux;
private:
	std::vector<hsStruct> Scores; 
};


//bool highscores_menu::reverse_sort(hsStruct a1,hsStruct a2){
bool reverse_sort(hsStruct a1,hsStruct a2){
	return a2._points<a1._points;
}

int main() {
	///cout<<"INICIO "<< endl;
	
	srand(time(0));
	int score = rand()%100;
	
	cout<<"Current score = "<<score<<endl;
	
	Game g;
	
	std::string str ; // std::string str = in.getValue();
	///str = "hola";
	if (str != "")
	{
		strcpy(g.aux._name,str.c_str()); // strcpy(g->aux._name,str.c_str());
	}
	
	//char caux[20] = "test";
	hsStruct add(g.aux._name,score); //hsStruct add(g.aux._name,this->score);
	g.AddScore(add); 
	
	std::vector<hsStruct> highscore = g.getHighscore();
	sort(highscore.begin(),highscore.end(),reverse_sort);
	
	cout<<"size: "<<highscore.size()<< endl;
	
	for (size_t i = 0; i < highscore.size() ; i++){
		cout<<i<<". Nombres: "<<highscore[i]._name<<" Valores: "<<highscore[i]._points<< endl;
	}
	
	///cout<<"FIN "<< endl;
	
	return 0;
}

Game::Game() 
	//: m_window(VideoMode(640,1024),"Skyjump")
	//: m_window(VideoMode(640,720),"Skyjump")
{
	cout<<"Game::Game "<< endl;
	
	char fname[20] = "anonimo";
	for (int i = 0; i < 20; i++)
	{
		aux._name[i]=fname[i];
	}
	///string s1 = aux._name;
	///cout<<"aux._name "<<aux._name<< endl;
	
	aux._points = 0;
	/*m_window.setFramerateLimit(60);
	//FILL WITH FIRST SCENE AS menuScene 
	this->m_scene = new Menu(m_window);*/
	this->InitHighScore();
}


void Game::InitHighScore ( ) {
	cout<<"Game::InitHighScore "<< endl;
	
	ifstream file("HighScores.bin",ios::binary|ios::in|ios::ate); // ifstream file("bin/HighScores.bin",ios::binary|ios::in|ios::ate);
	if(!file){
		cerr << "/n The file could not be opened n/" ;
		ofstream newFile("HighScores.bin", ios::trunc | ios::binary); // ofstream newFile("bin/HighScores.bin", ios::trunc | ios::binary);
		newFile.close();
		for (int i = 0; i < 10; i++)
		{
			char caux[20] = "___";
			hsStruct aux(caux,0);
			Scores.push_back(aux);
		}
		this->saveScores();
	}
	int can = file.tellg()/sizeof(hsStruct);
	file.seekg(0);
	
	hsStruct p;
	for(int i=0; i<can;++i){
		file.read(reinterpret_cast<char*>(&p),sizeof(hsStruct));
		Scores.push_back(p);
		if(Scores.size()>10){
			cerr << "/n error initializing vector n/";
		}
	}
	
	file.close();
}

void Game::AddScore (hsStruct score) {
	cout<<"Game::AddScore "<< endl;
	
	if(Scores[0]._points<score._points){
		Scores[0] = score;
		//sort(Scores.begin(),Scores.end(),reverse_sort);
		sort(Scores.begin(),Scores.end());
	}
	saveScores();
}

vector<hsStruct> Game::getHighscore(){
	cout<<"Game::getHighscore "<< endl;
	this->saveScores();
	return this->Scores;
}

void Game::saveScores(){
	cout<<"Game::saveScores "<< endl;
	
	ofstream file("HighScores.bin",ios::ate|ios::binary|ios::out|ios::trunc); // ofstream file("bin/HighScores.bin",ios::ate|ios::binary|ios::out|ios::trunc);
	
	for(size_t i=0; i<Scores.size();++i){
		hsStruct aux = Scores[i];
		file.write(reinterpret_cast<char*>(&aux),sizeof(hsStruct));
	}
	
	file.close();
}

Game::~Game ( ) {
	
}

/*
void death_scene::Update(Game &g){
	if (this->MouseisInsideBox(backToMenu) && m_ev.type == Event::EventType::MouseButtonPressed)
	{   
		//char caux[20] = "test";
		hsStruct add(g.aux._name,this->score);
		g.AddScore(add); 
		g.SetScene(new Menu(*this->win));
	}
	if (this->MouseisInsideBox(playAgain) && m_ev.type == Event::EventType::MouseButtonPressed)
	{   
		hsStruct add(g.aux._name,this->score);
		g.AddScore(add); 
		g.SetScene(new playScene(*this->win));
	}
}
*/
