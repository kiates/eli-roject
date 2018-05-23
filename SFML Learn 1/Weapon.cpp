#include "Weapon.h"



Weapon::Weapon(sf::Mouse mouse, Player play)
{
	
}

void Weapon::fireWeapon(sf::Mouse mouse, Player play, sf::RenderWindow & window)
{
	
	m_mouse = mouse;
	m_play = play;
	sf::Vector2i mousePos = mouse.getPosition(window);

	m_mousePosition = window.mapPixelToCoords(mousePos);

	float changeInY = (play.getCenter().y  - m_mousePosition.y);
	float changeInX = (play.getCenter().x - m_mousePosition.x);

	m_slope = changeInY / changeInX;
	
	float speedMultiplier = abs(changeInX) / sqrt(pow(changeInY, 2) + pow(changeInX, 2));

	float x1 = play.getCenter().x;
	float y1 = play.getCenter().y;
	Bullet * c_bullet;
	if (m_mousePosition.x < m_play.getCenter().x) {
		c_bullet = new Bullet(speedMultiplier, m_slope, x1, y1, x1, y1, false);
	}
	else {
		c_bullet = new Bullet(speedMultiplier, m_slope, x1, y1, x1, y1, true);
	}	
	m_bullets.push_back(*c_bullet);
	//m_bullets.insert(m_bullets.begin(), *c_bullet);
	
	std::cout << m_mousePosition.x << std::endl;

	//obj.setPosition(m_play.getCenter());



}

void Weapon::update(sf::RenderWindow& window)
{
	for (int i = 0; i < m_bullets.size(); i++) {
			m_bullets[i].update(window);
			if (m_bullets[i].getTime() > 50.0f) {
				//m_bullets.erase(m_bullets.begin);
				m_bullets.pop_back();
			}
	}
	m_bullets.shrink_to_fit();
}

void Weapon::clearBullets()
{
	m_bullets.clear();
}


Weapon::~Weapon()
{
}
