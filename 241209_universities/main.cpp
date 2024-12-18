#include "structs.hpp"
#include "functiones.hpp"
#include "menu_fragments.hpp"

#include <clocale>
#include <iostream>

int main() {
	std::setlocale(LC_ALL, "");

	const str::MenuItem* current = &str::MAIN;
	do {
		current = current->func(current);
	} while (true);
}