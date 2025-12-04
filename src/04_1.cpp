#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <cmath>

// check criteria of a particular row/col
int32_t countRolls(int32_t j, int32_t i, const std::vector<std::string>& lines)
{
	int32_t count = 0;
	for (int32_t y = std::max(j - 1, 0); y <= std::min(j + 1, static_cast<int32_t>(lines.size() - 1)); y++)
	{
		for (int32_t x = std::max(i - 1, 0); x <= std::min(i + 1, static_cast<int32_t>(lines[0].length() - 1)); x++)
		{
			if (y == j && x == i) continue;
			count += lines[y][x] == '@' ? 1 : 0;
		}
	}
	return count;
}

int main()
{
	// read data as strings; create NxM grid
	std::ifstream file("inputs/04_1.txt");
	std::string line;
	std::vector<std::string> lines;
	while (std::getline(file, line))
		lines.push_back(line);

	// iterate over each character and check the 'game of life' criteria
	int32_t width = static_cast<int32_t>(lines[0].length());
	int32_t height = static_cast<int32_t>(lines.size());
	int32_t count = 0;
	for (int32_t j = 0; j < height; j++)
		for (int32_t i = 0; i < width; i++)
			count += (lines[j][i] == '@' && countRolls(j, i, lines) < 4) ? 1 : 0;

	std::cout << "Answer: " << std::to_string(count) << std::endl;
}
