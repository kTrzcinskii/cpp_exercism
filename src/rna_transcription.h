#pragma once
#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H

#include <string>
#include <cstring>

namespace rna_transcription {
	const std::string valuesToChange = "CTGA";
	char to_rna(char c);
	std::string to_rna(std::string dna);
}  // namespace rna_transcription

#endif // RNA_TRANSCRIPTION_H