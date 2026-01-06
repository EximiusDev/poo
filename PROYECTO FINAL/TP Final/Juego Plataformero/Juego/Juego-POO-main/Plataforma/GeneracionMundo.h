#ifndef GeneracionMundo_h
#define GeneracionMundo_h
#include "TipoBloque.h"
#include <vector>
using namespace std;

class GeneracionMundo {
private:
	vector<vector<int>>I; ///Creo la matriz de aleatoriedad
	vector<vector<TipoBloque>>J; ///Creo la matriz de bloques
public:
	GeneracionMundo();///Aca le doy el tamanio y los lleno con datos random
	
	
};

#endif

