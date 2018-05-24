#include "Platform.h"



Platform::Platform()
{
}

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
	sf::Vector2f objectCenter = getCenter();
	sf::Vector2f playerCenter = play.getCenter();
	sf::Vector2f distance = sf::Vector2f(std::abs(objectCenter.x - playerCenter.x), std::abs(objectCenter.y - playerCenter.y));
	sf::Vector2f radiusSum = sf::Vector2f(play.getWidth() / 2 + m_width / 2, play.getHeight() / 2 + m_height / 2);

	// Is the platform lower than the player.
	if (objectCenter.y >= playerCenter.y) {
		// Is the player overlapping the platform and the platform is a moving platform.
		auto overlappingX = distance.x < radiusSum.x;
		auto overlappingY = distance.y < radiusSum.y;
		if (overlappingX && overlappingY)
		{
			if (play.m_movingPlatform == false)
			{
				// Is the platform to the right of the player.
				if (objectCenter.x >= playerCenter.x)
				{
					play.collideRight();
					//std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
					return 1;
				}
				else {
					play.collideLeft();
					return 1;
				}
			}
			else
			{
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
	sf::Vector2f objectCenter = getCenter();
	sf::Vector2f playerCenter = play.getCenter();
	sf::Vector2f distance = sf::Vector2f(std::abs(objectCenter.x - playerCenter.x), std::abs(objectCenter.y - playerCenter.y));
	sf::Vector2f radiusSum = sf::Vector2f(play.getWidth() / 2 + m_width / 2, play.getHeight() / 2 + m_height / 2);

	// Is the player near the top of the platform.
	if (playerCenter.y >= m_yPos - (getHeight() / 2)) {
		// Is the player overlapping the platform.
		auto overlappingX = distance.x < radiusSum.x;
		auto overlappingY = distance.y < radiusSum.y;
		if (overlappingX && overlappingY) {
			if (m_platformType == 3) {
				play.updateXPos(sin(m_time * 0.5));
				return 1;
			}
			if (m_platformType == 4) {
				play.updateYPos(-sin(m_time * 0.5) );
				return 2;
			}
			else
			{
				//play.setYValue(m_yPos - play.getHeight());
				return 1;
			}
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
			//std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
			
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

