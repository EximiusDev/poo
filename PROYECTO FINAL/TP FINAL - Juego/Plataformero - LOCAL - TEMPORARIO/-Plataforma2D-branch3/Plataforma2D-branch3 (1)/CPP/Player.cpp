#include "../H/Player.h"
#include <string>
using namespace std;

Player::Player():Object() {
	///400, 500
	positionG = {200, 250};
	spr.setPosition(positionG);
	///0.5
	scaleG={0.4,0.4};
	spr.setScale(scaleG);

	
}

void Player::Update(bool on_Air){
	///Faltaria contemplar la colision con el terreno
	
	
	
	
	speedG={0.0,0.0};
	NumAnim+=1;
	
	
	if(!on_Air&&positionG.x>=-85){
		m_clock.restart();
		jumping_Animation=false;
		on_Air_Falling=false;
		on_Air_Jumping=false;
		speedG.x=-3;
		positionG.x+=speedG.x;
	}
	
	if(on_Air&&!on_Air_Jumping){
		speedG.y=+5;
		positionG.y+=speedG.y;
		jumping_Animation=true;
		on_Air_Falling=true;
	} 
	if (m_clock.getElapsedTime().asMilliseconds()>=500||!Keyboard::isKeyPressed(Keyboard::Up)&&!Keyboard::isKeyPressed(Keyboard::W)&&!Keyboard::isKeyPressed(Keyboard::Space))
	{
		on_Air_Falling=true;
		on_Air_Jumping=false;
	}
	
	if (!on_Air_Falling&&(Keyboard::isKeyPressed(Keyboard::Up)||Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::Space))){
		
			speedG.y=-10;
			positionG.y+=speedG.y;
		jumping_Animation=true;
			on_Air_Jumping=true;
		
		
		
	}	
	
	
	if ((Keyboard::isKeyPressed(Keyboard::Right)||Keyboard::isKeyPressed(Keyboard::D))&&positionG.x<1650){
		speedG.x=10;
		positionG.x+=speedG.x;
		scaleG.x=0.5;
		spr.setPosition(positionG.x,positionG.y);
		Walking= true;
	}
	
	if ((Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::A))){	
		if(positionG.x>-85){ 
			speedG.x=-10;
			positionG.x+=speedG.x;
			scaleG.x=-0.5;
			spr.setPosition(positionG.x+256,positionG.y);
		}
		
		
		
		Walking= true;
	}
	
	if(NumAnim>20||(NumAnim>8&&jumping_Animation)){
		NumAnim=1;
	}
	if(jumping_Animation){
		Name1="./Textures/J";
	}else{
		if(Walking){
			Name1="./Textures/Walk";
			Walking = false;
			
		}else{
			Name1="./Textures/";
		}
	}
	string Name2=to_string(NumAnim);
	string Name3=".png";
	tex.loadFromFile(Name1+Name2+Name3);
	spr.setTexture(tex);
	spr.setScale(scaleG);
	spr.move(speedG);
	
}
