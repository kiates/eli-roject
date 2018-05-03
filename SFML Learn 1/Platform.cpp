#include "Platform.h"



Platform::Platform(int xPos, int yPos, bool damagePlayer, sf::Color color)
{
	m_xPos = xPos * 100.0f;
	m_yPos = yPos * 100.0f;
	m_width = 100.0f;
	m_height = 100.0f;
	m_damagePlayer = damagePlayer;
	obj.setFillColor(color);
	obj.setSize(sf::Vector2f(100.0f, 100.0f));
	obj.setPosition(sf::Vector2f((float)xPos * 100.0f, (float)yPos * 100.0f)); // sets position of platform
}

bool Platform::detectCollision(Player &play)
{

	sf::Vector2f objectCenter((float)m_xPos + (getWidth() / 2), (float)m_yPos + 50.0f);
	if (m_yPos + (getHeight() / 2) >= play.getYValue() + (play.getHeight() / 2)){
		if ((m_xPos + (getWidth() / 2)) >= play.getXValue() + (play.getWidth() / 2)) {
			if ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) <= play.getWidth() / 2 + m_width / 2 && (m_yPos + (getHeight() / 2)) - (play.getYValue() + (play.getHeight() / 2)) < play.getHeight() / 2 + m_height / 2) {
				play.collideRight();
				return true;
			}
			else {
				return false;
			}
		}
		else {

			if (((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && (m_yPos + (getHeight() / 2)) - (play.getYValue() + (play.getHeight() / 2)) <  play.getHeight() / 2 + m_height / 2) {
				play.collideLeft();
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}

}

bool Platform::detectCollisionTop(Player & play)
{
	if (play.getYValue() + (play.getHeight() / 2) >= m_yPos - (getHeight() / 2)) {
		//if ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) <= m_width && (obj.getPosition().y + 50.0f) - (play.getYValue() + 50.0f) <= m_height && ((obj.getPosition().x + 50.0f) - (play.getXValue() + 50.0f) >= m_width)) {
		//	return true;
		//}
		if ((((play.getXValue() + (play.getWidth() / 2)) - (m_xPos + (getWidth() / 2))) < play.getWidth() / 2 + m_width / 2 && (play.getYValue() + (play.getHeight() / 2)) - (m_yPos + (getHeight() / 2)) < play.getHeight() / 2 + m_height / 2) && ((m_xPos + (getWidth() / 2)) - (play.getXValue() + (play.getWidth() / 2)) < play.getWidth() / 2 + m_width / 2)) {
			return true;
		}
		else {
			return false;
		}
	}
	else
		return false;
}

bool Platform::hurtPlayer(Player &play)
{
	if (m_damagePlayer == true) {
		if (detectCollision(play) || detectCollisionTop(play)) {
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

