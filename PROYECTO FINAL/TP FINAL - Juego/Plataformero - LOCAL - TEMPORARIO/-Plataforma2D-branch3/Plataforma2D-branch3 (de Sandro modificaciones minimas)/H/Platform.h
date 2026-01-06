#ifndef PLATFORM_H
#define PLATFORM_H
#include "Bloque.h"

class Platform {
public:
	Platform();
	void Draw(RenderWindow & win);
	void Update();
	Bloque getBloq(int i);
	int Get_Cant_Plat();
	
private:
	vector<Bloque>Plat1;
	int cant_plat;
	
	
};

#endif

