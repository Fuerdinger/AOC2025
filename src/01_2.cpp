#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

int main()
{
	// read rotations as signed integers
	std::ifstream file("inputs/01_2.txt");
	std::string line;
	std::vector<int32_t> rotations;
	while (std::getline(file, line))
		rotations.push_back(std::stoi(line.substr(1)) * (line[0] == 'R' ? 1 : -1));

	// start at 50, apply each rotation
	int32_t dial = 50;
	int32_t count = 0;
	for (int32_t rot : rotations)
	{
		// not very elegant... is there a better mathematical way of doing this? Maybe division?
		while (rot != 0)
		{
			// apply each rotation in parts, each sub rot between -99 to +99
			int32_t subRot = std::clamp(rot, -99, 99);

			// if this part of the rotation will make us go over/under 0, increment count
			if (dial + subRot >= 100 || (dial + subRot <= 0 && dial != 0))
				count++;

			// increment dial like in 1_1, continue applying sub rotations
			dial = ((dial + subRot) + 100) % 100;
			rot -= subRot;
		}
	}

	std::cout << "Answer: " << std::to_string(count) << std::endl;
}
