#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <utility>
#include <cstddef>

int main()
{
	// read ranges as signed integers
	std::ifstream file("inputs/05_1.txt");
	std::string line;
	std::vector<std::pair<int64_t, int64_t>> ranges;
	std::vector<int64_t> ids;
	while (std::getline(file, line))
	{
		size_t idx = line.find('-');
		if (idx == std::string::npos)
			break;
		ranges.push_back({std::stoll(line.substr(0, idx)), std::stoll(line.substr(idx + 1, line.length() - (idx + 1)))});
	}
	// read ids
	while (std::getline(file, line))
	{
		ids.push_back(std::stoll(line));
	}

	// check each id against each range. simple enough
	int64_t count = 0;
	for (int64_t id : ids)
	{
		for (auto& range : ranges)
		{
			if (id >= range.first && id <= range.second)
			{
				count += 1;
				break;
			}
		}
	}

	std::cout << "Answer: " << std::to_string(count) << std::endl;
}
