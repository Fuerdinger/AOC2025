#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

int main()
{
	// read rotations as signed integers
	std::ifstream file("inputs/01_1.txt");
	std::string line;
	std::vector<int32_t> rotations;
	while (std::getline(file, line))
		rotations.push_back(std::stoi(line.substr(1)) * (line[0] == 'R' ? 1 : -1));

	// start at 50, apply each rotation
	int32_t dial = 50;
	int32_t count = 0;
	for (int32_t rot : rotations)
	{
		// keep dial within 0-99
		dial = ((dial + rot) + 100) % 100;

		// increment count if dial is 0
		count += (dial == 0 ? 1 : 0);
	}

	std::cout << "Answer: " << std::to_string(count) << std::endl;
}
