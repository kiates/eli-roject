#pragma once

#include <SFML\Graphics.hpp>
#include "Object.h"

class Player : public Object
{
public:
	Player(int xPos, int yPos);
	~Player();

	void updatePlayer(sf::RenderWindow &window);

	//getters
	int getXValue();
	int getYValue();

	//setters

	void setXValue(int xPos);
	void setYValue(int yPos);



	sf::Vector2f getPosition();
};

