#include "Match.h"

Match::Match(RenderWindow & window, Game & game) : gameManager(window, game), playerOne(window, game,gameManager), userInterface(window)
{
	p_window = &window;
	p_window->setMouseCursorVisible(false);
	
	ground_tex.loadFromFile("Textures/ground.png");
	ground_spr.setTexture(ground_tex);
	
	cursor_tex.loadFromFile("Textures/mouse.png");
	cursor_spr.setTexture(cursor_tex);
	
	SetSpritesSize();
	
	spawnManager.Startup(playerOne, window, gameManager, userInterface, game);
	playerOne.Startup(userInterface);
	
	gameTheme_buffer.loadFromFile("Sounds/GameTheme.wav");
	gameTheme_sound.setBuffer(gameTheme_buffer);
	gameTheme_sound.setVolume(game.getVolume());
	gameTheme_sound.play();
	gameTheme_sound.setLoop(true);
}

Match::~Match()
{
	gameTheme_sound.stop();
}

void Match::InputEvents (Event & event) 
{
	playerOne.InputEvents(event);
}

void Match::Update (Game & game, float delta) 
{
	playerOne.Update(game, delta);
	spawnManager.Update(game, delta);
	userInterface.Update(game, delta);
	
	Vector2i mousePos = Mouse::getPosition(*p_window);
	cursor_spr.setPosition(mousePos.x, mousePos.y);
	gameManager.Update(game, delta);
}

void Match::Draw (RenderWindow & window) 
{
	window.draw(ground_spr);
	
	spawnManager.Draw(window);
	playerOne.Draw(window);
	userInterface.Draw(window);
	
	window.draw(cursor_spr);
}

void Match::SetSpritesSize()
{
	// get window resolution
	Vector2u windowSize = p_window->getSize();
	Vector2f defaultScale = {windowSize.x /426.0f , windowSize.y /240.0f};
	
	// Set Scale
	ground_spr.setScale(defaultScale);
	cursor_spr.setScale(defaultScale);
	
	// Set Origin in center
	ground_spr.setOrigin(ground_spr.getLocalBounds().width/2,ground_spr.getLocalBounds().height/2);
	cursor_spr.setOrigin(cursor_spr.getLocalBounds().width/2,cursor_spr.getLocalBounds().height/2);

	// Set Position
	ground_spr.setPosition(windowSize.x/2, windowSize.y/2);
}
