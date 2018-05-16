#pragma once
#include <vector>
#include "Platform.h"
#include "Levels.h"


class Level
{
public:
	Level(int(*map_data)[dimX][dimY], int width, int height);
	Level(int(*map_data)[STARTX][STARTY], int width, int height);
	~Level();

	void Generate();
	void GenerateHomeScreen();
public:
	int m_dimX = 10;
	int m_dimY = 10;
	int(*m_level)[dimX][dimY];
	int(*m_homeScreen)[STARTX][STARTY];
	std::vector <Platform> plats;
};

