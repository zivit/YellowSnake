#pragma once
#include <random>
#include <ctime>
#include "Coords.h++"

class Food
{
public:
	Food();
	~Food();

	void setMapSize(int mapWidth, int mapHeight);
	void dislocate();

	sg::Coords getCoords() const;

private:
	sg::Coords _foodCoord;
	int _mapWidth = 0;
	int _mapHeight = 0;
};

