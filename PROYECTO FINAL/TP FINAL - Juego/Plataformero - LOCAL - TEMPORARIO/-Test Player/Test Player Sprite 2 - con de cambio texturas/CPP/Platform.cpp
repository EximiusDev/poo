
#include "../H/Platform.h"
///Aca hay que hacerlo con puntero
///Podemos hacer que apraezcan con un timer
Platform::Platform() {
	cant_plat = 6;
	Plat1.resize(cant_plat);
	

	for(int i=0;i<cant_plat;i++) { 
		string Name1="./Textures/Tierra";
		string Name2=to_string(1);
		string Name3=".png";
		string Name4=Name1+Name3;
		Plat1[i].Init(Name4,i,1);
		
	
	}
}
void Platform::Update(){
	for(int i=0;i<cant_plat;i++) { 
		Plat1[i].Update(3); /// Ver
		
	}
}
Bloque Platform::getBloq(int i){
	return Plat1[i];
}

void Platform::Draw(RenderWindow & win){
	for(int i=0;i<cant_plat;i++) { 
		Plat1[i].Draw(win);
		
	}
}

int Platform::Get_Cant_Plat(){
	return cant_plat;
}
