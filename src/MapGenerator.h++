#pragma once

#include <string>
#include "Map.h++"


void generateLevel1(Map& map)
{
	map.clear();
	map.setSize(40, 28);

	std::string textMap[] = {
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"a                                      a",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	};

	map.setEmptyCount(0);
	int countEmptyCell = 0;

	for (int row = 0; row < map.getHeight(); ++row) {
		for (int col = 0; col < map.getWidth(); ++col) {
			if (textMap[row][col] == 'a') {
				map.addCoord(col, row);
			}
			if (textMap[row][col] == ' ') {
				++countEmptyCell;
			}
		}
	}

	map.setEmptyCount(countEmptyCell);
}
