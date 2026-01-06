#ifndef CREARMUNDO_H
#define CREARMUNDO_H
#include <vector>
#include "Bloques.h"
#include <SFML/Graphics/Rect.hpp>

#include "Enemigo.h"

using namespace std;
using namespace sf;
class CrearMundo {
private:
	
	vector<Bloques>Tierra1;
	vector<int>y;
	
	vector<int>enemigos;
	vector<Enemigo>Enemigos_Spr;
	
	int cantBloques;
	
public:
	CrearMundo(int cantBloques);
	void setMov(int x);
	Sprite getSpr2(int i);
	Sprite getSpr_En(int i);
	Rect<int> Colide(int i);
	vector<int> Ver_Spawn_Enem();
};

#endif

