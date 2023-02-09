#pragma once
#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <string>
#include <vector>
#include <map>

namespace protein_translation {
	const std::map<std::string, std::string> codons = {
		{"AUG", "Methionine"},
		{"UUU", "Phenylalanine"},
		{"UUC", "Phenylalanine"},
		{"UUA", "Leucine"},
		{"UUG", "Leucine"},
		{"UCU", "Serine"},
		{"UCC", "Serine"},
		{"UCA", "Serine"},
		{"UCG", "Serine"},
		{"UAU", "Tyrosine"},
		{"UAC", "Tyrosine"},
		{"UGU", "Cysteine"},
		{"UGC", "Cysteine"},
		{"UGG", "Tryptophan"},
		{"UAA", ""},
		{"UAG", ""},
		{"UGA", ""},
	};

	constexpr int CODON_LEN = 3;
	
	std::vector<std::string> proteins(std::string sequance);
}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
