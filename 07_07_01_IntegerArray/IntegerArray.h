#pragma once

class IntegerArray final {
public:
	IntegerArray() = default;
	explicit IntegerArray(int length);
	IntegerArray(const IntegerArray &other);
	~IntegerArray();
	IntegerArray &operator=(const IntegerArray &other);
	int &operator[](int index);
	void Erase();
	void Reallocate(int new_length);
	void Resize(int new_length);
	void InsertBefore(int value, int index);
	void PushFront(int value);
	void PushBack(int value);
	void Remove(int index);
	void Print() const;
	int FindFirst(int value) const;
	int FindLast(int value) const;
	int get_length() const;

private:
	int length_{ 0 };
	int *data_{ nullptr };
};

