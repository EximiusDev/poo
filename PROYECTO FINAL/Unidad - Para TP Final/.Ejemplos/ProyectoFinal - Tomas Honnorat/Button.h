#ifndef BUTTON_H
#define BUTTON_H
#include "Scene.h"



class Button : public Scene {
public:
	Button(RenderWindow &window, string fileNameImage, string fileNameFont, string textButton, float x, float y);
	void Startup(SoundBuffer& interact_buffer);
	void InputEvents (Event & event) override;
	void Update (Game & game, float delta) override;
	void Draw (RenderWindow & window) override;
	
	bool IsMouseOnButton();
	void SetSprites();
	void UpdateVolume(int i);
private:
	string buttonText;
	float xPos, yPos;
	
	bool canPlaySound;
	
	Texture button_tex;
	Sprite button_spr;
	
	Font main_font;
	Text title_text;
	
	
	Sound interact_sound;
};

#endif

