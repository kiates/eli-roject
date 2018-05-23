#include "Bullet.h"



Bullet::Bullet(float speedMultiplier, float slope, float x1, float y1, float xPos, float yPos, bool toLeft)
{
	m_speedMultiplier = speedMultiplier;
	m_slope = slope;
	m_xPos = xPos - 12.5f;
	m_yPos = yPos;
	m_x1 = x1;
	m_y1 = y1;

	m_toLeft = toLeft;

	obj.setPosition(sf::Vector2f(xPos + 100.0f, yPos));
	//obj.setOrigin(sf::Vector2f(xPos, yPos));
	obj.setSize(sf::Vector2f(10.0f, 10.0f));
	obj.setFillColor(sf::Color::Yellow);

	std::cout << m_slope << std::endl;

}

float Bullet::getTime()
{
	return m_time;
}

void Bullet::update(sf::RenderWindow & window)
{
	
	if (m_toLeft == false) {
		m_xPos -= 0.5f * m_speedMultiplier;
		m_yPos = (m_slope *(m_time) + m_y1 + 5.0f);
		m_time -= 0.5f * m_speedMultiplier;
		//obj.move(m_xPos, (m_slope *(m_time - m_x1) + m_y1));
		obj.setPosition(sf::Vector2f(m_xPos, m_yPos));
	}
	else {
		m_xPos += 0.5f * m_speedMultiplier;
		m_yPos = (m_slope *(m_time) + m_y1);
		m_time += 0.5f * m_speedMultiplier;
		//obj.move(m_xPos, (m_slope *(m_time - m_x1) + m_y1));
		obj.setPosition(sf::Vector2f(m_xPos, m_yPos));
	}
	window.draw(obj);
}

Bullet::~Bullet()
{
}
