#include <algorithm>
#include <iostream>
#include <random>

void print_array(const char* const comment, int* arr, int arr_size);

int main() {
    const int arr_size = 20;
    int arr[arr_size];
    srand(time(nullptr));
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 20;
    }

    print_array("Массив до обработки: ", arr, arr_size);

    // Обработка массива
    for (int i = 0; i < arr_size / 2; i++) {
        std::swap(arr[i], arr[arr_size - 1 - i]);
    }

    print_array("Массив после обработки: ", arr, arr_size);
}

void print_array(const char* const comment, int* arr, int arr_size) {
    std::cout << comment;
    static const char* space = " ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << space;
    }
    std::cout << std::endl;
}