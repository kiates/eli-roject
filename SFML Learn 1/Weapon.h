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
	void setTime(float time);

	float getTime();
	float getReloadSpeed();

	void clearBullets();
	~Weapon();
private:
	sf::Mouse m_mouse;
	sf::Vector2f m_mousePosition;
	float m_reloadSpeed = 25.0f;
	Player m_play;
	float m_slope;
	std::vector<Bullet> m_bullets;
	float m_time = 100.0f;
};

