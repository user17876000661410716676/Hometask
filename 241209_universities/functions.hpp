#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include "structs.hpp"

namespace str {
	const MenuItem* menu(const MenuItem* current);

	const MenuItem* exit(const MenuItem* current);

	const MenuItem* info_leti(const MenuItem* current);
	const MenuItem* info_spbsu(const MenuItem* current);
	const MenuItem* info_spbpu(const MenuItem* current);
	const MenuItem* info_itmo(const MenuItem* current);
	const MenuItem* info_back(const MenuItem* current);

	const MenuItem* spbsu_math_mech(const MenuItem* current);
	const MenuItem* spbsu_control_processes(const MenuItem* current);
	const MenuItem* spbsu_linguistics(const MenuItem* current);
	const MenuItem* spbsu_back(const MenuItem* current);
}

#endif