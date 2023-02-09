#pragma once
#if !defined(ISOGRAM_H)
#define ISOGRAM_H

#include <string>
#include <cctype>

namespace isogram {
	bool is_isogram(std::string word);
}  // namespace isogram

#endif // ISOGRAM_H