#include "output.hpp"
#include "sortings.hpp"

#include <random>

int main() {
	const int size = 100;
	int arr[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size;
	}

	dka::out::print_arr(arr, size, "Сгенерированный массив: ");

	dka::sort::insertion_sort(arr, size);

	dka::out::print_arr(arr, size, "Отсортированный массив: ");
}