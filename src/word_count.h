#pragma once
#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <map>
#include <string>
#include <vector>

namespace word_count {
	using word_count_t = std::map<std::string, int>;
	word_count_t words(std::string s);
	bool check_if_apo_is_in_word(const std::string& s, size_t pos);
	void remove_punctuation(std::string& s);
	void string_to_lower(std::string& s);
	void remove_double_whitespaces(std::string& s);
	std::vector<std::string> split_string(const std::string& s);
	const std::string PUNCUTATION = "!?,.;:'\"/-_@#$%^&*()";
	const std::string SPLIT_BY = " \n\r\f\v\t";
}  // namespace word_count

#endif // WORD_COUNT_H