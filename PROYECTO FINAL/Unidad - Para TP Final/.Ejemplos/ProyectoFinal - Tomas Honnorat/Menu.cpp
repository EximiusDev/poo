#include "Menu.h"
#include <iostream>
#include "Game.h"
#include "Match.h"
using namespace std;

Menu::Menu(RenderWindow &window, Game & game) : isFullscreen(false), mainMenu(window, *this), optionsMenu(window, *this), background(window)
{
	p_window = &window;
	windowSize = p_window->getSize();
	p_game = &game;
	
	// Sprites
	SetSpritesSize();
	
	// Sounds 
	succes_buffer.loadFromFile("Sounds/Confirm.wav");
	succes_sound.setBuffer(succes_buffer);
	
	// Main Theme
	mainTheme_buffer.loadFromFile("Sounds/MenuTheme.wav");
	mainTheme_sound.setBuffer(mainTheme_buffer);
	mainTheme_sound.play();
	mainTheme_sound.setLoop(true);
	
	UpdateVolume(0);
}

void Menu::InputEvents(Event &event)
{
	mainMenu.InputEvents(event);
	optionsMenu.InputEvents(event);
}

void Menu::Update (Game & game, float delta) 
{
	background.Update(game, delta);
	
	mainMenu.Update(game, delta);
	optionsMenu.Update(game, delta);
}

void Menu::Draw (sf::RenderWindow &window) 
{
	background.Draw(window);
	
	mainMenu.Draw(window);
	optionsMenu.Draw(window);
}

void Menu::SetSpritesSize()
{
	windowSize = p_window->getSize();
	
	background.SetSpritesSize();
	
	optionsMenu.SetSpritesSize();
	mainMenu.SetSpritesSize();
}


void Menu::ChangeResolution(Vector2u newSize)
{
	if(windowSize == newSize)
		return;
	
	if(isFullscreen)
		p_window->create(VideoMode(newSize.x, newSize.y), "Fullscreen" ,Style::Fullscreen);
	else
		p_window->create(VideoMode(newSize.x, newSize.y), "Prototype" ,Style::Default);
	
	
	windowSize = p_window->getSize();
}


void Menu::Fullscreen()
{
	if(isFullscreen)
		return;
	
	p_window->create(VideoMode(windowSize.x, windowSize.y), "Fullscreen", Style::Fullscreen);
	isFullscreen = true;
}

void Menu::Windowed()
{
	if(!isFullscreen)
		return;
	
	p_window->create(VideoMode(windowSize.x, windowSize.y), "Prototype", Style::Default);
	isFullscreen = false;
}

void Menu::StartGame()
{
	mainTheme_sound.stop();
	p_game->SetScene(new Match(*p_window, *p_game));
}

void Menu::Options()
{
	mainMenu.SetActive(false);
	optionsMenu.SetActive(true);
}

void Menu::Exit()
{
	p_game->CloseGame();
}

void Menu::Back()
{
	optionsMenu.SetActive(false);
	mainMenu.SetActive(true);
}

void Menu::playSuccesSound()
{
	succes_sound.play();
}

void Menu::UpdateVolume(int i)
{
	int newVolume = p_game->getVolume() + i;
	
	newVolume = Clamp(newVolume, 0, 100);
	
	p_game->setVolume(newVolume);
	succes_sound.setVolume(newVolume);
	mainTheme_sound.setVolume(newVolume);
	
	optionsMenu.UpdateVolume(newVolume);
	mainMenu.UpdateVolume(newVolume);
}




