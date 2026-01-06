#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Player_ {
public:
	Player_();
	void Update();
	void Update(sf::FloatRect platform_bounds);
	void Draw (sf::RenderWindow & win);
	
	float GetScore(){return p_score*1;}
private:
	CircleShape p_circle; // sf::CircleShape m_circle;
	Vector2f p_pos; // sf::Vector2f m_pos;
	Vector2f p_speed; 
	
	float p_score, score_pos;
};

#endif

