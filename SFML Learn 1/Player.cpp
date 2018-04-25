#include "Player.h"



Player::Player(int xPos, int yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
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

void Player::setXValue(int xPos)
{
	m_xPos = xPos;
}

void Player::setYValue(int yPos)
{
	m_yPos = yPos;
}

sf::Vector2f Player::getPosition()
{
	return obj.getPosition();
}
