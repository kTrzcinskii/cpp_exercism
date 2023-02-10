#include "hamming.h"

int hamming::compute(std::string s1, std::string s2)
{
	if (s1.length() != s2.length()) throw std::domain_error("Dna strands must have the same length");
	int diff = 0;
	for (int i = 0; i < s1.length(); i++) if (s1[i] != s2[i]) diff++;
	return diff;
}