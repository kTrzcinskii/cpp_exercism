#include "secret_handshake.h"
#include <algorithm>

std::vector<std::string> secret_handshake::commands(int n)
{
	std::vector<std::string> result{};
	//values are stored in map by key in ascending order so we can just iterate over the map and the order of the bits will be correct
	for (auto const& x : options) //using reference to avoid making copy of the map
	{
		//if they have the same bit
		if ((x.first & n) == x.first)
		{
			if (x.second == "REVERSE")
			{
				//easies way to reverse the vector
				std::reverse(result.begin(), result.end());
			}
			else
			{
				//just add the value to the vector
				result.push_back(x.second);
			}
		}
	}
	return result;
}