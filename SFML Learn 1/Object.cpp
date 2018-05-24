#include "Object.h"



Object::Object()
{
}

Object::Object(int xPos, int yPos)
{
	m_xVel = 0;
	m_yVel = 0;
	m_xPos = xPos;
	m_yPos = yPos;
	obj.setSize(sf::Vector2f(100.0f, 100.0f));
	obj.setPosition(sf::Vector2f((float)xPos, (float)yPos));
}


Object::~Object()
{
}

sf::Vector2f Object::getCenter()
{

	return (sf::Vector2f(m_xPos, m_yPos) + sf::Vector2f(m_width / 2, m_height / 2));
}

void Object::draw(sf::RenderWindow & window)
{
	window.draw(obj);
}

float Object::getHeight()
{
	return m_height;
}

float Object::getWidth()
{
	return m_width;
}