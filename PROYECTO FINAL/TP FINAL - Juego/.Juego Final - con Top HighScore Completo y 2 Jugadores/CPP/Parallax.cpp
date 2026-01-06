#include "../H/Parallax.h"

//#include "..\H\Parallax.h"
Parallax::Parallax(){
	background_Images.resize(12);
	for(int i=0;i<6;i++) { 
		string Name1="./Textures/B";
		string Name2=to_string(i+1);
		string Name3=".png";
		string Name4=Name1+Name2+Name3;
		background_Images[i].Init(Name4);
	}
	
}
void Parallax::Update(int velocity){
	for(int i=0;i<6;i++){background_Images[i].Update(i*velocity);
	}
}
void Parallax::Draw(RenderWindow &win){
	for(int i=0;i<6;i++){
		background_Images[i].Draw(win);
		
	}
}
