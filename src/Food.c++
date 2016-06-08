#include "Food.h++"


Food::Food()
{
	srand(time(0));
}


Food::~Food()
{}


void Food::setMapSize(int mapWidth, int mapHeight)
{
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
}


void Food::dislocate()
{
	_foodCoord.x = 1 + rand() % (_mapWidth - 2);
	_foodCoord.y = 1 + rand() % (_mapHeight - 2);
}


sg::Coords Food::getCoords() const
{
	return _foodCoord;
}
