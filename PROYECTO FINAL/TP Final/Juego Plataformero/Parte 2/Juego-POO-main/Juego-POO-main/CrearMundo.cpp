#include "CrearMundo.h"
#include <vector>
#include "Bloques.h"

#include "Enemigo.h"

using namespace std;

CrearMundo::CrearMundo(int cantBloques) {
	
	Tierra1.resize(cantBloques);
	
	y.resize(cantBloques);
	
	enemigos.resize(cantBloques, -1);
	Enemigos_Spr.resize(cantBloques);
	
	this->cantBloques = cantBloques;
	for(int i=0;i<cantBloques;i++) {
		
		
		int plat_salto = (rand()%5 );
		
		int alt_plat = (rand()%2 );
		
		bool plat6 = false;
		//int alt_plat;
		
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
		plat6 = true;
		for(int j=i-3;j<i+3;j++) { 
			//y[i-3] = alt_plat;
			if (y[j] != y[i-3]) plat6 = false;
		}
		if (plat6 == true)  enemigos[i] = y[i];
		//if (plat6 == true)  enemigos[i] = y[i]+ 96;
		plat6 = true;
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
		
		Enemigos_Spr[i].Crear_Spr("sfml.png");
		if(enemigos[i] != -1) Enemigos_Spr[i].Set_Pos_Spr(i*96,y[i]);
		Enemigos_Spr[i].setScale(4,-4); ///
	}
}
void CrearMundo::setMov(int x){
	for(int j=0;j<cantBloques;j++) { 
		Tierra1[j].setPos(j*96+x*10,y[j]);
		
		if(enemigos[j] != -1) Enemigos_Spr[j].Set_Pos_Spr(j*96+x*10,enemigos[j]);
		
	}
}





Sprite CrearMundo::getSpr2(int i){return Tierra1[i].getSpr();}

Sprite CrearMundo::getSpr_En(int i){return Enemigos_Spr[i].get_Spr();}
vector<int> CrearMundo::Ver_Spawn_Enem(){return enemigos;}

//FloatRect CrearMundo::Colide(int i){FloatRect r1 =Tierra1[i].getSpr().getGlobalBounds(); return r1;}
Rect<int> CrearMundo::Colide(int i){Rect <int> A(Tierra1[i].getX(),Tierra1[i].getY(),96,96);return A;}
