#include "Level.h"


int level1[dimX][dimY] = {
	{ 0,0,0,0,0,0,0,0,0,0 }, 
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,2,0,0,0 },
	{ 0,0,0,0,0,1,0,0,0,0 },
	{ 0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,1,1,0,1,0,0,0,1 },
	{ 1,1,1,1,1,1,2,2,1,1 },
};

Level::Level(int (*map_data)[dimX][dimY], int width, int height)
{
	m_level = map_data;
	m_dimX = width;
	m_dimY = height;
	Generate();
}


Level::~Level()
{
}

void Level::Generate()
{
	for (int y = 0; y < m_dimX; y++) {
		for (int x = 0; x < m_dimY; x++) {
			if ((*m_level)[y][x] == 1) {
				Platform plat(x, y, false, sf::Color::Blue);
				plats.push_back(plat);
			}
			else if ((*m_level)[y][x] == 2) {
				Platform plat(x, y, true, sf::Color::Red);
				plats.push_back(plat);
			}
				
		}
	}
}
