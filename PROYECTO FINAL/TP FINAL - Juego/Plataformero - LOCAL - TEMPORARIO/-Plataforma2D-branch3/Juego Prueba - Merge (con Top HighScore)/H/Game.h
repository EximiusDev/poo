#ifndef GAME_H
#define GAME_H
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Window/Event.hpp>
#include "../Data_Struct.h"
#include "../Data_Manager.h"
using namespace sf;
//using namespace std;

class Game {
public:
	Game(Scene *first_scene);
	void Run();
	void ProcessEvents();
	void Update();
	void Draw();
	void SetScene(Scene *next_scene);
	void Pause_Scene(Scene *temp_scene);
	void Unpause_Scene();
	void Delete_aux_Scene();
	~Game();
	void Stop();
	
	float GetDeltaTime();
	float GetTime_Sec_Curr_Scn(); // seconds of current Scene
	float GetTime_mSec_Curr_Scn();
	float GetTime_mSec_Pause();
	
	void AddScore(Data_Struct score);
	Data_Manager & Get_Dat_Manager();
	Data_Struct Strc_aux;
private:
	RenderWindow m_window;
	Scene *m_scene, *m_next_scene = nullptr;
	Scene *m_aux_scene = nullptr, *m_pause_scene = nullptr;
	
	Clock clk1;
	Clock clk2;
	Clock clk_pause;
	long millisec_paused = 0;
	
	float delta;
	
	Data_Manager Saved_data;
	
};

#endif

/*
int main(){
	Game the_game (new EscenaMenu() );
	the_game.Run();
}
*/
