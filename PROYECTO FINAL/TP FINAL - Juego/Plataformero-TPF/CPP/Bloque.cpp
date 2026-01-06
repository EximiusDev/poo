

#include "../H/Bloque.h"
//#include "../H/Object.h"

Bloque::Bloque():Object(){
	scaleG={1.f*tamanio_pixeles/cant_pixeles,1.f*tamanio_pixeles/cant_pixeles};
	spr.setScale(scaleG);
}

void Bloque::Update(float vel){
	spr.move(-vel,speedG.y);
	positionG.x+=speedG.x*-vel;
	///Esto de abajo lo deberia hacer la plataforma preseteada
	if(positionG.x<=-1*resolutionG.x/2){
		spr.setPosition(resolutionG.x,positionG.y);
		positionG.x=resolutionG.x;
		reset_block = true;
	}
	/*
	else if(positionG.x >= 0){
	reset_block = false;
	}*/
}
void Bloque::Update(float vel, float delta){
	speedG.x = - vel;
	positionG += speedG; // positionG.x+=speedG.x*-vel;
	spr.move(speedG); // spr.move(-vel,speedG.y);
	///Esto de abajo lo deberia hacer la plataforma preseteada
	if(positionG.x<=-1*resolutionG.x/2){
		spr.setPosition(resolutionG.x,positionG.y);
		positionG.x=resolutionG.x;
		reset_block = true;
	}
	/*
	else if(positionG.x >= 0){
	reset_block = false;
	}*/
}

void Bloque::Init(string name,int i,int j){ 
	tex.loadFromFile(name);
	spr.setTexture(tex);
	positionG={i*tamanio_pixeles*1.f,j*tamanio_pixeles*1.f};
	spr.setPosition(positionG);
	reset_block = false;
}
void Bloque::Init(Texture & textu,int i,int j){ 
	//tex = textu;
	//spr.setTexture(tex);
	spr.setTexture(textu);
	positionG={i*tamanio_pixeles*1.f,j*tamanio_pixeles*1.f};
	spr.setPosition(positionG);
	reset_block = false;
}

void Bloque::Draw (RenderWindow& win , bool is_active) {
	if (is_active) win.draw(spr);
}

bool Bloque::is_block_active(){
	return reset_block;
}
void Bloque::block_out_window(bool state){
	reset_block = state;
}

