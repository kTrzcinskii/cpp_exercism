#include "word_count.h"
#include <cctype>

bool word_count::check_if_apo_is_in_word(const std::string& s, size_t pos)
{
	return pos != 0 && pos != s.length() - 1 && s[pos] == '\'' && isalpha(s[pos - 1]) && isalpha(s[pos + 1]);
}

void word_count::remove_punctuation(std::string& s)
{
	size_t pos = s.find_first_of(word_count::PUNCUTATION);
	while (pos != std::string::npos)
	{
		if (check_if_apo_is_in_word(s, pos))
		{
			pos = s.find_first_of(word_count::PUNCUTATION, pos + 1);
			continue;
		}
		s.replace(pos, 1, " "); //we replace it with " " so that the words are kept seperated
		pos = s.find_first_of(word_count::PUNCUTATION);
	}
}

void word_count::string_to_lower(std::string& s)
{
	for (auto& c : s) c = tolower(c);
}

void word_count::remove_double_whitespaces(std::string& s)
{
	size_t pos = s.find_first_of(word_count::SPLIT_BY);
	size_t pos2 = s.substr(pos + 1).find_first_of(word_count::SPLIT_BY);
	while (pos != std::string::npos)
	{
		if(pos2 == 0) 
		{
			//it means that whitespace is first char in substring
			//but the element before is also whitespace, so we remove it
			s.erase(pos, 1);
			pos--;
			//we search from pos + 1, but as we deleted one element we must decrease pos by one
		}

		pos = s.find_first_of(word_count::SPLIT_BY, pos + 1);
		pos2 = s.substr(pos + 1).find_first_of(word_count::SPLIT_BY);
	}

	if (isspace(s.back())) s.pop_back(); //remove last char if its a single whitespace
	if (isspace(s.front())) s.erase(0, 1); //same with front
}

std::vector<std::string> word_count::split_string(const std::string& s)
{
	std::vector<std::string> result{};
	size_t index = 0;
	size_t pos = s.find_first_of(word_count::SPLIT_BY);
	while (pos != std::string::npos)
	{
		std::string word = s.substr(index, pos - index);
		result.push_back(word);
		index = pos + 1;
		pos = s.find_first_of(word_count::SPLIT_BY, pos + 1); //pos + 1 so we can search for the next occcurane
	}
	result.push_back(s.substr(index)); //we must add the last item, as there might not be whitespace after it

	return result;
}

word_count::word_count_t word_count::words(std::string s)
{
	word_count_t result{};
	remove_punctuation(s);
	remove_double_whitespaces(s);
	string_to_lower(s);
	std::vector<std::string> words = split_string(s);
	for (const auto &word : words)
	{
		if (result.find(word) == result.end()) //the key doesnt exist yet
		{
			result.insert({ word, 1 });
		}
		else //key already exists
		{
			result.find(word)->second++;
		}
	}
	return result;
}