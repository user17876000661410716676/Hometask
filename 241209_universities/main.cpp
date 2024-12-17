#include "structs.hpp"
#include "functiones.hpp"
#include "menu_fragments.hpp"

#include <iostream>

int main() {

	const str::MenuItem* current = &str::MAIN;
	do {
		current = current->func(current);
	} while (true);
}