#include "Object.h"



Object::Object()
{
}

Object::Object(int xPos, int yPos)
{
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

	return obj.getPosition() + sf::Vector2f(m_height / 2, m_width / 2);
}

void Object::draw(sf::RenderWindow & window)
{
	window.draw(obj);
}

void Object::updatePos()
{
	m_xPos = obj.getPosition().x;
	m_yPos = obj.getPosition().y;
}
