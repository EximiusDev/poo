#ifndef CREARMUNDO_H
#define CREARMUNDO_H
#include <vector>
#include "Bloques.h"
using namespace std;

class CrearMundo {
private:
	vector<Bloques>Tierra;
	vector<Bloques>Tierra1;
	int cantBloques;
	
public:
	CrearMundo(int cantBloques);
	void setMov(int x);
	Sprite getSpr1(int i);
	Sprite getSpr2(int i);
};

#endif

