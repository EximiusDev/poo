#ifndef PLATFORM_H
#define PLATFORM_H
#include "Bloque.h"

#include <SFML/Graphics/Texture.hpp>
//#include "Preset_Platform.h"
#include "../Preset_Platform.h"

class Platform {
public:
	Platform();
	void Draw(RenderWindow & win);
	
	void Update(int Velocity);
	//void Update(Vector2f Velocity);
	//Bloque getBloq(int i);
	Bloque getBloq(int i, int num_bloq_y = 1);
	int Get_cant_bloq_plat(int i = 1);
	int Get_cant_bloq_plat_y();
	bool Get_block_existence(int i, int j);
	
private:
	vector<Bloque>Plat0;
	vector<Bloque>Plat1;
	vector<Bloque>Plat2;
	vector<Bloque>Plat3;
	vector<Bloque>Plat4;
	vector<Bloque>Plat5;
	vector<Bloque>Plat6;
	vector<Bloque>Plat7;
	vector<Bloque>Plat8;
	int cant_bloq_plat;
	int cant_bloq_plat_y;
	Clock Timer;
	Texture textu;
	Bloque Block_no_colition;
	
	vector<vector<bool>> block_is_active;
	Preset_Platform pSet_Plat;
	Preset_Platform pSet_Plat_aux;
	int num_plat_rand;
};

#endif
