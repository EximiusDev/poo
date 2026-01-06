
#include "../H/Plataform.h"
///Aca hay que hacerlo con puntero
///Podemos hacer que apraezcan con un timer
Plataform::Plataform() {
	Plat1.resize(7);
	

	for(int i=0;i<7;i++) { 
		string Name1="vTierra";
		string Name2=to_string(1);
		string Name3=".png";
		string Name4=Name1+Name2+Name3;
		Plat1[i].Init(Name4,i,1);
		
	
	}
}
void Plataform::Update(){
	for(int i=0;i<7;i++) { 
		Plat1[i].Update(3);
		
	}
}
Bloque Plataform::getBloq(int i){
	return Plat1[i];
}

void Plataform::Draw(RenderWindow & win){
	for(int i=0;i<7;i++) { 
		Plat1[i].Draw(win);
		
	}
	
}
