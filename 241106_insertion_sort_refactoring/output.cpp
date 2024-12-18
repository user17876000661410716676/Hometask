#include "output.hpp"

#include <iostream>

void dka::out::print_arr(int* arr, const int size, const char* const comment) {
	static const char space = ' ';

	std::cout << comment;
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << space;
	}
	std::cout << std::endl;
}