#ifndef PLATFORM_H
#define PLATFORM_H
#include "Bloque.h"

class Platform {
public:
	Platform();
	void Draw(RenderWindow & win);
	void Update();
	Bloque getBloq(int i);
private:
	vector<Bloque>Plat1;
	
	
	
};

#endif

