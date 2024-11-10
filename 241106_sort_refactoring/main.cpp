#include "output.hpp"
#include "sortings.hpp"

#include <random>

int main() {
	const int size = 100;
	int arr[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size;
	}

	out::PrintArr(arr, size, "Generated array:");

	sort::InsertionSort(arr, size);

	out::PrintArr(arr, size, "Sorted array:");
}