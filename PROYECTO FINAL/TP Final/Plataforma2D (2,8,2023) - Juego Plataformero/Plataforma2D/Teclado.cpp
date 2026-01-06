#include "Teclado.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
using namespace std;

Teclado::Teclado() {
	
}
int Teclado::Tecla(Keyboard KeyB){
	if (KeyB.isKeyPressed(KeyB.Add)){
	return 1;
	}
	if (KeyB.isKeyPressed(KeyB.Subtract)){
	return 2;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
	return 3;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
	return 4;
	}
	return 0;
}
