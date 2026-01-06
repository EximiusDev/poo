
#include "../H/Bloque.h"
#include "../H/Object.h"

Bloque::Bloque():Object(){
	spr.setScale(scaleG);
	
}

void Bloque::Update(int i){
	spr.move(speedG.x*-i,speedG.y);
	positionG.x+=speedG.x*-i;
	if(positionG.x<=-16*scaleG.x){
		spr.setPosition(1920,positionG.y);
		positionG.x=1920;
	}
	
}
void Bloque::Init(string name,int i,int Pl){ ///Pl indica el el numero de plataforma
	
	tex.loadFromFile(name);
	spr.setTexture(tex);
	///{i*200,900}
	positionG={i*100,450};
	spr.setPosition(positionG);
	 ///Estos valores dependen de la resolucion para hacer que dejen de ser valores magicos debemos calcular el cambio de resolucion en "object" (Solo para valores menores a 6)
		
}
