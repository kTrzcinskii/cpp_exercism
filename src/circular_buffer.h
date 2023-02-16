#pragma once
#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <queue>

namespace circular_buffer {

	template <typename T>
	class circular_buffer {
	public:
		circular_buffer<T>(size_t capacity);
		T read();
		void write(T arg);
		void clear();
		void overwrite(T arg);
	private:
		std::queue<T> data_;
		size_t capacity_;
		size_t size_ = 0;
	};

}  // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H