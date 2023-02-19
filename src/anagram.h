#pragma once
#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <string>
#include <vector>
#include <map>

namespace anagram {
	class anagram {
		using words_list_t = std::vector<std::string>;
		using letters_map_t = std::map<char, unsigned int>;
	public:
		anagram(std::string original_word);
		words_list_t matches(words_list_t input);
	private:
		std::string original_word_;
		bool is_anagram(std::string original_word, std::string possible_anagram);
		letters_map_t get_letters_map(std::string word);
		std::string string_to_lower(std::string s);
	};
}  // namespace anagram

#endif // ANAGRAM_H