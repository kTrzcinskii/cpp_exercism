#include "crypto_square.h"
#include <cctype>
#include <cmath>

namespace crypto_square {
	cipher::cipher(std::string text)
	{
		plain_text_ = text;
		set_normalized_plain_text();
		set_plain_text_segments();
		set_normalized_cipher_text();
		set_cipher_text();
	}

	void cipher::set_normalized_plain_text()
	{
		for (auto const c : plain_text_)
		{
			if (isdigit(c)) normalized_plain_text_ += c;
			if (isalpha(c)) normalized_plain_text_ += tolower(c);
		}
	}

	cipher::rectangle_size_t cipher::find_rectangle(std::string s)
	{
		int len = s.length();

		//square
		for (int i = 1; i <= sqrt(len); i++)
		{
			if (i * i == len) return rectangle_size_t{ i, i };
		}

		//rectangle
		for (int i = 1; i <= sqrt(len); i++)
		{
			if (i * (i + 1) >= len) return rectangle_size_t{ i + 1 , i };
		}

		return rectangle_size_t{ 0, 0 };
	}

	void cipher::set_plain_text_segments()
	{
		rectangle_size_t rect = find_rectangle(normalized_plain_text_);

		std::string temp{};
		for (int i = 0; i < rect.second; i++)
		{
			temp = normalized_plain_text_.substr(rect.first * i, rect.first);
			while (temp.length() < static_cast<size_t>(rect.first)) temp += " ";
			plain_text_semgents_.push_back(temp);
		}
	}

	void cipher::set_cipher_text()
	{
		cipher_text_ = normalized_cipher_text_;
		size_t pos = cipher_text_.find(" ");
		while (pos != std::string::npos)
		{
			cipher_text_.erase(pos, 1);
			pos = cipher_text_.find(" ");
		}
	}

	void cipher::set_normalized_cipher_text()
	{
		rectangle_size_t rect = find_rectangle(normalized_plain_text_);

		std::string temp{};
		for (int i = 0; i < rect.first; i++)
		{
			if (i != 0) normalized_cipher_text_ += " ";
			for (int j = 0; j < rect.second; j++) temp += plain_text_semgents_[j][i];
			normalized_cipher_text_ += temp;
			temp.clear();
		}
	}

	cipher::text_semgents_t cipher::plain_text_segments()
	{
		text_semgents_t result{};
		for (auto el : plain_text_semgents_)
		{
			size_t pos = el.find(" ");
			while (pos != std::string::npos)
			{
				el.erase(pos, 1);
				pos = el.find(" ");
			}
			result.push_back(el);
		}
		return result;
	}
}