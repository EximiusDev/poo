#ifndef MAINMENU_H
#define MAINMENU_H
#include "Scene.h"
#include "Button.h"

class MainMenu : public Scene {
public:
	MainMenu(RenderWindow &window, class Menu &menu);
	void InputEvents (Event & event) override;
	void Update (Game & game, float delta) override;
	void Draw (RenderWindow & window) override;
	
	bool GetActive(){return isActive;}
	void SetActive(bool active){isActive = active;}
	
	void SetSpritesSize();
	void UpdateVolume(int i);
private:
	bool isActive;
	Menu* p_Menu;
	
	Button background_button;
	Button play_button;
	Button options_button;
	Button exit_button;
	
	SoundBuffer interact_buffer;
};

#endif

