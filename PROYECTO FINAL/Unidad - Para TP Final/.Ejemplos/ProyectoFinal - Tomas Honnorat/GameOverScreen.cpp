#include "GameOverScreen.h"
#include "Menu.h"
#include <fstream>
using namespace std;


GameOverScreen::GameOverScreen(RenderWindow & window, int currentScore,  Game& game) : 
	menu_button(window, "Textures/Button.png","RetroGaming.ttf", "Main Menu", -150, 0),
	exit_button(window, "Textures/Button.png","RetroGaming.ttf", "Exit", 150, 0)
{
	p_game = &game;
	p_window = &window;
	p_window->setMouseCursorVisible(true);

	// Fonts
	mainFont.loadFromFile("RetroGaming.ttf");
	
	currentScore_text.setFont(mainFont);
	highScore_text.setFont(mainFont);
	
	// Textures
	background_tex.loadFromFile("Textures/BackgroundStatic.png");
	midleground_tex.loadFromFile("Textures/midleground.png");
	
	background_spr.setTexture(background_tex);
	midleground_spr.setTexture(midleground_tex);
	
	
	SetSpriteSize(currentScore, SaveAndLoad(currentScore));
	
	succes_buffer.loadFromFile("Sounds/Confirm.wav");
	succes_sound.setBuffer(succes_buffer);
	
	interact_buffer.loadFromFile("Sounds/MenuMove.wav");
	
	menu_button.UpdateVolume(game.getVolume());
	exit_button.UpdateVolume(game.getVolume());
	
	menu_button.Startup(interact_buffer);
	exit_button.Startup(interact_buffer);
}

void GameOverScreen::InputEvents (Event & event) 
{
	if(event.type == Event::MouseButtonPressed)
	{
		if(Mouse::isButtonPressed(Mouse::Left) && menu_button.IsMouseOnButton())
		{
			succes_sound.play();
			p_game->SetScene(new Menu(*p_window, *p_game));
		}
		
		if(Mouse::isButtonPressed(Mouse::Left) && exit_button.IsMouseOnButton())
		{
			p_game->CloseGame();
		}
	} 
}

void GameOverScreen::Update (Game & game, float delta) 
{
	menu_button.Update(game, delta);
	exit_button.Update(game, delta);
}

void GameOverScreen::Draw (RenderWindow & window) 
{
	window.draw(background_spr);
	window.draw(midleground_spr);
	
	window.draw(currentScore_text);
	window.draw(highScore_text);
	
	menu_button.Draw(window);
	exit_button.Draw(window);
}

void GameOverScreen::SetSpriteSize(int currentScore, int highscore)
{
	
	// get window resolution
	Vector2u windowSize = p_window->getSize();
	Vector2f defaultScale = {windowSize.x /426.0f , windowSize.y /240.0f};
	
	// Set Scale
	background_spr.setScale(defaultScale);
	midleground_spr.setScale(defaultScale);
	
	// Set Origin in center
	background_spr.setOrigin(background_spr.getLocalBounds().width/2, background_spr.getLocalBounds().height/2);
	midleground_spr.setOrigin(midleground_spr.getLocalBounds().width/2, midleground_spr.getLocalBounds().height/2);
	
	// Set Position
	background_spr.setPosition(windowSize.x/2, windowSize.y/2);
	midleground_spr.setPosition(windowSize.x/2, windowSize.y/2);
	
	
	string score = to_string(currentScore);
	string hscore = to_string(highscore);
	
	//Set Text
	currentScore_text.setString("Score : " + score + " Kills");
	highScore_text.setString("Highscore : " + hscore + " Kills");

	// set Color
	currentScore_text.setFillColor({245,229,166});
	highScore_text.setFillColor({245,229,166});

	// Set Size
	currentScore_text.setCharacterSize((windowSize.x*32/1280)); 
	highScore_text.setCharacterSize((windowSize.x*32/1280));

	// Set Origin in center
	currentScore_text.setOrigin(currentScore_text.getLocalBounds().width/2 ,currentScore_text.getLocalBounds().height/2);
	highScore_text.setOrigin(highScore_text.getLocalBounds().width/2 ,highScore_text.getLocalBounds().height/2);
	
	// Set position
	currentScore_text.setPosition(windowSize.x/2, windowSize.y/2 - (windowSize.y * 160)/ 720.0f);
	highScore_text.setPosition(windowSize.x/2, windowSize.y/2 - (windowSize.y * 100)/ 720.0f);
}

int GameOverScreen::SaveAndLoad(int score)
{
	int highscore;
	
	ifstream in_archi("SaveData.dat", ios::binary);
	
	if(!in_archi.is_open())
	{
		ofstream out_archi("SaveData.dat", ios::binary);
		out_archi.write(reinterpret_cast<char*>(&score),sizeof(score));
		highscore = score;
		out_archi.close();
	} else
	{
		in_archi.seekg(0);
		in_archi.read(reinterpret_cast<char*>(&highscore),sizeof(highscore));
		in_archi.close();	
		
		if(score > highscore)
		{
			ofstream out_archi("SaveData.dat", ios::binary);
			out_archi.seekp(0);
			out_archi.write(reinterpret_cast<char*>(&score),sizeof(score));
			highscore = score;
			out_archi.close();
		}
	}
	
	return highscore;
}

