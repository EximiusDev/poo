#ifndef MENU_H
#define MENU_H

#include "Scene.h"
#include "MainMenu.h"
#include "OptionsMenu.h"
#include "MenuBackground.h"

class Menu : public Scene {
public:
	Menu(RenderWindow &window, Game & game);
	void InputEvents(Event &event)override;
	void Update (Game & game, float delta) override;
	void Draw (sf::RenderWindow & window) override;

	void ChangeResolution(Vector2u newSize);
	void Fullscreen();
	void Windowed();
	
	void StartGame();
	void Options();
	void Exit();
	void Back();
	
	void UpdateVolume(int i);
	void playSuccesSound();
	
	void SetSpritesSize();
private:
	bool isFullscreen;
	Game * p_game;
	
	MenuBackground background;
	
	MainMenu mainMenu;
	OptionsMenu optionsMenu;
	
	SoundBuffer succes_buffer;
	Sound succes_sound;
	
	SoundBuffer mainTheme_buffer;
	Sound mainTheme_sound;
};

#endif

