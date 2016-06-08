#pragma once

#include "Coords.h++"
#include "Map.h++"
#include "Snake.h++"
#include "Food.h++"


bool checkCollisions(Snake& snake, Food& food)
{
	sg::Coords snakeCoord;
	sg::Coords foodCoord;

	snakeCoord = snake.getCoords().front();
	foodCoord = food.getCoords();

	bool isFoodInTail = true;
	{
		for (auto tail : snake.getCoords()) {
			isFoodInTail = false;
			if ((tail.x == foodCoord.x) && (tail.y == foodCoord.y)) {
				food.dislocate();
				isFoodInTail = true;
			}
		}
	} while (isFoodInTail);


	if ((snakeCoord.x == foodCoord.x) && (snakeCoord.y == foodCoord.y)) {
		food.dislocate();
		snake.eat();
		return true;
	}

	return false;
}


bool checkCollisions(Snake& snake, Map& map)
{
	sg::Coords snakeCoord;
	std::vector<sg::Coords> mapCoords;

	snakeCoord = snake.getCoords().front();
	mapCoords = map.getCoords();

	for (auto mapc : mapCoords) {
		if ((snakeCoord.x == mapc.x) && (snakeCoord.y == mapc.y)) {
			snake.death();
			return true;
		}
	}

	return false;
}


bool checkCollisions(Snake& snake)
{
	sg::Coords snakeHeadCoord;
	std::deque<sg::Coords> snakeTailCoords;

	snakeHeadCoord = snake.getCoords().front();
	snakeTailCoords = snake.getCoords();
	snakeTailCoords.pop_front();

	for (auto tail : snakeTailCoords) {
		if ((snakeHeadCoord.x == tail.x) && (snakeHeadCoord.y == tail.y)) {
			snake.death();
			return true;
		}
	}

	return false;
}
