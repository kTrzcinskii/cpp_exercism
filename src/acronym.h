#pragma once
#if !defined(ACRONYM_H)
#define ACRONYM_H

#include <string>

namespace acronym {
	std::string format_string(std::string input);
	std::string acronym(const std::string &input);
}  // namespace acronym

#endif // ACRONYM_H