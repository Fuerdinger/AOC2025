#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <utility>
#include <cstddef>

bool mergeRanges(std::pair<int64_t, int64_t> range1, std::pair<int64_t, int64_t> range2, std::pair<int64_t, int64_t>& rangeOut)
{
	// if ranges appear like:
	//  *-------------*
	//                     *-------------*
	// where they don't have any overlap, then return false
	if (range1.second < range2.first || range1.first > range2.second)
		return false;

	// if ranges appear like:
	// *--------------*
	//             *-------------*
	// where they have some overlap, then "merge" them into one, and assign the merged version into rangeOut
	rangeOut.first = std::min(range1.first, range2.first);
	rangeOut.second = std::max(range1.second, range2.second);
	return true;
}

int main()
{
	// read ranges as signed integers
	std::ifstream file("inputs/05_2.txt");
	std::string line;
	std::vector<std::pair<int64_t, int64_t>> ranges;
	while (std::getline(file, line))
	{
		size_t idx = line.find('-');
		int64_t x1 = std::stoll(line.substr(0, idx));
		int64_t x2 = std::stoll(line.substr(idx + 1, line.length() - (idx + 1)));
		ranges.push_back({x1, x2});
	}

	// iterate over each range
	int64_t count = 0;
	for (int64_t i = 0; i < ranges.size(); i++)
	{
		// merge this range with all other ranges. Will not modify current range.
		int64_t mergeCount = 0;
		for (int64_t j = i + 1; j < ranges.size(); j++)
			mergeCount += mergeRanges(ranges[i], ranges[j], ranges[j]) == true ? 1 : 0;

		// if we couldn't merge the range with any other ranges, then we can say it is a "unique"
		//  range, and it stands on its own. Add its count
		if (mergeCount == 0)
			count += (ranges[i].second - ranges[i].first) + 1;
	}

	std::cout << "Answer: " << std::to_string(count) << std::endl;
}
