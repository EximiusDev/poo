#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "string.h"
#include <cstring>
#include <sstream>
#include <ctime>
#include <time.h>
using namespace std;
//using namespace sf;



struct Data_Struct{
public:
	Data_Struct(){
		points_str = 0;
		strcpy(date_str, "...");
		strcpy(name_str, "...");
		//is_highScore = false;
		//is_topScore = false;
	}
	char name_str[25];
	int points_str;
	char date_str[25];
	bool is_highScore = false;
	bool is_topScore = false;
	//int life_str;
	//long time_str;
	//bool is_saved = false;
	//bool is_current_save = false;
	
	Data_Struct(char name[25], int points){
		for (int i = 0; i < 25; i++){
			name_str[i]=name[i];
		}
		this->points_str = points;
	}
	Data_Struct(char name[25], int points,char date[25]){
		for (int i = 0; i < 25; i++){ name_str[i]=name[i];}
		for (int i = 0; i < 25; i++){ date_str[i]=date[i];}
		this->points_str = points;
	}
	bool operator<(Data_Struct aux){
		if (this->points_str<aux.points_str){
				return true;
		}
		return false;
	}
	bool operator>(Data_Struct aux){
		if (this->points_str>aux.points_str){
			return true;
		}
	return false;
	}
};

class Data_Manager {
public:
	//Functions
	Data_Manager();
	// Para el sistema de puntajes
	void InitHighScore();//passes the data from the Tanto file to a vector of scores
	void AddScore(Data_Struct score);//if the score is higher than the last score saved, it add the score to the scores vector
	std::vector<Data_Struct> getHighscore();
	void saveScores();
	~Data_Manager();
	
	//Variables
	Data_Struct Strc_aux;
	Data_Struct aux;
private:
	string folder_name = "GameData.bin";
	//string folder_name = "SaveData.bin";
	std::vector<Data_Struct> Scores;  
};

/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//bool highscores_menu::reverse_sort(Data_Struct a1,Data_Struct a2){
bool reverse_sort(Data_Struct a1,Data_Struct a2){
	return a2.points_str<a1.points_str;
}


int main() {
	///cout<<"INICIO "<< endl;
	
	srand(time(0));
	int score = rand()%100;
	
	cout<<"Current score = "<<score<<endl;
	
	Data_Manager Archi_Man;
	/*
	Menu::~Menu() {
		std::string str = in.getValue();
		if (str != "")
		{
			strcpy(m_g->aux._name,str.c_str());
		}
	*/
	std::string str ; // std::string str = in.getValue();
	///str = "hola";
	if (str != "")
	{
		strcpy(Archi_Man.Strc_aux.name_str,str.c_str()); // strcpy(g->aux.name_str,str.c_str());
	}
	
	time_t current_time; /// current_time es una clase de tipo time_t
	current_time = time(NULL); 
	strcpy(Archi_Man.Strc_aux.date_str, ctime(&current_time)); /// pone un \n al final
	//cout<<Archi_Man.Strc_aux.date_str<<endl;
	//char caux[20] = "test";
	//Data_Struct add(Archi_Man.Strc_aux.name_str , score); //Data_Struct add(g.aux.name_str,this->score);
	Data_Struct add(Archi_Man.Strc_aux.name_str , score, Archi_Man.Strc_aux.date_str); //Data_Struct add(g.aux.name_str,this->score);
	Archi_Man.AddScore(add); 
	
	/// ////////////// menu de highscores
	
	std::vector<Data_Struct> highscore = Archi_Man.getHighscore();
	sort(highscore.begin(),highscore.end(),reverse_sort);
	
	cout<<"size: "<<highscore.size()<< endl;
	
	for (size_t i = 0; i < highscore.size() ; i++){
		cout<<i<<". Nombres: "<<highscore[i].name_str<<" Valores: "<<highscore[i].points_str<<" Fecha: "<<highscore[i].date_str<<endl;
	}
	
	///cout<<"FIN "<< endl;
	
	return 0;
}
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Data_Manager::Data_Manager(){
	cout<<"Game::Data_Manager "<< endl;
	
	char fname[25] = "Player"; // char fname[20] = "anonimo";
	for (int i = 0; i < 25; i++)
	{
		Strc_aux.name_str[i]=fname[i];
	}
	///string s1 = aux.name_str;
	///cout<<"aux.name_str "<<aux.name_str<< endl;
	
	Strc_aux.points_str = 0;
	this->InitHighScore();
}


void Data_Manager::InitHighScore ( ) {
	cout<<"Game::InitHighScore "<< endl;
	
	ifstream file(folder_name,ios::binary|ios::in|ios::ate); // ifstream file("bin/HighScores.bin",ios::binary|ios::in|ios::ate);
	if(!file){
		cerr << "\n The file could not be opened \n"<<endl; // cerr << "/n The file could not be opened n/" ;
		ofstream newFile(folder_name, ios::trunc | ios::binary); // ofstream newFile("bin/HighScores.bin", ios::trunc | ios::binary);
		newFile.close();
		for (int i = 0; i < 10; i++){
			char aux_name[25] = "___";
			char aux_date[25] = "___";
			
			Data_Struct Strc_aux(aux_name,0,aux_date); // Data_Struct Strc_aux(aux_name,0); //Data_Struct Strc_aux;
			
			Scores.push_back(Strc_aux);
		}
		this->saveScores();
	}
	int cant = file.tellg()/sizeof(Data_Struct);
	file.seekg(0);
	
	Data_Struct p_aux;
	for(int i=0; i<cant;++i){
		file.read(reinterpret_cast<char*>(&p_aux),sizeof(Data_Struct));
		Scores.push_back(p_aux);
		if(Scores.size()>10){
			cerr << "\n  error initializing vector \n";
		}
	}
	
	file.close();
}

void Data_Manager::AddScore (Data_Struct score) {
	cout<<"Game::AddScore "<< endl;
	
	if(Scores[0].points_str<score.points_str){
		Scores[0] = score;
		//sort(Scores.begin(),Scores.end(),reverse_sort);
		sort(Scores.begin(),Scores.end());
	}
	saveScores();
}

vector<Data_Struct> Data_Manager::getHighscore(){
	cout<<"Game::getHighscore "<< endl;
	this->saveScores();
	return this->Scores;
}

void Data_Manager::saveScores(){
	cout<<"Game::saveScores "<< endl;
	
	ofstream file(folder_name,ios::ate|ios::binary|ios::out|ios::trunc); // ofstream file("bin/HighScores.bin",ios::ate|ios::binary|ios::out|ios::trunc);
	
	for(size_t i=0; i<Scores.size();++i){
		Data_Struct Strc_aux = Scores[i];
		file.write(reinterpret_cast<char*>(&Strc_aux),sizeof(Data_Struct));
	}
	
	file.close();
}

Data_Manager::~Data_Manager ( ) {
	
}

/*
void death_scene::Update(Game &g){
	if (this->MouseisInsideBox(backToMenu) && m_ev.type == Event::EventType::MouseButtonPressed)
	{   
		//char caux[20] = "test";
		Data_Struct add(g.Strc_aux.name_str,this->score);
		g.AddScore(add); 
		g.SetScene(new Menu(*this->win));
	}
	if (this->MouseisInsideBox(playAgain) && m_ev.type == Event::EventType::MouseButtonPressed)
	{   
		Data_Struct add(g.aux.name_str,this->score);
		g.AddScore(add); 
		g.SetScene(new playScene(*this->win));
	}
}
*/
