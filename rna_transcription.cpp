#include "rna_transcription.h"

char rna_transcription::to_rna(char c)
{
	switch (c)
	{
	case 'C':
		return 'G';
	case 'G':
		return 'C';
	case 'A':
		return 'U';
	case 'T':
		return 'A';
	default:
		return ' ';
	}
}

std::string rna_transcription::to_rna(std::string dna)
{
	//probably there is a better way to write this funtion
	//here I used some tricks from C, <string> or <cstring> may have a function that better handles it
	char* element = strpbrk(&dna[0], &rna_transcription::valuesToChange[0]);
	while (element != nullptr)
	{
		*element = to_rna(*element);
		element = strpbrk(element + 1, &rna_transcription::valuesToChange[0]);
	}
	return dna;
}