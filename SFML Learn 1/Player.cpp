#include "Player.h"



Player::Player(int xPos, int yPos)
{
	m_xPos = xPos * 100;
	m_yPos = yPos * 100;
	m_height = 100.0f;
	m_width = 100.0f;
	m_speed = 0.2f;
	obj.setSize(sf::Vector2f(100.0f, 100.0f));
	obj.setPosition(sf::Vector2f((float)xPos, (float)yPos));
}


Player::~Player()
{
}

void Player::updatePlayer(sf::RenderWindow & window, bool isColiding)
{
	float timer;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		obj.move(-m_speed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		obj.move(m_speed, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		isJumping = true;
	}

	if (isJumping == true) {
		time += 0.01f;
		obj.move((0.0f), (pow(time, 2) - 2.4 * time));
	}
	if (isColiding == true) {
		time = 0;
		isJumping = false;
		if (((int)obj.getPosition().y % 100) != 0) {
			obj.setPosition(sf::Vector2f(m_xPos, round(obj.getPosition().y / 100.0f) * 100.0f));
		}
	}
	if (isColiding == false) {
		obj.move((0.0f), (2.4 * time));
	}
	m_xPos = obj.getPosition().x;
	m_yPos = obj.getPosition().y;

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

void Player::collideLeft()
{
	obj.move(m_speed, 0.0f);
}

void Player::collideRight()
{
	obj.move(-m_speed, 0.0f);
}

void Player::collideBottom()
{
}

void Player::CollideTop()
{
}

sf::Vector2f Player::getPosition()
{
	return obj.getPosition();
}
