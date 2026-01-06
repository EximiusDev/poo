#include "Game.h"
#include "Menu.h"

using namespace std;

Game::Game(int xResolution, int yResolution, std::string windowTitle) : globalVolume(15)
{
	gameWindow = new RenderWindow(VideoMode(xResolution, yResolution), windowTitle);
	
	m_currentScene = new Menu(*gameWindow, *this);
}

Game::~Game() 
{
	delete gameWindow;
}

void Game::Play()
{		
	Clock clk;
	while(gameWindow->isOpen())
	{
		float delta = clk.restart().asSeconds();
		
		InputEvents();
		Update(delta);
		Draw();
		
		if(m_nextScene){
			delete m_currentScene;
			m_currentScene = m_nextScene;
			m_nextScene = nullptr;
		}
	}
}

void Game::InputEvents()
{
	Event ev;
	while(gameWindow->pollEvent(ev)){
		if(ev.type == Event::Closed){
			CloseGame();
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			CloseGame();
		}
		m_currentScene->InputEvents(ev);
	}
}

void Game::Update(float deltaTime)
{
	m_currentScene->Update(*this, deltaTime);
}

void Game::Draw()
{
	gameWindow->clear();
	
	m_currentScene->Draw(*gameWindow);
	
	gameWindow->display();
}

void Game::SetScene(Scene *nextScene){
	m_nextScene = nextScene;
}

void Game::CloseGame()
{
	gameWindow->close();
}

int Game::getVolume()
{
	return globalVolume;
}
void Game::setVolume(int v)
{
	globalVolume = v;
}
