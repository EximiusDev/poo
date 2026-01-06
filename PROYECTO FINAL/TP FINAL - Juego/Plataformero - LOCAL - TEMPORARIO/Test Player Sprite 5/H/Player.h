#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window/Keyboard.hpp>
#include "Object.h"
#include <ctime>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace std;
using namespace sf;
class Player: public Object{
private:
	Clock m_clock;
	string Name1;
	int NumAnim=1;
	bool Walking=false;
	bool jumping_Animation=false;
	bool on_Air_Jumping;
	bool on_Air_Falling;
	
	Texture texP;
	Sprite sprP;
	RectangleShape Player_hitbox;
	Vector2f scaleP;
	Vector2f positionP;
	Vector2f margen;
	
	const int cant_pixeles = 24; ///bloque de la hit box
	const int cant_pixeles_x = 155;
	const int cant_pixeles_y = 277;
	int tamanio_pixeles = resolutionG.x/16;
	
public:
	Player();
	void Update(bool on_Air);
	
	//Sprite * Draw_spr();
	void Draw_spr(RenderWindow& win);
	//RectangleShape * Draw_Shape();
};	

#endif

