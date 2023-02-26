#include "food_chain.h"

std::string food_chain::verse(int start)
{
	if (start == NUMBER_OF_VERSES)
	{
		return FINAL;
	}

	std::string result = VERSE_DATA[start - 1];

	for (int i = 0; i < start; i++)
	{
		result += FULL_TEXT[FULL_TEXT_LENGTH - start + i];
	}

	return result;
}

std::string food_chain::verses(int start, int end)
{
	std::string result{};
	for (int i = start; i <= end; i++)
	{
		result += verse(i);
		result += "\n";
	}
	return result;
}

std::string food_chain::sing()
{
	return verses(1, NUMBER_OF_VERSES);
}

