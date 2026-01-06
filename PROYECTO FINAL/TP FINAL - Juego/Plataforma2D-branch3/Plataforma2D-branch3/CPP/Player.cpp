#include "../H/Player.h"

Player::Player():Object("./Textures/1.png") {
	spr.setPosition(x_position,y_position);
}

void Player::Update(){
	///Faltaria contemplar la colision con el terreno
	Jumping= false;
	if ((Keyboard::isKeyPressed(Keyboard::Up)||Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::Space))&&Jumping_Time>0)
	{
		spr.move(-speedPJ);
		y_position-=10;
		Jumping= true;
		Jumping_Time-=1;
	}	
	if ((Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::D))&&x_position<1650&&!Jumping)
	{
		spr.move(speedPW);
		x_position+=10;
		Jumping_Time=40;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Right)||Keyboard::isKeyPressed(Keyboard::A))&&x_position>-200&&!Jumping)
	{
		spr.move(-speedPW);
		x_position-=10;
		Jumping_Time=40;
	}
	
} 
