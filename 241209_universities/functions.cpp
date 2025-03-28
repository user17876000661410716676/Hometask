#include "functions.hpp"

#include <cstdlib>
#include <iostream>

const str::MenuItem* str::menu(const str::MenuItem* current) {
	std::cout << "Список Высших Учебных Заведений Санкт-Петербурга" << std::endl;
	for (int i = 1; i < current->children_count; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;
	std::cout << "Ввод ->";

	int input;
	std::cin >> input;
	std::cout << std::endl;

	return current->children[input];
}

const str::MenuItem* str::exit(const str::MenuItem* current) {
	exit(0);
	return 0;
}

const str::MenuItem* str::info_leti(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* str::info_spbpu(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* str::info_itmo(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* str::info_back(const str::MenuItem* current) {
	return current->parent->parent;
}

const str::MenuItem* str::spbsu_math_mech(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}
const str::MenuItem* str::spbsu_control_processes(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}
const str::MenuItem* str::spbsu_linguistics(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}
const str::MenuItem* str::spbsu_back(const str::MenuItem* current) {
	return current->parent->parent;
}