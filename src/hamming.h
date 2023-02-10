#pragma once
#if !defined(HAMMING_H)
#define HAMMING_H

#include <stdexcept>
#include <string>

namespace hamming {
	int compute(std::string s1, std::string s2);
}  // namespace hamming

#endif // HAMMING_H