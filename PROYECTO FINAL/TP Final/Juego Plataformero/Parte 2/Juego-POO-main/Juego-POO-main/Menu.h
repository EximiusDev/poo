#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;
class Menu {
private:
	Texture MenuT;
	Sprite MenuS;
	Texture NuevoJuegoT;
	Sprite NuevoJuegoS;
	Texture SalirT;
	Sprite SalirS;
	Texture ContinuarT;
	Sprite ContinuarS;
public:
	Menu();
	Sprite Men();
	Sprite NuevoJuego();
	Sprite Continuar();
	Sprite Salir();
	void ColNJ(int a,int b,int c);
	void ColC(int a,int b,int c);
	void ColS(int a,int b,int c);
};

#endif

