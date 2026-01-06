#include "CrearMundo.h"
#include <vector>
#include "Bloques.h"
using namespace std;

CrearMundo::CrearMundo(int cantBloques) {
	
	Tierra1.resize(cantBloques);
	
	y.resize(cantBloques);
	
	enemigos.resize(cantBloques);
	
	this->cantBloques = cantBloques;
	for(int i=0;i<cantBloques;i++) {
		
		
		int plat_salto = (rand()%5 );
		
		int alt_plat = (rand()%2 );
		if (i > 9){
			for(int j=i-5;j<i;j++) { 
				if (y[j]< 672){
					if (plat_salto <= 1){
						y[i]= ((rand()%4 )+ 1 )*96;
					}
					else{
						//y[i]=576; // 6
						y[i]=672; // 7
					}
				}
				else{
					if (plat_salto <=  1){
						
						y[i]= (alt_plat+4)*96;
					}
					else{
						//y[i]=576;
						y[i]=672;
					}
					
				}
			}
			
		}else y[i]=672;
		/*
		y[0]=672;
		y[1]=672;
		y[2]=672;
		y[3]=672;
		y[4]=672;
		y[5]=672;
		y[6]=672;
		y[7]=672;
		y[8]=672;
		y[9]=672;
		*/
		/*
		y[10]= alt_plat;
		y[11]=288;
		y[ 15 ]=288;
		y[16]=288;
		y[20]=288;
		y[21]=288;
		y[22]=288;
		y[23]=288;
		y[26]=288;
		y[27]=288;
		*/
		
	Tierra1[i].Start("Tierra2.png");
	Tierra1[i].setPos(i*96,y[i]);

	
	
	
}
}
void CrearMundo::setMov(int x){
	for(int j=0;j<cantBloques;j++) { 
		Tierra1[j].setPos(j*96+x*10,y[j]);
		
		
		
	
	}
}

vector<int> CrearMundo::Pos_Enemigos(){return enemigos;}


Sprite CrearMundo::getSpr2(int i){return Tierra1[i].getSpr();}
//FloatRect CrearMundo::Colide(int i){FloatRect r1 =Tierra1[i].getSpr().getGlobalBounds(); return r1;}
Rect<int> CrearMundo::Colide(int i){Rect <int> A(Tierra1[i].getX(),Tierra1[i].getY(),96,96);return A;}
