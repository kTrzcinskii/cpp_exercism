#include "nucleotide_count.h"

namespace nucleotide_count {
	counter::counter(std::string seq)
	{
		std::map<char, int> nucls = {
			{'A', 0},
			{'C', 0},
			{'G', 0},
			{'T', 0},
		};

		for (auto letter : seq)
		{
			if (!is_valid_nucleotide(letter)) throw std::invalid_argument(letter + " is not a correct nucleotide!");
			auto pointer = nucls.find(letter);
			pointer->second++;
		}

		data = nucls;
	}

	inline bool counter::is_valid_nucleotide(char c)
	{
		return c == 'A' || c == 'C' || c == 'G' || c == 'T';
	}

	std::map<char, int> counter::nucleotide_counts() const
	{
		return data;
	}
}