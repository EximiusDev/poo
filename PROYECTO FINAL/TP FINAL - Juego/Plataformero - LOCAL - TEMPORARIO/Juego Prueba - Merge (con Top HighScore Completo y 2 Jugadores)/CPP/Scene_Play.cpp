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
Scene_Play::Scene_Play(bool two_players): two_players(two_players) {
	this->Unpause_Scn();//paused = this->GetPause();
	/*
	m_floor.setSize({640.f,300.f});
	m_floor.setPosition({0.f,350.f});
	m_floor.setFillColor({100,200,100});
	*/
	
	pinchos.Init("./Textures/Pinchos.png",-50,0);
	
	///initialize text
	//m_font.loadFromFile("RetroGaming.ttf");
	m_font.loadFromFile("JollyLodger.ttf");
	txt_mov_lat.setFont(m_font);
	txt_salto.setFont(m_font);
	txt_score.setFont(m_font);
	
	txt_mov_lat.setString("Movimiento: Left - Right");
	txt_mov_lat.setFillColor({255,255,255});
	txt_mov_lat.setPosition(0 + 300,720-40);
	txt_mov_lat.setCharacterSize(30);
	
	//txt_subtitulo.setString("<presione Enter para comenzar a jugar> \n<presione Escape para comenzar a jugar>");
	txt_salto.setString("Salto: Up");
	//txt_salto.setFillColor({150,150,150});
	txt_salto.setFillColor({255,255,255});
	txt_salto.setPosition(1280 - 300,720-40);
	txt_salto.setCharacterSize(30);
	
	
	txt_score.setString("Score : " + std::to_string(m_score) + " \nTime: "+ std::to_string(seconds_game)); //txt_score.setString("Score : " + std::to_string(m_score) + ""); //txt_score.setString("Score : " + score + "");
	txt_score.setFillColor({255,255,255});
	txt_score.setPosition(0 + 35,0);
	txt_score.setCharacterSize(30);
	acel_velocity = 3.f;
	
	if(two_players){
		player_two.Init("./Textures/Player-Hitbox.png", 1280 * 0.4f + 200, 720 * 0.5f);
		Player player_aux(two_players);
		player_two = player_aux;
	}
	else life_two = 0;
	
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
	
	if (!this->GetPause()){ // (!paused){
		
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){ // Escape
			playgame.SetScene(new Scene_Menu());
			///playgame.Stop();
		}
		//m_player.Update(m_floor.getGlobalBounds());
		
		/// ////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		collide_With_top_1=false;
		collide_With_floor_1=false;
		collide_With_wall_left_1=false;
		collide_With_wall_right_1=false;
		if(two_players){
			collide_With_top_2=false;
			collide_With_floor_2=false;
			collide_With_wall_left_2=false;
			collide_With_wall_right_2=false;
		}
		
		
		
		for(int i=0;i<plat.Get_cant_bloq_plat_y();i++) { 
			for(int j=0;j<plat.Get_cant_bloq_plat(i);j++) {
				if(plat.Get_block_existence(i,j)){
					if(plat.getBloq(i,j).Collide(player_one)){
						Bloque aux=plat.getBloq(i,j);
						
						if(player_one.CollideDown(aux)){
							collide_With_floor_1=true;
						}
						else if(player_one.CollideUp(aux)){
							collide_With_top_1=true;
						}
						
						if(player_one.CollideWithWallright(aux)){
							collide_With_wall_right_1=true;
						}
						else if(player_one.CollideWithWallleft(aux)){
							collide_With_wall_left_1=true;
						}
					}
					if(two_players){
						if(plat.getBloq(i,j).Collide(player_two)){
							Bloque aux=plat.getBloq(i,j);
							if(player_two.CollideDown(aux)){
								collide_With_floor_2=true;
							}
							else if(player_two.CollideUp(aux)){
								collide_With_top_2=true;
							}
							
							if(player_two.CollideWithWallright(aux)){
								collide_With_wall_right_2=true;
							}
							else if(player_two.CollideWithWallleft(aux)){
								collide_With_wall_left_2=true;
							}
						}
					}
				}
			}
		}/*
		if(!on_Air) cout<<"Colision superior"<<endl;
		else if(collide_With_wall_right_1)cout<<"Colision derecha"<<endl;
		else if(collide_With_wall_left_1)cout<<"Colision izquierda"<<endl;
		//else cout<<"No colisiona"<<endl;
		*/
		
		
		acel_velocity += playgame.GetDeltaTime()/10; //acel_velocity=acelerador.getElapsedTime().asSeconds()/10;
		//acel_velocity  = 10;
		//	cout<<"velocidad: "<<acel_velocity<<" delta: "<<playgame.GetDeltaTime()<<endl;
		
		plat.Update(acel_velocity);
		if(life_one > 0){
			player_one.Update(collide_With_floor_1,collide_With_top_1,collide_With_wall_left_1,collide_With_wall_right_1,acel_velocity, life_one,playgame);
		}
		
		if(two_players){
			if(life_two > 0){
				player_two.Update(collide_With_floor_2,collide_With_top_2,collide_With_wall_left_2,collide_With_wall_right_2,acel_velocity, life_two, playgame);
			}
			
		}
		
		background_Parallax.Update(acel_velocity);
		
		/// ////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		if (player_one.GetScore() >= player_two.GetScore()) m_score = player_one.GetScore();
		else m_score = player_two.GetScore();
		
		seconds_pause = playgame.GetTime_mSec_Pause()/100; /// que lo haga el game
		seconds_game = playgame.GetTime_mSec_Curr_Scn()/100;
		seconds_played = ( playgame.GetTime_mSec_Curr_Scn() - playgame.GetTime_mSec_Pause() )/100;
		//txt_score.setString("Score: " + to_string(m_score) + " \nTime: "+ to_string(seconds_game - seconds_pause));
		txt_score.setString("Score: " + to_string(m_score) + " \nTime: "+ to_string(seconds_played));
		//txt_score.setString("Score: " + to_string(m_score) + " \nTime: "+ to_string(seconds_game) + " \n time pause: " + to_string(seconds_pause));
		
		//if(seconds_game<seconds_pause) cout<<"ERROR: tiempo pausa 1"<<endl;
		if(seconds_game<seconds_pause) cerr<<"ERROR: tiempo pausa 1"<<endl;
		if(seconds_played!=seconds_game - seconds_pause) cerr<<"ERROR: tiempo pausa 2"<<endl;
		//if(seconds_played!=seconds_game - seconds_pause) cout<<"ERROR: tiempo pausa 2"<<endl;
		
		///player.Change_score(seconds_played);
		
		if(life_one <= 0 and life_two <= 0){
			playgame.SetScene(new Scene_GameOver(m_score));
		}
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
	if(life_one > 0) player_one.Draw(win);
	if(two_players) if(life_two > 0) player_two.Draw(win);
	
	pinchos.Draw(win);
	
	win.draw(txt_mov_lat);
	win.draw(txt_salto);
	win.draw(txt_score);
	//win.display();
}


