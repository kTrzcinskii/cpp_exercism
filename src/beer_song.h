#pragma once
#include "beer_song.h"
#if !defined(BEER_SONG_H)
#define BEER_SONG_H

#include <string>

namespace beer_song {
	std::string verse(unsigned int index);
	std::string sing(unsigned int from, unsigned int to = 0);
}  // namespace beer_song

#endif // BEER_SONG_H