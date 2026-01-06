#ifndef UI_H
#define UI_H
#include "Scene.h"


class UI : public Scene {
public:
	UI(RenderWindow & window);
	void InputEvents (Event & event) override;
	void Update (Game & game, float delta) override;
	void Draw (RenderWindow & window) override;
	void SetSpritesSize();
	
	void updateHealth(int i);
	void updateAmmo(int i);
	void updateKills(int i);
private:
	Font mainFont;
	
	// Healt UI
	Texture heart_tex;
	Sprite heart1_spr;
	Sprite heart2_spr;
	Sprite heart3_spr;
	int HealthCount;
	
	// Ammo UI
	Texture bulletUI_tex;
	Sprite bulletUI_spr;
	Text ammo_text;
	
	// kills 
	Text kills_text;
	
	// tutorial
	Text tutorial_text;
	float totalTimeTutorial;
	float disableTutorialTime;
	bool tut;
	
	// intro
	Texture circle_tex;
	Sprite circle_spr;
	bool introEnable;
	float totalTimeIntro;
	float disableTimeIntro;
	Vector2f defaultScale;
	

};

#endif

