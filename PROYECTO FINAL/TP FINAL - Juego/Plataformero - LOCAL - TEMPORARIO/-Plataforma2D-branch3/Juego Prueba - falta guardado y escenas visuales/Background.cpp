#include "Background.h"
//#include "../H/Background.h"
//#include "../H/Object.h"

Background::Background(){
	spr.setPosition(0,0);
	
	spr.setScale(resolutionG.x*0.0042,resolutionG.x*0.0042);
}

void Background::Update(int i){
	
	spr.move(speedG.x*-i,speedG.y);
	positionG.x+=speedG.x*-i;
	if(positionG.x<=-resolutionG.x*0.0042*320){
		spr.setPosition(0,0);
		positionG.x=0;
	}
}


void Background::Init(string name){
	tex.loadFromFile(name);
	spr.setTexture(tex);
}


