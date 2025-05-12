#include "doubly_linked_list.hpp"

#include <iostream>

using biv::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	Node* current = begin;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	return size;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	Node* current = begin;
	while (current != nullptr) {
		if (current->value == value) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	Node* current = begin;
	while (current != nullptr) {
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* new_node = new Node(value);
	if (begin == nullptr) {
		begin = new_node;
		end = new_node;
	}
	else {
		end->next = new_node;
		new_node->prev = end;
		end = new_node;
	}
	size++;
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	Node* current = begin;
	while (current != nullptr) {
		if (current->value == value) {
			if (current == begin) {
				begin = current->next;
				if (begin != nullptr) {
					begin->prev = nullptr;
				}
			}
			else if (current == end) {
				end = current->prev;
				end->next = nullptr;
			}
			else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}

			delete current;
			size--;
			return 1;
		}
		current = current->next;
	}
	return 0;
}

template<typename T>
T DoublyLinkedList<T>::get_value(std::size_t index) {
	if (index >= size) {
		throw std::out_of_range("Out of range");
	}

	Node* current = begin;
	std::size_t current_index = 0;
	while (current_index < index) {
		current = current->next;
		current_index++;
	}
	return current->value;
}
