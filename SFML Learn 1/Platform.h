#pragma once

#include "Object.h"
#include <SFML\Graphics.hpp>

class Platform : public Object
{
public:
	Platform(int xPos, int yPos);

	~Platform();
};

