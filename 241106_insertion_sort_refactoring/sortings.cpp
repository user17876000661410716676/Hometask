#include "sortings.hpp"

#include <iostream>

void dka::sort::insertion_sort(int* arr,const int size) {
	int temp = 0;
	for (int i = 1; i < size; i++) {
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}