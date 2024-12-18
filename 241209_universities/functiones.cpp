#include "functiones.hpp"

#include <cstdlib>
#include <iostream>

const str::MenuItem* menu(const str::MenuItem* current) {
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

const str::MenuItem* exit(const str::MenuItem* current) {
	exit(0);
	return 0;
}

const str::MenuItem* info_leti(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* info_spbpu(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* info_itmo(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* info_back(const str::MenuItem* current) {
	return current->parent->parent;
}

const str::MenuItem* spbsu_math_mech(const MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}
const str::MenuItem* spbsu_control_processes(const MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}
const str::MenuItem* spbsu_linguistics(const MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}
const str::MenuItem* spbsu_back(const MenuItem* current) {
	return current->parent->parent;
}