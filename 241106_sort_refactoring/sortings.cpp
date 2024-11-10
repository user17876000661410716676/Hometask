#include "sortings.hpp"

#include <iostream>

void sort::InsertionSort(int* arr, int size) {
	int temp = 0;
	for (int i = 0; i < size; i++) {
		int j = i;
		while (arr[j] < arr[j - 1]) {
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}