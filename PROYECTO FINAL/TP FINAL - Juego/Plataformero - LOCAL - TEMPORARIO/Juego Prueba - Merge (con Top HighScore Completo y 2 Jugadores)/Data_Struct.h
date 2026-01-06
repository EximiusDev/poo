#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include <cstring>
using namespace std;

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



#endif
