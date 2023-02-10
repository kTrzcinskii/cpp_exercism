#pragma once
#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <string>
#include <map>
#include <stdexcept>

namespace nucleotide_count {
	class counter {
	public:
		counter(std::string sequance);
		std::map<char, int> nucleotide_counts() const;
	private:
		std::map<char, int> data;
		inline bool is_valid_nucleotide(char c);
	};
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H