#ifndef MENUBACKGROUND_H
#define MENUBACKGROUND_H

#include "Scene.h"

class MenuBackground : public Scene {
public:
	MenuBackground(RenderWindow & window);
	void InputEvents (Event & event)override;
	void Update (Game & game, float delta)override;
	void Draw (RenderWindow & window)override;
	void SetSpritesSize();
private:
	Texture background_tex;
	Sprite background_spr;
	
	Texture foreground_tex;
	Sprite foreground_spr;
	
	Clock clk;
};

#endif

