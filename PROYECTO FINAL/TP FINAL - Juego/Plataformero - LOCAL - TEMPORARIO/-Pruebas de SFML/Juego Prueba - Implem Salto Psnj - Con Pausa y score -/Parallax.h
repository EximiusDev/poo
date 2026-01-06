#ifndef PARALLAX_H
#define PARALLAX_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Background.h"
class Parallax{
public:
	Parallax();
	void Update();
	void Draw(RenderWindow &win);
private:
	vector<Background>background_Images;
	
} ;

#endif
