#include "queen_attack.h"
#include <stdexcept>
#include <cmath>

namespace queen_attack {
	chess_board::chess_board(position_t w, position_t b)
	{
		if (w.first < 0 || w.second < 0 || b.first < 0 || b.second < 0) throw std::domain_error("Columns and rows must be positive");
		if (w.first >= MAX_ROWS_COLS || w.second >= MAX_ROWS_COLS || b.first >= MAX_ROWS_COLS || b.second >= MAX_ROWS_COLS) throw std::domain_error("Columns and rows cannot be greater than " + MAX_ROWS_COLS);
		white_pos_ = w;
		black_pos_ = b;
	}

	position_t chess_board::white() const
	{
		return white_pos_;
	}

	position_t chess_board::black() const
	{
		return black_pos_;
	}

	bool chess_board::can_attack() const
	{
		//if the same row or same col then obviously yes
		if (white_pos_.first == black_pos_.first || white_pos_.second == black_pos_.second) return true;

		//if not, then we have to check if they are on the same diagonal
		//if thats the case, the difference between row and col is the same
		if (abs(white_pos_.first - black_pos_.first) == abs(white_pos_.second - black_pos_.second)) return true;
		
		return false;
	}
}