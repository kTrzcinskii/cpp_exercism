#include "scrabble_score.h"

int scrabble_score::score(std::string word)
{
	int score = 0;

	for (auto letter : word)
	{
		//if its not a letter we dont care
		if (!isalpha(letter)) continue;
		//it will always find something so we dont check if the return iterator is equal to values.end()
		score += values.find(tolower(letter))->second;
	}

	return score;
}