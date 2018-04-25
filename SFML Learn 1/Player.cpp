#include "Player.h"



Player::Player(int xPos, int yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
	m_height = 100.0f;
	m_width = 100.0f;
	obj.setSize(sf::Vector2f(100.0f, 100.0f));
	obj.setPosition(sf::Vector2f((float)xPos, (float)yPos));
}


Player::~Player()
{
}

void Player::updatePlayer(sf::RenderWindow & window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		obj.move(-0.1f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		obj.move(0.1f, 0.0f);
	}
}

int Player::getXValue()
{
	return m_xPos;
}

int Player::getYValue()
{
	return m_yPos;
}

float Player::getHeight()
{
	return m_height;
}

float Player::getWidth()
{
	return m_width;
}

void Player::setXValue(int xPos)
{
	m_xPos = xPos;
}

void Player::setYValue(int yPos)
{
	m_yPos = yPos;
}

void Player::setHeight(float height)
{
	m_height = height;
}

void Player::setWidth(float width)
{
	m_width = width;
}

sf::Vector2f Player::getPosition()
{
	return obj.getPosition();
}
