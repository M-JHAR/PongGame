#ifndef BAT_H
#define BAT_H

#include <SFML/Graphics.hpp>

class Bat
{
private:
	sf::Vector2f m_Position;
	
	sf::RectangleShape m_Shape;

	float m_Speed = 1000.0f;
	
	bool m_MovingRight = false;
	bool m_MovingLeft = false;

public:

	Bat(float startX, float startY);
	sf::FloatRect getPosition() const;
	sf::RectangleShape getShape() const;

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(sf::Time dt);

};

#endif