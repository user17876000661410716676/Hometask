#include <algorithm>
#include <cmath>
#include <iostream>
#include <clocale>
#include <random>
#include <locale>

void print_array(const char* const comment, int* arr, int arr_size);

int main() {
    // Инициализация массива
    const int arr_size = 20;
    int arr[arr_size];
    srand(time(nullptr));
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 20;
    }

    setlocale(LC_ALL, "");
    print_array("Массив до обработки: ", arr, arr_size);

    // Обработка массива
    for (int i = 0; i < arr_size / 2; i++) {
        std::swap(arr[i], arr[arr_size - 1 - i]);
    }

    print_array("Массив после обработки: ", arr, arr_size);
}

void print_array(const char* const comment, int* arr, int arr_size) {
    std::cout << comment;
    for (int i = 0; i < arr_size; i++) {
        std::wcout << arr[i] << L" ";
    }
    std::cout << std::endl;
}