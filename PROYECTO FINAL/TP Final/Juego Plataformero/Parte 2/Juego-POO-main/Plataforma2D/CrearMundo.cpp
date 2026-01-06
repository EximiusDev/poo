#include "CrearMundo.h"
#include <vector>
#include "Bloques.h"
using namespace std;

CrearMundo::CrearMundo(int cantBloques) {
	Tierra.resize(cantBloques);
	Tierra1.resize(cantBloques);
	this->cantBloques = cantBloques;
	for(int i=0;i<cantBloques;i++) { 
	Tierra[i].Start("Tierra.png");
	Tierra1[i].Start("Tierra2.png");
	Tierra1[i].setPos(i*96,804);
	Tierra[i].setPos(i*96,900);
}
}
void CrearMundo::setMov(int x){
	for(int j=0;j<cantBloques;j++) { 
		Tierra1[j].setPos(j*96+x*10,804);
		Tierra[j].setPos(j*96+x*10,900);
	}
}
Sprite CrearMundo::getSpr1(int i){return Tierra[i].getSpr();}
Sprite CrearMundo::getSpr2(int i){return Tierra1[i].getSpr();}

