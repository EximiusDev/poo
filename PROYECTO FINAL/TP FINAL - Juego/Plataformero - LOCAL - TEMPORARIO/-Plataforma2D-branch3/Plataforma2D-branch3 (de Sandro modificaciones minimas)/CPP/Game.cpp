#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../H/Game.h"
#include "../H/Background.h"
#include <iostream>
using namespace sf;

//Game::Game():win(VideoMode(1280,720),"Juego Final P.O.O, Francisco Maldonado y Sandro Otero"){
Game::Game(int resolution_x, int resolution_y):win(VideoMode( resolution_x, resolution_y),"Juego Final P.O.O, Francisco Maldonado y Sandro Otero"){
//Game::Game(Vector2i resolutionWindows):win(VideoMode( resolutionWindows.x, resolutionWindows.y),"Juego Final P.O.O, Francisco Maldonado y Sandro Otero"){
	win.setFramerateLimit(60);
	//resolutionWin   = resolutionWindows;
	resolutionWin.x = resolution_x;		resolutionWin.y = resolution_y;
}

void Game::run(){
	while(win.isOpen()) {
		processEvent();
		update();
		draw();
	}
}
void Game::update(){
	on_Air=true;
	collide_With_wall_left=false;
	collide_With_wall_right=false;
	
	for(int i=0;i<plat.Get_Cant_Plat();i++) { 
		if(plat.getBloq(i).Collide(player)){
			on_Air=false;
		}
		if(plat.getBloq(i).CollideWithWallright(player)){
			collide_With_wall_right=true;
		}
		if(plat.getBloq(i).CollideWithWallleft(player)){
			collide_With_wall_left=true;
		}
	}
	
	
	plat.Update();
	player.Update(on_Air , collide_With_wall_left,collide_With_wall_right);

	background_Parallax.Update();
		
	
}
void Game::draw(){
		win.clear(Color(255,255,255,255));
		

		background_Parallax.Draw(win);
		plat.Draw(win);
		player.Draw(win);
		
		
		win.display();
}



void Game::processEvent(){
	Event e;
	while(win.pollEvent(e)) {
	if(e.type == Event::Closed)
	win.close();	
						}}
