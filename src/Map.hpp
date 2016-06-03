#pragma once

#include <vector>
#include "Coords.hpp"


class Map
{
public:
	Map();
	~Map();

	void setSize(int width, int height);
	int getWidth() const;
	int getHeight() const;

	void setEmptyCount(int num);
	int getEmptyCount() const;

	void addCoord(int x, int y);
	std::vector<sg::Coords> getCoords() const;

	void clear();

private:
	std::vector<sg::Coords> _mapCoords;
	int _width;
	int _height;
	int _emptyCount = 0;
};

