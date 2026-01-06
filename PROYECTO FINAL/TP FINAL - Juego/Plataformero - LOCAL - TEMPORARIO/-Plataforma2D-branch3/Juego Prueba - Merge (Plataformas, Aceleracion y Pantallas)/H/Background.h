#ifndef BACKGROUND_H
#define BACKGROUND_H
//#include "../H/Object.h"
#include <vector>
#include "Object.h"
using namespace std;

class Background:public Object{
	
	
private:
	FloatRect r1;
public:
	Background();
	void Update(int i);
	void Init(string name);
	
	
};

#endif
