#include "UI.h"

UI::UI(RenderWindow & window) : HealthCount(3), totalTimeTutorial(0), disableTutorialTime(10), tut(true), introEnable(true),
	totalTimeIntro(0), disableTimeIntro(2)
{
	p_window = &window;

	
	heart_tex.loadFromFile("Textures/heart.png");
	heart1_spr.setTexture(heart_tex);
	heart2_spr.setTexture(heart_tex);
	heart3_spr.setTexture(heart_tex);
	
	bulletUI_tex.loadFromFile("Textures/BulletUI.png");
	bulletUI_spr.setTexture(bulletUI_tex);
	
	circle_tex.loadFromFile("Textures/Circle.png");
	circle_spr.setTexture(circle_tex);
	
	mainFont.loadFromFile("RetroGaming.ttf");
	ammo_text.setFont(mainFont);
	kills_text.setFont(mainFont);
	tutorial_text.setFont(mainFont);
	
	SetSpritesSize();
	defaultScale = circle_spr.getScale();
}

void UI::InputEvents (Event & event) 
{
	
}

void UI::Update (Game & game, float delta) 
{
	
	if(tut)
	{
		totalTimeTutorial += delta;
		if(totalTimeTutorial >= disableTutorialTime)
		{
			tutorial_text.setString(" ");
			tut = false;
		}
	}
	
	if(introEnable)
	{
		totalTimeIntro += delta;
		
		Vector2f newScale = {Lerp(defaultScale.x * 20.0f, circle_spr.getScale().x, delta*5),
			Lerp(defaultScale.y * 20.0f, circle_spr.getScale().y, delta*5)};
		
		circle_spr.setScale(newScale);
		
		if(totalTimeIntro >= disableTimeIntro)
		{
			introEnable = false;
			circle_spr.setColor({0,0,0,0});
		}
	}
	
}

void UI::Draw (RenderWindow & window) 
{
	if(HealthCount >= 3){
		window.draw(heart1_spr);
		window.draw(heart2_spr);
		window.draw(heart3_spr);
	}
	else if (HealthCount >= 2){
		window.draw(heart1_spr);
		window.draw(heart2_spr);
	}
	else if (HealthCount >= 1){
		window.draw(heart1_spr);
	}
	
	window.draw(bulletUI_spr);
	window.draw(ammo_text);
	window.draw(kills_text);
	window.draw(tutorial_text);
	window.draw(circle_spr);
}

void UI::SetSpritesSize()
{
	// get window resolution
	Vector2u windowSize = p_window->getSize();
	Vector2f defaultScale = {windowSize.x /426.0f , windowSize.y /240.0f};
	
	// Set Scale
	heart1_spr.setScale(defaultScale);
	heart2_spr.setScale(defaultScale);
	heart3_spr.setScale(defaultScale);
	
	bulletUI_spr.setScale(defaultScale);
	circle_spr.setScale({windowSize.x /1920.0f , windowSize.y /1080.0f});
	
	// Set Origin in center
	heart1_spr.setOrigin(heart1_spr.getLocalBounds().width/2, heart1_spr.getLocalBounds().height/2);
	heart2_spr.setOrigin(heart2_spr.getLocalBounds().width/2, heart2_spr.getLocalBounds().height/2);
	heart3_spr.setOrigin(heart3_spr.getLocalBounds().width/2, heart3_spr.getLocalBounds().height/2);
	
	bulletUI_spr.setOrigin(bulletUI_spr.getLocalBounds().width/2, bulletUI_spr.getLocalBounds().height/2);
	circle_spr.setOrigin(circle_spr.getLocalBounds().width/2, circle_spr.getLocalBounds().height/2);
	
	
	// Set Position
	heart1_spr.setPosition(windowSize.x/2 - (windowSize.x * 600)/ 1280.0f, windowSize.y/2 - (windowSize.y * 320)/ 720.0f);
	heart2_spr.setPosition(windowSize.x/2 - (windowSize.x * 535)/ 1280.0f, windowSize.y/2 - (windowSize.y * 320)/ 720.0f);
	heart3_spr.setPosition(windowSize.x/2 - (windowSize.x * 470)/ 1280.0f, windowSize.y/2 - (windowSize.y * 320)/ 720.0f);
	
	bulletUI_spr.setPosition(windowSize.x/2 - (windowSize.x * 600)/ 1280.0f, windowSize.y/2 - (windowSize.y * 260)/ 720.0f);
	circle_spr.setPosition(windowSize.x/2 , windowSize.y/2);
	
	
	
	//Set Text
	ammo_text.setString("08/08");
	kills_text.setString("Kills : 0");
	tutorial_text.setString("WASD - Move     Left Click - Shoot");
	// set Color
	ammo_text.setFillColor({245,229,166});
	kills_text.setFillColor({245,229,166});
	tutorial_text.setFillColor({245,229,166});
	// Set Size
	ammo_text.setCharacterSize((windowSize.x*32/1280)); 
	kills_text.setCharacterSize((windowSize.x*32/1280));
	tutorial_text.setCharacterSize((windowSize.x*20/1280));
	// Set Origin in center
	ammo_text.setOrigin(ammo_text.getLocalBounds().width/2 ,ammo_text.getLocalBounds().height/2);
	kills_text.setOrigin(kills_text.getLocalBounds().width/2 ,kills_text.getLocalBounds().height/2);
	tutorial_text.setOrigin(tutorial_text.getLocalBounds().width/2 ,tutorial_text.getLocalBounds().height/2);
	// Set position
	ammo_text.setPosition(windowSize.x/2 - (windowSize.x * 520)/ 1280.0f, windowSize.y/2 - (windowSize.y * 265)/ 720.0f);
	kills_text.setPosition(windowSize.x/2 + (windowSize.x * 500)/ 1280.0f, windowSize.y/2 - (windowSize.y * 320)/ 720.0f);
	tutorial_text.setPosition(windowSize.x/2 , windowSize.y/2 + (windowSize.y * 320)/ 720.0f);
}

void UI::updateHealth(int i)
{
	HealthCount = i;
	HealthCount = Clamp(HealthCount, 0 , 3);
}

void UI::updateAmmo(int i)
{
	string s = to_string(i);	
	ammo_text.setString("0" + s + "/08");
}

void UI::updateKills(int i)
{
	string s = to_string(i);
	kills_text.setString("Kills : " + s);
}
