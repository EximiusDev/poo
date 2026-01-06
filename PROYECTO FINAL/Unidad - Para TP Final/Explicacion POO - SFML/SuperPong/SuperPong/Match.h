#ifndef MATCH_H
#define MATCH_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Ball.h"
#include "Player.h"
#include "Scene.h"
using namespace sf;

class Match : public Scene {
public:
	Match();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
private:
	Ball m_ball;
	Player m_p1, m_p2;
};

#endif

