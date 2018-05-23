#pragma once
#include "Platform.h"
class Bullet : public Platform
{
public:
	Bullet(float speedMultiplier, float slope, float x1, float y1, float xPos, float yPos, bool toLeft);
	float getTime();
	void update(sf::RenderWindow& window);
	~Bullet();
private:
	float m_speedMultiplier;
	float m_slope;
	float m_x1;
	float m_y1;
	float m_time = 0.0f;
	const float SPEED = 0.1f;
	bool m_toLeft;
};

