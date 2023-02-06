#include "isogram.h"

bool isogram::is_isogram(std::string word)
{
	constexpr int howManyLetters = 'z' - 'a' + 1;
	bool letter[howManyLetters]{}; //fancy way to init it with false

	for (auto c : word)
	{
		if (!isalpha(c)) continue;
		c = tolower(c);
		int index = c - 'a';
		if (letter[index]) return false;
		letter[index] = true;
	}

	return true;
}