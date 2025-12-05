#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <cmath>
#include <utility>

// return whether the roll has been removed, and assign the new value in the 'out' param
bool removeRolls(int32_t j, int32_t i, const std::vector<std::string>& linesIn, std::vector<std::string>& linesOut)
{
	int32_t count = 0;
	for (int32_t y = std::max(j - 1, 0); y <= std::min(j + 1, static_cast<int32_t>(linesIn.size() - 1)); y++)
	{
		for (int32_t x = std::max(i - 1, 0); x <= std::min(i + 1, static_cast<int32_t>(linesIn[0].length() - 1)); x++)
		{
			if (y == j && x == i) continue;
			count += linesIn[y][x] == '@' ? 1 : 0;
		}
	}

	// if criteria is satisfied, remove roll
	if (count < 4)
	{
		linesOut[j][i] = '.';
		return true;
	}
	return false;
}

int main()
{
	// read data as strings; create NxM grid
	std::ifstream file("inputs/04_2.txt");
	std::string line;
	std::vector<std::string> lines1;
	while (std::getline(file, line))
		lines1.push_back(line);

	// create an 'in' buffer and an 'out' buffer
	std::vector<std::string> lines2 = lines1;
	int32_t width = static_cast<int32_t>(lines1[0].length());
	int32_t height = static_cast<int32_t>(lines1.size());
	int32_t count = 0;
	int32_t currentCount;

	// iterate over each character and check the 'game of life' criteria
	do
	{
		currentCount = 0;
		for (int32_t j = 0; j < height; j++)
			for (int32_t i = 0; i < width; i++)
				currentCount += (lines1[j][i] == '@' && removeRolls(j, i, lines1, lines2)) ? 1 : 0;
		count += currentCount;
		lines1 = lines2;
	} while (currentCount != 0);

	std::cout << "Answer: " << std::to_string(count) << std::endl;
}
