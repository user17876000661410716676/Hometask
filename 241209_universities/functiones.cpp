#include "functiones.hpp"

#include <cstdlib>
#include <iostream>

const str::MenuItem* menu(const str::MenuItem* current) {
	std::cout << "Welcome to Saint_Petersburg's Universities list!" << std::endl;
	for (int i = 1; i < current->children_count; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;
	std::cout << "Input ->";

	int input;
	std::cin >> input;
	std::cout << std::endl;

	return current->children[input];
}

const str::MenuItem* exit(const str::MenuItem* current) {
	exit(0);
	return 0;
}

const str::MenuItem* leti(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* spbsu(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* spbpu(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* itmo(const str::MenuItem* current) {
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const str::MenuItem* back(const str::MenuItem* current) {
	return current->parent->parent;
}