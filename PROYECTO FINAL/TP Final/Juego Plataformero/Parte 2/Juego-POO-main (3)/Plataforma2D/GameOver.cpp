#include "GameOver.h"

GameOver::GameOver() {
	T.loadFromFile("GameOver.png");
	S.setTexture(T);
	S.setPosition(0,0);
}

Sprite GameOver::Perdio(){
	
	
	return S;

}
