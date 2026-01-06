#include "GameOver.h"

GameOver::GameOver() {
	PerdisteT.loadFromFile("Perdiste.png");
	PerdisteS.setTexture(PerdisteT);
	PerdisteS.setPosition(0,0);
	ReiniciarT.loadFromFile("Reiniciar.png");
	ReiniciarS.setTexture(ReiniciarT);
	ReiniciarS.setPosition(363,362);
	
	SalirT.loadFromFile("Salir.png");
	SalirS.setTexture(SalirT);
	SalirS.setPosition(385,501);
	
}

Sprite GameOver::Perdiste(){return PerdisteS;}
Sprite GameOver::Salir(){return SalirS;}
Sprite GameOver::Reiniciar(){return ReiniciarS;}
