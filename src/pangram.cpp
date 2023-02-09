#include "pangram.h"

bool pangram::is_pangram(std::string s)
{
	constexpr int arr_size = 'z' - 'a' + 1; //constexp make compiler calculate this before doing anything else so that we can use it as a size of array
	bool doesContain[arr_size]{}; // {} is to initialize array with all fields set to false

	for (auto c : s) //fancy for loop, somethign like foreach in other languages
	{
		int index = std::tolower(c) - 'a';
		if (index < 0 || index >= arr_size) continue; //its not letter so we can skip this character
		doesContain[index] = true;
	}

	for (auto value : doesContain) if (!value) return false; //if there is any letter that is not in the string we return false

	return true;
}