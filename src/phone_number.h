#pragma once
#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

namespace phone_number {
	class phone_number {
	public:
		phone_number(const std::string &number);
		std::string number() const;
		std::string area_code() const;
		operator std::string() const;
	private:
		static const unsigned int AREA_CODE_LEN = 3;
		static const unsigned int NUM_LEN = 10;
		std::string full_number_;
		std::string area_code_;
		bool is_valid_number(const std::string &number);
	};
}  // namespace phone_number

#endif // PHONE_NUMBER_H