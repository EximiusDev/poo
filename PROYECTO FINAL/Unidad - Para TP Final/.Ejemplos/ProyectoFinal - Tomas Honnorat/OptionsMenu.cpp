#include "OptionsMenu.h"
#include <iostream>
#include "Menu.h"



OptionsMenu::OptionsMenu(RenderWindow &window, Menu &menu) : isActive(false), 
	
	background_button(window, "Textures/OptionsBackground.png","RetroGaming.ttf", "", 0,0),
	
	windowMode_button(window, "Textures/LargeButton.png","RetroGaming.ttf", "Window Mode", -280,78),
	resolution_button(window, "Textures/LargeButton.png","RetroGaming.ttf", "Resolution", 0, 78),
	volume_button(window, "Textures/LargeButton.png","RetroGaming.ttf", "Volume", 280 , 78),
	
	fullscreen_button(window, "Textures/Button.png","RetroGaming.ttf", "Fullscreen", -280, 28),
	windowed_button(window, "Textures/Button.png","RetroGaming.ttf", "Windowed", -280 , -20),
	
	res1_button(window, "Textures/Button.png","RetroGaming.ttf", "1920 x 1080", 0 , 28),
	res2_button(window, "Textures/Button.png","RetroGaming.ttf", "1600 x 900", 0 , -20),
	res3_button(window, "Textures/Button.png","RetroGaming.ttf", "1280 x 720", 0 , -68),
	
	back_button(window, "Textures/Button.png","RetroGaming.ttf", "Back", 280 , -68),
	
	decrease_button(window, "Textures/miniButton.png","RetroGaming.ttf", "<<", 180 , 28),
	increase_button(window, "Textures/miniButton.png","RetroGaming.ttf", ">>", 380 , 28)
{
	p_window = &window;
	windowSize = p_window->getSize();
	p_Menu = &menu;
	
	main_font.loadFromFile("RetroGaming.ttf");
	UpdateSizeTextVolume();
	
	interact_buffer.loadFromFile("Sounds/MenuMove.wav");
	
	fullscreen_button.Startup(interact_buffer);
	windowed_button.Startup(interact_buffer);
	
	res1_button.Startup(interact_buffer);
	res2_button.Startup(interact_buffer);
	res3_button.Startup(interact_buffer);
	
	back_button.Startup(interact_buffer);
	
	decrease_button.Startup(interact_buffer);
	increase_button.Startup(interact_buffer);
}

void OptionsMenu::InputEvents (Event & event) 
{
	if(isActive){
		
		if(event.type == Event::MouseButtonPressed)
		{
			if(Mouse::isButtonPressed(Mouse::Left) && fullscreen_button.IsMouseOnButton())
			{
				p_Menu->Fullscreen();
				p_Menu->SetSpritesSize();
				p_Menu->playSuccesSound();
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) && windowed_button.IsMouseOnButton())
			{
				p_Menu->Windowed();
				p_Menu->SetSpritesSize();
				p_Menu->playSuccesSound();
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) && res1_button.IsMouseOnButton())
			{
				Vector2u v = {1920, 1080};
				p_Menu->ChangeResolution(v);
				p_Menu->SetSpritesSize();
				p_Menu->playSuccesSound();
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) && res2_button.IsMouseOnButton())
			{
				Vector2u v = {1600, 900};
				p_Menu->ChangeResolution(v);
				p_Menu->SetSpritesSize();
				p_Menu->playSuccesSound();
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) && res3_button.IsMouseOnButton())
			{
				Vector2u v = {1280, 720};
				p_Menu->ChangeResolution(v);
				p_Menu->SetSpritesSize();
				p_Menu->playSuccesSound();
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) && back_button.IsMouseOnButton())
			{
				p_Menu->Back();
				p_Menu->playSuccesSound();
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) && decrease_button.IsMouseOnButton())
			{
				p_Menu->UpdateVolume(-1);
				p_Menu->playSuccesSound();
			}
			
			if(Mouse::isButtonPressed(Mouse::Left) && increase_button.IsMouseOnButton())
			{
				p_Menu->UpdateVolume(1);
				p_Menu->playSuccesSound();
			}
		} 
		
	}
}

void OptionsMenu::Update (Game & game, float delta)
{
	if(isActive)
	{
		// Buttons Updates
		fullscreen_button.Update(game, delta);
		windowed_button.Update(game, delta);
		
		res1_button.Update(game, delta);
		res2_button.Update(game, delta);
		res3_button.Update(game, delta);
		
		back_button.Update(game, delta);
		
		decrease_button.Update(game, delta);
		increase_button.Update(game, delta);
	}

}

void OptionsMenu::Draw (RenderWindow & window) 
{
	if(isActive)
	{
		background_button.Draw(window);
		
		windowMode_button.Draw(window);
		resolution_button.Draw(window);
		volume_button.Draw(window);
		
		fullscreen_button.Draw(window);
		windowed_button.Draw(window);
		
		res1_button.Draw(window);
		res2_button.Draw(window);
		res3_button.Draw(window);
		
		back_button.Draw(window);
		
		decrease_button.Draw(window);
		increase_button.Draw(window);
		
		window.draw(volume_text);
	}
}

void OptionsMenu::SetSpritesSize()
{
	background_button.SetSprites();
	
	windowMode_button.SetSprites();
	resolution_button.SetSprites();
	volume_button.SetSprites();
	
	fullscreen_button.SetSprites();
	windowed_button.SetSprites();
	
	res1_button.SetSprites();
	res2_button.SetSprites();
	res3_button.SetSprites();
	
	back_button.SetSprites();
	
	decrease_button.SetSprites();
	increase_button.SetSprites();
	
	UpdateSizeTextVolume();
}

void OptionsMenu::UpdateVolume(int i)
{
	
	fullscreen_button.UpdateVolume(i);
	windowed_button.UpdateVolume(i);
	
	res1_button.UpdateVolume(i);
	res2_button.UpdateVolume(i);
	res3_button.UpdateVolume(i);
	
	back_button.UpdateVolume(i);
	
	decrease_button.UpdateVolume(i);
	increase_button.UpdateVolume(i);
	
	updateTextVolume(i);

}

void OptionsMenu::updateTextVolume(int v)
{
	string s = to_string(v);
	volume_text.setFont(main_font);
	//Set Text
	volume_text.setString(s);
	UpdateSizeTextVolume();
}

void OptionsMenu::UpdateSizeTextVolume()
{
	windowSize = p_window->getSize();
	
	
	float xOff = (windowSize.x * 280)/ 1280.0f;
	float yOff = (windowSize.y * 32) / 720.0f;
	
	// set Color
	volume_text.setFillColor({245,229,166});
	// Set Size
	volume_text.setCharacterSize((windowSize.x/64)); 
	// Set Origin in center
	volume_text.setOrigin(volume_text.getLocalBounds().width/2 ,volume_text.getLocalBounds().height/2);
	// Set position
	volume_text.setPosition(windowSize.x/2 + xOff, windowSize.y/2 - yOff);
}
