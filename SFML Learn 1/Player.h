#pragma once

#include <SFML\Graphics.hpp>
#include "Object.h"

class Player : public Object
{
public:
	Player(int xPos, int yPos);
	~Player();

	void Reset(int xPos, int yPos);

	void updatePlayer(sf::RenderWindow &window, bool isColiding);

	//getters
	int getXValue();
	int getYValue();
	
	float getHeight();
	float getWidth();

	float getPlayerHealth();
	//setters
	void setXValue(int xPos);
	void setYValue(int yPos);

	void setHeight(float height);
	void setWidth(float width);

	void setPlayerHealth(float health);
	//colliding
	void collideLeft(); //relative to player
	void collideRight(); //relative to player
	void collideBottom(); //relative to player
	void CollideTop(); //relative to player


	sf::Vector2f getPosition();
private:
	float m_speed;
	bool isJumping = false;
	float time;
	float m_health = 100.0f;
};

