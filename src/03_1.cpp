#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

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
	int32_t count = 0;
	for (auto& vec : lines)
	{
		// get first largest int (purposefully don't include last element in search)
		auto maxIter = std::max_element(vec.begin(), vec.end() - 1);

		// get the largest int in the range AFTER our first largest int
		auto maxIter2 = std::max_element(maxIter + 1, vec.end());

		// the searches above guarantee we will get two integers
		count += (*maxIter) * 10 + (*maxIter2);
	}

	std::cout << "Answer: " << std::to_string(count) << std::endl;
}
