#ifndef GAME_H
#define GAME_H

#include "Scene.h"

class Game {
	
public:
	Game(int xResolution, int yResolution, std::string windowTitle);
	~Game();
	
	void Play();
	void InputEvents();	
	void Update(float delta);
	void Draw();
	void SetScene(Scene *nextScene);
	
	int getVolume();
	void setVolume(int v);
	
	void CloseGame();
private:
	RenderWindow *gameWindow;
	
	Scene *m_currentScene;
	Scene *m_nextScene = nullptr;
	
	int globalVolume;
};

#endif

