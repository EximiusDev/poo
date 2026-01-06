#include "../H/Background.h"
#include "../H/Object.h"
Background::Background(){
	spr.setPosition(0,0);
	///6,6
	spr.setScale(4,4);
}

void Background::Update(int i){

		spr.move(speedG.x*-i,speedG.y);
		positionG.x+=speedG.x*-i;
		if(positionG.x<=-1920){
			spr.setPosition(0,0);
			positionG.x=0;
		}
	}
	

void Background::Init(string name){
	tex.loadFromFile(name);
	spr.setTexture(tex);
}

