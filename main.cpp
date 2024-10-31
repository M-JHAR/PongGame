#include "Bat.h"
#include "Ball.h"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>


int main()
{
	sf::VideoMode vm(1920, 1080);

	sf::RenderWindow window(vm, "PongGame", sf::Style::Fullscreen);
	int score = 0;
	int lives = 3;

	Bat bat(1920.f / 2, 1080.f - 20);
	Ball ball(1920.f / 2, 0);

	sf::Font font;
	sf::Text hud;

	font.loadFromFile("fonts/DS-DIGIT.ttf");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::White);
	hud.setPosition(20.f, 20.f);

	sf::Clock clock;
	sf::Event event;

	//Game Loop
	while (window.isOpen())
	{
		//UPDATE PLAYER INPUT

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}

		//UPDATE OBJECTS
		sf::Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);

		std::stringstream ss;
		ss << "Score: " << score << " Lives: " << lives;
		hud.setString(ss.str());

		if (ball.getPosition().top > window.getSize().y)
		{
			ball.reboundBottom();

			lives--;
			
			//reset the game hud
			if (lives < 1)
			{
				score = 0;

				lives = 3;
			}
		}

		if (ball.getPosition().top < 0)
		{
			std::cerr << ball.getPosition().top;
			ball.reboundBatOrTop();
			score++;
			
		}
		if (ball.getPosition().left < 0 ||
			ball.getPosition().left + ball.getPosition().width > window.getSize().x)
		{
			
			ball.reboundSides();
		}
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			ball.reboundBatOrTop();
		}
		//DRAW OBJECTS

		window.clear();

		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.draw(hud);

		window.display();
	}

	return 0;
}