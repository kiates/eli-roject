#pragma once

#include <SFML\Graphics.hpp>

class Object
{
public:
	Object();
	Object(int xPos, int yPos);
	~Object();

	void draw(sf::RenderWindow &window);


protected:
	sf::RectangleShape obj;
	int m_xPos;
	int m_yPos;
};

