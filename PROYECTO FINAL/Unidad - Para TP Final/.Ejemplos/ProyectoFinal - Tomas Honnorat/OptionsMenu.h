#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H
#include "Scene.h"
#include "Button.h"

class OptionsMenu : public Scene {
public:
	OptionsMenu(RenderWindow &window, class Menu &menu);
	void InputEvents (Event & event) override;
	void Update (Game & game, float delta) override;
	void Draw (RenderWindow & window) override;
	
	bool GetActive(){return isActive;}
	void SetActive(bool active){isActive = active;}
	
	void SetSpritesSize();
	void UpdateVolume(int i);
	void updateTextVolume(int v);
	void UpdateSizeTextVolume();
private:
	bool isActive;
	Menu* p_Menu;
	
	Button background_button;
	
	Button windowMode_button;
	Button resolution_button;
	Button volume_button;
	
	Button fullscreen_button;
	Button windowed_button;
	
	Button res1_button;
	Button res2_button;
	Button res3_button;
	
	Button back_button;
	
	Button decrease_button;
	Button increase_button;
	
	Font main_font;
	Text volume_text;
	
	SoundBuffer interact_buffer;
};

#endif

