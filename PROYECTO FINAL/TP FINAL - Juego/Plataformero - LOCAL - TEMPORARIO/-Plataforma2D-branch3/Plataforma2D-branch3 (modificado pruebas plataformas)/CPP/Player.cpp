#include "../H/Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player():Object() {
	
	///Cambio de variables
	positionG = {resolutionG.x*0.2f, resolutionG.y*0.5f};
	scaleG={resolutionG.x*0.0003f,resolutionG.x*0.0003f};
	
	///Modificacion del spr
	spr.setPosition(positionG);
	spr.setScale(scaleG);

	
}

void Player::Update(bool on_Air,bool collide_With_wall_left,bool collide_With_wall_right){
	
	if(!on_Air){ //Si no esta en el aire...
		jump_clock.restart(); // El reloj de salto se resetea
		jumping_Animation=false; // Se apaga la animacion de salto
		on_Air_Falling=false; // No esta activada la caida 
		on_Air_Jumping=false; // No esta activado el salto 
		speedG.x=-3; //La plataforma traslada al jugador
		///speedG=worldspeed; //La plataforma traslada al jugador
		positionG.x+=speedG.x;
	}
	
	if(on_Air&&!on_Air_Jumping){ //Si esta en el aire pero no esta saltando
		jumping_Animation=true; //Activo la animacion de salto/caida
		on_Air_Falling=true; // Esta cayendo
		speedG.y=+5; // Velocidad de caida
		positionG.y+=speedG.y;
	} 

	if (jump_clock.getElapsedTime().asMilliseconds()>=500||!Keyboard::isKeyPressed(Keyboard::Up)&&!Keyboard::isKeyPressed(Keyboard::W)&&!Keyboard::isKeyPressed(Keyboard::Space)&&on_Air){ //Si paso el tiempo O si no fueron apretadas las tecla de salto en el aire...
		on_Air_Falling=true; //Se activa la caida
		on_Air_Jumping=false; //Se apaga la animacion de salto
		//speedG.y=0;
	}

	if (!on_Air_Falling&&(Keyboard::isKeyPressed(Keyboard::Up)||Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::Space))){ // Si no esta cayendo y se apreto la tecla de salto...
		jumping_Animation=true; // Se activa la animacion de salto
		on_Air_Jumping=true;// Se activa el salto
		speedG.y=-10;// Velocidad de salto
		positionG.y+=speedG.y;
	}	

	if ((Keyboard::isKeyPressed(Keyboard::Right)||Keyboard::isKeyPressed(Keyboard::D))&&positionG.x<1650&&!collide_With_wall_right){
		
		speedG.x=10; //Velocidad de movimiento
		positionG.x+=speedG.x; //Se guarda posicion
		scaleG.x=resolutionG.x*0.0003; //Se espeja el sprite
		spr.setPosition(positionG); //Se arregla el error del espejo
		walking_animation= true;// Se activa la animacion de movimiento
	}

	if ((Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::A))&&!collide_With_wall_left){	
		speedG.x=-10;//Velocidad de movimiento
		positionG.x+=speedG.x;//Se guarda posicion
		scaleG.x=resolutionG.x*-0.0003;//Se espeja el sprite
		spr.setPosition(positionG.x-r1.width,positionG.y);//Se arregla el error del espejo
		walking_animation= true;// Se activa la animacion de movimiento
	}
	if(collide_With_wall_right){
		speedG.x=3;
		positionG.x+=speedG.x;
	}if(collide_With_wall_left){
		speedG.x=-3;
		positionG.x+=speedG.x;
	}
	
	tex.loadFromFile(Animation());
	spr.setTexture(tex);
	spr.setScale(scaleG);
	spr.move(speedG);
	//positionG+=speedG;
	speedG={-0.0,0.0}; /// la velocidad por defecto es la velocidad del mundo
	//speedG = worldspeed; /// la velocidad por defecto es la velocidad del mundo
	
	
}
string Player::Animation(){
	number_Animation+=1;
	if(number_Animation>20||(number_Animation>8&&jumping_Animation)){
		number_Animation=1;
	}
	if(jumping_Animation){
		Name1="./Textures/J";
	}else{
		if(walking_animation){
			Name1="./Textures/Walk";
			walking_animation = false;
			
		}else{
			Name1="./Textures/";
		}
	}
	string Name2=to_string(number_Animation);
	string Name3=".png";
	return Name1+Name2+Name3;
}
