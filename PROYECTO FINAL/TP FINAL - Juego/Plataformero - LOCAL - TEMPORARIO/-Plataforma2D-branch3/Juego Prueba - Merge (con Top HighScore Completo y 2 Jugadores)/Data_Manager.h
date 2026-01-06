#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H
#include "Data_Struct.h"

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
//using namespace sf;
using namespace std;

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
	//Data_Struct aux;
private:
	string folder_name = "GameData.bin"; ///
	vector<Data_Struct> Scores; 
};

#endif

