
#include "../H/Platform.h"
///Aca hay que hacerlo con puntero
///Podemos hacer que apraezcan con un timer
Platform::Platform() {
	cant_bloq_plat_y = 3;
	cant_bloq_plat = 24; /// maximo 32 = 16*2 =8*4 : es decir 4 plataformas predise�as mostrandose todo el tiempo
	
	Plat0.resize(16);
	Plat1.resize(cant_bloq_plat);
	Plat2.resize(32);
	
	string Name4="./Textures/Tierra.png";
	/*for(int i=0;i<cant_bloq_plat;i++) { 
	string Name1="./Textures/Tierra";
	string Name2=to_string(1);
	string Name3=".png";
	string Name4=Name1+Name3;
	//Plat0[i].Init(Name4,i,8);
	Plat1[i].Init(Name4,i);
	//Plat2[i].Init(Name4,i,6);
	}*/
	//Texture textu;
	textu.loadFromFile(Name4);
	
	
	for(int j=0;j< cant_bloq_plat_y;j++) { 
		for(int i=0;i<this->Get_cant_bloq_plat(j);i++) {
			switch(j){
			case 0:
				Plat0[i].Init(textu,i,3);
				break;
			case 1:
				Plat1[i].Init(textu,i,6);
				break;
			case 2:
				Plat2[i].Init(textu,i,7);
				break;
			default:
				Plat1[i].Init(textu,i);
			}
		}
	}
}
void Platform::Update(Vector2f Velocity){
	/*
	for(int i=0;i<cant_bloq_plat;i++) { 
	Plat0[i].Update( 3 ); /// Velocidad (speed = -1* 3)
	Plat1[i].Update( 3 ); /// Velocidad (speed = -1* 3)
	Plat2[i].Update( 3 ); /// Velocidad (speed = -1* 3)
}*/
	if(Timer.getElapsedTime().asMilliseconds()>=500){
		Velocity.x=2;
		Timer.restart();
	}
	for(int j=0;j< cant_bloq_plat_y;j++) { 
		for(int i=0;i<this->Get_cant_bloq_plat(j);i++) {
			switch(j){
			case 0:
				Plat0[i].Update( Velocity.x ); /// Velocidad (speed = -1* 3)
				break;
			case 1:
				Plat1[i].Update( Velocity.x ); /// Velocidad (speed = -1* 3)
				break;
			case 2:
				Plat2[i].Update( Velocity.x ); /// Velocidad (speed = -1* 3)
				break;
			default:
				Plat1[i].Update( Velocity.x); /// Velocidad (speed = -1* 3)
			}
		}
	}
}
/*
Bloque Platform::getBloq(int i){
return Plat1[i];
}*/
Bloque Platform::getBloq(int i, int num_bloq_y){
	switch(num_bloq_y){
	case 0:
		return Plat0[i];
		//break;
	case 1:
		return Plat1[i];
		//break;
	case 2:
		return Plat2[i];
		//break;
	default:
		return Plat1[i];
	}
	
}

void Platform::Draw(RenderWindow & win){
	for(int j=0;j< cant_bloq_plat_y;j++) { 
		for(int i=0;i<this->Get_cant_bloq_plat(j);i++) {
			switch(j){
			case 0:
				Plat0[i].Draw(win);
				break;
			case 1:
				Plat1[i].Draw(win);
				break;
			case 2:
				Plat2[i].Draw(win);
				break;
			default:
				Plat1[i].Draw(win);
			}
		}
	}
	/*
	for(int i=0;i< cant_bloq_plat;i++) { 
	Plat0[i].Draw(win);
	Plat1[i].Draw(win);
	Plat2[i].Draw(win);
	
	}*/
}
int Platform::Get_cant_bloq_plat(int i){
	switch(i){
	case 0:
		return Plat0.size();
		//break;
	case 1:
		return Plat1.size();
		//break;
	case 2:
		return Plat2.size();
		//break;
	default:
		return cant_bloq_plat;
	}
}
int Platform::Get_cant_bloq_plat_y(){
	return cant_bloq_plat_y;
}
