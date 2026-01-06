#ifndef GAME_H
#define GAME_H
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Window/Event.hpp>
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
	~Game();
	void Stop();
	
	float GetTime_Sec_Curr_Scn();
	float GetTime_Sec_Curr_mScn();
private:
	RenderWindow m_window;
	Scene *m_scene, *m_next_scene = nullptr;
	
	Clock clk1;
	Clock clk2;
};

#endif

/*
int main(){
	Game the_game (new EscenaMenu() );
	the_game.Run();
}
*/
