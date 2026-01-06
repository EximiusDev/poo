#include "Game.h"
#include <SFML/Window/Event.hpp>
//#include <SFML/Window/VideoMode.hpp>
//#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
using namespace sf;
//using namespace std;

Game::Game(Scene *first_scene):m_window(VideoMode(640,480),"Prueba") {
	//RenderWindow m_window(VideoMode(640,480),"Prueba"); /// NO ANDA
	m_window.setFramerateLimit(60);
	m_scene = first_scene;
	//m_next_scene = nullptr;
	
	// o sino como siempre empieza en menu
	// m_scene = new Scene_Menu();
}

void Game::SetScene(Scene * next_scene){
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
	while(m_window.isOpen()) {
		/*
		Event evt;
		while(m_window.pollEvent(evt)) {
			if(evt.type == Event::Closed)
				m_window.close();	
		}*/
		ProcessEvents();
		
		Update(); //m_scene->Update(*this);
		
		Draw(); //m_scene->Draw(m_window);
		
		m_window.display();
		
		if(m_next_scene){
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
		m_scene->InputEvents(evt);
	}
}

void Game::Update ( ) {
	m_scene->Update(*this);
}

void Game::Draw ( ) {
	m_scene->Draw(m_window);
}
