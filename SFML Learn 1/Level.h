#pragma once
#include <vector>
#include "Platform.h"

static const int dimX = 10;
static const int dimY = 10;
extern int level1[dimX][dimY];

class Level
{
public:
	Level(int (*map_data)[dimX][dimY], int width, int height);
	~Level();

	void Generate();
public:
	int m_dimX = 10;
	int m_dimY = 10;
	int (*m_level)[dimX][dimY];
	std::vector <Platform> plats;
};

