#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <cmath>
#include <cstddef>

int main()
{
	// read battery power as signed integers
	std::ifstream file("inputs/03_1.txt");
	std::string line;
	std::vector<std::vector<int32_t>> lines;
	while (std::getline(file, line))
	{
		lines.push_back({});
		for (char c : line)
			lines.back().push_back(c - '0');
	}

	// search for max elements
	size_t count = 0;
	for (auto& vec : lines)
	{
		// this algorithm is basically the same as 03_1, but generalized from length 2 to length 12
		auto maxIter = vec.begin();
		for (int32_t i = 11; i >= 0; i--)
		{
			maxIter = std::max_element(maxIter, vec.end() - i);
			count += (static_cast<size_t>(*maxIter)) * static_cast<size_t>(std::round(std::pow(10.0, static_cast<double>(i))));
			maxIter += 1;
		}
	}

	std::cout << "Answer: " << std::to_string(count) << std::endl;
}
