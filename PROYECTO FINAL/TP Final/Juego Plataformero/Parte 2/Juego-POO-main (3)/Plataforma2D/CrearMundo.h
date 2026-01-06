#ifndef CREARMUNDO_H
#define CREARMUNDO_H
#include <vector>
#include "Bloques.h"
#include <SFML/Graphics/Rect.hpp>
using namespace std;
using namespace sf;
class CrearMundo {
private:

	vector<Bloques>Tierra1;
	vector<int>y;
	//vector<int>alt_plat;
	
	int cantBloques;
	
public:
	CrearMundo(int cantBloques);
	void setMov(int x);
	Sprite getSpr2(int i);
	Rect<int> Colide(int i);
};

#endif

