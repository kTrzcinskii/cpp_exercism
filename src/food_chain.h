#pragma once
#if !defined(FOOD_CHAIN_H)
#define FOOD_CHAIN_H

#include <string>

namespace food_chain {
	std::string verse(int start);
	std::string verses(int start, int end);
	std::string sing();

	const std::string FULL_TEXT[] = { "She swallowed the cow to catch the goat.\n",
		"She swallowed the goat to catch the dog.\n",
		"She swallowed the dog to catch the cat.\n",
		"She swallowed the cat to catch the bird.\n",
		"She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n",
		"She swallowed the spider to catch the fly.\n",
		"I don't know why she swallowed the fly. Perhaps she'll die.\n"};

	const std::string VERSE_DATA[] = {
		"I know an old lady who swallowed a fly.\n",
		"I know an old lady who swallowed a spider.\nIt wriggled and jiggled and tickled inside her.\n",
		"I know an old lady who swallowed a bird.\nHow absurd to swallow a bird!\n",
		"I know an old lady who swallowed a cat.\nImagine that, to swallow a cat!\n",
		"I know an old lady who swallowed a dog.\nWhat a hog, to swallow a dog!\n",
		"I know an old lady who swallowed a goat.\nJust opened her throat and swallowed a goat!\n",
		"I know an old lady who swallowed a cow.\nI don't know how she swallowed a cow!\n",
	};

	const std::string FINAL = "I know an old lady who swallowed a horse.\nShe's dead, of course!\n";

	constexpr int NUMBER_OF_VERSES = 8;
	constexpr int FULL_TEXT_LENGTH = 7;

}  // namespace food_chain

#endif // FOOD_CHAIN_H