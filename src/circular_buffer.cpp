#include "circular_buffer.h"
#include <stdexcept>

namespace circular_buffer {
	template <typename T>
	circular_buffer<T>::circular_buffer(size_t capacity)
	{
		capacity_ = capacity;
		data_ = std::queue<T>{};
	}

	template <typename T>
	T circular_buffer<T>::read()
	{
		if (size_ == 0) throw std::domain_error("Nothing to read!");
		T temp = data_.front();
		data_.pop();
		size_--;
		return temp;
	}

	template <typename T>
	void circular_buffer<T>::write(T arg)
	{
		if (size_ == capacity_) throw std::domain_error("Buffer is full!");
		data_.push(arg);
		size_++;
	}

	template <typename T>
	void circular_buffer<T>::clear()
	{
		//replace actual queue with an empty one
		std::queue<T> empty{};
		std::swap(data_, empty);
		size_ = 0;
	}

	template <typename T>
	void circular_buffer<T>::overwrite(T arg)
	{
		if (size_ < capacity_)
		{
			write(arg);
			return;
		}

		//if data is full, remove element and add new one
		data_.pop();
		data_.push(arg);
	}
}