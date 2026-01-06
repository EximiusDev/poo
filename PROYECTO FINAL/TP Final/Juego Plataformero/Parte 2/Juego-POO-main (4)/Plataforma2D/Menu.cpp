#include "Menu.h"

Menu::Menu() {
	MenuT.loadFromFile("Menu.png");
	MenuS.setTexture(MenuT);
	MenuS.setPosition(0,0);
	NuevoJuegoT.loadFromFile("NuevoJuego.png");
	NuevoJuegoS.setTexture(NuevoJuegoT);
	NuevoJuegoS.setPosition(411,329);
	ContinuarT.loadFromFile("Continuar.png");
	ContinuarS.setTexture(ContinuarT);
	ContinuarS.setPosition(364,429);
	SalirT.loadFromFile("Salir.png");
	SalirS.setTexture(SalirT);
	SalirS.setPosition(386,528);
	
}

Sprite Menu::Men(){return MenuS;}
Sprite Menu::NuevoJuego(){return NuevoJuegoS;}
Sprite Menu::Continuar(){return ContinuarS;}
Sprite Menu::Salir(){return SalirS;}

