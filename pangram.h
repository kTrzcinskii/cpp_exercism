#pragma once
#if !defined(PANGRAM_H)
#define PANGRAM_H

#include <stdbool.h>
#include <string>

namespace pangram {
	bool is_pangram(std::string s);
}  // namespace pangram

#endif // PANGRAM_H