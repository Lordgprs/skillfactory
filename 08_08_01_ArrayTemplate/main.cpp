#include "bad_length.h"
#include "bad_range.h"
#include "array.h"

#include <iostream>
#include <exception>
#include <string>

int main() {
	Array<int> array(10);

	for (int i = 0; i < 10; ++i) {
		array[i] = i + 1;
	}
	std::cout << "Original array: " << std::endl;
	array.Print();
	array.Resize(8);
	std::cout << "After Resize(8): " << std::endl;
	array.Print();
	array.InsertBefore(20, 5);
	std::cout << "After InsertBefore (20, 5): " << std::endl;
	array.Print();
	array.Remove(3);
	std::cout << "After Remove(3): " << std::endl;
	array.Print();
	array.PushBack(30);
	std::cout << "After PushBack(30): " << std::endl;
	array.Print();
	array.PushFront(40);
	std::cout << "After PushFront(40): " << std::endl;
	array.Print();
	array.PushBack(30);
	std::cout << "After PushBack(30): " << std::endl;
	array.Print();
	std::cout << "First occurence of number 30: " << array.FindFirst(30) << std::endl;
	std::cout << "Last occurence of number 30: " << array.FindLast(30) << std::endl;
	try {
		array[-5] = 0;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught via array indexing: " << e.what() << std::endl;
	}
	try {
		array.InsertBefore(100, 16);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught via inserting new element into array: " << e.what() << std::endl;
	}
	try {
		array.Resize(-1);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught via array resizing: " << e.what() << std::endl;
	}
	Array<std::string> text{1};
	text[0] = "First line";
	text.PushBack("Second line");
	text.PushFront("Zero line");
	text.Print();
	text.Remove(1);
	text.PushBack("Third line");
	text.Print();
	std::cout << "Second line index is " << text.FindFirst("Second line") << std::endl;


	return 0;
}