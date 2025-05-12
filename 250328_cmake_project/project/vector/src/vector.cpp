#include "vector.hpp"

#include <iostream>

using biv::Vector;

template<typename T>
Vector<T>::Vector() : capacity(START_CAPACITY), size(0) {
	arr = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
	delete[] arr;
}

template<typename T>
T& Vector<T>::operator[](std::size_t index) {
	if (index >= size) {
		throw std::out_of_range("Index out of range");
	}
	return arr[index];
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
	return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (std::size_t i = 0; i < size; i++) {
		if (arr[i] == value) return 1;
	}
	return 0;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (position > size) {
		return 0;
	}

	if (size >= capacity) {
		capacity *= 2;
		T* new_arr = new T[capacity];

		for (std::size_t i = 0; i < size; i++) {
			new_arr[i] = arr[i];
		}

		delete[] arr;
		arr = new_arr;
	}

	for (std::size_t i = size; i > position; i--) {
		arr[i] = arr[i - 1];
	}

	arr[position] = value;
	size++;
	return 1;
}

template<typename T>
void Vector<T>::print() const noexcept {
	for (std::size_t i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	if (size < capacity) {
		arr[size] = value;
		size++;
	} else {
		capacity *= 2;
		T* new_arr = new T[capacity];

		for (std::size_t i = 0; i < size; i++) {
			new_arr[i] = arr[i];
		}
		delete[] arr;

		new_arr[size] = value;
		arr = new_arr;
		size++;
	}
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
	for (std::size_t i = 0; i < size; i++) {
		if (value == arr[i]) {
			for (i; i < size - 1; i++) {
				arr[i] = arr[i + 1];
			}
			size--;
			
			if (capacity - size >= 200) {
				capacity = size + 100;
				T* new_arr = new T[capacity];
				for(std::size_t i = 0; i < size; i++){
					new_arr[i] = arr[i];
				}
				delete[] arr;
				arr = new_arr;
			}
			return 1;
		}
	}
	return 0;
}