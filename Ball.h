#ifndef BALL_H 
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::Vector2f m_Position;
	sf::RectangleShape m_Shape;

	float m_Speed     = 300.0f;
	float m_DirectionX = 1.f;
	float m_DirectionY = 1.f;
public:
	Ball(float startX, float startY);

	sf::FloatRect	   getPosition() const;
	sf::RectangleShape getShape() const;

	float getXVelocity();
	void  reboundSides();
	void  reboundBatOrTop();
	void  reboundBottom();
	void  update(sf::Time dt);


};



#endif