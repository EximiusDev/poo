#ifndef TEXTO_H
#define TEXTO_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
//#include "Scene.h"
#include <string>

using namespace std;
using namespace sf;

class Texto {
private:
	Font m_font;
	Text m_texto1, m_texto2;
	string Nom1, Nom2;
public:
	Texto();
	void Dibujar_Pant(RenderWindow & window);
	Text Get_Texto();
	void Set_oracion(string Nom1 );
};

#endif

