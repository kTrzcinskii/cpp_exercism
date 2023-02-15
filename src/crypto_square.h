#pragma once
#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include <string>
#include <vector>
#include <tuple>

namespace crypto_square {
	class cipher {
		using text_semgents_t = std::vector<std::string>;
		using rectangle_size_t = std::pair<int, int>;
	public:
		cipher(std::string text);
		std::string normalize_plain_text() const { return normalized_plain_text_; }
		text_semgents_t plain_text_segments();
		std::string cipher_text() const { return cipher_text_; }
		std::string normalized_cipher_text() const { return normalized_cipher_text_; }
	private:
		std::string plain_text_;
		std::string normalized_plain_text_;
		text_semgents_t plain_text_semgents_{};
		std::string cipher_text_;
		std::string normalized_cipher_text_;

		void set_normalized_plain_text();
		void set_plain_text_segments();
		void set_cipher_text();
		void set_normalized_cipher_text();
		rectangle_size_t find_rectangle(std::string s);
		
	};
}  // namespace crypto_square

#endif // CRYPTO_SQUARE_H