#include "CrearMundo.h"
#include <vector>
#include "Bloques.h"
#include <cstdlib>
using namespace std;

CrearMundo::CrearMundo(int cantBloques) {

	vector<int>GuaRd(30);
	for(int i=0;i<30;i++) { 
		GuaRd[i]=rand()%400+200;
	}
	Tierra1.resize(cantBloques);
	
	y.resize(cantBloques);
	this->cantBloques = cantBloques;
	for(int i=0;i<cantBloques;i++) {
		y[i]=650;
	y[10]=GuaRd[1];
	y[11]=GuaRd[1];
	y[15]=GuaRd[2];
	y[16]=GuaRd[2];
	y[20]=GuaRd[3];
	y[21]=GuaRd[3];
	y[22]=GuaRd[3];
	y[23]=GuaRd[3];
	y[26]=GuaRd[4];
	y[27]=GuaRd[4];
	y[35]=GuaRd[5];
	y[36]=GuaRd[5];
	y[40]=GuaRd[6];
	y[41]=GuaRd[6];
	y[42]=GuaRd[6];
	y[46]=GuaRd[7];
	y[47]=GuaRd[7];
	y[50]=GuaRd[8];
	y[51]=GuaRd[8];
	y[52]=GuaRd[9];
	y[53]=GuaRd[9];
	y[54]=GuaRd[9];
	y[60]=GuaRd[10];
	y[61]=GuaRd[10];
	y[62]=GuaRd[10];
	y[65]=GuaRd[11];
	y[66]=GuaRd[11];
	y[70]=GuaRd[12];
	y[71]=GuaRd[12];
	y[75]=GuaRd[13];
	y[76]=GuaRd[13];
	y[77]=GuaRd[13];
	y[80]=GuaRd[14];
	y[81]=GuaRd[14];
	Tierra1[i].Start("Tierra2.png");
	Tierra1[i].setPos(i*96,y[i]);

	
	
	
}
}
void CrearMundo::setMov(int x){
	for(int j=0;j<cantBloques;j++) { 
		Tierra1[j].setPos(j*96+x*10,y[j]);
		
		
		
	
	}
}




Sprite CrearMundo::getSpr2(int i){return Tierra1[i].getSpr();}
//FloatRect CrearMundo::Colide(int i){FloatRect r1 =Tierra1[i].getSpr().getGlobalBounds(); return r1;}
Rect<int> CrearMundo::Colide(int i){Rect <int> A(Tierra1[i].getX(),Tierra1[i].getY(),96,96);return A;}
