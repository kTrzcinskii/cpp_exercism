#include "phone_number.h"
#include <cctype>
#include <stdexcept>

namespace phone_number {
	phone_number::phone_number(const std::string &number)
	{
		std::string actual_number{};
		for (auto const& c : number)
		{
			if (isdigit(c)) actual_number += c;
		}
		if (!is_valid_number(actual_number)) throw std::domain_error("Provided number is not valid");
		if (actual_number.length() == static_cast<size_t>(NUM_LEN + 1)) actual_number = actual_number.substr(1);
		full_number_ = actual_number;
		area_code_ = actual_number.substr(0, AREA_CODE_LEN);
	}

	bool phone_number::is_valid_number(const std::string &number)
	{
		if (number.length() != static_cast<size_t>(NUM_LEN) && number.length() != static_cast<size_t>(NUM_LEN + 1)) return false;

		if (number.length() == static_cast<size_t>(NUM_LEN + 1))
		{
			if (number[0] != '1') return false;
			if (number[1] == '0' || number[1] == '1') return false;
			if (number[4] == '0' || number[4] == '1') return false;
		}
		else
		{
			if (number[0] == '0' || number[0] == '1') return false;
			if (number[3] == '0' || number[3] == '1') return false;
		}

		return true;
	}

	std::string phone_number::number() const
	{
		return full_number_;
	}

	std::string phone_number::area_code() const
	{
		return area_code_;
	}

	phone_number::operator std::string() const
	{
		std::string number{};
		number = "(" + area_code_ + ") " + full_number_.substr(3, 3) + "-" + full_number_.substr(6, 4);
		return number;
	}
}