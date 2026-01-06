#include "Data_Manager.h"
#include <iostream>
using namespace std;

Data_Manager::Data_Manager(){
	//cout<<"Game::Data_Manager "<< endl;
	
				    //123456789012345678901234
	char fname[25] = "Player"; // char fname[25] = "anonimo";
	//char fname[25] = "123456789012345678901234"; // char fname[25] = "anonimo";
	for (int i = 0; i < 25; i++){
		Strc_aux.name_str[i]=fname[i];
	}
	///string s1 = aux.name_str;
	///cout<<"aux.name_str "<<aux.name_str<< endl;
	
	Strc_aux.points_str = 0;
	this->InitHighScore();
}


void Data_Manager::InitHighScore ( ) {
	//cout<<"Game::InitHighScore "<< endl;
	
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
			cerr << "\n  error initializing vector \n"; //cout << "\n  error initializing vector \n";
		}
	}
	
	file.close();
}

void Data_Manager::AddScore (Data_Struct score) {
	//cout<<"Game::AddScore "<< endl;
	/*
	//(score.date_str == '')
	if( (score.date_str == "") or (score.date_str == "...") or (score.date_str == " ") or (score.date_str == " \0") or (score.date_str == 0) or (score.date_str == "___") ){
		time_t current_time; /// current_time es una clase de tipo time_t
		current_time = time(NULL); 
		strcpy(score.date_str, ctime(&current_time)); /// pone un \n al final
		cout<<score.date_str<<endl;
	}
	cout<<score.date_str<<endl;
	*/
	if(Scores[0].points_str<score.points_str){
		Scores[0] = score;
		//sort(Scores.begin(),Scores.end(),reverse_sort);
		sort(Scores.begin(),Scores.end());
	}
	saveScores();
}

vector<Data_Struct> Data_Manager::getHighscore(){
	//cout<<"Game::getHighscore "<< endl;
	this->saveScores();
	return this->Scores;
}

void Data_Manager::saveScores(){
	//cout<<"Game::saveScores "<< endl;
	
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
void Scene_GameOver::Update(Game &playgame){
	if (this->MouseisInsideBox(backToMenu) && m_ev.type == Event::EventType::MouseButtonPressed)
	{   
		//char caux[20] = "test";
		Data_Struct add(playgame.Strc_aux.name_str,this->score);
		playgame.AddScore(add); 
		playgame.SetScene(new Menu(*this->win));
	}
	if (this->MouseisInsideBox(playAgain) && m_evt.type == Event::EventType::MouseButtonPressed)
	{   
		Data_Struct add(playgame.aux.name_str,this->score);
		playgame.AddScore(add); 
		playgame.SetScene(new playScene(*this->win));
	}
}
*/
