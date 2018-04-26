#pragma once

#include "Object.h"
#include "Player.h"
#include <SFML\Graphics.hpp>

class Platform : public Object
{
public:
	Platform(int xPos, int yPos);
	bool detectCollision(Player play);

	~Platform();
private:
	sf::Vector2f center;
};

