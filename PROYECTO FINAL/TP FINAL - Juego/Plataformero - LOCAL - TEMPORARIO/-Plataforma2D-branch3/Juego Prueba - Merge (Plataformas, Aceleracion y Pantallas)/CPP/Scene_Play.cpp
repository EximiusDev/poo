#include "../H/Scene_Play.h"
#include "../H/Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "../H/Scene_Menu.h"
#include <iostream>
#include "../H/Scene_Pause.h"
#include "../Scene_GameOver.h"
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
//#include "../H/Game.h"
#include "../H/Background.h"//#include "../H/Background.h"
#include "../H/Player.h"
#include <iostream>
using namespace sf;
using namespace std;
Scene_Play::Scene_Play() {
	this->Unpause_Scn();//paused = this->GetPause();
	/*
	m_floor.setSize({640.f,300.f});
	m_floor.setPosition({0.f,350.f});
	m_floor.setFillColor({100,200,100});
	*/
	
	//initialize text
	m_font.loadFromFile("RetroGaming.ttf");
	txt_mov_lat.setFont(m_font);
	txt_salto.setFont(m_font);
	txt_score.setFont(m_font);
	
	txt_mov_lat.setString("Movimiento: Left - Right");
	txt_mov_lat.setFillColor({255,255,255});
	txt_mov_lat.setPosition(0,720-30);
	txt_mov_lat.setCharacterSize(20);
	
	//txt_subtitulo.setString("<presione Enter para comenzar a jugar> \n<presione Escape para comenzar a jugar>");
	txt_salto.setString("Salto: Up");
	//txt_salto.setFillColor({150,150,150});
	txt_salto.setFillColor({255,255,255});
	txt_salto.setPosition(500,720-30);
	txt_salto.setCharacterSize(20);
	
	
	txt_score.setString("Score : " + std::to_string(m_score) + " \nTime: "+ std::to_string(seconds_game)); //txt_score.setString("Score : " + std::to_string(m_score) + ""); //txt_score.setString("Score : " + score + "");
	txt_score.setFillColor({255,255,255});
	txt_score.setPosition(0,0);
	txt_score.setCharacterSize(20);
}

void Scene_Play::Update (Game & playgame, RenderWindow & win) {
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)){
		/* ///NO USAR NO ESTA BIEN HECHO
		bool press = false;
		//cout<<"---"<<endl;
		while (press == false){
		//cout<<"xxx"<<endl;
		if (Keyboard::isKeyPressed(Keyboard::Key::Return)) press = true;
	}*/
		//paused = true;
		playgame.Pause_Scene(new Scene_Pause());
	}
	aceleration=acelerador.getElapsedTime().asSeconds()/2;
	if (!this->GetPause()){ // (!paused){
		
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){ // Escape
			playgame.SetScene(new Scene_Menu());
			///playgame.Stop();
		}
		//m_player.Update(m_floor.getGlobalBounds());
		
		/// ////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		collide_With_top=false;
		collide_With_floor=false;
		collide_With_wall_left=false;
		collide_With_wall_right=false;
		
		
		for(int i=0;i<plat.Get_cant_bloq_plat_y();i++) { 
			for(int j=0;j<plat.Get_cant_bloq_plat(i);j++) {
				if(plat.Get_block_existence(i,j)){
					if(plat.getBloq(i,j).Collide(player)){
						Bloque aux=plat.getBloq(i,j);
						
						if(player.CollideDown(aux)){
							collide_With_floor=true;
						}
						else if(player.CollideUp(aux)){
							collide_With_top=true;
						}
						
						if(player.CollideWithWallright(aux)){
							collide_With_wall_right=true;
						}
						else if(player.CollideWithWallleft(aux)){
							collide_With_wall_left=true;
						}
					}
				}
			}
		}/*
		if(!on_Air) cout<<"Colision superior"<<endl;
		else if(collide_With_wall_right)cout<<"Colision derecha"<<endl;
		else if(collide_With_wall_left)cout<<"Colision izquierda"<<endl;
		//else cout<<"No colisiona"<<endl;
		*/
		
		
		plat.Update(aceleration);
		player.Update(collide_With_floor,collide_With_top,collide_With_wall_left,collide_With_wall_right,aceleration,playgame);
		
		
		background_Parallax.Update(aceleration);
		
		
		
		
		/// ////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		///m_score = m_player.GetScore();
		seconds_pause = playgame.GetTime_mSec_Pause()/100; /// que lo haga el game
		seconds_game = playgame.GetTime_mSec_Curr_Scn()/100;
		seconds_played = ( playgame.GetTime_mSec_Curr_Scn() - playgame.GetTime_mSec_Pause() )/100;
		//txt_score.setString("Score : " + to_string(m_score) + " \nTime: "+ to_string(seconds_game - seconds_pause));
		txt_score.setString("Score : " + to_string(m_score) + " \nTime: "+ to_string(seconds_played));
		//txt_score.setString("Score : " + to_string(m_score) + " \nTime: "+ to_string(seconds_game) + " \n time pause: " + to_string(seconds_pause));
		if(seconds_game<=seconds_pause) cout<<"ERROR 1"<<endl;
		if(seconds_played!=seconds_game - seconds_pause) cout<<"ERROR 2"<<endl;
		
		player.Change_score(seconds_played);
	}
}

void Scene_Play::Draw (sf::RenderWindow & win) {
	/*
	//win.clear(Color(180,255,180,255));
	win.clear({150,255,255});
	win.draw(m_floor);
	m_player.Draw(win);
	
	win.draw(txt_mov_lat);
	win.draw(txt_salto);
	win.draw(txt_score);
	*/
	win.clear(Color(255,255,255,255));
	
	
	background_Parallax.Draw(win);
	plat.Draw(win);
	player.Draw(win);
	
	win.draw(txt_mov_lat);
	win.draw(txt_salto);
	win.draw(txt_score);
	//win.display();
}


