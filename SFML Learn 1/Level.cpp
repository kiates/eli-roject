#include "Level.h"




Level::Level(int (*map_data)[dimX][dimY], int width, int height)
{
	m_level = map_data;
	m_dimX = width;
	m_dimY = height;
	Generate();
}

Level::Level(int(*map_data)[STARTX][STARTY], int width, int height)
{
	m_homeScreen = map_data;
	m_dimX = width;
	m_dimY = height;
	GenerateHomeScreen();
}


Level::~Level()
{
}

void Level::Generate()
{
	for (int y = 0; y < m_dimX; y++) {
		for (int x = 0; x < m_dimY; x++) {
			if ((*m_level)[y][x] == 1) {
				Platform plat(x, y, 1, sf::Color::Blue);
				plats.push_back(plat);
			}
			else if ((*m_level)[y][x] == 2) {
				Platform plat(x, y, 2, sf::Color::Red);
				plats.push_back(plat);
			}
			else if ((*m_level)[y][x] == 3) {
				Platform plat(x, y, 3, sf::Color::Magenta);
				plats.push_back(plat);
			}
			else if ((*m_level)[y][x] == 4) {
				Platform plat(x, y, 4, sf::Color::Magenta);
				plats.push_back(plat);
			}
				
		}
	}
}

void Level::GenerateHomeScreen()
{
	for (int y = 0; y < m_dimX; y++) {
		for (int x = 0; x <= m_dimY; x++) {
			if ((*m_homeScreen)[y][x] == 1) {
				Platform plat(x, y, 1, sf::Color::Blue);
				plats.push_back(plat);
			}
			else if ((*m_homeScreen)[y][x] == 2) {
				Platform plat(x, y, 2, sf::Color::Red);
				plats.push_back(plat);
			}

		}
	}
}
