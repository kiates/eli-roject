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
		m_xPos -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		m_xPos += 1;
	}
}

sf::Vector2f Player::getPosition()
{
	return obj.getPosition();
}
