#ifndef SCENE_PAUSE_H
#define SCENE_PAUSE_H
#include "Scene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Scene_Pause : public Scene {
public:
	Scene_Pause();
	void Update (Game & playgame,RenderWindow & win) override;
	void Draw (sf::RenderWindow & win) override;
	void InputEvents (Event & event) override;
private:
	Font m_font;
	Text txt_button_menu, txt_button_play;
	Texture Tex;
	Sprite Spr;
};

#endif

