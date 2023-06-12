#include "IntegerArray.h"
#include "bad_range.h"
#include "bad_length.h"
#include <iostream>

IntegerArray::IntegerArray(const int length) : length_{ length } {
	if (length_ < 0) {
		throw bad_length{length};
	}

	if (length > 0) {
		data_ = new int[length];
	}
}

IntegerArray::IntegerArray(const IntegerArray &other) {
	Reallocate(other.get_length());
	for (int index = 0; index < length_; ++index) {
		data_[index] = other.data_[index];
	}
}

IntegerArray::~IntegerArray() {
	delete[] data_;
}

void IntegerArray::Erase() {
	delete[] data_;
	length_ = 0;
	data_ = nullptr;
}

void IntegerArray::Reallocate(const int new_length) {
	if (new_length <= 0) {
		throw bad_length{new_length};
	}

	Erase();
	delete[] data_;
	data_ = new int[new_length];
}

void IntegerArray::Resize(const int new_length) {
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

	int *temp = new int[new_length];
	int min = new_length > length_ ? length_ : new_length;
	for (int index = 0; index < min; ++index) {
		temp[index] = data_[index];
	}
	delete[] data_;
	data_ = temp;
	length_ = new_length;
}

void IntegerArray::InsertBefore(const int value, const int index) {
	if (index < 0 || index > length_) {
		throw bad_range{index};
	}

	int *temp = new int[length_ + 1];
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

void IntegerArray::PushFront(const int value) {
	InsertBefore(value, 0);
}

void IntegerArray::PushBack(const int value) {
	InsertBefore(value, length_);
}

void IntegerArray::Remove(int index) {
	if (index < 0 || index >= length_) {
		throw bad_range{index};
	}
	if (length_ == 1) {
		Erase();
		return;
	}

	int *temp = new int[length_ - 1];
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

void IntegerArray::Print() const {
	std::cout << "Array elements: ";
	for (int i = 0; i < length_; ++i) {
		std::cout << data_[i] << "; ";
	}
	std::cout << std::endl;
}

int IntegerArray::FindFirst(const int value) const {
	for (int i = 0; i < length_; ++i) {
		if (data_[i] == value) {
			return i;
		}
	}
	return -1;
}

int IntegerArray::FindLast(const int value) const {
	for (int i = length_ - 1; i >= 0; --i) {
		if (data_[i] == value) {
			return i;
		}
	}
	return -1;
}

IntegerArray &IntegerArray::operator=(const IntegerArray &other) {
	if (this == &other) {
		return *this; // self-assigning check
	}
	
	Reallocate(other.get_length());
	for (int index = 0; index < length_; ++index) {
		data_[index] = other.data_[index];
	}

	return *this;
}

int &IntegerArray::operator[](const int index) {
	if (index < 0 || index >= length_) {
		throw bad_range{index};
	}
	return data_[index];
}

int IntegerArray::get_length() const {
	return length_;
}
