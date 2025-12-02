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
	std::ifstream file("inputs/02_2.txt");
	std::string line;
	std::vector<std::pair<int64_t, int64_t>> ranges;
	std::getline(file, line);
	size_t idx1 = 0, idx2 = 0, idx3 = 0;
	while (idx3 != std::string::npos)
	{
		idx2 = line.find('-', idx1) + 1;
		idx3 = line.find(',', idx2);
		ranges.push_back({std::stoll(line.substr(idx1, idx2 - idx1 - 1)), std::stoll(line.substr(idx2, idx3 - idx2))});
		idx1 = idx3 + 1;
	}

	// check each ID in each range to see if it is invalid
	int64_t count = 0;
	for (auto pair : ranges)
	{
		for (int64_t i = pair.first; i <= pair.second; i++)
		{
			// convert back to string
			std::string id = std::to_string(i);

			// try each combination of sequences (length 1 sequences, length 2 sequences, ...)
			for (int64_t j = 1; j <= id.length() / 2; j++)
			{
				// if the sequence length doesn't divide evenly into the string, skip it
				if (id.length() % j == 1)
					continue;

				// check to see if all sub strings of sequence length 'j' are the same
				std::string idSub = id.substr(0, j);
				bool isSame = true;
				for (int64_t k = 0; k < id.length(); k += j)
				{
					if (id.substr(k, j) != idSub)
					{
						isSame = false;
						break;
					}
				}

				// add invalid ID to i, only if it satisfies criteria
				count += (isSame) ? i : 0;
				if (isSame)
					break;
			}
		}
	}

	std::cout << "Answer: " << std::to_string(count) << std::endl;
}
