#include "Player.h"



Player::Player(int xPos, int yPos, float width)
{
	Reset(xPos, yPos, width);
}

void Player::Reset(int xPos, int yPos, float width)
{
	m_xPos = xPos * 100;
	m_yPos = yPos * 100;
	m_height = 100.0f;
	m_width = width;
	m_speed = 0.4f;
	m_health = 100.0f;
	obj.setSize(sf::Vector2f(m_width, m_height));
	obj.setPosition(sf::Vector2f((float)xPos, (float)yPos));
	m_healthBar.setSize(sf::Vector2f(100.0f, 50.0f));
	m_healthBar.setPosition(sf::Vector2f(m_xPos + 100.0f, m_yPos + 100.0f));
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
		time += 0.01f;
		m_yVel += 9.8f*.025f * 0.166667f;
		m_yPos = m_yPos + m_yVel * 0.1666667f;
		if (time > 17.0f) {
			m_health = 0.0f;
			time = 0.0f;
		}
	}
	if (isColiding == true && m_yVel >= 0 && m_movingPlatform == false) {
		time = 0;
		isJumping = false;
		if (((int)obj.getPosition().y % 100) != 0) {
			m_yPos = round(m_yPos / 100.0f) * 100.0f;
		}
	}
	if (isColiding == true && m_yVel >= 0 && m_movingPlatform == true) {
		time = 0;
		isJumping = false;
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

void Player::drawHealthBar(sf::RenderWindow & window, sf::View view)
{
	sf::RectangleShape sideBars(sf::Vector2f(0.0f,0.0f));
	sf::RectangleShape topBars(sf::Vector2f(0.0f, 0.0f));
	m_healthBar.setPosition(view.getCenter() - (view.getSize() / 2.0f) + sf::Vector2f(10.0f, 10.0f));
	m_healthBar.setSize(sf::Vector2f(2 * m_health, 50.0f));
	m_healthBar.setFillColor(sf::Color::Red);

	sideBars.setSize(sf::Vector2f(10.0f, 70.0f));
	sideBars.setFillColor(sf::Color::Blue);
	sideBars.setPosition(view.getCenter() - (view.getSize() / 2.0f));
	window.draw(sideBars);
	sideBars.setPosition(view.getCenter() - (view.getSize() / 2.0f) + sf::Vector2f(210.0f, 0.0f));
	window.draw(sideBars);

	topBars.setSize(sf::Vector2f(220.0f, 10.0f));
	topBars.setFillColor(sf::Color::Blue);
	topBars.setPosition(view.getCenter() - (view.getSize() / 2.0f));
	window.draw(topBars);
	topBars.setPosition(view.getCenter() - (view.getSize() / 2.0f) + sf::Vector2f(0.0f, 60.0f));
	window.draw(topBars);

	window.draw(m_healthBar);
	
}



int Player::getXValue()
{
	return m_xPos;
}

int Player::getYValue()
{
	return m_yPos;
}

void Player::updateXPos(float x)
{
	m_xPos += x;
}

void Player::updateYPos(float y)
{
	m_yPos += y;
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

void Player::setJumping(bool jumpoing)
{
	isJumping = jumpoing;
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

void Player::loseHealth(float amountLost)
{
	m_health -= amountLost;
}

sf::Vector2f Player::getPosition()
{
	return obj.getPosition();
}
