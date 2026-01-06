
#include "../H/Bloque.h"
#include "../H/Object.h"

Bloque::Bloque():Object(){
	scaleG={1.f*tamanio_pixeles/cant_pixeles,1.f*tamanio_pixeles/cant_pixeles};
	spr.setScale(scaleG);
}

void Bloque::Update(int i){
	spr.move(speedG.x*-i,speedG.y);
	positionG.x+=speedG.x*-i;
	///Esto de abajo lo deberia hacer la plataforma preseteada
	if(positionG.x<=-1*resolutionG.x){
		spr.setPosition(resolutionG.x,positionG.y);
		positionG.x=resolutionG.x;
	}
}
void Bloque::Init(string name,int i,int j){ 
	tex.loadFromFile(name);
	spr.setTexture(tex);
	positionG={i*tamanio_pixeles*1.f,j*tamanio_pixeles*1.f};
	spr.setPosition(positionG);
}
void Bloque::Init(Texture & textu,int i,int j){ 
	tex = textu;
	spr.setTexture(tex);
	positionG={i*tamanio_pixeles*1.f,j*tamanio_pixeles*1.f};
	spr.setPosition(positionG);
}
