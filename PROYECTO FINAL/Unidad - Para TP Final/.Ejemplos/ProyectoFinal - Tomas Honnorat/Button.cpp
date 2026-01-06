#include "Button.h"

Button::Button(RenderWindow &window, string fileNameImage, string fileNameFont, string textButton, float x, float y) 
	: buttonText(textButton) ,xPos(x), yPos(y), canPlaySound(true)
{
	p_window = &window;
	windowSize = p_window->getSize();
	
	// Load Texture
	button_tex.loadFromFile(fileNameImage);
	// Load Font
	main_font.loadFromFile(fileNameFont);
	
	
	
	SetSprites();
}

void Button::Startup(SoundBuffer& interact_buffer)
{
	interact_sound.setBuffer(interact_buffer);
}

void Button::InputEvents (Event & event) 
{

}

void Button::Update (Game & game, float delta) 
{
	Vector2f defaultScale = {windowSize.x /426.0f , windowSize.y /240.0f};
	
	
	if(IsMouseOnButton()){
		
		Vector2f newScale = {Lerp(defaultScale.x * 1.1f, button_spr.getScale().x, delta*5),
							Lerp(defaultScale.y * 1.1f, button_spr.getScale().y, delta*5)}; ///Lerp (origen, destino, delta)
		
		button_spr.setScale(newScale);
		title_text.setScale(1.1f, 1.1f);
		
		if(canPlaySound){
			canPlaySound = false;
			interact_sound.play();
			//cout << "play sound" << endl;
		}
		
	} else
	{
		Vector2f newScale = {Lerp(defaultScale.x, button_spr.getScale().x, delta*5),
							Lerp(defaultScale.y, button_spr.getScale().y, delta*5)};  ///Lerp (origen, destino, delta)
		
		button_spr.setScale(newScale);
		title_text.setScale(1, 1);
		canPlaySound = true;
	}
}

void Button::Draw (RenderWindow & window) 
{
	window.draw(button_spr);
	window.draw(title_text);
}

void Button::SetSprites()
{
	windowSize = p_window->getSize();
	Vector2f defaultScale = {windowSize.x /426.0f , windowSize.y /240.0f}; 
	
	float xOff = (windowSize.x * xPos)/ 1280.0f;
	float yOff = (windowSize.y * yPos) / 720.0f;
	
	title_text.setFont(main_font);

	// Set Texture
	button_spr.setTexture(button_tex);
	// Set Scale
	button_spr.setScale(defaultScale);
	// Set Origin in center
	button_spr.setOrigin(button_spr.getLocalBounds().width/2,button_spr.getLocalBounds().height/2);
	// Set Position (center default)
	button_spr.setPosition(windowSize.x/2 + xOff, windowSize.y/2 - yOff);
	
	//Set Text
	title_text.setString(buttonText);
	// set Color
	title_text.setFillColor({245,229,166});
	// Set Size
	title_text.setCharacterSize((windowSize.x*20/1280)); // size 20 en 1280 (1280/20 = 64) 
	// Set Origin in center
	title_text.setOrigin(title_text.getLocalBounds().width/2 ,title_text.getLocalBounds().height/2);
	// Adjust font position
	Vector2f correctionPos = {0,((windowSize.y * 5.0f) / 720.0f)};
	// Set position
	title_text.setPosition(button_spr.getPosition() - correctionPos);
}

bool Button::IsMouseOnButton()
{
	Vector2i mousePos = Mouse::getPosition(*p_window);
	auto rec(button_spr.getGlobalBounds());

	return mousePos.x > rec.left &&  mousePos.x < (rec.left + rec.width) 
		&& mousePos.y > rec.top &&  mousePos.y < (rec.top + rec.height);
}

void Button::UpdateVolume(int i)
{
	interact_sound.setVolume(i);
}
