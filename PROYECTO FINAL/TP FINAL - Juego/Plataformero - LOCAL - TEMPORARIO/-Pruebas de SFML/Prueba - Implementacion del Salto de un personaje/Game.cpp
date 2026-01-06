#include "Game.h"
#include <SFML/Window/Event.hpp>
//#include <SFML/Window/VideoMode.hpp>
//#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include <iostream>
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;
//using namespace std;

Game::Game(Scene *first_scene):m_window(VideoMode(640,480),"Prueba") {
	m_window.setFramerateLimit(60);
	m_scene = first_scene;
	
	// o sino como siempre empieza en menu
	// m_scene = new Scene_Menu();
}

void Game::SetScene(Scene *next_scene){
	m_next_scene = next_scene;
}

Game::~Game() {
	delete m_scene;
	///delete m_next_scene; // ver si agregar o no 
}

void Game::Stop(){
	m_window.close();
}

void Game::Run(){
	//Event evt;
	
	//Clock clk1;
	//Clock clk2;
	while(m_window.isOpen()) {
		
		float delta = clk1.restart().asSeconds();
		// cout<<delta<<endl;
		//cout<<clk2.getElapsedTime().asMilliseconds()<<endl;
		//cout<<clk2.getElapsedTime().asSeconds()<<endl;
		
		ProcessEvents();
		Update(); //m_scene->Update(*this);
		Draw(); //m_scene->Draw(m_window);
		
		m_window.display();
		
		if(m_next_scene){
			clk2.restart();
			delete m_scene;
			m_scene = m_next_scene;
			m_next_scene = nullptr;
		}
	}
}

void Game::ProcessEvents ( ) {
	Event evt;
	while(m_window.pollEvent(evt)) {
		if(evt.type == Event::Closed)
			// m_window.close();
			Stop();
	}
}

void Game::Update ( ) {
	m_scene->Update(*this);
}

void Game::Draw ( ) {
	m_scene->Draw(m_window);
}

float Game::GetTime_Sec_Curr_Scn(){
	return clk2.getElapsedTime().asSeconds();
}
float Game::GetTime_Sec_Curr_mScn(){
	return clk2.getElapsedTime().asMilliseconds();
}
