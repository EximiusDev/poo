#ifndef PRESET_PLATFORM_H
#define PRESET_PLATFORM_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Preset_Platform{
private:
	//vector<vector<string>>MatrizBloq;
	vector<vector<int>>MatrizBloq;
	//vector<vector<char>>MatrizBloq;
	vector<string>Preset_Platform_Plat;
	int num_plat = 0;
	int tamanio = 8;
	int tamanio_x = 8;
	int tamanio_y = 9;
	void str_to_int();
	int tam_tot_x  = 24;
	vector<int> currents_plat;
public:
	Preset_Platform();
	Preset_Platform(int num_plat);
	//int VerTipoBloq(int x, int y);
	string VerEsquemaBloq(int x, int y);
	int VerTipoBloq(int x, int y);
	
	void Set_Predet_Plat(int num_plat);
	
	int VerTamanio_x(){return Preset_Platform_Plat[0].size();}
	int VerTamanio_y(){return Preset_Platform_Plat.size();}
};
#endif

