#ifndef SCENE_MENU_H
#define SCENE_MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"

#include "Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
using namespace sf;
using namespace std;

class Scene_Menu : public Scene {
public:
	Scene_Menu();
	void Update (Game & playgame) override;
	void Draw (sf::RenderWindow & win) override;
	
	void InputEvents (Event & event) override {};
	//~Scene_Menu();
private:
	Texture textu;
	Sprite spr;
	
	Font m_font;
	Text txt_subtitulo, txt_titulo;
	
	//bool exit = false;
	bool new_scene = false; /// TEMPORAL quitar despues
};

#endif

