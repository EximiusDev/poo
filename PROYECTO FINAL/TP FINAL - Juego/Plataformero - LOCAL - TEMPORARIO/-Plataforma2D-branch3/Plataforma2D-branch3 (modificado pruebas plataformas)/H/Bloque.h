#ifndef BLOQUE_H
#define BLOQUE_H
#include "Object.h"

class Bloque:public Object{
private:
	const int cant_pixeles = 24;
	int tamanio_pixeles = resolutionG.x/16;
public:
	Bloque();
	void Update(int i);
	void Init(string name,int i,int j = 7);
};

#endif

