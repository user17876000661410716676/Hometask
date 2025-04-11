#include <iostream>

int main() {
	const int size = 5;
	int arr[size]{ 3, 6, 5 , 9, 10 };

	const char space = ' ';
	std::cout << "Массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << space;
	}
	std::cout << std::endl;

	int max = arr[0];
	for (int i : arr) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	int min = arr[0];
	for (int i : arr) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}

	std::cout << "Массив: ";
	for (int i : arr) {
		std::cout << arr[i] << space;
	}
	std::cout << std::endl;

	std::cout << "Минимальный элемент: "
		<< min
		<< std::endl
		<< "Максимальный элемент: "
		<< max;
}