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



void Object::draw(sf::RenderWindow & window)
{
	window.draw(obj);
}
