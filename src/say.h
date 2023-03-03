#pragma once
#if !defined(SAY_H)
#define SAY_H

#include <string>
#include <vector>

namespace say {
	enum VALUES {
		BILLION = 4,
		MILLION = 3,
		THOUSAND = 2,
	};

	std::string zero_to_nineteen(unsigned int number);
	std::string dozens(unsigned int number);
	std::string hundreds(unsigned int number);
	std::string zero_to_ninety_nine(unsigned int number);
	std::string up_to_3_digits(unsigned int number);
	std::vector<unsigned int> get_groups_of_3(long long number);
	std::string get_value_string(unsigned int n);
	std::string in_english(long long number);
	constexpr unsigned long long MAX_NUMBER = 999999999999;
}  // namespace say

#endif // SAY_H