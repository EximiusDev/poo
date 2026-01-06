#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int SaveAndLoad(int score)
{
	int highscore;
	
	ifstream in_archi("SaveData.dat", ios::binary);
	
	if(!in_archi.is_open())
	{
		ofstream out_archi("SaveData.dat", ios::binary);
		out_archi.write(reinterpret_cast<char*>(&score),sizeof(score));
		highscore = score;
		out_archi.close();
	} else
	{
		in_archi.seekg(0);
		in_archi.read(reinterpret_cast<char*>(&highscore),sizeof(highscore));
		in_archi.close();	
		
		if(score > highscore)
		{
			ofstream out_archi("SaveData.dat", ios::binary);
			out_archi.seekp(0);
			out_archi.write(reinterpret_cast<char*>(&score),sizeof(score));
			highscore = score;
			out_archi.close();
		}
	}
	
	return highscore;
}

int main() {
	srand(time(0));
	int score = rand()%100;
	
	cout<<"Current score = "<<score<<endl;
	int highScore = SaveAndLoad(score);
	cout<<"HighScore = "<<highScore<<endl;
	
	return 0;
}

