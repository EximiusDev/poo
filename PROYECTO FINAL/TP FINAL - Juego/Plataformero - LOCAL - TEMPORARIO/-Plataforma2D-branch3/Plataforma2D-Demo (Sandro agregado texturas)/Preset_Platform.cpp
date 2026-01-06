#include "Preset_Platform.h"

Preset_Platform::Preset_Platform() {
	num_plat = 0;
	currents_plat.resize(3);
	//currents_plat[0] = 0;
	//currents_plat[1] = 1;
	//currents_plat[2] = 2;
	
	
	Preset_Platform_Plat.resize(tamanio_y); /// de 0 a 7
	this->Set_Predet_Plat(num_plat);
}

Preset_Platform::Preset_Platform(int num_plat):num_plat(num_plat){
	currents_plat.resize(3);
	//currents_plat[0] = 0;
	//currents_plat[1] = 1;
	//currents_plat[2] = 2;
	
	
	Preset_Platform_Plat.resize(tamanio_y); /// de 0 a 7
	this->Set_Predet_Plat(num_plat);
}
void Preset_Platform::Set_Predet_Plat(int num_plat){
	this->num_plat = num_plat;
	switch(num_plat){
	case 0:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "OOOOOOOO";
		break;
		
	case 1:
		
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = ".....OO.";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = ".OO.....";
		Preset_Platform_Plat[8] = "........";
		break;
	case 2:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "....O...";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "O......O";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
	case 3:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "...OOO..";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
	case 4:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "..OOO...";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;		
	case 5:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "OOOOOOOO";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
		
	case 6:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "....OOO.";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;		
	case 7:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = ".OOOO...";
		Preset_Platform_Plat[8] = "........";
		break;
	case 8:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = ".OOOO...";
		Preset_Platform_Plat[8] = "........";
		break;
	case 9:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "..OOOO..";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		break;
		
	default:
		//						  "0123456789"
		Preset_Platform_Plat[0] = "........";
		Preset_Platform_Plat[1] = "........";
		Preset_Platform_Plat[2] = "........";
		Preset_Platform_Plat[3] = "........";
		Preset_Platform_Plat[4] = "........";
		Preset_Platform_Plat[5] = "........";
		Preset_Platform_Plat[6] = "........";
		Preset_Platform_Plat[7] = "........";
		Preset_Platform_Plat[8] = "........";
		//break;
	}
	this->str_to_int();
}

string Preset_Platform::VerEsquemaBloq(int x, int y){
	string aux(Preset_Platform_Plat[y],x,1); /// tomo Preset_Platform_Plat[y], que es un string desde la posicion "x" "1" caracter
	return aux;
}
int Preset_Platform::VerTipoBloq(int x, int y){
	return MatrizBloq[y][x];
}

void Preset_Platform::str_to_int(){
	MatrizBloq.resize(tamanio_y);
	
	for(unsigned int i=0;i<MatrizBloq.size();i++) { 
		MatrizBloq[i].resize(tamanio_x);
		for(unsigned int j=0;j<MatrizBloq[i].size();j++) { 
			if(this->VerEsquemaBloq(j,i)==".")MatrizBloq[i][j] = 0;
			else if(this->VerEsquemaBloq(j,i)=="O")MatrizBloq[i][j] = 1;
			//else(this->VerTipoBloq(j,i)==".")MatrizBloq[i][j] = 0;
		}
	}
}

//Preset_Platform::Update(){
/// ACTUALMENTE LO HACE BLOQUE
/* 
if(positionG.x<=-1*resolutionG.x/2){
spr.setPosition(resolutionG.x,positionG.y);
positionG.x=resolutionG.x;
}
*/
/*for(int i=0;i<currents_plat.size();i++) { 
currents_plat[i] = currents_plat[i+1];
currents_plat[currents_plat.size()-1] = rand()%10;
}*/
//currents_plat[0] = 
//}
