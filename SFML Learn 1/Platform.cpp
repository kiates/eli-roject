#include "Platform.h"


Platform::Platform(int xPos, int yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
	m_width = 100.0f;
	m_height = 100.0f;
	obj.setSize(sf::Vector2f(100.0f, 100.0f));
	obj.setPosition(sf::Vector2f((float)xPos * 100.0f, (float)yPos * 100.0f)); // sets position of platform
}

bool Platform::detectCollision(Player play)
{

	sf::Vector2f objectCenter((float)m_xPos + 50.0f, (float)m_yPos + 50.0f);

	if ((obj.getPosition().x +50.0f) - (play.getXValue() + 50.0f) <= m_width && (obj.getPosition().y + 50.0f) - (play.getYValue() + 50.0f) <= m_height) {
		std::cout << obj.getPosition().x + 50.0f << std::endl;
		std::cout << play.getXValue() + 50.0f << std::endl;
		std::cout << obj.getPosition().y + 50.0f << std::endl;
		std::cout << play.getYValue() + 50.0f << std::endl;
		return true;
	}
	else {
		std::cout << obj.getPosition().x + 50.0f << std::endl;
		std::cout << play.getXValue() + 50.0f << std::endl;
		std::cout << obj.getPosition().y + 50.0f << std::endl;
		std::cout << play.getYValue() + 50.0f << std::endl;
		return false;
	}
}

Platform::~Platform()
{
}

