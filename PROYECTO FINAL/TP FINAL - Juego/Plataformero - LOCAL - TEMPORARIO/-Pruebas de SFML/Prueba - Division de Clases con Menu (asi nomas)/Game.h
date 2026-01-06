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
private:
	RenderWindow m_window;
	Scene *m_scene;
	Scene *m_next_scene = nullptr;
};

#endif

/*
int main(){
	Game the_game (new EscenaMenu() );
	the_game.Run();
}
*/
