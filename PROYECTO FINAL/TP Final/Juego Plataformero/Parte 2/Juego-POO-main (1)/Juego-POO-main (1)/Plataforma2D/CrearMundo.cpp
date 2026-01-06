#include "CrearMundo.h"
#include <vector>
#include "Bloques.h"
using namespace std;

CrearMundo::CrearMundo(int cantBloques) {
	Tierra.resize(cantBloques);
	Tierra1.resize(cantBloques);
	
	y.resize(cantBloques);
	this->cantBloques = cantBloques;
	for(int i=0;i<cantBloques;i++) {
		y[i]=804;
	Tierra[i].Start("Tierra.png");
	Tierra1[i].Start("Tierra2.png");
	Tierra1[i].setPos(i*96,y[i]);
	Tierra[i].setPos(i*96,y[i]+96);
	y[10]=504;
	y[11]=504;
	Tierra1[10].setPos(10*96,y[10]);
	Tierra[10].setPos(10*96,y[10]+96);
	Tierra1[11].setPos(11*96,y[10]);
	Tierra[11].setPos(11*96,y[10]+96);
	
}
}
void CrearMundo::setMov(int x){
	for(int j=0;j<cantBloques;j++) { 
		Tierra1[j].setPos(j*96+x*10,y[j]);
		Tierra[j].setPos(j*96+x*10,y[j]+96);
	}
}
Sprite CrearMundo::getSpr1(int i){return Tierra[i].getSpr();}
Sprite CrearMundo::getSpr2(int i){return Tierra1[i].getSpr();}
FloatRect CrearMundo::Colide(int i){FloatRect r1 =Tierra1[i].getSpr().getGlobalBounds(); return r1;}
