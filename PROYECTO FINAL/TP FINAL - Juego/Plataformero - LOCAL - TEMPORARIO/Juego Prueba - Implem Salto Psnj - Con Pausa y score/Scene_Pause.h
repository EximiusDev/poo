#ifndef SCENE_PAUSE_H
#define SCENE_PAUSE_H
#include "Scene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class Scene_Pause : public Scene {
public:
	Scene_Pause();
	void Update (Game & playgame) override;
	void Draw (sf::RenderWindow & win) override;
	void InputEvents (Event & event) override;
private:
	Font m_font;
	Text txt_button_menu, txt_button_play;
};

#endif

