#include "../H/Player.h"
#include <string>
using namespace std;

Player::Player():Object("./Textures/Tierra.png") {
	///400, 500
	positionG = {120, 250}; /// cambiar por valores relativos
	margen = {60, 60}; 
	positionP = positionG-margen;
	spr.setPosition(positionG);
	///0.5
	scaleG={0.5,0.5}; /// cambiar por valores relativos
	spr.setScale(scaleG.x*10,scaleG.y*10);

	//spr.setTexture();
	//spr.setTextureRect(scaleG);
	
	texP.loadFromFile("./Textures/1.png");
	sprP.setTexture(texP);
	sprP.setPosition(positionP); /// cambiar por valores relativos
	///sprP.setScale(scaleG);
	scaleP = {5,5}; /// cambiar por valores relativos
	sprP.setScale(scaleP);
	
	///spr.setColor(Color(255,255,255,0));
}

void Player::Update(bool on_Air){
	///Faltaria contemplar la colision con el terreno
	
	
	
	
	speedG={0.0,0.0};
	NumAnim+=1;
	
	
	///if(!on_Air&&positionG.x>=-85){
	if(!on_Air){
		m_clock.restart();
		jumping_Animation=false;
		on_Air_Falling=false;
		on_Air_Jumping=false;
		///speedG.x=-3;
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
			if (scaleG.x<0){ 
				scaleG.x= -1*scaleG.x; //scaleG.x=0.5;
				positionG.x= positionG.x-150;
			}
			else {
				spr.setPosition(positionG);
				//sprP.setPosition(positionG);
			}
			
		Walking= true;
	}
	
	if ((Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::A))){	
		if(positionG.x>-85){ 
			speedG.x=-10;
			positionG.x+=speedG.x;
			if (scaleG.x>0){
				scaleG.x= -1*scaleG.x; //scaleG.x=-0.5;
				//spr.setPosition(positionG.x+256,positionG.y);
				positionG.x = positionG.x+150; ///hacer relativa al tamnio
			}
		}
		
		
		
		Walking= true;
	}
	
	///ANIMACION
	
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
	texP.loadFromFile(Name1+Name2+Name3);
	
	sprP.setTexture(texP);
	
	/// VARIABLES
	
	spr.setPosition(positionG);
	positionP = positionG-margen;
	sprP.setPosition(positionP);
	
	spr.setScale(scaleG.x*10,scaleG.y*10);
	spr.move(speedG);
	
	sprP.setScale(scaleG.x,scaleG.y);
	sprP.move(speedG);
	
	//sprP.setPosition(80,90);
}
void Player::Draw_spr(RenderWindow& win){
	win.draw(sprP);
}

