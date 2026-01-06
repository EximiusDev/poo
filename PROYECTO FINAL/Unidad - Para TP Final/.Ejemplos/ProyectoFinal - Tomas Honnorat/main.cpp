#include "Game.h"

int main(){
	
	Game* game = new Game(1280, 720, "Prototype");
	game->Play();
	
	return 0;
}

