#pragma once

#include <fstream>


int loadHiscore()
{
	std::ifstream fin("score.dat", std::ios_base::binary);

	int number = 0;
	if (fin.is_open()) {
		fin >> number;
	}

	return number;
}


void saveHiscore(int score)
{
	std::ofstream fout("score.dat", std::ios_base::binary);
	fout << score;
}