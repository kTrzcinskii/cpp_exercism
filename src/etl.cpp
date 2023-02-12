#include "etl.h"
#include <string> //tolower

std::map<char, int> etl::transform(std::map<int, std::vector<char>> old)
{
	std::map<char, int> result;
	
	for (auto const& pair : old)
	{
		for (auto const letter : pair.second)
		{
			result.insert({ tolower(letter), pair.first });
		}
	}

	return result;
}