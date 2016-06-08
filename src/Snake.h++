#pragma once

#include <deque>
#include "Coords.h++"
#include "Color.h++"

class Snake
{
public:
	Snake(sg::Coords coords);
	~Snake();

	std::deque<sg::Coords> getCoords() const;
	
	void reload(sg::Coords coords);
	void move();
	void setDirectionUp();
	void setDirectionDown();
	void setDirectionLeft();
	void setDirectionRight();
	void eat();
	int getFoodEaten();
	void death();
	sg::Color getColor() const;

private:
	std::deque<sg::Coords> _snakeCoords;
	int dirX = 1;
	int dirY = 0;
	bool isMove = true;
	sg::Color _snakeHeadColor;
	int _foodEaten = 0;
};

