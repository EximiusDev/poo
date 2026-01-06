
#include "../H/Bloque.h"
#include "../H/Object.h"

Bloque::Bloque():Object(){
	scaleG={6,6};
	spr.setScale(scaleG);
}

void Bloque::Update(int i){
	spr.move(speedG.x*-i,speedG.y);
	positionG.x+=speedG.x*-i;
	if(positionG.x<=-16*scaleG.x){
		spr.setPosition(resolutionG.x,positionG.y);
		positionG.x=resolutionG.x;
	}
	
}
void Bloque::Init(string name,int i,int j){ 
	
	tex.loadFromFile(name);
	spr.setTexture(tex);
	positionG={i*144.f,j*144.f};
	spr.setPosition(positionG);

	
}
