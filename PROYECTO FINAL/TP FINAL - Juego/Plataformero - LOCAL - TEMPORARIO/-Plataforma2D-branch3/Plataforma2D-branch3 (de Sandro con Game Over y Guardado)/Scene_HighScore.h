#ifndef SCENE_HIGHSCORE_H
#define SCENE_HIGHSCORE_H
#include "H/Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene_HighScore.h"
#include "H/Game.h"
#include <SFML/Graphics/RenderWindow.hpp>



#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Mouse.hpp>
using namespace sf;
using namespace sf;
using namespace std;
class Scene_HighScore:public Scene {
public:
	Scene_HighScore();
	
	void Update (Game & playgame, RenderWindow & win) override;
	void Draw (RenderWindow & win) override;
	void InputEvents (Event & event) override {};
private:
};

#endif

