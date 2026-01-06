#include "../H/Player.h"

#include <string>

#include <iostream>

#include <SFML/Window/Sensor.hpp>

using namespace std;

Player::Player(): Object() {

    ///Cambio de variables
    scaleG = {
        resolutionG.x * 0.0003f,
        resolutionG.x * 0.0003f
    };

    ///Modificacion del spr
    spr.setScale(scaleG);
	
    ///Modificacion del spr
	positionG = {resolutionG.x * 0.4f, resolutionG.y * 0.5f};
	spr.setPosition(positionG);
	

}

void Player::Update(bool collide_With_floor, bool collide_With_top,bool collide_With_wall_left, bool collide_With_wall_right) {
    speedG={0,0};

    if (collide_With_floor) { //Si no esta en el aire...
        jumping_time.restart(); // El reloj de salto se resetea=
        jumping_Animation = false; // Se apaga la animacion de salto
        on_Air_Falling = false; // No esta activada la caida 
        on_Air_Jumping = false;
        speedG.x = -2; /// velocidad de la plataforma
        //No esta activado el salto 
        //La plataforma traslada al jugador
        ///speedG = worldspeed; //La plataforma traslada al jugador
		
		///positionG.y = other_bounds.top - m_bounds.height;
		///speedG.y = 0;
    }
   
    if (!collide_With_floor && !on_Air_Jumping) { //Si esta en el aire pero no esta saltando
        jumping_Animation = true; //Activo la animacion de salto/caida
        on_Air_Falling = true; // Esta cayendo
        speedG.y = +9; // Velocidad de caida
    }
    if (m_bounds.top > resolutionG.y || m_bounds.left <= 0) { /// si se sale de la pantalla por la izquierda
        //spr.setPosition(resolutionG.x * 0.4f, resolutionG.y * 0.2f);
		positionG = {resolutionG.x * 0.4f, resolutionG.y * 0.2f};
    }
    if (jumping_time.getElapsedTime().asMilliseconds() >= 500 || !Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::Space) || m_bounds.top < 0|| collide_With_top && !collide_With_floor) { //Si paso el tiempo O si no fueron apretadas las tecla de salto en el aire...
        on_Air_Falling = true; //Se activa la caida
        on_Air_Jumping = false; //Se apaga la animacion de salto
    }

    if (!on_Air_Falling && (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space))) { // Si no esta cayendo y se apreto la tecla de salto...
        jumping_Animation = true; // Se activa la animacion de salto
        on_Air_Jumping = true; // Se activa el salto
        speedG.y = -10; // Velocidad de salto
    }
    
    if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))&&m_bounds.left + m_bounds.width < resolutionG.x && !collide_With_wall_right ) {
      
        speedG.x = 10; //Velocidad de movimiento
        scaleG.x = resolutionG.x * 0.0003f; //Se espeja el sprite
       // spr.setPosition(m_bounds.left, m_bounds.top); //Se arregla el error del espejo
		positionG = {m_bounds.left, m_bounds.top};
        walking_animation = true; // Se activa la animacion de movimiento
    }

    if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && !collide_With_wall_left && m_bounds.left > 0) {
        speedG.x = -10; //Velocidad de movimiento
        scaleG.x = resolutionG.x * -0.0003f; //Se espeja el sprite
        //spr.setPosition(m_bounds.left + m_bounds.width, m_bounds.top); //Se arregla el error del espejo
		positionG = {m_bounds.left + m_bounds.width, m_bounds.top};
        walking_animation = true;
    }
   
   

    tex.loadFromFile(Animation());
    spr.setTexture(tex);
    spr.setScale(scaleG);
	
	positionG += speedG;
	spr.setPosition(positionG);
   // spr.move(speedG);

    m_bounds = spr.getGlobalBounds(); ///r1 = m_bounds
    //speedG = worldspeed; /// la velocidad por defecto es la velocidad del mundo

}
string Player::Animation() {
    number_Animation += 1;
    if (number_Animation > 20 || (number_Animation > 8 && jumping_Animation)) {
        number_Animation = 1;
    }
    if (jumping_Animation) {
        Name1 = "./Textures/J";
    } else {
        if (walking_animation) {
            Name1 = "./Textures/Walk";
            walking_animation = false;

        } else {
            Name1 = "./Textures/";
        }
    }
    string Name2 = to_string(number_Animation);
    string Name3 = ".png";
    return Name1 + Name2 + Name3;
}
