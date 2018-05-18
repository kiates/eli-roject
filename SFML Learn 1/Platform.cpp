#include "Platform.h"



Platform::Platform(int xPos, int yPos, int platformType, sf::Color color)
{
	m_xPos = xPos * 100.0f;
	m_yPos = yPos * 100.0f;
	m_width = 100.0f;
	m_height = 100.0f;
	m_platformType = platformType;
	obj.setFillColor(color);
	obj.setSize(sf::Vector2f(100.0f, 100.0f));
	obj.setPosition(sf::Vector2f((float)xPos * 100.0f, (float)yPos * 100.0f)); // sets position of platform
}

int Platform::detectCollision(Player &play)
{

	sf::Vector2f objectCenter((float)m_xPos + (getWidth() / 2), (float)m_yPos + 50.0f);
	if (m_yPos + (getHeight() / 2) >= play.getYValue() + (play.getHeight() / 2)){
		if ((m_xPos + (getWidth() / 2)) >= play.getXValue() + (play.getWidth() / 2)) {
			if ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) < play.getWidth() / 2 + m_width / 2 && (m_yPos + (getHeight() / 2)) - (play.getYValue() + (play.getHeight() / 2)) < play.getHeight() / 2 + m_height / 2) {
				play.collideRight();
				//std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
				return 1;
			}
			else {
				return 0;
			}
		}
		else {

			if (((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && (m_yPos + (getHeight() / 2)) - (play.getYValue() + (play.getHeight() / 2)) <  play.getHeight() / 2 + m_height / 2) {
				play.collideLeft();
				//std::cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	else {
		return 0;
	}

}

int Platform::detectCollisionTop(Player & play)
{
	if (play.getYValue() + (play.getHeight() / 2) >= m_yPos - (getHeight() / 2)) {
		//if ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) <= m_width && (obj.getPosition().y + 50.0f) - (play.getYValue() + 50.0f) <= m_height && ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) >= m_width)) {
		//	return true;
		//}
		if ((((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && (play.getYValue() + (play.getHeight() / 2)) - (m_yPos + (getHeight() / 2)) < play.getHeight() / 2 + m_height / 2) && ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) < play.getWidth() / 2 + m_width / 2)) {
			if (m_platformType == 3) {
				play.updateXPos(sin(m_time * 0.5));
			}
			return 1;
		}
		else {
			return 0;
		}
	}
	else
		return 0;
}

int Platform::detectCollisionBottom(Player & play)
{
	if (m_yPos - (getHeight() / 2) >= play.getYValue() - (play.getWidth() / 2)) {
		//if ((((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && -(play.getYValue() + (play.getHeight() / 2)) + (m_yPos + (getHeight() / 2)) < play.getHeight() / 2 - m_height / 2) && ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) < play.getWidth() / 2 + m_width / 2)) {
		//	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
		//	return 1;
	//	}

		if (((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && (-(play.getYValue() + (play.getHeight() / 2)) + (m_yPos + (getHeight() / 2)) < play.getHeight() / 2 + m_height / 2) && ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) < play.getWidth() / 2 + m_width / 2)) {
			std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
			
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

void Platform::movingPlatform()
{

	if (m_platformType == 3) {
		//Player platform(m_xPos, m_yPos, m_width);
		float speed = 0.5f;
		if (m_time <= 720.0f) {
			m_time += 0.01f;
			m_xPos += sin(m_time * speed);
		}
		else {
			m_time = 0.0f;
			//m_xPos -= sin(m_time * speed);
		}
		
		obj.setPosition(sf::Vector2f(m_xPos, m_yPos));
		
	}
	else if (m_platformType == 4) {
		//Player platform(m_xPos, m_yPos, m_width);
		float speed = 0.5f;
		if (m_time <= 720.0f) {
			m_time += 0.01f;
			m_yPos -= sin(m_time * speed);
		}
		else {
			m_time = 0.0f;
			//m_xPos -= sin(m_time * speed);
		}

		obj.setPosition(sf::Vector2f(m_xPos, m_yPos));
	}
}

bool Platform::hurtPlayer(Player &play)
{
	if (m_platformType == 2) {
		if (detectCollision(play) == true || detectCollisionTop(play) == true) {
			play.loseHealth(0.1f);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

Platform::~Platform()
{
}

