#include "Player_.h"
#include <SFML/Window/Keyboard.hpp>
//using namespace std;

Player_::Player_() { //: p_pos({50,300}){
	p_circle.setRadius(25);
	p_circle.setFillColor({200,150,50});
	p_pos = {50,0};  //p_circle.setPosition({50,300});
	
	p_score = 0;
	score_pos = p_pos.x;
}

void Player_::Update(FloatRect platform_bounds){
	if(sf::Keyboard::isKeyPressed(Keyboard::Left))
		//p_pos.x -= 3; /// 1era implementacion
		p_speed.x = -3;
	else if(sf::Keyboard::isKeyPressed(Keyboard::Right))
		//p_pos.x += 3; /// 1era implementacion
		p_speed.x = +3;
	else 
		p_speed.x = 0;
	
	//p_pos.y += 3; /// gravedad sin aceleracion (la gravedad siempre actua) 
	p_speed.y += .163; ///9.8/delta;
	
	p_pos += p_speed;
	
	if(p_speed.x > 0){ 		///TEMPORAL
		if (score_pos == p_pos.x) score_pos = -999;
		if (score_pos <= p_pos.x) p_score += p_speed.x; // p_score ++; //
	}
	else{
		if (score_pos == -999){
			score_pos = p_pos.x;
		}
	} 						///TEMPORAL
	//cout<<p_score<<"  "<<score_pos<<"  "<<p_pos.x<<endl;
	
	
	p_circle.setPosition(p_pos);
	auto Player__bounds = p_circle.getGlobalBounds(); // FloatRect
	
	//if(p_pos.y >=300){
	if(Player__bounds.intersects(platform_bounds)){
		p_speed.y = 0;
		//p_speed.y = -p_speed.y +1;/// rebota
		
		p_pos.y = platform_bounds.top - Player__bounds.height;// p_pos.y = 300;
		p_circle.setPosition(p_pos);
		if(sf::Keyboard::isKeyPressed(Keyboard::Up))
			p_speed.y = -10;
	}
	
	//if(sf::Keyboard::isKeyPressed(Keyboard::Down)) p_speed.y = +10; /// caer para abajo
}
	
	
void Player_::Draw (sf::RenderWindow & win){
	win.draw(p_circle);
}
	
