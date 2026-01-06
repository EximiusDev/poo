#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../H/Game.h"
#include "../H/Background.h"
#include <iostream>
using namespace sf;
///1920,1080
Game::Game():win(VideoMode(1280,720),"Juego Final P.O.O, Francisco Maldonado y Sandro Otero"){
	win.setFramerateLimit(60);
	
	
	
}

void Game::run(){
	while(win.isOpen()) {
		processEvent();
		update();
		draw();
		
	
}}
void Game::update(){
	on_Air=true;
	Collision=false;
	
	/*
	for(int i=0;i<plat.Get_Cant_Plat();i++) { 
		
		
		if(plat.getBloq(i).Collide(player))
		{
			on_Air=false;
			cout<<i<<" Colision"<<endl;
		}else cout<<i<<" NO Colision"<<endl;
	}*/
	for(int i=0;i<plat.Get_cant_bloq_plat_y();i++) { 
		for(int j=0;j<plat.Get_cant_bloq_plat(i);j++) { 
			if(plat.getBloq(j,i).Collide(player)){
				on_Air=false;
				Collision=true;
				cout<<i<<" Colision"<<endl;
			}else cout<<i<<" NO Colision"<<endl;
			if(Collision)int zxc; ///veo por que lado colisiona
		}
	}
	
	
	plat.Update();
	player.Update(on_Air);
	//background_Parallax.Update();
		
	
}
void Game::draw(){
		win.clear(Color(255,255,255,255));
		

		//background_Parallax.Draw(win);
		plat.Draw(win);
		player.Draw(win);
		player.Draw_spr(win);
		//win.draw(player.Draw_spr);
		//player.Draw_spr.Draw(win);
		
		win.display();
}



void Game::processEvent(){
	Event e;
	while(win.pollEvent(e)) {
	if(e.type == Event::Closed)
	win.close();	
						}}
