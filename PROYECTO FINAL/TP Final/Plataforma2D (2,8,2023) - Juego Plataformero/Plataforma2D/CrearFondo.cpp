#include "CrearFondo.h"
#include <vector>
#include "Background.h"
using namespace std;
using namespace sf;
CrearFondo::CrearFondo() {
	Backg.resize(6);
	for(int i=1;i<6;i++) { 
		Backg[i].createBackg("B"+to_string(i)+".png"); 
	}
}

void CrearFondo::setMov(int x){
	for(int j=1;j<7;j++) { Backg[j].setPos(x*j,0); };
}
Sprite CrearFondo::getSpr(int i){

	return Backg[i].getSpr();
}
