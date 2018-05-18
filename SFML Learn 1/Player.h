#pragma once

#include <SFML\Graphics.hpp>
#include "Object.h"

class Player : public Object
{
public:
	Player(int xPos, int yPos, float width = 75.0f);
	~Player();

	void Reset(int xPos, int yPos, float width = 75.0f);

	void updatePlayer(sf::RenderWindow &window, bool isColiding);

	void drawHealthBar(sf::RenderWindow &window, sf::View view);

	//getters
	int getXValue();
	int getYValue();

	//updatesrs
	void updateXPos(float x);
	void updateYPos(float y);

	float getPlayerHealth();
	//setters
	void setXValue(int xPos);
	void setYValue(int yPos);

	void setJumping(bool jumpoing);

	void setHeight(float height);
	void setWidth(float width);

	void setPlayerHealth(float health);
	//colliding
	void collideLeft(); //relative to player
	void collideRight(); //relative to player
	void collideBottom(); //relative to player
	void CollideTop(); //relative to player

	void loseHealth(float amountLost);
	sf::Vector2f getPosition();

	bool m_movingPlatform = false;

private:
	float m_speed;
	bool isJumping = false;
	float time;
	
	float m_health = 100.0f;
	sf::RectangleShape m_healthBar;
};

