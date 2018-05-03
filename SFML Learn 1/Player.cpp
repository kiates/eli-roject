#include "Player.h"



Player::Player(int xPos, int yPos)
{
	Reset(xPos, yPos);
}

void Player::Reset(int xPos, int yPos)
{
	m_xPos = xPos * 100;
	m_yPos = yPos * 100;
	m_height = 100.0f;
	m_width = 100.0f;
	m_speed = 0.4f;
	m_health = 100.0f;
	obj.setSize(sf::Vector2f(100.0f, 100.0f));
	obj.setPosition(sf::Vector2f((float)xPos, (float)yPos));
}

Player::~Player()
{
}

void Player::updatePlayer(sf::RenderWindow & window, bool isColiding)
{
	float timer;

	std::cout << "col:" << isColiding;
	std::cout << "jump:" << isJumping;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		m_xPos -= m_speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		m_xPos += m_speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		if (isJumping == false)
			m_yVel = -10.0f;
		isJumping = true;
		
	}

	if (isJumping == true) {
		m_yVel += 9.8f*.025f * 0.166667f;
		m_yPos = m_yPos + m_yVel * 0.1666667f;
	}
	if (isColiding == true && m_yVel >= 0) {
		time = 0;
		isJumping = false;
		if (((int)obj.getPosition().y % 100) != 0) {
			m_yPos = round(m_yPos / 100.0f) * 100.0f;
		}
	}
	if (isColiding == false && isJumping == false) {
		time += 0.01f;
		m_yPos += 2.4f * time;
		if (time > 5.0f) {
			m_health = 0.0f;
			time = 0.0f;
		}
	}
	
	obj.setPosition(sf::Vector2f(m_xPos, m_yPos));
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

float Player::getPlayerHealth()
{
	return m_health;
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

void Player::setPlayerHealth(float health)
{
	m_health = health;
}

void Player::collideLeft()
{
	m_xPos += m_speed;
}

void Player::collideRight()
{
	m_xPos -= m_speed;
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
