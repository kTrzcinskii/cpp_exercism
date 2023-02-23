#include "beer_song.h"

std::string beer_song::verse(unsigned int index)
{
	if (index == 0)
	{
		return "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n";
	}
	if (index == 1)
	{
		return "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n";
	}

	std::string id = std::to_string(index);
	std::string id_decreased = std::to_string(index - 1);

	return  id + " bottles of beer on the wall, " + id + " bottles of beer.\nTake one down and pass it around, " + id_decreased + " bottle" + (index - 1 > 1 ? "s" : "") + " of beer on the wall.\n";
}

std::string beer_song::sing(unsigned int from, unsigned int to)
{
	std::string result{};
	for (int i = static_cast<int>(from); i >= static_cast<int>(to); i--)
	{
		if (i != static_cast<int>(from)) result += "\n";
		result += verse(i);
	}
	return result;
}