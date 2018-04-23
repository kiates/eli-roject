#pragma once

#include <SFML\Graphics.hpp>
#include "Object.h"

class Player : public Object
{
public:
	Player(int xPos, int yPos);
	~Player();

	void updatePlayer(sf::RenderWindow &window);

	sf::Vector2f getPosition();
};

