#include "Snake.h++"


Snake::Snake(sg::Coords coords)
{
	_snakeCoords.push_back({ coords.x, coords.y });
	_snakeCoords.push_back({ coords.x - 1, coords.y });
	_snakeCoords.push_back({ coords.x - 1, coords.y - 1 });

	_snakeHeadColor = sg::Color(230, 230, 0);
}


Snake::~Snake()
{}


void Snake::reload(sg::Coords coords)
{
	_snakeCoords.clear();

	dirX = 1;
	dirY = 0;
	isMove = true;
	_foodEaten = 0;

	_snakeCoords.push_back({ coords.x, coords.y });
	_snakeCoords.push_back({ coords.x - 1, coords.y });
	_snakeCoords.push_back({ coords.x - 1, coords.y - 1 });

	_snakeHeadColor = sg::Color(230, 230, 0);	
}


std::deque<sg::Coords> Snake::getCoords() const
{
	return _snakeCoords;
}


void Snake::move()
{
	sg::Coords head;
	head = _snakeCoords.front();
	head.x += dirX;
	head.y += dirY;

	_snakeCoords.push_front(head);
	_snakeCoords.pop_back();

	isMove = true;
}


void Snake::setDirectionUp()
{	
	if (isMove) {
		if (dirY != 1) {
			dirX = 0;
			dirY = -1;
			isMove = false;
		}
	}
}


void Snake::setDirectionDown()
{
	if (isMove) {
		if (dirY != -1) {
			dirX = 0;
			dirY = 1;
			isMove = false;
		}
	}
}


void Snake::setDirectionLeft()
{
	if (isMove) {
		if (dirX != 1) {
			dirX = -1;
			dirY = 0;
			isMove = false;
		}
	}
}


void Snake::setDirectionRight()
{
	if (isMove) {
		if (dirX != -1) {
			dirX = 1;
			dirY = 0;
			isMove = false;
		}
	}
}


void Snake::eat()
{
	_snakeCoords.push_back(_snakeCoords.back());
	_foodEaten++;
}


int Snake::getFoodEaten()
{
	return _foodEaten;
}


void Snake::death()
{
	_snakeHeadColor = sg::Color(255, 0, 0);
}


sg::Color Snake::getColor() const
{
	return _snakeHeadColor;
}
