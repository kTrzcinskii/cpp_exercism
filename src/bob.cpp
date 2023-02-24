#include <cctype>
#include "bob.h"

bool bob::no_letters_in_string(const std::string& input)
{
	for (const auto& element : input)
	{
		if (isalpha(element)) return false;
	}
	return true;
}

bool bob::no_digits_in_string(const std::string& input)
{
	for (const auto& element : input)
	{
		if (isdigit(element)) return false;
	}
	return true;
}

bool bob::is_sentence_a_question(const std::string &input)
{
	char last_element{};
	int i = 0;
	do
	{
		last_element = input[input.size() - i - 1];
		i++;

	} while (isspace(last_element) && static_cast<size_t>(i + 1) <= input.size());
	return last_element == '?';
}

bool bob::all_letters_upper(const std::string& input)
{
	for (const auto& element : input)
	{
		if (islower(element)) return false;
	}
	return true;
}

std::string bob::hey(std::string input)
{
	if (no_letters_in_string(input) && no_digits_in_string(input) && !is_sentence_a_question(input)) return all_responses[static_cast<size_t>(Responses::Fine)];
	if (is_sentence_a_question(input))
	{
		if (all_letters_upper(input) && !no_letters_in_string(input)) return all_responses[static_cast<size_t>(Responses::Calm_Down)];
		else return all_responses[static_cast<size_t>(Responses::Sure)];
	}
	if (all_letters_upper(input) && !no_letters_in_string(input)) return all_responses[static_cast<size_t>(Responses::Whoa)];
	return all_responses[static_cast<size_t>(Responses::Whatever)];
}