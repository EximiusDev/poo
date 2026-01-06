#include "../H/Game.h"
#include <SFML/Window/Event.hpp>
//#include <SFML/Window/VideoMode.hpp>
//#include <SFML/Graphics/RenderWindow.hpp>
#include "../H/Scene.h"
#include <iostream>
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;
//using namespace std;

//Game::Game(Scene *first_scene):m_window(VideoMode(640,480),"Prueba") {
Game::Game(Scene *first_scene):m_window(VideoMode(1280,720),"Juego Final P.O.O") {
	m_window.setFramerateLimit(60);
	m_scene = first_scene;
	
	// o sino como siempre empieza en menu
	// m_scene = new Scene_Menu();
}

void Game::SetScene(Scene *next_scene){
	m_next_scene = next_scene;
}
void Game::Pause_Scene(Scene *temp_scene){
	m_scene->Pause_Scn();
	m_pause_scene = temp_scene;
	clk_pause.restart();
}
void Game::Unpause_Scene(){
	delete m_scene;
	m_scene = m_aux_scene;
	m_aux_scene = nullptr;
	m_scene->Unpause_Scn();
	
	if(clk2.getElapsedTime().asMilliseconds() > millisec_paused) millisec_paused += clk_pause.getElapsedTime().asMilliseconds();
	else clk_pause.restart();
}
void Game::Delete_aux_Scene(){
	delete m_aux_scene;
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
		
		//float delta = clk1.restart().asSeconds();
		delta = clk1.restart().asSeconds();
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
		else if(m_pause_scene){
			//clk_pause.restart();
			//delete m_aux_scene;
			m_aux_scene = m_scene;
			m_scene = m_pause_scene;
			m_pause_scene = nullptr;
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
	m_scene->Update(*this,m_window);
}

void Game::Draw ( ) {
	m_scene->Draw(m_window);
}

float Game::GetDeltaTime(){
	return delta;
	//return clk1.getElapsedTime().asSeconds();
	//return clk1.getElapsedTime().asMilliseconds();
}
float Game::GetTime_Sec_Curr_Scn(){
	return clk2.getElapsedTime().asSeconds();
}
float Game::GetTime_mSec_Curr_Scn(){
	return clk2.getElapsedTime().asMilliseconds();
}
float Game::GetTime_mSec_Pause(){
	if(m_scene->GetPause()){
		if (millisec_paused == 0) return clk_pause.getElapsedTime().asMilliseconds();
		//else return millisec_paused;
	}
	else return millisec_paused;
}
