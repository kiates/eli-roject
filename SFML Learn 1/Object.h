#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Object
{
public:
	Object();
	Object(int xPos, int yPos);
	~Object();

	sf::Vector2f getCenter();

	void draw(sf::RenderWindow &window);
	void updatePos();


protected:
	sf::RectangleShape obj;
	float m_xPos;
	float m_yPos;
	float m_height;
	float m_width;
};

