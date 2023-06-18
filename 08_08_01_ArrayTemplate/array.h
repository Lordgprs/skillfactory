#pragma once

#include "bad_range.h"
#include "bad_length.h"
#include <iostream>

template <typename T>
class Array final {
public:
	Array() = default;
	explicit Array(int length) : length_{ length } {
		if (length_ < 0) {
			throw bad_length{length};
		}

		if (length > 0) {
			data_ = new T[length];
		}
	}
	Array(const Array &other) {
		Reallocate(other.get_length());
		for (int index = 0; index < length_; ++index) {
			data_[index] = other.data_[index];
		}
	}
	~Array() {
		delete[] data_;
	}
	Array &operator=(const Array &other) {
		if (this == &other) {
			return *this; // self-assigning check
		}

		Reallocate(other.get_length());
		for (int index = 0; index < length_; ++index) {
			data_[index] = other.data_[index];
		}

		return *this;
	}
	T &operator[](int index) {
		if (index < 0 || index >= length_) {
			throw bad_range{index};
		}
		return data_[index];
	}
	void Erase() {
		delete[] data_;
		length_ = 0;
		data_ = nullptr;
	}
	void Reallocate(int new_length) {
		if (new_length <= 0) {
			throw bad_length{new_length};
		}

		Erase();
		delete[] data_;
		data_ = new T[new_length];
	}
	void Resize(int new_length) {
		if (new_length <= 0) {
			throw bad_length{new_length};
		}
		if (new_length == length_) {
			return;
		}
		if (new_length == 0) {
			Erase();
			return;
		}

		T *temp = new T[new_length];
		int min = new_length > length_ ? length_ : new_length;
		for (int index = 0; index < min; ++index) {
			temp[index] = data_[index];
		}
		delete[] data_;
		data_ = temp;
		length_ = new_length;
	}
	void InsertBefore(T value, int index) {
		if (index < 0 || index > length_) {
			throw bad_range{index};
		}

		T *temp = new T[length_ + 1];
		for (int i = 0; i < index; ++i) {
			temp[i] = data_[i];
		}
		temp[index] = value;
		for (int i = index + 1; i <= length_; ++i) {
			temp[i] = data_[i - 1];
		}
		delete[] data_;
		data_ = temp;
		++length_;
	}
	void PushFront(T value) {
		InsertBefore(value, 0);
	}
	void PushBack(T value) {
		InsertBefore(value, length_);
	}
	void Remove(int index) {
		if (index < 0 || index >= length_) {
			throw bad_range{index};
		}
		if (length_ == 1) {
			Erase();
			return;
		}

		T *temp = new T[length_ - 1];
		for (int i = 0; i < index; ++i) {
			temp[i] = data_[i];
		}
		for (int i = index + 1; i < length_; ++i) {
			temp[i - 1] = data_[i];
		}
		delete[] data_;
		data_ = temp;
		--length_;
	}
	void Print() const {
		std::cout << "Array elements: ";
		for (int i = 0; i < length_; ++i) {
			std::cout << data_[i] << "; ";
		}
		std::cout << std::endl;
	}
	int FindFirst(T value) const {
		for (int i = 0; i < length_; ++i) {
			if (data_[i] == value) {
				return i;
			}
		}
		return -1;
	}
	int FindLast(T value) const {
		for (int i = length_ - 1; i >= 0; --i) {
			if (data_[i] == value) {
				return i;
			}
		}
		return -1;
	}
	int get_length() const {
		return length_;
	}

private:
	int length_{ 0 };
	T *data_{ nullptr };
};
