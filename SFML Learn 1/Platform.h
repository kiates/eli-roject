#pragma once

#include "Object.h"
#include "Player.h"
#include <SFML\Graphics.hpp>

class Platform : public Object
{
public:
	Platform(int xPos, int yPos, bool damagePlayer, sf::Color color);
	bool detectCollision(Player &play);
	bool detectCollisionTop(Player &play);

	bool hurtPlayer(Player &play);

	~Platform();
private:
	sf::Vector2f center;
	bool m_damagePlayer;
};

