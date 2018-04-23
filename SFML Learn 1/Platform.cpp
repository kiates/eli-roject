#include "Platform.h"


Platform::Platform(int xPos, int yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
	obj.setSize(sf::Vector2f(100.0f, 100.0f));
	obj.setPosition(sf::Vector2f((float)xPos * 100.0f, (float)yPos * 100.0f)); // sets position of platform
}

Platform::~Platform()
{
}

