#include "anagram.h"
#include <cctype>

namespace anagram {
	anagram::anagram(std::string original_word)
	{
		original_word_ = original_word;
	}

	anagram::words_list_t anagram::matches(words_list_t input)
	{
		words_list_t result{};
		for (const auto& word : input)
		{
			if (is_anagram(original_word_, word)) result.push_back(word);
		}
		return result;
	}

	anagram::letters_map_t anagram::get_letters_map(std::string word)
	{
		letters_map_t result{};
		for (const auto& letter : word)
		{
			char let = tolower(letter); //it must be case insensitive
			if (result.find(let) == result.end()) // letter is not yet in map
			{
				result.insert({ let, 1 });
			}
			else //letter already in map, only need to increase
			{
				result.find(let)->second++;
			}
		}
		return result;
	}

	bool anagram::is_anagram(std::string original_word, std::string possbile_anagram)
	{
		return get_letters_map(original_word) == get_letters_map(possbile_anagram) && string_to_lower(original_word) != string_to_lower(possbile_anagram); //the word is not anagram of itself!
	}

	std::string anagram::string_to_lower(std::string s)
	{
		for (auto &c : s)
		{
			c = tolower(c);
		}
		return s;
	}
}