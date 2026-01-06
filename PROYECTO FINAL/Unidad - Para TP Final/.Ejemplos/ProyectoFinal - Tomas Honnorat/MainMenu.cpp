#include "MainMenu.h"
#include "Menu.h"

MainMenu::MainMenu(RenderWindow &window, Menu &menu) : isActive(true),
	
	background_button(window, "Textures/MainBackground.png","RetroGaming.ttf", "", -484, -254),
	play_button(window, "Textures/Button.png","RetroGaming.ttf", "Play", -484, -204),
	options_button(window, "Textures/Button.png","RetroGaming.ttf", "Options", -484, -254),
	exit_button(window, "Textures/Button.png","RetroGaming.ttf", "Exit", -484, -304)
{
	p_window = &window;
	windowSize = p_window->getSize();
	p_Menu = &menu;
	
	interact_buffer.loadFromFile("Sounds/MenuMove.wav");
	play_button.Startup(interact_buffer);
	options_button.Startup(interact_buffer);
	exit_button.Startup(interact_buffer);
}

void MainMenu::InputEvents (Event & event) 
{
	if(isActive){
		
		if(event.type == Event::MouseButtonPressed)
		{
			if(Mouse::isButtonPressed(Mouse::Left) && play_button.IsMouseOnButton())
			{
				p_Menu->playSuccesSound();
				p_Menu->StartGame();
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) && options_button.IsMouseOnButton())
			{
				p_Menu->playSuccesSound();
				p_Menu->Options();
				
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) && exit_button.IsMouseOnButton())
			{
				p_Menu->Exit();
			}
		} 
		
	}
}

void MainMenu::Update (Game & game, float delta) 
{
	if(isActive)
	{
		play_button.Update(game, delta);
		options_button.Update(game, delta);
		exit_button.Update(game, delta);
	}
}

void MainMenu::Draw (RenderWindow & window) 
{
	if(isActive)
	{
		background_button.Draw(window);
		play_button.Draw(window);
		options_button.Draw(window);
		exit_button.Draw(window);
	}
}

void MainMenu::SetSpritesSize()
{
	background_button.SetSprites();
	play_button.SetSprites();
	options_button.SetSprites();
	exit_button.SetSprites();

}

void MainMenu::UpdateVolume(int i)
{
	background_button.UpdateVolume(i);
	play_button.UpdateVolume(i);
	options_button.UpdateVolume(i);
	exit_button.UpdateVolume(i);
}
