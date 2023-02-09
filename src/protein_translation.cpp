#include "protein_translation.h"

std::vector<std::string> protein_translation::proteins(std::string sequence)
{
	std::vector<std::string> output;
	//we asume that sequence is correct
	//so that it only have values we have in our map
	//and that the length of sequence is multiple of 3
	int current_pos = 0;
	//there is probably better way to operate on substrings than this
	while (current_pos * CODON_LEN < static_cast<int>(sequence.length())) //to make exercsim compiler happy about types
	{
		std::string sub = sequence.substr(current_pos * CODON_LEN, CODON_LEN);
		std::string value = codons.find(sub)->second;
		if (value == "") break;
		output.push_back(value);
		current_pos++;
	}
	return output;
}