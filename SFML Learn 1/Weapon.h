#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Bullet.h"
class Weapon : public Object
{
public:
	Weapon(sf::Mouse mouse, Player play);
	void fireWeapon(sf::Mouse mouse, Player play, sf::RenderWindow & Window);
	void update(sf::RenderWindow & window);
	void clearBullets();
	~Weapon();
private:
	sf::Mouse m_mouse;
	sf::Vector2f m_mousePosition;
	Player m_play;
	float m_slope;
	std::vector<Bullet> m_bullets;
};

