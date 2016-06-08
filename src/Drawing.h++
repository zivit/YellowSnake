#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Coords.h++"
#include "Map.h++"
#include "Snake.h++"
#include "Food.h++"


void drawMap(sf::RenderTarget& target, const std::vector<sg::Coords>& mapCoord)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(16.0f, 16.0f));
	rectangle.setFillColor(sf::Color(220, 220, 220));

	for (auto map : mapCoord) {
		rectangle.setPosition(map.x * 16, map.y * 16);
		target.draw(rectangle);
	}
}


void drawSnake(sf::RenderTarget& target, const Snake& snake)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(16.0f, 16.0f));
	rectangle.setFillColor(sf::Color::Yellow);

	for (auto snake : snake.getCoords()) {		
		rectangle.setPosition(snake.x * 16, snake.y * 16);
		target.draw(rectangle);
	}

	rectangle.setPosition(snake.getCoords().front().x * 16, snake.getCoords().front().y * 16);
	rectangle.setFillColor(sf::Color(snake.getColor().r, snake.getColor().g, snake.getColor().b));
	target.draw(rectangle);
}


void drawFood(sf::RenderTarget& target, const sg::Coords& foodCoord)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(16.0f, 16.0f));
	rectangle.setFillColor(sf::Color::Green);

	rectangle.setPosition(foodCoord.x * 16, foodCoord.y * 16);
	target.draw(rectangle);
}
