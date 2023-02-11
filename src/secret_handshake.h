#pragma once
#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H

#include <vector>
#include <string>
#include <map>

namespace secret_handshake {
	std::vector<std::string> commands(int n);
	const std::map<int, std::string> options = {
		{0b1, "wink"},
		{0b10, "double blink"},
		{0b100, "close your eyes"},
		{0b1000, "jump"},
		{0b10000, "REVERSE"},
	};
}  // namespace secret_handshake

#endif // SECRET_HANDSHAKE_H
