#include "MenuBackground.h"

MenuBackground::MenuBackground(RenderWindow & window) 
{
	p_window = &window;
	
	background_tex.loadFromFile("Textures/Background.png");
	foreground_tex.loadFromFile("Textures/foreground.png");
	background_spr.setTexture(background_tex);
	foreground_spr.setTexture(foreground_tex);
	
	SetSpritesSize();
}

void MenuBackground::InputEvents (Event & event) 
{
	
}

void MenuBackground::Update (Game & game, float delta) 
{
	float t = clk.getElapsedTime().asSeconds();
	
	background_spr.setPosition( p_window->getSize().x/2 + (sin(t*0.45)*70 *p_window->getSize().x )/1280, background_spr.getPosition().y);
}

void MenuBackground::Draw (RenderWindow & window) 
{
	window.draw(background_spr);
	
	window.draw(foreground_spr);
}

void MenuBackground::SetSpritesSize()
{
	auto windowSize = p_window->getSize();
	
	// Set Scale
	background_spr.setScale(windowSize.x / 426.0f, windowSize.y / 240.0f);
	foreground_spr.setScale(windowSize.x / 426.0f, windowSize.y / 240.0f);
	
	//Set Origin
	background_spr.setOrigin(background_spr.getLocalBounds().width/2,background_spr.getLocalBounds().height/2);
	foreground_spr.setOrigin(foreground_spr.getLocalBounds().width/2, foreground_spr.getLocalBounds().height/2);
	
	// Set Position
	background_spr.setPosition(windowSize.x/2, windowSize.y/2);
	foreground_spr.setPosition(windowSize.x/2, windowSize.y/2);
	

}

