#ifndef BLOQUE_H
#define BLOQUE_H
#include "Object.h"

class Bloque:public Object{
private:
	
public:
	Bloque();
	void Update(int i);
	void Init(string name,int i,int Pl);
};

#endif

