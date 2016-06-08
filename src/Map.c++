#include "Map.h++"


Map::Map()
{}


Map::~Map()
{}


void Map::setSize(int width, int height)
{
	_width = width;
	_height = height;
}


int Map::getWidth() const
{
	return _width;
}


int Map::getHeight() const
{
	return _height;
}


void Map::setEmptyCount(int num)
{
	_emptyCount = num;
}


int Map::getEmptyCount() const
{
	return _emptyCount;
}


void Map::addCoord(int x, int y)
{
	_mapCoords.push_back({ x, y });
}


std::vector<sg::Coords> Map::getCoords() const
{
	return _mapCoords;
}


void Map::clear()
{
	_mapCoords.clear();
}
