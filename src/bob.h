#pragma once
#if !defined(BOB_H)
#define BOB_H

#include <string>

namespace bob {
	bool no_letters_in_string(const std::string &input);
	bool no_digits_in_string(const std::string &input);
	bool is_sentence_a_question(const std::string &input);
	bool all_letters_upper(const std::string &input);
	std::string hey(std::string input);
	const std::string all_responses[] = {
		"Sure.",
		"Whoa, chill out!",
		"Calm down, I know what I'm doing!",
		"Fine. Be that way!",
		"Whatever."
	};
	enum class Responses {
		Sure = 0,
		Whoa = 1,
		Calm_Down = 2,
		Fine = 3,
		Whatever = 4
	};
}  // namespace bob

#endif // BOB_H