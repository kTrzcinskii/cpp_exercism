#pragma once
#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H

#include <string>

namespace atbash_cipher {
	std::string encode(std::string s);
	char encode(char c);
	std::string decode(std::string s);
	char decode(char c);

	const std::string originalAlphabet = "abcdefghijklmnopqrstuvwxyz";
	const std::string encodedAlphabet = "zyxwvutsrqponmlkjihgfedcba";
}  // namespace atbash_cipher

#endif // ATBASH_CIPHER_H