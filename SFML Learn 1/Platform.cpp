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

bool Platform::detectCollision(Player &play)
{

	sf::Vector2f objectCenter((float)m_xPos + 50.0f, (float)m_yPos + 50.0f);
	if ((obj.getPosition().x + 50.0f) >= play.getXValue() + 50.0f) {
		if ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) <= m_width && (obj.getPosition().y + 50.0f) - (play.getYValue() + 50.0f) < m_height) {
			return true;
		}
		else {
			std::cout << true;
			return false;
		}
	}
	else {

		if (((play.getXValue() + 50.0f) - (obj.getPosition().x + 50.0f)) < m_width && (obj.getPosition().y + 50.0f) - (play.getYValue() + 50.0f) < m_height) {
			return true;
		}
		else {
			std::cout << false;
			return false;
		}
	}

}

bool Platform::detectCollisionTop(Player & play)
{
	if (play.getYValue() + 50.0f > obj.getPosition().y - 50.0f) {
		if ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) <= m_width && (obj.getPosition().y + 50.0f) - (play.getYValue() + 50.0f) <= m_height && ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) >= m_width)) {
			std::cout << "true1";
			return true;
		}
		else if ((((play.getXValue() + 50.0f) - (obj.getPosition().x + 50.0f)) <= m_width && (play.getYValue() + 50.0f) - (obj.getPosition().y + 50.0f) < m_height) && ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) <= m_width)) {
			std::cout << "true";
			return true;
		}
		else {
			return false;
		}
	}
	else
		return false;
}

Platform::~Platform()
{
}

