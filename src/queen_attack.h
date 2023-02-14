#pragma once
#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <tuple>

namespace queen_attack {
	using position_t = std::pair<int, int>;

	class chess_board {
	public:
		chess_board(position_t w, position_t b);
		position_t white() const;
		position_t black() const;
		bool can_attack() const;
	private:
		position_t white_pos_;
		position_t black_pos_;
		const int MAX_ROWS_COLS = 8;
	};
}  // namespace queen_attack

#endif // QUEEN_ATTACK_H