#ifndef SCENE_GAMEOVER_H
#define SCENE_GAMEOVER_H
#include "H/Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>
using namespace sf;
using namespace std;
class Scene_GameOver :public Scene {
public:
	Scene_GameOver();
	void Update (Game & playgame, RenderWindow & win) override;
	void Draw (RenderWindow & win) override;
	
	void InputEvents (Event & event) override {};
	int SaveAndLoad(int score);
private:
	vector<Texture>Tex;
	vector<Sprite>Spr;
	
	Mouse Arrow;
	Vector2i r1;
};

#endif

